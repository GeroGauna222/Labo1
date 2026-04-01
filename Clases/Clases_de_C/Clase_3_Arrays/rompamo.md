# Ejemplos de Errores: Buffers y Desbordamiento de Arrays

En C, la computadora confía ciegamente en el programador. Si le decís que escriba en una posición que no existe, lo va a intentar, provocando desastres en la memoria. A continuación, veremos los errores más comunes con ejemplos de código.

---

## 1. Buffer Overflow (Desbordamiento de Buffer) con `scanf`
Este es el error más clásico. Ocurre cuando pedimos datos al usuario pero no limitamos cuánto puede ingresar.

```c
#include <stdio.h>

void error_overflow() {
    char nombre[5]; // Espacio para 4 letras + '\0'
    
    printf("Ingrese su nombre (máximo 4 letras): ");
    // Si el usuario escribe "Geronimo", se necesitan 9 bytes.
    // scanf seguirá escribiendo en las casas de los vecinos.
    scanf("%s", nombre); 
    
    printf("Hola, %s\n", nombre);
}
```
**Consecuencia:** El programa puede seguir funcionando un rato, pero acabás de destruir datos que estaban "después" de `nombre` en la memoria. Si tenías otra variable ahí, su valor cambió mágicamente.

---

## 2. El Error "Off-by-One" (Fuera por uno)
Ocurre frecuentemente en bucles `for` cuando nos olvidamos que los índices arrancan en 0 y terminan en $n-1$.

```c
#include <stdio.h>

void error_indice() {
    int numeros[3] = {10, 20, 30};

    // Queremos imprimir los 3 números, pero el bucle llega hasta i=3
    for (int i = 0; i <= 3; i++) {
        // En la iteración i=3, estamos accediendo a numeros[3]
        // ¡Esa posición NO pertenece al array!
        printf("Posicion %d: %d\n", i, numeros[i]);
    }
}
```
**Consecuencia:** En `numeros[3]`, el programa va a leer lo que sea que haya en el siguiente bloque de 4 bytes de la RAM. Verás un número extraño ("basura") o el valor de otra variable.

---

## 3. Corrupción de Variables Adyacentes (El "Fantasma")
Este es el error más difícil de detectar porque el programa no falla, pero los resultados son erróneos.

```c
#include <stdio.h>
#include <string.h>

void corrupcion_silenciosa() {
    int llave_maestra = 0; // 0 significa "Cerrado"
    char password_ingresada[4]; // Espacio muy pequeño

    printf("Llave antes: %d\n", llave_maestra);

    // El usuario ingresa "12345"
    // "1234" entra en el array, el '5' y el '\0' 
    // se escriben en la memoria de 'llave_maestra'
    scanf("%s", password_ingresada);

    printf("Password: %s\n", password_ingresada);
    printf("Llave después: %d (¡Se cambió sola!)\n", llave_maestra);
}
```
**Explicación:** Como las variables se guardan pegadas en la memoria, al desbordar el array `password_ingresada`, los bytes sobrantes "chorrean" sobre la variable `llave_maestra`, cambiando su valor de 0 a otra cosa. **Así es como funcionan muchos hackeos reales.**

---

## 4. El String Infinito (Falta del `\0`)
Si manipulamos un array de caracteres y olvidamos (o pisamos) el carácter nulo, las funciones de C no saben dónde frenar.

```c
#include <stdio.h>

void string_infinito() {
    char saludo[4] = {'H', 'o', 'l', 'a'}; // Falta el '\0'

    // printf va a imprimir "Hola" y va a seguir leyendo 
    // toda la RAM de largo hasta encontrar un 0 por casualidad.
    printf("%s\n", saludo); 
}
```
**Consecuencia:** Verás caracteres extraños (caritas, símbolos, letras raras) después de tu palabra. Si la memoria está muy "limpia", quizás no notes el error, pero en una computadora con muchos programas abiertos, el desastre es total.

---

## 5. El "Segmentation Fault" (Acceso Prohibido)
Este ocurre cuando el desbordamiento es tan grande que intentás escribir en una zona de memoria que le pertenece al Sistema Operativo o a otro proceso.

```c
void crash_total() {
    int array[10];
    // Intentamos escribir en la posición un millón
    // La PC detecta que estamos "saltando la reja" y mata el proceso.
    array[1000000] = 99; 
}
```
**Consecuencia:** El programa se cierra inmediatamente con el mensaje: `Segmentation fault (core dumped)`.

---

### Resumen de Prevención:
1. **Usar `fgets`**: Siempre limita la cantidad de caracteres que entran.
2. **Chequear límites**: Antes de acceder a `array[i]`, asegurate de que `i < tamaño`.
3. **Inicializar**: No confíes en que el contenido de un array es 0 si no lo pusiste vos.
