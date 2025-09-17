# Clase: **Punteros en C (Nivel Inicial, C estándar)**

> **Para 1er año de Tecnicatura en Programación.**  
> Objetivo: entender qué es un puntero, cómo se declara y usa, para qué sirve el operador `&` (dirección) y `*` (contenido), cómo pasar variables a funciones “por referencia”, y cómo evitar errores comunes.  
> **No** veremos temas avanzados (punteros a funciones, `restrict`, aritmética compleja) para enfocarnos en lo esencial.

---

## 0) Requisitos mínimos

- Saber qué es una **variable** y un **arreglo** (array).
- Saber usar un **`main`** y `printf` / `scanf` o `fgets`.
- Compilación recomendada:
  - **Code::Blocks**: crear proyecto “Console Application (C)” y pegar los ejemplos.
  - **GCC** (opcional):  
    ```bash
    gcc -std=c11 archivo.c -Wall -Wextra -O2 -o programa
    ./programa
    ```

---

## 1) Idea intuitiva

- Una **variable** guarda un **valor** (por ej. `int edad = 18;`).
- Ese valor está en algún lugar de la **memoria** de la PC.
- Un **puntero** guarda la **dirección** de memoria donde vive otra variable.

**Analogía:** pensá en una casa (la **variable**) y su dirección (el **puntero**).  
Si tenés la dirección, podés llegar a la casa y **ver o cambiar** lo que hay adentro.

---

## 2) Dos operadores clave

- `&x` → **dirección de** `x`.  
- `*p` → **contenido** al que apunta `p` (también se dice **dereferenciar**).

```c
#include <stdio.h>

int main(void) {
    int x = 42;       // variable normal
    int *p = &x;      // p guarda la dirección de x

    printf("x = %d\n", x);
    printf("&x (direccion) = %p\n", (void*)&x);
    printf("p  (lo que guarda) = %p\n", (void*)p);
    printf("*p (contenido apuntado) = %d\n", *p);

    *p = 100;         // cambia x, porque p apunta a x
    printf("x ahora vale = %d\n", x);

    return 0;
}
```

> Importante: `p` es “puntero a `int`” (se escribe `int *p;`).

---

## 3) Declaración y tipos básicos de puntero

```c
int    *pi;   // puntero a int
double *pd;   // puntero a double
char   *pc;   // puntero a char (muy usado con cadenas)
void   *pv;   // puntero "genérico" (no se puede dereferenciar sin convertir)
```

- El `*` **va con el nombre**: `int *a, *b;` (ambos son punteros a int).
- `void *` sirve para guardar **direcciones de cualquier tipo**, pero **no** se puede usar `*pv` directamente (primero hay que convertirlo al tipo correcto).

---

## 4) Punteros y arreglos (array)

Cuando usamos un arreglo en una **expresión**, su nombre “se convierte” (decay) en **puntero al primer elemento**.

```c
#include <stdio.h>

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;            // igual a: int *p = &a[0];

    printf("a[2] = %d\n", a[2]);     // 30
    printf("*(a+2) = %d\n", *(a+2)); // 30 (equivalente)

    // Recorrer con puntero:
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}
```

**Ojo:**  
- `sizeof(a)` (tamaño del arreglo) **no** es lo mismo que `sizeof(p)` (tamaño de un puntero).  
- Un puntero es **solo una dirección**; un arreglo es **bloque de datos**.

---

## 5) Cadenas (`char*`) y entrada segura

Una **cadena C** es un arreglo de `char` que termina con `'\0'`.

```c
#include <stdio.h>

int main(void) {
    char nombre[32];

    printf("Ingresá tu nombre: ");
    if (fgets(nombre, sizeof(nombre), stdin)) {
        // Quitar el '\n' final si aparece
        for (int i = 0; nombre[i] != '\0'; i++) {
            if (nombre[i] == '\n') { nombre[i] = '\0'; break; }
        }
        printf("Hola, %s!\n", nombre);
    }
    return 0;
}
```

> **No usar `gets`** (fue eliminada del estándar por insegura).  
> `scanf("%s", ...)` es riesgoso si la palabra es más larga que el espacio. Para principiantes, `fgets` es más seguro.

---

## 6) “Paso por referencia” (modificar variables en funciones)

En C todo se pasa **por valor**. Para que una función **modifique** algo del que la llama, le pasamos la **dirección** de esa variable (un **puntero**).

```c
#include <stdio.h>

void swap_int(int *a, int *b) {
    int tmp = *a;   // contenido al que apunta a
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 5, y = 9;
    swap_int(&x, &y);   // pasamos direcciones
    printf("x=%d, y=%d\n", x, y); // x=9, y=5
    return 0;
}
```

**¿Para qué sirve?**
- Para **devolver más de un dato** desde una función.
- Para **evitar copias grandes** (por ejemplo, de estructuras).
- Para **rellenar** algo que la función recibe (por ejemplo, leer un valor y guardarlo en una variable del main).

---

## 7) Puntero nulo y errores comunes

- `NULL` significa “**no apunta a ningún lado válido**”.
- Antes de usar `*p`, conviene chequear: `if (p != NULL) { ... }`

**Errores típicos y cómo evitarlos:**
1. **Usar punteros sin inicializar** (punteros “salvajes”): inicializá con `NULL`.  
2. **Dereferenciar `NULL`**: chequeá `p != NULL` antes de `*p`.  
3. **Salir del arreglo** (desbordes): siempre respetar los límites.  
4. **Retornar la dirección de una variable local**: **prohibido** (la variable muere al salir de la función).  
5. **Confundir `&` y `*`**: recordá, `&` → dirección, `*` → contenido.

---

## 8) Aritmética de punteros (solo lo necesario)

Mover un puntero en un arreglo avanza por **elementos**, no por bytes.

```c
#include <stdio.h>

int main(void) {
    int v[4] = {3, 6, 9, 12};
    int *p = v;        // &v[0]

    printf("%d\n", *p);     // 3
    p = p + 2;              // ahora apunta a v[2]
    printf("%d\n", *p);     // 9

    // Volver al inicio:
    p = v;
    for (int i = 0; i < 4; i++) {
        printf("v[%d] = %d\n", i, *(p + i));
    }
    return 0;
}
```

> **Regla de oro**: no te muevas fuera de los límites del arreglo.

---

## 9) Mini–proyectos guiados (para practicar en clase)

### 9.1) Contar mayores que un umbral (sin `string.h`)
**Descripción:** leer `n` enteros en un arreglo y contar cuántos son **mayores** a un valor `T`. Recorrelos con un puntero.

```c
#include <stdio.h>

int main(void) {
    int n;
    printf("Cuantos numeros vas a cargar (max 100)? ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;

    int v[100];
    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    int T;
    printf("Umbral T: ");
    scanf("%d", &T);

    int *p = v;   // apuntar al comienzo
    int cuenta = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > T) cuenta++;
    }

    printf("Hay %d numeros mayores que %d.\n", cuenta, T);
    return 0;
}
```

### 9.2) Invertir una cadena **in place** (sin `string.h`)
```c
#include <stdio.h>

void invertir(char *s) {
    int i = 0, j = 0;
    while (s[j] != '\0') j++;   // buscar fin
    if (j == 0) return;
    j--;                        // último índice válido
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}

int main(void) {
    char texto[64];

    printf("Ingresa texto (max 63 chars): ");
    if (fgets(texto, sizeof(texto), stdin)) {
        // quitar '\n'
        for (int i = 0; texto[i] != '\0'; i++) {
            if (texto[i] == '\n') { texto[i] = '\0'; break; }
        }
        invertir(texto);
        printf("Invertido: %s\n", texto);
    }
    return 0;
}
```

### 9.3) `swap` genérico para `int`
```c
#include <stdio.h>

void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int main(void) {
    int x = 7, y = 11;
    printf("Antes: x=%d y=%d\n", x, y);
    swap_int(&x, &y);
    printf("Despues: x=%d y=%d\n", x, y);
    return 0;
}
```

---

## 10) Plantilla base para tus ejercicios

```c
#include <stdio.h>

int main(void) {
    // 1) Declarar variables
    // 2) Leer datos
    // 3) Trabajar con punteros (& para direccion, * para contenido)
    // 4) Mostrar resultados
    return 0;
}
```

---

## 11) Actividades rápidas en clase (5–10 min cada una)

1. **Señalar con el dedo:** en un programa con `int x=1; int *p=&x;`, pediles que digan qué imprime `printf("%d", *p);` y qué pasa si hacen `*p=5;`.
2. **Detective de errores:** dar un snippet con `int *p; *p=10;` y que expliquen por qué está mal (puntero sin inicializar).
3. **Recorrer un arreglo:** cambiar un `for` basado en índices a uno que use puntero.
4. **Mini–quiz oral:** “¿Qué hace `&`? ¿Qué hace `*`? ¿Qué es `NULL`?”

---

## 12) Errores típicos (lista para pegar en el aula)

- Usar un puntero **sin** asignarle una dirección válida → inicializar con `NULL` y **luego** apuntar bien.
- Olvidar `&` en `scanf`: `scanf("%d", &x);` (¡no `x` a secas!).
- Salirse del arreglo al mover el puntero.
- Creer que `a` (arreglo) y `&a` son lo mismo: **no** lo son (tipos distintos).
- Intentar **modificar literales** de cadena: `char *s = "hola";` es **solo lectura** → usar `const char *s`.

---

## 13) Checklist de comprensión (auto–evaluación)

- [ ] Puedo explicar con mis palabras qué es un puntero.  
- [ ] Sé usar `&` para obtener direcciones.  
- [ ] Sé usar `*` para acceder y **modificar** el contenido apuntado.  
- [ ] Puedo pasar una variable “por referencia” a una función y que se modifique.  
- [ ] Puedo recorrer un arreglo usando un puntero sin salirme de rango.  
- [ ] Sé evitar los errores comunes de la sección 12.

---

## 14) Tarea para la casa (opcional)

1) Escribí una función `int contar_c(char *s, char c)` que cuente cuántas veces aparece el carácter `c` en la cadena `s`.  
2) Escribí una función `void normalizar_mayus(char *s)` que convierta letras minúsculas a mayúsculas **sin** usar `string.h` (recordá que `'a'..'z'` y `'A'..'Z'` tienen códigos contiguos en ASCII).  
3) Escribí `void ordenar_dos(int *a, int *b)` que deje en `*a` el menor y en `*b` el mayor (usando punteros).

> **Sugerencia**: probá cada función con varios casos (incluyendo cadena vacía `""` y valores iguales en `ordenar_dos`).

---

## 15) Apunte visual (ASCII)

```
Variable:      [  x  ]   <-- valor (por ej. 42)
Direccion:    0x7ffc...  <-- dónde vive x en memoria

Puntero p:    [0x7ffc...]   (guarda la direccion de x)
               |
               v
Contenido *p: 42   (mismo valor que x)
```

---

### Cierre

- Los punteros son **direcciones**.  
- `&` te da la dirección, `*` te da (y permite cambiar) el **contenido**.  
- Empezá por **casos sencillos**, mucha práctica y lectura de ejemplos.  
- ¡No te preocupes si al principio cuesta! Con punteros, **practicar** es la clave.
