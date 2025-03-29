# Clase 2: Tipos de Variables y Operadores en C

## Tipos de Variables en C

En el lenguaje de programación C, existen varios tipos de variables que se pueden utilizar para almacenar diferentes tipos de datos. Los tipos de variables más comunes son:

### Variables Globales y Locales

En C, las variables pueden ser declaradas como globales o locales dependiendo de su ámbito de visibilidad y tiempo de vida.

- **Variables Globales**: Son aquellas que se declaran fuera de cualquier función y son accesibles desde cualquier parte del programa. Su tiempo de vida es durante toda la ejecución del programa.
  ```c
  int global = 10; // Variable global

  void funcion() {
      printf("%d\n", global); // Acceso a la variable global
  }
  ```

- **Variables Locales**: Son aquellas que se declaran dentro de una función y solo son accesibles dentro de esa función. Su tiempo de vida es durante la ejecución de la función.
  ```c
  void funcion() {
      int local = 5; // Variable local
      printf("%d\n", local); // Acceso a la variable local
  }
  ```

### Tipos de Datos Primitivos

- **int**: Utilizado para almacenar números enteros. Se suele utilizar para contar elementos, controlar bucles y realizar operaciones aritméticas básicas.
  - Modificador de formato: `%d`
  ```c
  int numero = 10;
  ```

- **float**: Utilizado para almacenar números con punto decimal de precisión simple. Se utiliza comúnmente en cálculos matemáticos que requieren decimales, como operaciones financieras y científicas.
  - Modificador de formato: `%f`
  ```c
  float decimal = 3.14;
  ```

- **double**: Utilizado para almacenar números con punto decimal de doble precisión. Es ideal para cálculos que requieren una mayor precisión que la proporcionada por `float`.
  - Modificador de formato: `%lf`
  ```c
  double grande = 3.1415926535;
  ```

- **char**: Utilizado para almacenar un solo carácter. Se utiliza para manejar caracteres individuales y cadenas de texto.
  - Modificador de formato: `%c`
  ```c
  char letra = 'A';
  ```

- **bool**: Utilizado para almacenar valores booleanos (`true` o `false`). Es útil para condiciones lógicas y control de flujo en programas. Requiere incluir el encabezado `<stdbool.h>`.
  - Modificador de formato: `%d`
  ```c
  #include <stdbool.h>
  bool verdadero = true;
  bool falso = false;
  ```

### Modificadores de Tipos

- **short**: Reduce el tamaño de un entero a 2 bytes.
  ```c
  short int corto = 32767;
  ```

- **long**: Aumenta el tamaño de un entero a 8 bytes en sistemas de 64 bits.
  ```c
  long int largo = 2147483647;
  ```

- **unsigned**: Solo permite valores positivos, duplicando el rango positivo del tipo de dato base. Por ejemplo, un `unsigned int` ocupa 4 bytes y puede almacenar valores de 0 a 4294967295.
  ```c
  unsigned int positivo = 4294967295;
  ```

## Operadores en C

Los operadores son símbolos que le indican al compilador que debe realizar una operación matemática, lógica o de manipulación de datos. A continuación, se presentan algunos de los operadores más utilizados en C:

### Operadores Aritméticos

- **+**: Suma
  ```c
  int suma = 5 + 3; // Resultado: 8
  ```

- **-**: Resta
  ```c
  int resta = 5 - 3; // Resultado: 2
  ```

- **\***: Multiplicación
  ```c
  int multiplicacion = 5 * 3; // Resultado: 15
  ```

- **/**: División
  ```c
  int division = 10 / 2; // Resultado: 5
  ```

- **%**: Módulo (resto de la división)
  ```c
  int modulo = 10 % 3; // Resultado: 1
  ```

### Operadores de Incremento y Asignación Compuesta

- **`++variable`**: Incrementa el valor de la variable en 1 antes de usarla en una expresión.
  ```c
  int a = 5;
  int b = ++a; // a se incrementa a 6, luego b toma el valor de 6
  printf("a: %d, b: %d\n", a, b); // Salida: a: 6, b: 6
  ```

- **`variable++`**: Incrementa el valor de la variable en 1 después de usarla en una expresión.
  ```c
  int a = 5;
  int b = a++; // b toma el valor de 5, luego a se incrementa a 6
  printf("a: %d, b: %d\n", a, b); // Salida: a: 6, b: 5
  ```

- **`+=`**: Suma y asigna el resultado a la variable.
  ```c
  int a = 5;
  a += 3; // Equivalente a: a = a + 3
  printf("a: %d\n", a); // Salida: a: 8
  ```

- **`-=`**: Resta y asigna el resultado a la variable.
  ```c
  int a = 5;
  a -= 3; // Equivalente a: a = a - 3
  printf("a: %d\n", a); // Salida: a: 2
  ```

- **`*=`**: Multiplica y asigna el resultado a la variable.
  ```c
  int a = 5;
  a *= 3; // Equivalente a: a = a * 3
  printf("a: %d\n", a); // Salida: a: 15
  ```

- **`/=`**: Divide y asigna el resultado a la variable.
  ```c
  int a = 10;
  a /= 2; // Equivalente a: a = a / 2
  printf("a: %d\n", a); // Salida: a: 5
  ```

- **`%=`**: Calcula el módulo y asigna el resultado a la variable.
  ```c
  int a = 10;
  a %= 3; // Equivalente a: a = a % 3
  printf("a: %d\n", a); // Salida: a: 1
  ```

### Operadores Lógicos

- **&&**: AND lógico
  ```c
  int resultado = (5 > 3) && (8 > 5); // Resultado: 1 (true)
  ```

- **||**: OR lógico
  ```c
  int resultado = (5 > 3) || (8 < 5); // Resultado: 1 (true)
  ```

- **!**: NOT lógico
  ```c
  int resultado = !(5 > 3); // Resultado: 0 (false)
  ```

### Operadores Bit a Bit

- **&**: AND bit a bit
  ```c
  int resultado = 5 & 3; // Resultado: 1
  ```

- **|**: OR bit a bit
  ```c
  int resultado = 5 | 3; // Resultado: 7
  ```

- **^**: XOR bit a bit
  ```c
  int resultado = 5 ^ 3; // Resultado: 6
  ```

- **~**: NOT bit a bit
  ```c
  int resultado = ~5; // Resultado: -6
  ```

- **<<**: Desplazamiento a la izquierda
  ```c
  int resultado = 5 << 1; // Resultado: 10
  ```

- **>>**: Desplazamiento a la derecha
  ```c
  int resultado = 5 >> 1; // Resultado: 2
  ```

## Conclusión

En esta clase hemos revisado los tipos de variables más comunes en C y los operadores que podemos utilizar para manipular estos datos. Es fundamental comprender estos conceptos básicos para poder escribir programas eficientes y efectivos en C.
