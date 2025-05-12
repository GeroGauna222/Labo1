## Arrays Bidimensionales (Matrices)

## Objetivo

Entender cómo se declaran, acceden y manipulan arrays bidimensionales (también llamados **matrices**) en el lenguaje C.

---

## Introducción conceptual

Un array bidimensional es una estructura de datos que permite almacenar datos en forma de tabla: **filas y columnas**.

Por ejemplo, una tabla de 3 filas y 4 columnas puede representarse como:

```
1   2   3   4
5   6   7   8
9  10  11  12
```

Esto es equivalente a un `int matriz[3][4];` en C.

---

## Contenidos

### 1. Declaración y definición

```c
int matriz[3][4];  // 3 filas, 4 columnas
```

Podés también inicializarla directamente:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### 2. Acceso a elementos

```c
matriz[0][0] = 10; // primera fila, primera columna
matriz[1][2] = 7;  // segunda fila, tercera columna
```

Acuerdeseeee: en C los índices empiezan en 0.

### 3. Recorrer con bucles

```c
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
```

### 4. Manejo de cadenas en arrays 2D

También podemos usar arrays 2D para almacenar **palabras o cadenas de texto**. Por ejemplo:

```c
char palabras[3][20];
```

Esto declara un array con 3 palabras, de hasta 19 caracteres cada una (el 20 es para el `\0`).

Cargar por teclado:

```c
for (int i = 0; i < 3; i++) {
    printf("Ingrese una palabra: ");
    scanf("%19s", palabras[i]);
}
```

Mostrar las palabras:

```c
for (int i = 0; i < 3; i++) {
    printf("%s\n", palabras[i]);
}
```

---

## 🧪 Actividades prácticas

### Actividad 1: Cargar una matriz de 3x3 por teclado

```c
int matriz[3][3];

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Ingrese el valor para [%d][%d]: ", i, j);
        scanf("%d", &matriz[i][j]);
    }
}
```

### Actividad 2: Sumar todas las posiciones de una matriz 3x3

```c
int suma = 0;
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        suma += matriz[i][j];
    }
}
printf("La suma es: %d\n", suma);
```

### Actividad 3: Mostrar la diagonal principal

```c
for (int i = 0; i < 3; i++) {
    printf("%d ", matriz[i][i]);
}
```

### Actividad 4: Cargar y mostrar 5 nombres

```c
char nombres[5][30];

for (int i = 0; i < 5; i++) {
    printf("Ingrese un nombre: ");
    scanf("%29s", nombres[i]);
}

printf("\nNombres ingresados:\n");
for (int i = 0; i < 5; i++) {
    printf("%s\n", nombres[i]);
}
```

---

## Consejos

* Usá constantes o `#define` para indicar las dimensiones.
* Cuidado con los límites de los bucles.
* Siempre verificá que los datos ingresados se asignen correctamente.
* Para cadenas, recordá que siempre se reserva un carácter extra para el terminador `\0`.

---

## Ejercicio tipo integrador de esta clase

1. Crear una matriz 3x3.
2. Cargarla por teclado.
3. Mostrarla.
4. Calcular la suma de la fila 1.
5. Calcular la suma de la columna 2.
6. Mostrar la matriz transpuesta.
7. Cargar una lista de palabras y mostrarlas ordenadas alfabéticamente (opcional con `strcmp`).

---

## Resumiendo:

| Concepto       | Ejemplo                        |
| -------------- | ------------------------------ |
| Declaración    | `int m[3][3];`                 |
| Inicialización | `int m[2][2] = {{1,2},{3,4}};` |
| Acceso         | `m[1][0] = 5;`                 |
| Recorrido      | `for` anidados                 |
| Cadenas 2D     | `char nombres[5][20];`         |
| Acceso         | `m[1][0] = 5;`                 |
| Recorrido      | `for` anidados                 |
