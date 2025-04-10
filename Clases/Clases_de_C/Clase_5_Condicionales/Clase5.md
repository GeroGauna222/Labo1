# Clase 5: Estructuras Condicionales en C

## ¿Qué son las estructuras condicionales?

Las estructuras condicionales son elementos fundamentales en la programación que permiten que un programa tome decisiones y ejecute diferentes bloques de código dependiendo de si ciertas condiciones se cumplen o no. Estas estructuras son la base de la lógica de programación y permiten crear programas dinámicos que responden de manera diferente según las circunstancias.

### Tipos de estructuras condicionales en C

- **if**: Evalúa una condición y ejecuta un bloque de código si es verdadera.
- **if-else**: Permite ejecutar un bloque de código si la condición es verdadera y otro bloque si es falsa.
- **if-else if-else**: Permite evaluar múltiples condiciones en secuencia.
- **switch-case**: Permite seleccionar uno de varios bloques de código para ejecutar según el valor de una expresión.

## La estructura if

La instrucción `if` es la estructura condicional más básica. Evalúa una expresión y, si esta se evalúa como verdadera (cualquier valor distinto de cero), ejecuta un bloque de código.

### Sintaxis básica

```c
if (condición) {
    // Código a ejecutar si la condición es verdadera
}
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int edad = 18;
    
    if (edad >= 18) {
        printf("Que grande que sos\n");
    }
    
    return 0;
}
```

## La estructura if-else

La estructura `if-else` permite ejecutar un bloque de código cuando la condición es verdadera y otro bloque diferente cuando la condición es falsa.

### Sintaxis básica

```c
if (condición) {
    // Código a ejecutar si la condición es verdadera
} else {
    // Código a ejecutar si la condición es falsa
}
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int edad = 15;
    
    if (edad >= 18) {
        printf("Grandote.\n");
    } else {
        printf("Chiquito.\n");
    }
    
    return 0;
}
```

## La estructura if-else if-else

Cuando necesitamos evaluar múltiples condiciones en secuencia, podemos usar la estructura `if-else if-else`.

### Sintaxis básica

```c
if (condición1) {
    // Código a ejecutar si condición1 es verdadera
} else if (condición2) {
    // Código a ejecutar si condición1 es falsa y condición2 es verdadera
} else if (condición3) {
    // Código a ejecutar si condición1 y condición2 son falsas y condición3 es verdadera
} else {
    // Código a ejecutar si todas las condiciones anteriores son falsas
}
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int calificacion = 75;
    
    if (calificacion >= 90) {
        printf("Excelente\n");
    } else if (calificacion >= 80) {
        printf("Muy bien\n");
    } else if (calificacion >= 70) {
        printf("Bien\n");
    } else if (calificacion >= 60) {
        printf("Suficiente\n");
    } else {
        printf("Desaprobado\n");
    }
    
    return 0;
}
```

## Operadores lógicos en condiciones

Para crear condiciones más complejas, podemos utilizar operadores lógicos:

- **`&&`** (AND lógico): Verdadero si ambas condiciones son verdaderas.
- **`||`** (OR lógico): Verdadero si al menos una de las condiciones es verdadera.
- **`!`** (NOT lógico): Invierte el valor de la condición.

### Ejemplo

```c
#include <stdio.h>

int main() {
    int edad = 20;
    int ingreso = 15000;
    
    // AND lógico (ambas condiciones deben ser verdaderas)
    if (edad >= 18 && ingreso > 10000) {
        printf("Te damos el prestamo.\n");
    }
    
    // OR lógico (al menos una condición debe ser verdadera)
    if (edad > 65 || ingreso < 5000) {
        printf("Te damos asistencia.\n");
    }
    
    // NOT lógico (invierte el valor)
    if (!(edad < 18)) {
        printf("No sos chiquito.\n");
    }
    
    return 0;
}
```

## El operador ternario

El operador condicional ternario (`? :`) es una forma abreviada de escribir declaraciones simples de if-else.

### Sintaxis básica

```c
resultado = (condición) ? valor_si_verdadero : valor_si_falso;
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int edad = 20;
    char* mensaje;
    
    mensaje = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
    printf("%s\n", mensaje);
    
    // También puede usarse directamente en una expresión
    printf("Estado: %s\n", (edad >= 18) ? "Adulto" : "Menor");
    
    return 0;
}
```

## La estructura switch-case

La instrucción `switch` es una forma alternativa de expresar múltiples condiciones cuando estamos comparando una variable con valores específicos.

### Sintaxis básica

```c
switch (expresión) {
    case valor1:
        // Código a ejecutar si expresión == valor1
        break;
    case valor2:
        // Código a ejecutar si expresión == valor2
        break;
    // ... más casos ...
    default:
        // Código a ejecutar si ningún caso coincide
}
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int dia = 3;
    
    switch (dia) {
        case 1:
            printf("Lunes\n");
            break;
        case 2:
            printf("Martes\n");
            break;
        case 3:
            printf("Miércoles\n");
            break;
        case 4:
            printf("Jueves\n");
            break;
        case 5:
            printf("Viernes\n");
            break;
        case 6:
            printf("Sábado\n");
            break;
        case 7:
            printf("Domingo\n");
            break;
        default:
            printf("Día inválido\n");
    }
    
    return 0;
}
```

### Comportamiento de la instrucción break

La instrucción `break` es crucial en un `switch` ya que termina la ejecución del bloque. Si se omite, el flujo de control "cae" al siguiente caso:

```c
#include <stdio.h>

int main() {
    int opcion = 2;
    
    switch (opcion) {
        case 1:
            printf("Opción 1 seleccionada\n");
            break;
        case 2:
            printf("Opción 2 seleccionada\n");
            // Sin break, continúa ejecutando el caso 3
        case 3:
            printf("Procesando opciones 2 y 3\n");
            break;
        default:
            printf("Opción desconocida\n");
    }
    
    return 0;
}
```

Este comportamiento, conocido como "fall-through", puede ser útil en ciertos escenarios pero también puede causar bugs difíciles de detectar si no es intencional.

## Estructuras condicionales anidadas

Las estructuras condicionales pueden anidarse unas dentro de otras para crear lógicas más complejas.

### Ejemplo de if anidados

```c
#include <stdio.h>

int main() {
    int edad = 25;
    int ingreso = 30000;
    
    if (edad >= 18) {
        printf("Eres mayor de edad.\n");
        
        if (ingreso > 20000) {
            printf("Calificas para un préstamo grande.\n");
        } else if (ingreso > 10000) {
            printf("Calificas para un préstamo mediano.\n");
        } else {
            printf("Calificas para un préstamo pequeño.\n");
        }
    } else {
        printf("Eres menor de edad.\n");
        printf("No calificas para ningún préstamo.\n");
    }
    
    return 0;
}
```

### Ejemplo de switch anidados

```c
#include <stdio.h>

int main() {
    int departamento = 1;
    int categoría = 2;
    
    switch (departamento) {
        case 1: // Departamento de ventas
            printf("Departamento de Ventas\n");
            switch (categoría) {
                case 1:
                    printf("Vendedor Junior\n");
                    break;
                case 2:
                    printf("Vendedor Senior\n");
                    break;
                default:
                    printf("Categoría desconocida\n");
            }
            break;
        case 2: // Departamento de TI
            printf("Departamento de TI\n");
            switch (categoría) {
                case 1:
                    printf("Programador Junior\n");
                    break;
                case 2:
                    printf("Programador Senior\n");
                    break;
                default:
                    printf("Categoría desconocida\n");
            }
            break;
        default:
            printf("Departamento desconocido\n");
    }
    
    return 0;
}
```

## Buenas prácticas con estructuras condicionales

1. **Claridad**: Usar llaves `{ }` incluso para bloques de una sola línea para mejorar la legibilidad.
   ```c
   // Recomendado
   if (condición) {
       ejecutarAcción();
   }
   
   // No recomendado (pero válido)
   if (condición)
       ejecutarAcción();
   ```

2. **Evitar anidaciones excesivas**: Las estructuras muy anidadas pueden dificultar la lectura del código.

3. **Priorizar condiciones**: En estructuras `if-else if`, ordenar las condiciones desde la más específica a la más general.

4. **Usar switch para múltiples valores de una variable**: Cuando se compara una variable con muchos valores posibles, `switch` suele ser más legible que múltiples `if-else if`.

5. **No olvidar el break en switch**: A menos que el "fall-through" sea intencional, siempre incluir `break` al final de cada caso.

## Ejemplo práctico: Sistema de calificaciones

A continuación, un ejemplo completo que ilustra el uso de varias estructuras condicionales:

```c
#include <stdio.h>

int main() {
    float calificacion;
    char letra;
    
    printf("Ingrese la calificación numérica (0-100): ");
    scanf("%f", &calificacion);
    
    // Validar rango
    if (calificacion < 0 || calificacion > 100) {
        printf("Error: La calificación debe estar entre 0 y 100.\n");
    } else {
        // Determinar letra usando if-else if
        if (calificacion >= 90) {
            letra = 'A';
        } else if (calificación >= 80) {
            letra = 'B';
        } else if (calificación >= 70) {
            letra = 'C';
        } else if (calificación >= 60) {
            letra = 'D';
        } else {
            letra = 'F';
        }
        
        // Mostrar resultados
        printf("Calificación: %.1f\n", calificacion);
        printf("Letra: %c\n", letra);
        
        // Usar switch para mostrar mensaje según la letra
        switch (letra) {
            case 'A':
                printf("¡Excelente trabajo!\n");
                break;
            case 'B':
                printf("Buen trabajo.\n");
                break;
            case 'C':
                printf("Trabajo aceptable.\n");
                break;
            case 'D':
                printf("Necesitas mejorar.\n");
                break;
            case 'F':
                printf("Reprobado. Estudia más para la próxima.\n");
                break;
        }
        
        // Mensaje adicional usando operador ternario
        printf("%s\n", (calificacion >= 60) ? "Has aprobado el curso." : "Has reprobado el curso.");
    }
    
    return 0;
}
```

## Ejercicios prácticos

1. **Calculadora simple**: Crea una calculadora que solicite dos números y una operación (suma, resta, multiplicación, división) utilizando `switch`.

2. **Clasificador de triángulos**: Recibe las longitudes de tres lados y determina si forman un triángulo equilátero, isósceles o escaleno.

3. **Validación de fecha**: Solicita día, mes y año, y verifica si forman una fecha válida (considerando años bisiestos).

4. **Simulador de cajero automático**: Crea un menú con opciones para consultar saldo, depositar, retirar y salir, utilizando `switch` y validando condiciones como saldo insuficiente.

## Conclusión

Las estructuras condicionales son herramientas esenciales en programación que permiten crear programas dinámicos capaces de tomar decisiones. En C, tenemos varias opciones como `if`, `if-else`, `if-else if-else` y `switch-case`, cada una con sus propios casos de uso óptimos. Dominar estas estructuras es fundamental para crear programas eficientes y lógicos.

Al elegir qué estructura condicional usar, considera:
- Para condiciones simples: `if` o el operador ternario
- Para bifurcaciones binarias: `if-else`
- Para múltiples condiciones relacionadas: `if-else if-else`
- Para múltiples valores de una sola variable: `switch-case`

Practicar con estos conceptos te dará la base para resolver problemas más complejos y escribir código más eficiente y fácil de mantener.
