# Clase: **Ingreso de cadenas de texto por *buffer* de entrada (C estándar) – Nivel Inicial**
 
> Objetivo: leer **texto** desde teclado de forma **segura** y **predecible** usando el *buffer* de entrada estándar (**`stdin`**). Veremos **`fgets`** (recomendada), **`scanf` con anchos**, y **bucles con `getchar`** para controlar el salto de línea y limpiar el *buffer* sin usar `string.h`.

---

## 0) Requisitos mínimos
- Variables, `main`, `printf`, `scanf`.
- Diferencia entre **carácter** (`char`), **arreglo de `char`** y **cadena C** (termina en `'\0'`).
- Compilar y ejecutar en **Code::Blocks** o con **GCC**:
  ```bash
  gcc -std=c11 archivo.c -Wall -Wextra -O2 -o programa
  ./programa
  ```

---

## 1) ¿Qué es el *buffer* de entrada?
El **teclado** no le entrega caracteres “uno por uno” al programa: el sistema operativo acumula lo que escribís en un **búfer** (memoria temporal).  
Cuando **presionás Enter**, ese bloque (terminado en `'\n'`) queda disponible para que lo lea el programa desde **`stdin`**.

**Consecuencia práctica:** muchas veces hay que **manejar o descartar** el `'\n'` que queda en el *buffer* para que la próxima lectura funcione como esperamos.

---

## 2) Opciones para leer texto (resumen)
- **✅ `fgets` (recomendada)**: lee **una línea completa** (hasta `n-1` caracteres o hasta `'\n'`), y **si hay espacio**, incluye el `'\n'`. Siempre termina la cadena con `'\0'` si tuvo éxito.
- **🟡 `scanf` con *anchos***: sirve para **palabras** (sin espacios) con `%Ns` (ej: `%31s`). Se puede usar un *scanset* como `%31[^\n]` para leer hasta `'\n'`. Cuidado con espacios pendientes.
- **🛠️ `getchar` en bucle**: útil para **descartar** el resto de la línea o para leer **carácter por carácter** (incluye espacios).

> ❌ **No usar `gets`** (fue eliminada del estándar por insegura).  
> ⚠️ **No usar `fflush(stdin)`**: en C estándar su comportamiento es **indefinido** (no confiable).

---

## 3) Leer una **línea completa** con `fgets` (y quitar `'\n'` sin `string.h`)
```c
#include <stdio.h>

int main(void) {
    char linea[32];

    printf("Escribe una linea (max 31 chars): ");
    if (fgets(linea, sizeof(linea), stdin)) {
        // Quitar el '\n' si quedó guardado (sin usar string.h)
        for (int i = 0; linea[i] != '\0'; i++) {
            if (linea[i] == '\n') { linea[i] = '\0'; break; }
        }
        printf("Leido: \"%s\"\n", linea);
    } else {
        printf("EOF o error de lectura.\n");
    }
    return 0;
}
```
**Notas clave:**
- Si la entrada excede 31 caracteres, `fgets` lee **solo una parte** y **deja** el resto en el *buffer* para una lectura posterior.
- Siempre chequear el **valor de retorno** (si es `NULL` hubo EOF o error).

---

## 4) Leer **una palabra (sin espacios)** con `scanf` y ancho
```c
#include <stdio.h>

int main(void) {
    char palabra[16]; // admite hasta 15 letras + '\0'
    printf("Ingresa una palabra: ");
    if (scanf("%15s", palabra) == 1) {
        printf("Palabra: \"%s\"\n", palabra);
    } else {
        printf("No se pudo leer la palabra.\n");
    }
    return 0;
}
```
**Tips:**
- Con `%s`, `scanf` **corta en el primer espacio**.  
- El **ancho** (`%15s`) evita **desbordes** del arreglo.  
- Si luego querés leer una **línea**, queda un `'\n'` pendiente: habrá que **descartarlo** (ver sección 6).

---

## 5) Leer **hasta el fin de línea** con `scanf` (scanset)
```c
#include <stdio.h>

int main(void) {
    char linea[32];
    printf("Ingresa una linea (con espacios): ");
    // Lee hasta '\n', limitando a 31 caracteres
    if (scanf("%31[^\n]", linea) == 1) {
        printf("Linea: \"%s\"\n", linea);
    } else {
        printf("No se leyo texto (posible linea vacia).\n");
    }

    // Consumir el '\n' que queda en el buffer (si existe)
    int c;
    do { c = getchar(); } while (c != '\n' && c != EOF);
    return 0;
}
```
**Advertencias:**
- Si la línea está **vacía**, el formato `%[^\n]` falla (retorna 0).
- Después de leer con `%[^\n]` suele **quedar** el `'\n'` pendiente: conviene **consumirlo**.

---

## 6) **Mezclar** números y líneas: el clásico problema del `'\n'`
Si usás `scanf` para leer números y **luego** `fgets` para una línea, el `'\n'` del número queda en el *buffer* y `fgets` leerá **solo una cadena vacía**.

### Solución A: **descartar** hasta `'\n'` antes de `fgets`
```c
#include <stdio.h>

int main(void) {
    int edad;
    char nombre[32];

    printf("Edad: ");
    if (scanf("%d", &edad) != 1) return 1;

    // Descartar el resto de la linea (incluido el '\n')
    int ch;
    do { ch = getchar(); } while (ch != '\n' && ch != EOF);

    printf("Nombre y apellido: ");
    if (fgets(nombre, sizeof(nombre), stdin)) {
        for (int i = 0; nombre[i] != '\0'; i++) {
            if (nombre[i] == '\n') { nombre[i] = '\0'; break; }
        }
        printf("Edad=%d, Nombre=\"%s\"\n", edad, nombre);
    }
    return 0;
}
```

### Solución B (recomendada): **todo con `fgets`** + parseo
```c
#include <stdio.h>

int main(void) {
    char buf[64];
    int edad;

    printf("Edad: ");
    if (!fgets(buf, sizeof(buf), stdin)) return 1;
    if (sscanf(buf, "%d", &edad) != 1) {
        printf("Edad invalida.\n");
        return 1;
    }

    char nombre[32];
    printf("Nombre y apellido: ");
    if (!fgets(nombre, sizeof(nombre), stdin)) return 1;
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (nombre[i] == '\n') { nombre[i] = '\0'; break; }
    }

    printf("Edad=%d, Nombre=\"%s\"\n", edad, nombre);
    return 0;
}
```
> Ventaja: **`fgets` + `sscanf`** evita problemas de `'\n'` y te permite **validar** con facilidad.

---

## 7) **Limpiar** el *buffer* de entrada (C estándar)
Para descartar lo que quede hasta el fin de línea (incluido el `'\n'`):
```c
int c;
do { c = getchar(); } while (c != '\n' && c != EOF);
```
- Útil después de un `scanf` si luego vas a hacer un `fgets` o un nuevo `scanf` que no ignore espacios.
- **No** uses `fflush(stdin)`: **indefinido** en C estándar.

---

## 8) Leer **un carácter** (incluyendo espacios)
```c
#include <stdio.h>

int main(void) {
    char ch;

    printf("Ingresa cualquier caracter (incluye espacios): ");
    ch = getchar(); // lee el primer caracter crudo
    printf("Leido (getchar): '%c' (codigo %d)\n", ch, (int)ch);

    // Consumir el resto de la linea:
    int c; do { c = getchar(); } while (c != '\n' && c != EOF);

    // Con scanf: el espacio delante ignora blancos previos (incluye '\n')
    printf("Ingresa otra tecla: ");
    if (scanf(" %c", &ch) == 1) {
        printf("Leido (scanf): '%c'\n", ch);
    }
    return 0;
}
```
- En `scanf(" %c", &ch)`, el espacio **consume** cualquier cantidad de espacios/blancos previos, incluyendo el `'\n'`.

---

## 9) Validación y reintentos con `fgets` + `sscanf`
```c
#include <stdio.h>

int leer_entero_seguro(const char *prompt, int *out) {
    char buf[64];
    int ok = 0;
    while (!ok) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) return 0; // EOF/error
        if (sscanf(buf, "%d", out) == 1) ok = 1;
        else printf("Valor invalido, intenta de nuevo.\n");
    }
    return 1;
}

int main(void) {
    int edad;
    if (!leer_entero_seguro("Edad: ", &edad)) return 1;

    char nombre[32];
    printf("Nombre: ");
    if (!fgets(nombre, sizeof(nombre), stdin)) return 1;
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (nombre[i] == '\n') { nombre[i] = '\0'; break; }
    }

    printf("OK -> Edad=%d, Nombre=\"%s\"\n", edad, nombre);
    return 0;
}
```
> **Patrón recomendado** para principiantes: **siempre leer con `fgets`** y **parsear** con `sscanf` (o `strtol` más adelante).

---

## 10) Errores comunes y cómo evitarlos
- **Desbordar** el arreglo: siempre limitar (`fgets(buf, sizeof buf, ...)`, `%15s`, `%31[^\n]`, etc.).
- Olvidar que `fgets` **puede** dejar `'\n'` y que **hay que tratarlo**.
- **Mezclar** `scanf` (números) + `fgets` sin descartar el `'\n'` pendiente.
- Confiar en `fflush(stdin)`: **no es C estándar** (indefinido).
- No chequear **valores de retorno** (`fgets` `== NULL`, `scanf` `< 1`, etc.).
- Suponer que `%s` lee una frase completa: **corta en el primer espacio**.

---

## 11) Mini–proyectos guiados (para practicar en clase)
### 11.1) Frase con conteo de caracteres (sin `string.h`)
- **Tarea:** leer una línea con `fgets`, **quitar `'\n'`** y **contar** longitud manualmente.
```c
int len = 0;
while (linea[len] != '\0') len++;
printf("Largo = %d\n", len);
```

### 11.2) Formulario simple (validado)
- Pedir **edad** (entero, reintentar si no es válido) y **nombre completo** (con espacios). Mostrar: `Edad=X, Nombre="..."`.

### 11.3) Lista de compras (hasta línea vacía)
- Leer líneas con `fgets` en un bucle. Si la línea es **vacía** (`"\n"` o `""` luego de quitar `'\n'`), **terminar**. Imprimir la lista cargada.

---

## 12) Plantilla base para tus ejercicios
```c
#include <stdio.h>

int main(void) {
    // 1) Pedir datos
    // 2) Leer con fgets o scanf con anchos segun convenga
    // 3) Limpiar/descartar '\n' si corresponde
    // 4) Validar entradas con bucles
    // 5) Mostrar resultados
    return 0;
}
```

---

## 13) Actividades rápidas (5–10 min)
1. **¿Qué imprime?**: Explicar qué pasa si después de `scanf("%d", &x)` se hace un `fgets` inmediato (sin limpiar el `'\n'`).  
2. **Detective:** Corregir un programa que usa `gets` o `fflush(stdin)`.  
3. **Diseño:** Elegir la mejor técnica para: “leer nombre completo”, “leer una sola palabra”, “leer un número y después una frase”.

---

## 14) Checklist de comprensión
- [ ] Puedo usar `fgets` para leer una **línea completa** de forma segura.  
- [ ] Sé quitar el `'\n'` **sin** `string.h`.  
- [ ] Sé usar `scanf` con **anchos** y **scanset**.  
- [ ] Sé **limpiar el buffer** con `getchar` hasta `'\n'`.  
- [ ] Puedo **validar** la entrada con `fgets` + `sscanf`.  
- [ ] Evito `gets` y `fflush(stdin)` (no estándar/seguro).

---

## 15) Tarea para casita (opcional)
1) Escribí `int leer_linea(char *buf, int tam)` que lea con `fgets`, quite `'\n'` y devuelva `1` en éxito, `0` en EOF/error.  
2) Escribí `int contar_palabras(const char *s)` (sin `string.h`): contar secuencias separadas por espacios.  
3) Escribí un mini–formulario que pida **DNI (entero)**, **apellido y nombre** (línea), y **inicial** (un `char`), validando cada campo.

---

### Apunte visual (ASCII)
```
Teclado -> [b u f f e r ... '\n'] -> stdin
               ^^^^^^^^^^^^^^^^^
               queda en memoria hasta que el programa lo lee
```

**Cierre:** Elegí el camino que prefieras: `fgets` es la opción por defecto para leer texto. Si necesitás números, podes usar `fgets` + `sscanf`. Si preferís mezclar `scanf` y `fgets`, **siempre** controlá el `'\n'`. En nuestro curso, vamos a limitarnos y suponer que quien ingresa datos será inteligente, y no estará intentando desbordar el buffer ni queriendo romper nuestro código :) 
