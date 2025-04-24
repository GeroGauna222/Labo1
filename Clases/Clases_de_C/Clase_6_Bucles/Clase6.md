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

#include <stdio.h>

```c
int main() {
    int i = 1;
    do {
        printf("Iteración %d\n", i);
        i++;
    } while (i <= 5);
    return 0;
}
```

### `for`

El bucle `for` es una estructura que repite un bloque de código que al armarlo, le podes incluir un valor de inicialización, una condición y un incremento. 
- `inicializacion`: Acá podemos poner una variable con un cierto valor para entrar al loop, sería esa i que usamos en el while para controlar el loop, se ejecuta **una vez** antes de iniciar el bucle
- `condicion`: Acá bueno, va la condición que chequea en cada vuelta, se chequea **ANTES** de iniciar la vuelta
- `incremento`: **DESPUES** de cada vuelta del loop, se dará esta acción

### Sintáxis básica
```c
for (inicialización; condición; incremento) {
    // Código a ejecutar
}
```

Suele usarse con contadores por su estructura, sabiendo la cantidad de iteraciones que harían falta. Además notemos que es posible utilizarlo como si fuera un while. **No es necesario incluir una condicion y un incremento en un for si o si**.

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        printf("Iteración %d\n", i);
    }
    return 0;
}
```

| Tipo de bucle | ¿Cuándo usarlo? |
|--------------|--------------|
| for       | Cuando sabemos cuántas veces debe repetirse       |
| while       | Cuando no sabemos cuántas veces, pero hay una condición clara       |
| do while    | Cuando queremos al menos una ejecución, incluso si la condición es falsa al principio       |



## Bucles anidados
Podemos usar bucles dentro de otros bucles. Esto es útil para estructuras como matrices o para repetir tareas en varios niveles.

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("i=%d, j=%d\n", i, j);
        }
    }
    return 0;
}
```

## Palabras clave: `break` y `continue`
`break`: Salgo inmediatamente del bucle.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    printf("%d\n", i);
}
```
`continue`: Salto la iteración actual y sigo a la siguiente directo.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;
    printf("%d\n", i);
}
```
### Buenas prácticas con bucles

- Evitar bucles infinitos: Asegurate de que haya una condición de salida clara.

- Elegir el bucle correcto: Usá for para iteraciones contadas, while o do-while si depende de condiciones externas.

- Manejar bien las variables del bucle: Declaralas y actualizalas correctamente.

### Ejemplo práctico: Tabla de multiplicar
```c
#include <stdio.h>

int main() {
    int n;
    printf("Ingrese un número para ver su tabla de multiplicar: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
```


# Ejercicios prácticos

1. Suma de números del 1 al 100: Usá un bucle para calcular la suma.

2. Cuenta regresiva: Imprimí del 10 al 1 con un bucle while.

3. Menú interactivo: Mostrá un menú con varias opciones hasta que el usuario elija salir (usando do-while).

4. Adivina el número: Generá un número aleatorio entre 1 y 100 y pedile al usuario que adivine. Usá un while.
