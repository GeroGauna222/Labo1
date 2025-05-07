# Clase: Introducción a Punteros y Vectores en C

## Objetivos de la clase

* Comprender qué es un puntero y cuál es su utilidad.
* Comprender la relación entre punteros y vectores.
* Aprender a declarar, inicializar y utilizar punteros.
* Realizar ejemplos prácticos para consolidar conceptos.

---

## 1. Variables y Memoria

En C, cuando declaramos una variable, el sistema reserva un espacio en la memoria RAM para almacenarla.

```c
int x = 10;
```

Esto significa:

* Se reserva espacio en la RAM para un `int`.
* El valor `10` se almacena en ese espacio.
* La variable `x` actúa como un nombre para ese espacio de memoria.

Podemos conocer la dirección de memoria usando `&`:

```c
printf("Dirección de x: %p\n", &x);
```

---

## 2. ¿Qué es un puntero?

Un puntero es una variable que **almacena la dirección de memoria** de otra variable.

```c
int x = 10;
int *p = &x;
```

* `*p` nos permite acceder al **valor** almacenado en la dirección que guarda `p`.

### Analogía:

Imaginemos una hoja de papel con una dirección escrita: esa es la variable puntero. Para saber qué hay en esa dirección (el verdadero dato), usamos el operador `*` (desreferenciación).

```c
printf("Valor de x usando p: %d\n", *p); // Imprime 10
```

---

## 3. Aplicaciones de los punteros

* Permiten compartir datos entre funciones sin copiarlos.
* Acceder a arreglos y vectores de forma eficiente.
* Trabajar con estructuras de datos dinámicas (listas, pilas, etc.).

---

## 4. Vectores en C

Un vector es un conjunto de variables del mismo tipo almacenadas en posiciones contiguas de memoria.

```c
int arr[3] = {10, 20, 30};
```

### Relación con punteros:

* El nombre del vector `arr` es un puntero al primer elemento.
* `arr[0]` es equivalente a `*arr`.
* `arr[1]` es equivalente a `*(arr + 1)`.

```c
printf("Segundo elemento: %d\n", arr[1]);       // 20
printf("Segundo elemento con puntero: %d\n", *(arr + 1)); // 20
```

---

## 5. Lógica para el uso de punteros

1. **Declarar** el puntero del tipo adecuado:

```c
int *p;
```

2. **Asignarle** la dirección de una variable existente:

```c
p = &x;
```

3. **Acceder** al valor apuntado:

```c
*p = 15;  // Cambia el valor de x a 15
```

### Ejemplo completo:

```c
#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;

    printf("Valor de x: %d\n", x);
    printf("Dirección de x: %p\n", &x);
    printf("Valor de p: %p\n", p);
    printf("Valor apuntado por p: %d\n", *p);

    *p = 20;
    printf("Nuevo valor de x: %d\n", x);

    return 0;
}
```

---

## 6. Ejercicios propuestos

1. Declarar una variable `int`, un puntero y cambiar su valor usando el puntero.
2. Crear un vector de 5 enteros e imprimir sus valores usando punteros.
3. Escribir una función que reciba un puntero a entero y lo multiplique por 2.

---

## 7. Conclusión

* Los punteros son fundamentales en C para trabajar con memoria y estructuras complejas.
* Comprender cómo se relacionan con los vectores es clave para optimizar el código.
* Practicar su uso ayuda a evitar errores comunes como la desreferenciación de punteros nulos o uso indebido de memoria.

---

## Recursos adicionales

* [Visualgo - Estructuras de datos visuales](https://visualgo.net)
* [Simulador de memoria y punteros en C](https://pythontutor.com/c.html)

---

**Fin de la clase.**
