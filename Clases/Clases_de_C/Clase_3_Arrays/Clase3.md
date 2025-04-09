# Arrays en Lenguaje C

### Antes de empezar: Buffer de entrada y salida
Antes de empezar esta explicación, vamos a abordar un tema importante para comprender lo que vamos a charlar hoy: `buffers`

Un **buffer** es una zona de la memoria usada para **almacenar datos temporalmente** mientras se están transfiriendo entre dos lugares. En C estamos constantemente usando sin saberlo dos buffers: `stdin` y `stdout`

- 📥 **Buffer de entrada (`stdin`)**: almacena lo que el usuario escribe **antes de que el programa lo procese**. veámoslo como la cajita en la que el usuario ingresa datos. Cuando uno escribe en el teclado y toca el enter, el buffer recibiría cada letra y el \n. Luego, la función que trabaja con una entrada lo trabaja o analiza de su propia forma.
> Cuando uso scanf(), estoy ingresando datos al stdin
- 📤 **Buffer de salida (`stdout`)**: guarda temporalmente lo que el programa quiere mostrar, **antes de imprimirlo en pantalla**.
> En C, cuando usamos funciones como `printf()`, lo que estamos haciendo en realidad es escribir en este buffer, que luego "suelta" su contenido en la pantalla.

---

## ¿Qué es un array?

Un **array** (o *arreglo*) es una **colección / conjunto de variables del mismo tipo** que se almacenan en **posiciones *contiguas* de memoria**. 
Cada elemento del array se puede acceder mediante un índice.

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

> Para un array de n datos, los valores guardados se recuperan con indices del 0 al n-1. Recordamos: las posiciones donde se guardan son *seguidas*

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
Tambien notemos, cada espacio de memoria es un byte, la dirección indicada es la del *primer byte del dato*

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

- Acceder fuera del rango puede provocar comportamientos inesperados o errores.

---
# Formemos palabras: el string

En C, un string no es un tipo de dato especial como en otros lenguajes (Python, Java). 
En realidad, es un array de caracteres (char) terminado en `\0`: el carácter nulo

`\0`: indica el final del string. Sin él, la maquina no puede saber dónde termina la frase. es el *ASCII 0*

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

  // 9. strcspn: Busca en un string la primera posición donde aparece algún carácter que esté en un segundo string.
  //Si no lo encuentra devuelve la última posición
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

✴ Esto se llama `desbordamiento de buffer (buffer overrun)` y puede llevar a problemas:

- Mensajes raros o basura printeada en pantalla.

- Fallos o bloqueos del programa (segmentation fault).

- Vulnerabilidades de seguridad (que alguien puede aprovechar).

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
Ya encontramos una particularidad, no?
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

fgets es una funcion que tiene la capacidad de trabajar directamente con el buffer de entrada (en realidad esta pensada para trabajar con archivos), se le ingresan los parametros: (donde guardo, tamaño que pienso guardar, de donde saco esa cantidad de información). Ademas, termina la lectura en el `\n`, y despues de la cantidad de caracteres leída se ocupa de poner un `\0`. A notar que le pase el tamaño de mi variable como parámetro, es porque fgets YA SABE que en esa cantidad de caracteres debería entrar el `\0`.

Ok, arregle un problema......... y cree otro je. fgets termina de leer cuando encuentra el `\n`, peeeero además se lo agarra, no lo deja en el buffer!! 
Un intento mas (la 3ra es la vencida dicen ¿?)

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

Bueno, logramos arreglar eso! cambie el `\n` por un `\0`... pero hay un problema todavía... si ingreso más de 20 caracteres? Bueno, ese sobrante quedaría en el buffer. Y si quiero usar scanf y tambien fgets en una misma funcion? Bueno, scanf deja el \n en el buffer, y fgets va a tomar eso de arranque, y no se va a poder ingresar más información.

```c
#include <stdio.h>

int main(void)
{
    char str[20];
    int age, c;

    puts("Ingrese su edad: ");
    scanf("%d", &age);
    printf("You entered %d.\n", a);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Hola %s! %d anitos, que grandote!!!\n", str, age);
}
```
Ahoooora, %d se supondría toma un numero entero, pero y si le ingreso 'abcd' que pasaría? Recaemos en lo que se llama *undefined behaviour*. 
Scanf no va a tomar esos valores ingresados y estos quedan tirados en mi buffer de entrada, si uso despues un fgets va a tomar esos valores ("abcd" y el enter '\n')


Asi nos encontramos con otro error... hagamos otra corrección:

```c
    char str[20];
    int age, c;

    puts("Ingrese su edad: ");
    scanf("%d", &age);
    while ((c = getchar()) != '\n' && c != EOF);
    puts("Ingrese su nombre Y apellido: ");
    fgets(str, sizeof(str), stdin);
    if (strcspn(str, "\n") == 19) {
        while ((c = getchar()) != '\n' && c != EOF);
        }
    else {
        str[strcspn(str, "\n")] = '\0';
        }
    printf("Hola %s! %d anitos, que grandote!!!\n", str, age);

    puts("Ingrese su nombre Y apellido: ");
    fgets(str, sizeof(str), stdin);
    if (strcspn(str, "\n") == 19) {
        while ((c = getchar()) != '\n' && c != EOF);
        }
    else {
        str[strcspn(str, "\n")] = '\0';
        }
    printf("Hola %s! %d anitos, que grandote!!!\n", str, age);
```

> Nos metemos a usar un bloque while, pero obviemos esto, simplemente está recorriendo el buffer consumiendo todo lo que quedó ahí hasta encontrar un `\n`.
el if chequea si el `\n` está en la lectura realizada el fgets

Buenoooo! Ahora sí, habiendo ya visto este ida y vuelta de código, vemos que en realidad tenemos un tema con todo esto. 
Ya abordamos en clases pasadas el uso de scanf para ingresar texto por teclado. Esto a la hora de trabajar con numeros, no trae problemas y su uso no esta mal, y si queremos mezclar datos podemos usar este quilombito chequeador que no trae problemas...  
pero como en todos lados existen las **prácticas recomendadas**. En C, mucha bibliografía recae en la siguiente combinación:

## `sscanf()` + `fgets()`

### ¿Qué hacen?

| Función    | ¿Para qué sirve?                                     |
|------------|------------------------------------------------------|
| `fgets()`  | Lee una línea entera como texto (incluye `\n`)       |
| `sscanf()` | Analiza ese texto como si fuera `scanf`, pero sobre un string |

### sscanf
> sscanf( de donde va a leer datos, indicador de formato del dato a leer, direccion de memoria donde gaurdar lo leído )

- `fgets()` evita desbordes: sabés exactamente **cuántos caracteres** va a leer.
- `sscanf()` te permite analizar el contenido **después de leerlo**, de forma controlada.
- Si el usuario escribe mal, podés **detectar el error** y manejarlo.

```c
#include <stdio.h>
#include <string.h>

void str_correct() {
    char buffer[100];
    int age;
    char n[20];
    char sn[20];

    printf("Ingrese edad: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &age) == 1) {
            printf("Edad: %d\n", age);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

    printf("Ingrese su nombre: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%19s", n) == 1) {
            printf("Nombre: %s\n", n);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

    printf("Ingrese su apellido: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%19[^\n]s", sn) == 1) {
            printf("Apellido: %s\n", sn);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

}
```

Listo, esta es la recomendación para el ingreso de datos. Vemos que ahora tenemos un buffer que es a donde va lo que ingrese el usuario, ahi lo guarda fgets(). Luego sscanf revisa ese nuevo "buffer" y de ahí lee la información en el formato que se desee, y además no lee el caracter Enter `\n`. De esta manera logramos manejar errores que podrían darse a la hora de leer datos. **Igualmente nos encontraremos con limitaciones**, pero que se arreglan con facilidad:
> `%s` lee solo una palabra, que se puede arreglar esto con %N[^\n]s (N siendo la cantidad de caracteres a leer como máximo y [^\n] indica que lea hasta el enter en vez de hasta el espacio)

Lo que vamos a hacer en este curso, va a ser darles libertad: si quieren usar scanf y fgets, haganlo así. Si quieren usar solo scanf con sus debidas correcciones, también. Si quieren usar lo recomendado, bienvenido sea; sólo sepan que lo que queremos es que se maneje correctamente la información.

POR AHORA, todo lo que es bucles while y condicionales if se usa como si fuera religión, ya vamos a entender como funcionan los bucles en la próxima clase. Mientras tanto, hacemos lo que un programador mejor hace: copy / paste de código.
