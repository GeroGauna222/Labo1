# Arrays en Lenguaje C

## ¿Qué es un array?

Un **array** (o *arreglo*) es una **colección / conjunto de variables del mismo tipo** que se almacenan en **posiciones *contiguas* de memoria**. 
Cada elemento del array se puede acceder mediante un índice.

---

## ¿Para qué usar arrays?

- Para **guardar múltiples datos relacionados** del mismo tipo.
- Para **procesar grandes volúmenes de datos** de forma más ordenada.
- Para **usar estructuras como listas, tablas, vectores**, etc.

---

## Sintaxis básica
```c
tipo_de_dato nombre_del_array[tamaño];
```
entonces...
```c
int ages[5];
```
esta es la declaración de un array de valores enteros, se reserva espacio de memoria para 5 enteros. 

Para un array de n datos, los valores guardados se recuperan con indices del 0 al n-1. Recordamos: las posiciones donde se guardan son *seguidas*

```c
#include <stdio.h>
#include <stdint.h>  // Necesario para uintptr_t
void show_array() {
  int ages[5] = {18, 19, 23, 34, 45};
  age_not_minor = ages[0];
  printf("Valor en la posición %d: %d // Dirección: %p\n", 0, ages[0], (unsigned long)(uintptr_t)&ages[0]);
  printf("Valor en la posición %d: %d // Dirección: %p\n", 1, ages[1], (unsigned long)(uintptr_t)&ages[1]);
  printf("Valor en la posición %d: %d // Dirección: %p\n", 4, ages[4], (unsigned long)(uintptr_t)&ages[4]);
}
```
para su entendimiento (no es info que deban saber, pero para que entiendan el código)...

`&`: Es para indicar que me estoy refiriendo no al valor de la variable, sino a la direccion de memoria donde se encuentra

`uintptr_t`: Se asegura de que podamos guardar la dirección de memoria como un número entero sin perder información.

`unsigned long` es para imprimirlo con %lu, que es el formato estándar para enteros largos sin signo.

### Entonces...
Vemos acá que las posiciones de memoria son esencialmente seguidas!!! 
Tambien notemos, cada cuadrado de memoria es un byte, la dirección indicada es la del *primer byte del dato*

---

## Inicialización

Clásico:
```c
int nums[4] = {1, 2, 3, 4};
char letters[7]; // sin inicializar, pero ta bom? (está bien en portugues) Todos los valores están indefinidos (son basura en memoria)
```

Inicialización automática:
```c
int zeros[5] = {0};  // Los 5 elementos serán 0 ( ={0, 0, 0, 0, 0} )
int datos[] = {10, 20, 30};  // El compilador deduce el tamaño (3)
int numeros[10] = {1, 2, 3};  // Solo los primeros 3 se inicializan, el resto queda como 0
```

Errores? 

- Tamaño incorrecto:
```c
int malArray[2] = {1, 2, 3};
```
- No pusiste el tamaño
```c
int datos[];
```
- El tamaño del array en ANSI C no es flexible, es decir, se declara el tamaño del array, y este se mantiene, *no puede cambiarse*.
Debe ser constante o conocido en tiempo de compilación (a menos que uses memoria dinámica).

- Acceder fuera del rango puede provocar comportamientos inesperados o errores fatales.

---
# Formemos palabras: el string

En C, un string no es un tipo de dato especial como en otros lenguajes (Python, Java). 
En realidad, es un array de caracteres (char) terminado en `\0`: el carácter nulo

`\0`: indica el final del string. Sin él, la maquina no se puede saber dónde termina. es el ASCII 0

---

## Declaración del string

### Correcto
```c
char str1[] = "Hola";
char str2[] = {'H', 'o', 'l', 'a', '\0'};
char str3[5] = "Hola";
char* str4 = "Hola mundo"; // usando punteros -> contenido de 'solo lectura'
```

### Incorrecta
```c
char str1[] = 'Hola';
char str2[4] = {'H', 'o', 'l', 'a'};
char str3[4] = "Hola";
char* str4 = "Hola mundo"; // usando punteros -> contenido de 'solo lectura'
str4[0] = 'h';
```

## #include <`string.h`>

```c
#include <stdio.h>
#include <string.h>  // Necesario para funciones de manejo de strings

void strings() {
    // 1. strcpy: copiar un string
    char origin[] = "Hello world";
    char destiny[50];
    strcpy(destiny, origin);
    printf("1. Copia con strcpy: %s\n", destiny);

    // 2. strlen: obtener longitud de un string (sin contar '\0')
    int length = strlen(origin);
    printf("2. Longitud con strlen: %d\n", length);

    // 3. strcat: concatenar strings
    char hi[100] = "Hi";
    strcat(hi, " ");
    strcat(hi, "Juan");
    printf("3. Concatenación con strcat: %s\n", hi);

    // 4. strcmp: comparar dos strings
    char palabra1[] = "perro";
    char palabra2[] = "gato";

    if (strcmp(palabra1, palabra2) == 0) {
        printf("4. Los strings son iguales\n");
    } else {
        printf("4. Los strings son diferentes\n");
    }

    // 5. strncpy: copiar N caracteres de un string
    char part[10];
    strncpy(part, origin, 4);  // Copia solo "Hell"
    parcial[4] = '\0';  // ¡Recordá agregar '\0' manualmente!
    printf("5. Copia parcial con strncpy: %s\n", part);

    // 6. strstr: buscar un substring dentro de otro
    char result[] = strstr(origin, "world");
    if (result != NULL) {
        printf("6. Substring encontrado: %s\n", result);
    }

    // 7. strchr: encontrar la primera aparición de un carácter
    int pos = strchr(origin, 'o');
    if (pos != NULL) {
        printf("7. Primer 'o' en origin: %d\n", pos);
    }

    // 8. memset: llenar un array con un carácter
    char buffer[10];
    memset(buffer, '-', 9);  // Llena los primeros 9 bytes con '-'
    buffer[9] = '\0';        // Agrega el final de string
    printf("8. Buffer con memset: %s\n", buffer);

    // 9. strcspn: Busca en un string la primera posición donde aparece algún carácter que esté en un segundo string. Si no lo encuentra devuelve la última posición
    char texto[] = "Hola mundo\n";
    int pos = strcspn(texto, "\n");
    printf("El salto de línea está en la posición: %d\n", pos);
}

```

## Profundizacion: `\0`

Cuando usás una función como printf, strlen, strcpy, etc., el compilador o la función:

- Empieza a leer la memoria desde el primer carácter del string.

- Sigue avanzando por la memoria leyendo caracteres.

- Se detiene al encontrar \0.

- Todo lo que viene después de \0 ya no se lee.

---

Si tu string no termina con \0, las funciones seguirán leyendo más allá del final del array, accediendo a zonas de memoria que no pertenecen al string.

✴ Esto se llama `desbordamiento de buffer (buffer overrun)` y puede causar:

- Mensajes raros o basura printeada en pantalla.

- Fallos o bloqueos del programa (segmentation fault).

- Vulnerabilidades de seguridad (que alguien puede explotar).

```c
#include <stdio.h>

void example_failing_str() {
    char nombre[4] = {'J', 'u', 'a', 'n'};

    printf("Sin \\0: %s\n", nombre);

    nombre[3] = '\0';
    printf("Con \\0: %s\n", nombre);
}

```

--

Otro posible error es la sobreescritura del \0

---
## Text Input

A la hora de ingresar texto es que la cosa se pone más complicada. 
Ya conocemos scanf(), entonces probemos...

```c
  char str[20];
  puts("Ingrese su nombre: ");
  scanf("%s", str);
  printf("Hola %s!\n", str);

  puts("Ingrese su nombre Y apellido: ");
  scanf("%s", str);
  printf("Hola %s!\n", str);
```
Ya encontramos una particularidad, no es así?
 Bueno, probemos ahora de la siguiente manera...

```c
  char str[20];
  puts("Ingrese su nombre: ");
  fgets(str,sizeof(str), stdin);
  printf("Hola %s!\n", str);

  puts("Ingrese su nombre Y apellido: ");
  fgets(str,sizeof(str), stdin);
  printf("Hola %s!\n", str);
```
Ok, arregle un problema......... y cree otro je.
Un intento mas (la 3ra es la vencida dicen)

```c
  char str[20];
  puts("Ingrese su nombre: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  printf("Hola %s!\n", str);

  puts("Ingrese su nombre Y apellido: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  printf("Hola %s!\n", str);
```

Bueno, logramos que funcione! Pero hay un problema todavía... si ingreso más de 20 caracteres?

Asi nos encontramos con otro error... hagamos otra corrección:

```c
  char str[20];
  int c;
  puts("Ingrese su nombre: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  while ((c = getchar()) != '\n' && c != EOF);
  printf("Hola %s!\n", str);

  puts("Ingrese su nombre Y apellido: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  while ((c = getchar()) != '\n' && c != EOF);
  printf("Hola %s!\n", str);
```

Ajá! ahora sí. Ahora, habiendo ya visto este ida y vuelta de código, expliquemos un poco qué fue lo que estuvimos viendo.



---
## Tipos de memoria


```c
char str[5] = "Hola";
str[4] = '!';  // Acaba de eliminar el '\0'
```
