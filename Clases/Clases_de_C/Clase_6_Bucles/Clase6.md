# Clase 6: Bucles en C

## ¿Qué es un bucle?

Un **bucle (loop)** permite ejecutar un bloque de código varias veces, ya sea mientras se cumpla una condición (bucles condicionales) o durante un número determinado de veces (bucles contados). 
¿Para que me sirve? para automatizar tareas repetitivas sin necesidad de escribir el mismo código una y otra vez, como puede ser por ejemplo **recorrer un array**.

---

## Tipos de bucles en C

Tenemos 3 tipos de bucles en C:

- `for`: Ideal cuando conocemos cuántas veces queremos repetir algo.

- `while`: Repite un bloque mientras una condición sea verdadera.

- `do-while`: Similar al while, pero garantiza al menos una ejecución del bloque.

### `while`

Se ejecuta **mientras** la condición sea verdadera. Siempre y cuando se cumpla lo que uno pone como condición al principio, se va a ejecutar lo que se encuentra dentro de la estructura.

### Sintáxis básica
```c
while (condición) {
    // Código a ejecutarse
}
```
Recordemos que cuando leo el código, estoy yendo *de arriba hacia abajo*. Cuando la maquina llega a la línea donde lee "*while( condicion )...*" en ese punto **ya estará corroborando** si tal condición se cumple o no.

De no cumplirse, nunca entra al bucle y el codigo dentro de la estructura **nunca llega a correrse**. Peeeero recordemos que existe el case contrario, es decir, que se cumpla **siempre**, y que uno quede atrapado en un **infinit loop**

```c
#include <stdio.h>

int main() {
    int i = 0;
    while (i < 5) {
        printf("i vale: %d\n", i);
        i++;
        // i = 1 // que generaría esto?
    }
    return 0;
}
```
### `do-while`

Podemos pensarlo exactamente igual que como un while, pero con una sola diferencia, que es vital: **se ejecuta al menos una vez**, y luego se repite mientras la condición sea verdadera.

### Sintáxis básica
```c
do {
    // Código a ejecutar
} while (condición);
```

Notamos que la diferencia con el while es que la condición la lee una vez que ya ejecuta una vez el código del bloque *do {...*
