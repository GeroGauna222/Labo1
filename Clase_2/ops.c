#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaración de variables
    int numero1 = 10, numero2 = 3, valorNoInicializado;
    bool valorVerdadero = true;
    bool valorFalso = false;
    float numeroDecimal1 = 2.2, numeroDecimal2 = 3.99;
    char caracter1 = 'a', caracter2 = 'g';

    // Mostrar el valor inicial de una variable no inicializada
    printf("El valor de la variable no inicializada es: %lf\n", valorNoInicializado);

    // Operaciones con enteros
    int sumaEnteros = numero1 + numero2;
    printf("La suma de %d y %d es: %d\n", numero1, numero2, sumaEnteros);
    sumaEnteros = numero1 + numeroDecimal2; // Suma de entero y flotante (implícita)
    printf("La suma de %d y %.2f es: %d\n", numero1, numeroDecimal2, sumaEnteros);

    // Operaciones con caracteres
    int sumaCaracteres = caracter1 + caracter2;
    printf("La suma de caracteres como enteros: %d(%c) + %d(%c) = %d\n", caracter1, caracter1, caracter2, caracter2, sumaCaracteres);

    // Operaciones con flotantes
    float sumaFlotantes = numero1 + numero2;
    printf("La suma de %d y %d como flotantes es: %.2f\n", numero1, numero2, sumaFlotantes);
    sumaFlotantes = numero1 + numeroDecimal2;
    printf("La suma de %d y %.2f es: %.2f\n", numero1, numeroDecimal2, sumaFlotantes);
    sumaFlotantes = numero1 / numero2; // División entera convertida a flotante
    printf("La división de %d entre %d como flotante es: %.2f\n", numero1, numero2, sumaFlotantes);
    sumaFlotantes = (float)(numero1 / numero2); // Conversión explícita después de la división
    printf("La división explícita de %d entre %d es: %.2f\n", numero1, numero2, sumaFlotantes);
    sumaFlotantes = (float)(numero1) / numero2; // Conversión explícita antes de la división
    printf("La división explícita de %d entre %d es: %.2f\n", numero1, numero2, sumaFlotantes);
    sumaFlotantes = numero1 / 3.0; // División con flotante
    printf("La división de %d entre 3.0 es: %.2f\n", numero1, sumaFlotantes);

    // Operación módulo (residuo de división)
    float residuoDivision = numero1 % numero2;
    printf("El residuo de la división de %d entre %d es: %.2f\n", numero1, numero2, residuoDivision);

    /* Determinar si un número es par o impar
       X / 2
       Según su resto:
       PAR: RESTO 0
       IMPAR: RESTO 1
    */
    printf("El valor inicial de numero1 es: %d\n", numero1);
    numero1++;
    printf("El valor de numero1 después de incrementar es: %d\n", numero1);
    int resultadoIncremento = numero1++;
    printf("El resultado del incremento es: %d\nEl valor actual de numero1 es: %d\n", resultadoIncremento, numero1);

    // Operadores lógicos (&&, ||)
    int resultadoLogico = valorVerdadero && valorFalso;
    printf("El resultado de %d AND %d es: %d\n", valorVerdadero, valorFalso, resultadoLogico);

    resultadoLogico = valorVerdadero && 120.10; // Evaluación de un flotante como booleano
    printf("El resultado de %d AND 120.10 es: %d\n", valorVerdadero, resultadoLogico);

    resultadoLogico = valorVerdadero || valorFalso;
    printf("El resultado de %d OR %d es: %d\n", valorVerdadero, valorFalso, resultadoLogico);

    resultadoLogico = 0 || valorFalso; // Evaluación de 0 como falso
    printf("El resultado de 0 OR %d es: %d\n", valorFalso, resultadoLogico);

    // Operador NOT (!)
    int resultadoNegacion = !12; // Evaluación de un número distinto de 0 como verdadero
    printf("El resultado de la negación de 12 es: %d\n", resultadoNegacion);

    // Comparación entre entero y carácter
    numero1 = 97;
    caracter1 = 'a';
    resultadoLogico = (numero1 == caracter1);
    printf("El resultado de comparar %d con '%c' es: %d\n", numero1, caracter1, resultadoLogico);

    return 0;
}
