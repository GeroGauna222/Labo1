# Ejercicios de Arrays y Strings (Sin uso de bucles)

## Ejercicio 1: Inicialización y acceso a arrays
Creá un programa que inicialice un array de 5 números enteros con los valores 10, 20, 30, 40 y 50. Imprimí el primer, tercer y último elemento del array.

```c
// Ayuda: Recordá que el primer elemento tiene índice 0
```

## Ejercicio 2: Manipulación básica de arrays
Declará un array de 3 números enteros y asignales valores iniciales. Luego:
1. Calculá la suma de los tres elementos
2. Calculá el promedio (media aritmética)
3. Imprimí los resultados

```c
// Ayuda: El promedio se calcula dividiendo la suma entre la cantidad de elementos
```

## Ejercicio 3: Inicialización parcial
Creá un array de 5 números enteros, pero inicializá solo los primeros 3 con valores (10, 20, 30). Imprimí los 5 elementos y verificá qué valor tienen las posiciones no inicializadas explícitamente.

```c
// Ayuda: int numeros[5] = {10, 20, 30};
```

## Ejercicio 4: Lectura de texto usando fgets y sscanf
Escribí un programa que le pida al usuario su nombre y edad:
1. Usá fgets() para leer la entrada
2. Usá sscanf() para extraer la edad como un entero
3. Imprimí un mensaje personalizado con el nombre y la edad

```c
// Ayuda: Seguí el patrón mostrado en la clase: fgets() para capturar la entrada y sscanf() para procesarla
```

## Ejercicio 5: Manejo de strings con string.h
Declará dos strings: "Hola" y "Mundo". Utilizando funciones de la biblioteca string.h:
1. Calculá la longitud de ambos strings
2. Creá un tercer string que sea la concatenación de los dos primeros
3. Compará si los dos strings originales son iguales y mostrá el resultado

```c
// Ayuda: Utilizá strlen(), strcat() y strcmp()
```

## Ejercicio 6: Manipulación de caracteres en strings
Declará un string con el valor "Programacion". Realizá las siguientes operaciones:
1. Cambiá la primera letra a minúscula
2. Reemplazá la última 'o' por 'O'
3. Imprimí el string resultante

```c
// Ayuda: Podés acceder a caracteres individuales como en un array: string[0] = 'p';
```

## Ejercicio 7: Validación de entrada
Escribí un programa que le pida al usuario ingresar un código postal (formato: 5 dígitos). El programa debe validar que la entrada sea correcta (solo 5 números) utilizando fgets() y sscanf().

```c
// Ayuda: Con sscanf() podés verificar cuántos elementos se leyeron correctamente
// Ejemplo: int leidos = sscanf(buffer, "%5d", &codigo);
```

## Ejercicio 8: Arrays de strings
Creá un array para almacenar 3 nombres de frutas. Inicializá cada elemento directamente. Luego:
1. Imprimí los 3 nombres de frutas
2. Calculá la longitud del nombre más largo
3. Compará el primer y segundo nombre alfabéticamente

```c
// Ayuda: Podés declararlo como char frutas[3][20] = {"Manzana", "Banana", "Uva"};
```

## Recomendaciones para los ejercicios:

1. Recordá incluir las bibliotecas necesarias:
   ```c
   #include <stdio.h>
   #include <string.h>
   ```

2. Para la entrada de texto, utilizá siempre la combinación recomendada:
   ```c
   char buffer[100];
   fgets(buffer, sizeof(buffer), stdin);
   // Eliminar el salto de línea si existe
   buffer[strcspn(buffer, "\n")] = '\0';
   ```

3. Para procesar la entrada, usá sscanf():
   ```c
   int edad;
   char nombre[50];
   char buffer[] = "22 Don Pepe";
   if (sscanf(buffer, "%d %49[^\n]s", &edad, nombre) == 2) {
       // Lectura correcta
   }
   ```

4. Recordá que los strings en C son arrays de caracteres terminados en '\0'