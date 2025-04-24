# Clase 7: Funciones en C

## ¿Qué son las funciones?

Las funciones son bloques de código que realizan una tarea específica y pueden ser reutilizados en diferentes partes de un programa. Son fundamentales en la programación porque permiten dividir problemas complejos en componentes más pequeños y manejables, mejorando la legibilidad, mantenimiento y reutilización del código.

### Características principales de las funciones

- **Modularidad**: Permiten dividir un programa en módulos independientes
- **Reutilización**: El mismo código puede ser llamado múltiples veces
- **Abstracción**: Ocultan la complejidad interna, exponiendo solo lo necesario
- **Mantenimiento**: Facilitan la corrección de errores y actualizaciones

## Declaración y definición de funciones

En C, una función debe ser declarada antes de ser utilizada. Esto puede hacerse mediante un prototipo de función o directamente con la definición completa.

### Sintaxis básica

```c
tipo_retorno nombre_funcion(tipo_parametro1 parametro1, tipo_parametro2 parametro2, ...);
```

### Ejemplo de declaración y definición

```c
#include <stdio.h>

// Prototipo de función (declaración)
int sumar(int a, int b);

int main() {
    int resultado = sumar(5, 3);
    printf("La suma es: %d\n", resultado);
    
    return 0;
}

// Definición de la función
int sumar(int a, int b) {
    return a + b;
}
```

## Tipos de funciones en C

### Funciones con valor de retorno

Son funciones que devuelven un valor después de su ejecución.

```c
#include <stdio.h>

// Función que calcula el cuadrado de un número
int cuadrado(int numero) {
    return numero * numero;
}

int main() {
    int valor = 4;
    int resultado = cuadrado(valor);
    
    printf("El cuadrado de %d es %d\n", valor, resultado);
    
    return 0;
}
```

### Funciones void (sin valor de retorno)

Son funciones que realizan acciones pero no devuelven ningún valor.

```c
#include <stdio.h>

// Función que imprime un mensaje
void saludar(char* nombre) {
    printf("¡Hola, %s! Bienvenido al curso de C.\n", nombre);
    // No hay declaración de return
}

int main() {
    saludar("Juan");
    saludar("Maria");
    
    return 0;
}
```

## Parámetros de funciones

Los parámetros son valores que se pasan a una función cuando se llama.

### Paso por valor

El valor del argumento se copia al parámetro de la función. Los cambios realizados al parámetro dentro de la función no afectan la variable original.

```c
#include <stdio.h>

void intentarModificar(int numero) {
    numero = numero * 2;  // Esta modificacion solo afecta a la copia local
    printf("Dentro de la funcion: %d\n", numero);
}

int main() {
    int valor = 5;
    printf("Antes de llamar a la funcion: %d\n", valor);
    
    intentarModificar(valor);
    
    printf("Despues de llamar a la funcion: %d\n", valor);  // El valor no cambia
    
    return 0;
}
```

## Funciones con múltiples parámetros

Las funciones pueden recibir múltiples parámetros separados por comas.

```c
#include <stdio.h>

float calcularPromedio(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

int main() {
    float nota1 = 8.5;
    float nota2 = 7.0;
    float nota3 = 9.5;
    
    float promedio = calcularPromedio(nota1, nota2, nota3);
    
    printf("El promedio es: %.2f\n", promedio);
    
    return 0;
}
```

## Recursividad

La recursividad ocurre cuando una función se llama a sí misma. Es útil para resolver problemas que pueden descomponerse en casos más simples del mismo problema.

### Ejemplo: Factorial

```c
#include <stdio.h>

// Función recursiva para calcular el factorial
unsigned int factorial(unsigned int n) {
    // Caso base
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso recursivo
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    unsigned int numero = 5;
    printf("El factorial de %u es %u\n", numero, factorial(numero));
    
    return 0;
}
```

### Ejemplo: Fibonacci

```c
#include <stdio.h>

// Función recursiva para calcular el n-ésimo número de Fibonacci
int fibonacci(int n) {
    // Casos base
    if (n <= 1) {
        return n;
    }
    // Caso recursivo
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int numero = 10;
    printf("El %d-esimo numero de Fibonacci es: %d\n", numero, fibonacci(numero));
    
    return 0;
}
```

## Ámbito de variables en funciones

El ámbito (scope) determina dónde puede ser accedida una variable en el código.

### Variables locales

Son declaradas dentro de una función y solo existen mientras la función se está ejecutando.

```c
#include <stdio.h>

void funcionConVariableLocal() {
    int variableLocal = 10;  // Solo existe dentro de esta función
    printf("Valor de variable local: %d\n", variableLocal);
}

int main() {
    funcionConVariableLocal();
    // Error: 'variableLocal' no está definida aquí
    // printf("Valor: %d\n", variableLocal);
    
    return 0;
}
```

### Variables globales

Son declaradas fuera de cualquier función y pueden ser accedidas desde cualquier parte del programa.

```c
#include <stdio.h>

// Variable global
int contadorGlobal = 0;

void incrementarContador() {
    contadorGlobal++;
    printf("Valor actual del contador: %d\n", contadorGlobal);
}

int main() {
    printf("Valor inicial del contador: %d\n", contadorGlobal);
    
    incrementarContador();
    incrementarContador();
    
    printf("Valor final del contador: %d\n", contadorGlobal);
    
    return 0;
}
```

### Variables estáticas

Mantienen su valor entre llamadas a la función.

```c
#include <stdio.h>

void funcionConContadorEstatico() {
    // Se inicializa solo una vez, mantiene su valor entre llamadas
    static int contador = 0;
    contador++;
    printf("Esta funcion ha sido llamada %d veces\n", contador);
}

int main() {
    funcionConContadorEstatico();
    funcionConContadorEstatico();
    funcionConContadorEstatico();
    
    return 0;
}
```

## Buenas prácticas al trabajar con funciones

1. **Nombres descriptivos**: Usá nombres que describan claramente lo que hace la función.

2. **Funciones pequeñas y enfocadas**: Cada función debe realizar una tarea específica.

3. **Documentación**: Comentá el propósito de la función, sus parámetros y valor de retorno.
   ```c
   /**
    * Calcula el área de un círculo
    * @param radio El radio del círculo
    * @return El área del círculo
    */
   double areaCirculo(double radio) {
       return 3.14159 * radio * radio;
   }
   ```

4. **Validación de parámetros**: Verificá que los parámetros sean válidos antes de utilizarlos.

5. **Minimiza efectos secundarios**: Las funciones deberían ser predecibles y no modificar variables externas a menos que ese sea su propósito explícito.

6. **Limitá el uso de variables globales**: Preferí pasar parámetros y devolver resultados.

## Ejemplo práctico: Librería de operaciones matemáticas

A continuación, un ejemplo completo que ilustra el uso de funciones para crear una pequeña librería matemática:

```c
#include <stdio.h>
#include <math.h>

// Prototipos de funciones
double calcularAreaCirculo(double radio);
double calcularPerimetroCirculo(double radio);
double calcularAreaRectangulo(double base, double altura);
double calcularPerimetroRectangulo(double base, double altura);
void mostrarMenu();
void procesarOpcion(int opcion);

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        printf("Ingresa una opcion: ");
        scanf("%d", &opcion);
        
        procesarOpcion(opcion);
        
    } while (opcion != 5);
    
    return 0;
}

void mostrarMenu() {
    printf("\n==== CALCULADORA GEOMETRICA ====\n");
    printf("1. Calcular area de un circulo\n");
    printf("2. Calcular perimetro de un circulo\n");
    printf("3. Calcular area de un rectangulo\n");
    printf("4. Calcular perimetro de un rectangulo\n");
    printf("5. Salir\n");
}

void procesarOpcion(int opcion) {
    double radio, base, altura, resultado;
    
    switch (opcion) {
        case 1:
            printf("Ingresa el radio del circulo: ");
            scanf("%lf", &radio);
            resultado = calcularAreaCirculo(radio);
            printf("El area del circulo es: %.2lf\n", resultado);
            break;
            
        case 2:
            printf("Ingresa el radio del circulo: ");
            scanf("%lf", &radio);
            resultado = calcularPerimetroCirculo(radio);
            printf("El perimetro del circulo es: %.2lf\n", resultado);
            break;
            
        case 3:
            printf("Ingresa la base del rectangulo: ");
            scanf("%lf", &base);
            printf("Ingresa la altura del rectangulo: ");
            scanf("%lf", &altura);
            resultado = calcularAreaRectangulo(base, altura);
            printf("El area del rectangulo es: %.2lf\n", resultado);
            break;
            
        case 4:
            printf("Ingresa la base del rectangulo: ");
            scanf("%lf", &base);
            printf("Ingresa la altura del rectangulo: ");
            scanf("%lf", &altura);
            resultado = calcularPerimetroRectangulo(base, altura);
            printf("El perimetro del rectangulo es: %.2lf\n", resultado);
            break;
            
        case 5:
            printf("¡Hasta luego!\n");
            break;
            
        default:
            printf("Opcion no valida. Intenta de nuevo.\n");
    }
}

double calcularAreaCirculo(double radio) {
    return M_PI * radio * radio;
}

double calcularPerimetroCirculo(double radio) {
    return 2 * M_PI * radio;
}

double calcularAreaRectangulo(double base, double altura) {
    return base * altura;
}

double calcularPerimetroRectangulo(double base, double altura) {
    return 2 * (base + altura);
}
```

## Ejercicios prácticos

1. **Calculadora avanzada**: Creá funciones para realizar operaciones básicas (suma, resta, multiplicación, división) y avanzadas (potencia, raíz cuadrada, logaritmo).

2. **Conversor de unidades**: Implementá funciones para convertir entre diferentes unidades (temperatura, longitud, peso, etc.).

3. **Manipulación de cadenas**: Creá funciones para operaciones como invertir una cadena, contar vocales, verificar si es palíndromo, etc.

4. **Biblioteca de estadísticas**: Implementá funciones para calcular la media, mediana, moda, desviación estándar de un conjunto de números.

## Conclusión

Las funciones son bloques fundamentales en la programación en C que permiten crear código modular, reutilizable y fácil de mantener. La capacidad para dividir problemas complejos en partes más pequeñas mediante funciones es esencial para desarrollar programas de cualquier tamaño.

Dominar el uso de funciones te permitirá:
- Escribir código más organizado y legible
- Reutilizar código eficientemente
- Facilitar la depuración y el mantenimiento
- Colaborar mejor en proyectos con otros programadores

La práctica constante con funciones te ayudará a desarrollar un estilo de programación más efectivo y profesional, preparándote para abordar proyectos de mayor escala y complejidad.