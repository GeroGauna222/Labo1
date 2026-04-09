# Clase 5: Estructuras Condicionales en C

## ¿Qué son las estructuras condicionales?

Las estructuras condicionales son elementos fundamentales en la programación que permiten que un programa tome decisiones y ejecute diferentes bloques de código dependiendo de si ciertas condiciones se cumplen o no. Estas estructuras son la base de la lógica de programación y permiten crear programas dinámicos que responden de manera diferente según las circunstancias.

Por ejemplo:
- SI la nota es mayor o igual a 6, aprueba
- SI un número es par, mostrar un mensaje
- SI el usuario elige una opción del menú, ejecutar una acción distinta

Una estructura condicional permite que el programa haga una pregunta y, según la respuesta, ejecute un bloque de código u otro.

---

### Condiciones en C

Una condición es una expresión que puede dar como resultado:
- **verdadero**
- **falso**

En C, una condición se considera:
- **verdadera** si vale distinto de 0
- **falsa** si vale 0

### Operadores de comparación

Estos operadores se usan para armar condiciones:
- `==` igual a
- `!=` distinto de
- `>` mayor que
- `<` menor que
- `>=` mayor o igual que
- `<=` menor o igual que

```c
edad >= 18
nota < 6
numero == 10
opcion != 3
```

---

### Tipos de estructuras condicionales en C

- **if**: Evalúa una condición y ejecuta un bloque de código si es verdadera.
- **if-else**: Permite ejecutar un bloque de código si la condición es verdadera y otro bloque si es falsa.
- **if-else if-else**: Permite evaluar múltiples condiciones en secuencia.
- **switch-case**: Permite seleccionar uno de varios bloques de código para ejecutar según el valor de una expresión.

## La estructura if

La instrucción `if` es la estructura condicional más básica. Evalúa una expresión y, si esta se evalúa como verdadera (cualquier valor distinto de cero), ejecuta un bloque de código.

### Sintaxis básica

```c
if (condicion) {
    // Codigo a ejecutar si la condicion es verdadera
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

### Explicación

- Se evalúa `edad >= 18`
- Como la condición es verdadera, se ejecuta el `printf`

Si la condición fuera falsa, no se ejecutaría nada dentro del bloque.

---

## La estructura if-else

La estructura `if-else` permite ejecutar un bloque de código cuando la condición es verdadera y otro bloque diferente cuando la condición es falsa.

### Sintaxis básica

```c
if (condicion) {
    // Codigo a ejecutar si la condicion es verdadera
} else {
    // Codigo a ejecutar si la condicion es falsa
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

### Idea importante

Con `if-else`, **siempre se ejecuta uno de los dos bloques**.

---

## La estructura if-else if-else

Cuando necesitamos evaluar múltiples condiciones en secuencia, podemos usar la estructura `if-else if-else`. **Hay más de dos posibilidades**

### Sintaxis básica

```c
if (condicion1) {
    // Codigo a ejecutar si condicion1 es verdadera
} else if (condicion2) {
    // Codigo a ejecutar si condicion1 es falsa y condicion2 es verdadera
} else if (condicion3) {
    // Codigo a ejecutar si condicion1 y condicion2 son falsas y condicion3 es verdadera
} else {
    // Codigo a ejecutar si todas las condiciones anteriores son falsas
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

### Explicación

El programa va evaluando de arriba hacia abajo:

- si cumple la primera, entra ahí y termina;
- si no, prueba la segunda;
- si no, prueba la tercera;
- si no cumple ninguna, entra en `else`.

---

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
    
    // AND logico (ambas condiciones deben ser verdaderas)
    if (edad >= 18 && ingreso > 10000) {
        printf("Te damos el prestamo.\n");
    }
    
    // OR logico (al menos una condicion debe ser verdadera)
    if (edad > 65 || ingreso < 5000) {
        printf("Te damos asistencia.\n");
    }
    
    // NOT logico (invierte el valor)
    if (!(edad < 18)) {
        printf("No sos chiquito.\n");
    }
    
    return 0;
}
```

---

## El operador ternario

El operador condicional ternario (`? :`) es una forma abreviada de escribir declaraciones simples de if-else.

### Sintaxis básica

```c
resultado = (condicion) ? valor_si_verdadero : valor_si_falso;
```

### Ejemplo

```c
#include <stdio.h>

int main() {
    int edad = 20;
    char* mensaje;
    
    mensaje = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
    printf("%s\n", mensaje);
    
    // Tambien puede usarse directamente en una expresion
    printf("Estado: %s\n", (edad >= 18) ? "Adulto" : "Menor");
    
    return 0;
}
```

---

## Errores comunes en condicionales

### 1. Confundir `=` con `==`

```c
if (x = 5)   // MAL
```

Acá no se está comparando: se está asignando.

Lo correcto es:

```c
if (x == 5)  // BIEN
```

---

### 2. Olvidarse de las llaves

```c
if (edad >= 18)
    printf("Mayor\n");
    printf("Puede pasar\n");
```

Aunque parezca que ambos `printf` dependen del `if`, en realidad solo el primero depende.

Lo correcto:

```c
if (edad >= 18) {
    printf("Mayor\n");
    printf("Puede pasar\n");
}
```

---

### 3. Poner mal el orden de las condiciones

Ejemplo incorrecto:

```c
if (nota >= 4) {
    printf("Recupera\n");
} else if (nota >= 7) {
    printf("Aprobado\n");
}
```

Si la nota es 8, entra en `nota >= 4` y nunca llega al otro caso.

Lo correcto es ir de lo más restrictivo a lo más general:

```c
if (nota >= 7) {
    printf("Aprobado\n");
} else if (nota >= 4) {
    printf("Recupera\n");
}
```

---

## La estructura switch-case

La instrucción `switch` es una forma alternativa de expresar múltiples condiciones cuando estamos comparando una variable con valores específicos.

### Sintaxis básica

```c
switch (expresion) {
    case valor1:
        // Codigo a ejecutar si expresion == valor1
        break;
    case valor2:
        // Codigo a ejecutar si expresion == valor2
        break;
    // ... mas casos ...
    default:
        // Codigo a ejecutar si ningun caso coincide
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
            printf("Miercoles\n");
            break;
        case 4:
            printf("Jueves\n");
            break;
        case 5:
            printf("Viernes\n");
            break;
        case 6:
            printf("Sabado\n");
            break;
        case 7:
            printf("Domingo\n");
            break;
        default:
            printf("Dia invalido\n");
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
            printf("Opcion 1 seleccionada\n");
            break;
        case 2:
            printf("Opcion 2 seleccionada\n");
            // Sin break, continua ejecutando el caso 3
        case 3:
            printf("Procesando opciones 2 y 3\n");
            break;
        default:
            printf("Opcion desconocida\n");
    }
    
    return 0;
}
```

Este comportamiento, conocido como "fall-through", puede ser útil en ciertos escenarios pero también puede causar bugs difíciles de detectar si no es intencional.

## Estructuras anidadas

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
            printf("Calificas para un prestamo grande.\n");
        } else if (ingreso > 10000) {
            printf("Calificas para un prestamo mediano.\n");
        } else {
            printf("Calificas para un prestamo pequenio.\n");
        }
    } else {
        printf("Eres menor de edad.\n");
        printf("No calificas para ningun prestamo.\n");
    }
    
    return 0;
}
```

### Ejemplo de switch anidados

```c
#include <stdio.h>

int main() {
    int departamento = 1;
    int categoria = 2;
    
    switch (departamento) {
        case 1: // Departamento de ventas
            printf("Departamento de Ventas\n");
            switch (categoria) {
                case 1:
                    printf("Vendedor Junior\n");
                    break;
                case 2:
                    printf("Vendedor Senior\n");
                    break;
                default:
                    printf("Categoria desconocida\n");
            }
            break;
        case 2: // Departamento de TI
            printf("Departamento de TI\n");
            switch (categoria) {
                case 1:
                    printf("Programador Junior\n");
                    break;
                case 2:
                    printf("Programador Senior\n");
                    break;
                default:
                    printf("Categoria desconocida\n");
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
   if (condicion) {
       ejecutarAccion();
   }
   
   // No recomendado (pero valido)
   if (condicion)
       ejecutarAccion();
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
    
    printf("Ingrese la calificacion numerica (0-100): ");
    scanf("%f", &calificacion);
    
    // Validar rango
    if (calificacion < 0 || calificacion > 100) {
        printf("Error: La calificacion debe estar entre 0 y 100.\n");
    } else {
        // Determinar letra usando if-else if
        if (calificacion >= 90) {
            letra = 'A';
        } else if (calificacion >= 80) {
            letra = 'B';
        } else if (calificacion >= 70) {
            letra = 'C';
        } else if (calificacion >= 60) {
            letra = 'D';
        } else {
            letra = 'F';
        }
        
        // Mostrar resultados
        printf("Calificacion: %.1f\n", calificacion);
        printf("Letra: %c\n", letra);
        
        // Usar switch para mostrar mensaje segun la letra
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
                printf("Reprobado. Estudia mas para la proxima.\n");
                break;
        }
        
        // Mensaje adicional usando operador ternario
        printf("%s\n", (calificacion >= 60) ? "Has aprobado el curso." : "Has reprobado el curso.");
    }
    
    return 0;
}
```

---

## ¿Cuándo usar `if` y cuándo usar `switch`?

### Conviene usar `if` cuando:

- comparamos rangos:
  - `nota >= 6`
  - `edad < 18`
- usamos operadores lógicos:
  - `edad >= 18 && tieneDNI == 1`

### Conviene usar `switch` cuando:

- una variable puede valer distintos números concretos:
  - opción 1, 2, 3, 4
- queremos hacer menús

### Ejemplo típico

```c
switch (opcion) {
    case 1:
        printf("Alta\n");
        break;
    case 2:
        printf("Baja\n");
        break;
    case 3:
        printf("Modificar\n");
        break;
    default:
        printf("Opción incorrecta\n");
}
```

---

## Ejemplo práctico: menú simple con `switch`

```c
#include <stdio.h>

int main() {
    int opcion;
    float n1, n2, resultado;

    printf("MENÚ DE CALCULADORA\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    printf("Ingrese dos números: ");
    scanf("%f %f", &n1, &n2);

    switch (opcion) {
        case 1:
            resultado = n1 + n2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = n1 - n2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = n1 * n2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            if (n2 != 0) {
                resultado = n1 / n2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("No se puede dividir por cero.\n");
            }
            break;
        default:
            printf("Opción inválida.\n");
    }

    return 0;
}
```

---

## Ejercicios prácticos

1. **Calculadora simple**: Crea una calculadora que solicite dos números y una operación (suma, resta, multiplicación, división) utilizando `switch`.

2. **Clasificador de triángulos**: Recibe las longitudes de tres lados y determina si forman un triángulo equilátero, isósceles o escaleno.

3. **Validación de fecha**: Solicita día, mes y año, y verifica si forman una fecha válida (considerando años bisiestos).

4. **Simulador de cajero automático**: Crea un menú con opciones para consultar saldo, depositar, retirar y salir, utilizando `switch` y validando condiciones como saldo insuficiente.

```c
#include <stdio.h>

int main() {
    int opcion;
    float saldo, monto;
    saldo = 10000;
    do{
        printf("\n**************************\n");
        printf("           CAJERO\n");
        printf("**************************\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar\n");
        printf("3. Retirar\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Su saldo es %.2f\n", saldo);
                break;
            case 2:
                printf("Cuanto desea depositar?\n");
                scanf("%f", &monto);
                if(monto > 0){
                    saldo += monto;
                } else {
                    printf("ingresaste un monto de deposito invalido\n");
                }
                break;
            case 3:
                printf("Cuanto desea retirar?\n");
                scanf("%f", &monto);
                if(monto > 0 && monto <= saldo){
                    saldo -= monto;
                    printf("retiraste $%.2f\n", monto);
                } else {
                    printf("ingresaste un monto de retiro invalido\n");
                }
                break;
            case 4:
                printf("Gracias por operar con nosotros.");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}
```

## Conclusión

Las estructuras condicionales son herramientas esenciales en programación que permiten crear programas dinámicos capaces de tomar decisiones. En C, tenemos varias opciones como `if`, `if-else`, `if-else if-else` y `switch-case`, cada una con sus propios casos de uso óptimos. Dominar estas estructuras es fundamental para crear programas eficientes y lógicos.

Al elegir qué estructura condicional usar, considera:
- Para condiciones simples: `if` o el operador ternario
- Para bifurcaciones binarias: `if-else`
- Para múltiples condiciones relacionadas: `if-else if-else`
- Para múltiples valores de una sola variable: `switch-case`

Practicar con estos conceptos te dará la base para resolver problemas más complejos y escribir código más eficiente y fácil de mantener.
