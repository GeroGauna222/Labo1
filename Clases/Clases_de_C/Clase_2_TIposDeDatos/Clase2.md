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

1. **int**: Utilizado para almacenar números enteros. Se suele utilizar para contar elementos, controlar bucles y realizar operaciones aritméticas básicas.
    - Modificador de formato: `%d`
    ```c
    int numero = 10;
    ```

2. **float**: Utilizado para almacenar números con punto decimal de precisión simple. Se utiliza comúnmente en cálculos matemáticos que requieren decimales, como operaciones financieras y científicas.
    - Modificador de formato: `%f`
    ```c
    float decimal = 3.14;
    ```

3. **double**: Utilizado para almacenar números con punto decimal de doble precisión. Es ideal para cálculos que requieren una mayor precisión que la proporcionada por `float`.
    - Modificador de formato: `%lf`
    ```c
    double grande = 3.1415926535;
    ```

4. **char**: Utilizado para almacenar un solo carácter. Se utiliza para manejar caracteres individuales y cadenas de texto.
    - Modificador de formato: `%c`
    ```c
    char letra = 'A';
    ```

5. **bool**: Utilizado para almacenar valores booleanos (`true` o `false`). Es útil para condiciones lógicas y control de flujo en programas. Requiere incluir el encabezado `<stdbool.h>`.
    - Modificador de formato: `%d`
    ```c
    #include <stdbool.h>
    bool verdadero = true;
    bool falso = false;
    ```
### Modificadores de Tipos

Los modificadores de tipos se utilizan para alterar el tamaño y/o el rango de los tipos de datos básicos. Algunos modificadores comunes son:

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

  #### Operadores de Incremento

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

  #### Operadores de Asignación Compuesta

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
  // Explicación:
  // 5 en binario:  0101
  // 3 en binario:  0011
  // AND bit a bit: 0001 (que es 1 en decimal)
  ```

- **|**: OR bit a bit
  ```c
  int resultado = 5 | 3; // Resultado: 7
  // Explicación:
  // 5 en binario:  0101
  // 3 en binario:  0011
  // OR bit a bit: 0111 (que es 7 en decimal)
  ```

- **^**: XOR bit a bit
  ```c
  int resultado = 5 ^ 3; // Resultado: 6
  // Explicación:
  // 5 en binario:  0101
  // 3 en binario:  0011
  // XOR bit a bit: 0110 (que es 6 en decimal)
  ```

- **~**: NOT bit a bit
  ```c
  int resultado = ~5; // Resultado: -6
  // Explicación:
  // 5 en binario:   00000000 00000000 00000000 00000101
  // NOT bit a bit:  11111111 11111111 11111111 11111010 (que es -6 en decimal, en complemento a dos)
  ```

- **<<**: Desplazamiento a la izquierda
  ```c
  int resultado = 5 << 1; // Resultado: 10
  // Explicación:
  // 5 en binario:       0101
  // Desplazamiento izq: 1010 (que es 10 en decimal)
  ```

- **>>**: Desplazamiento a la derecha
  ```c
  int resultado = 5 >> 1; // Resultado: 2
  // Explicación:
  // 5 en binario:       0101
  // Desplazamiento der: 0010 (que es 2 en decimal)
  ```
### Uso de `printf` para Mostrar Diferentes Tipos de Datos

La función `printf` en C se utiliza para imprimir datos en la consola. A continuación, se muestran ejemplos de cómo utilizar `printf` para mostrar diferentes tipos de datos:

- **int**: Para imprimir un número entero, se utiliza el especificador de formato `%d`.
    ```c
    int numero = 10;
    printf("El número entero es: %d\n", numero);
    ```

- **float**: Para imprimir un número de punto flotante de precisión simple, se utiliza el especificador de formato `%f`.
    ```c
    float decimal = 3.14;
    printf("El número decimal es: %f\n", decimal);
    ```

- **double**: Para imprimir un número de punto flotante de doble precisión, se utiliza el especificador de formato `%lf`.
    ```c
    double grande = 3.1415926535;
    printf("El número grande es: %lf\n", grande);
    ```

- **char**: Para imprimir un solo carácter, se utiliza el especificador de formato `%c`.
    ```c
    char letra = 'A';
    printf("El carácter es: %c\n", letra);
    ```

- **bool**: Para imprimir un valor booleano, se utiliza el especificador de formato `%d` (donde `true` se imprime como `1` y `false` como `0`).
    ```c
    #include <stdbool.h>
    bool verdadero = true;
    printf("El valor booleano es: %d\n", verdadero);
    ```

Estos ejemplos muestran cómo `printf` puede ser utilizado para mostrar diferentes tipos de datos en C, lo cual es esencial para la depuración y visualización de resultados en programas.

### Uso de `scanf` para Leer Datos desde la Entrada Estándar

La función `scanf` en C se utiliza para leer datos desde la entrada estándar (generalmente el teclado) y almacenarlos en variables. Es una herramienta esencial para interactuar con el usuario en programas.

#### Sintaxis Básica

```c
scanf("formato", &variable);
```

- **`formato`**: Especifica el tipo de dato que se espera leer, como `%d` para enteros, `%f` para números de punto flotante, `%c` para caracteres, etc.
- **`&variable`**: Es la dirección de memoria de la variable donde se almacenará el valor ingresado. El operador `&` (ampersand) es necesario para pasar la dirección de la variable.

#### Ejemplos de Uso

1. **Leer un número entero**:
  ```c
  int numero;
  printf("Ingrese un número entero: ");
  scanf("%d", &numero);
  printf("El número ingresado es: %d\n", numero);
  ```

2. **Leer un número de punto flotante**:
  ```c
  float decimal;
  printf("Ingrese un número decimal: ");
  scanf("%f", &decimal);
  printf("El número ingresado es: %f\n", decimal);
  ```

3. **Leer un carácter**:
  ```c
  char letra;
  printf("Ingrese un carácter: ");
  scanf(" %c", &letra); // El espacio antes de %c evita problemas con caracteres de nueva línea
  printf("El carácter ingresado es: %c\n", letra);
  ```

4. **Leer múltiples valores**:
  ```c
  int a, b;
  printf("Ingrese dos números enteros separados por un espacio: ");
  scanf("%d %d", &a, &b);
  printf("Los números ingresados son: %d y %d\n", a, b);
  ```

#### Consideraciones

- Es importante asegurarse de que el formato especificado en `scanf` coincida con el tipo de dato de la variable.
- `scanf` no valida automáticamente la entrada del usuario, por lo que se debe manejar cuidadosamente para evitar errores.
- Para leer cadenas de texto, se utiliza `%s`, pero se recomienda usar funciones más seguras como `fgets` para evitar desbordamientos de búfer.

El uso de `scanf` permite crear programas interactivos que pueden recibir datos del usuario y procesarlos de manera dinámica.
### Uso de `sizeof` para Determinar el Tamaño de Tipos de Datos

El operador `sizeof` en C se utiliza para determinar el tamaño en bytes de un tipo de dato o de una variable. A continuación, se muestran ejemplos de cómo utilizar `sizeof`:

- **Tamaño de un tipo de dato**: Para obtener el tamaño de un tipo de dato, se coloca el tipo de dato entre paréntesis después de `sizeof`.
    ```c
        printf("El tamaño de int es: %i bytes\n", sizeof(int));
        printf("El tamaño de float es: %i bytes\n", sizeof(float));
        printf("El tamaño de double es: %i bytes\n", sizeof(double));
        printf("El tamaño de char es: %i bytes\n", sizeof(char));
        ```

    - **Tamaño de una variable**: Para obtener el tamaño de una variable, se coloca el nombre de la variable entre paréntesis después de `sizeof`.
        ```c
        int numero = 10;
        float decimal = 3.14;
        double grande = 3.1415926535;
        char letra = 'A';

        printf("El tamaño de la variable numero es: %i bytes\n", sizeof(numero));
        printf("El tamaño de la variable decimal es: %i bytes\n", sizeof(decimal));
        printf("El tamaño de la variable grande es: %i bytes\n", sizeof(grande));
        printf("El tamaño de la variable letra es: %i bytes\n", sizeof(letra));
        ```
    ```

Estos ejemplos muestran cómo `sizeof` puede ser utilizado para determinar el tamaño de diferentes tipos de datos y variables en C, lo cual es útil para la gestión de memoria y la optimización de programas.
### Uso de `#define` en C

El preprocesador de C proporciona la directiva `#define`, que se utiliza para definir constantes simbólicas o macros. Esto permite asignar un nombre a un valor o a una expresión, facilitando la legibilidad y el mantenimiento del código.

#### Definición de Constantes

`#define` se utiliza comúnmente para definir constantes que no cambian durante la ejecución del programa.

```c
#define PI 3.14159
#define MAX 100

int main() {
  printf("El valor de PI es: %f\n", PI);
  printf("El valor máximo permitido es: %d\n", MAX);
  return 0;
}
```

#### Definición de Macros

También se puede usar `#define` para crear macros, que son fragmentos de código que se expanden en tiempo de preprocesamiento.

```c
#define CUADRADO(x) ((x) * (x))

int main() {
  int numero = 5;
  printf("El cuadrado de %d es: %d\n", numero, CUADRADO(numero));
  return 0;
}
```

#### Consideraciones

- No se debe terminar la línea de `#define` con un punto y coma (`;`).
- Las macros pueden hacer el código más compacto, pero un uso excesivo puede dificultar la depuración.
- Para constantes, se recomienda usar `const` en lugar de `#define` cuando sea posible, ya que `const` respeta el ámbito y el tipo de datos.

El uso de `#define` es una herramienta poderosa en C que permite simplificar el código y mejorar su legibilidad.
## Conclusión

En esta clase hemos revisado los tipos de variables más comunes en C y los operadores que podemos utilizar para manipular estos datos. Es fundamental comprender estos conceptos básicos para poder escribir programas eficientes y efectivos en C.
