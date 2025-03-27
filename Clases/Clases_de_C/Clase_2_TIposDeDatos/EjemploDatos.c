#include <stdio.h>
#include <stdbool.h>

int global = 10; // Variable global

void mostrarGlobal()
{
    printf("Variable global: %d\n", global);
}

void ejemploVariables()
{
    int local = 5; // Variable local
    printf("Variable local: %d\n", local);
}

void ejemploTiposDeDatos()
{
    // Tipos de datos primitivos
    int numero = -2147483648;
    float decimal = 3.1415926535;
    double grande = 3.1415926535;
    char letra = 'A';
    bool verdadero = true;

    printf("Ejemplo de tipos de datos:\n");
    printf("int: %d\n", 0x7FFFFFFF);
    printf("float: %.10f\n", decimal);
    printf("double: %.10lf\n", grande);
    printf("char: %c\n", letra);
    printf("bool: %d\n", verdadero);
    printf("int como hex: %x\n", numero);
    printf("int como octal: %o\n", numero);
}

void ejemploOperadores()
{
    // Operadores aritméticos
    int suma = 5 + 3;
    int resta = 5 - 3;
    int multiplicacion = 5 * 3;
    int division = 10 / 2;
    int modulo = 10 % 3;

    printf("\nEjemplo de operadores aritmeticos:\n");
    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Multiplicacion: %d\n", multiplicacion);
    printf("Division: %d\n", division);
    printf("Modulo: %d\n", modulo);

    // Operadores lógicos
    int resultadoAnd = (5 > 3) && (8 > 5);
    int resultadoOr = (5 > 3) || (8 < 5);
    int resultadoNot = !(5 > 3);

    printf("\nEjemplo de operadores lógicos:\n");
    printf("AND logico: %d\n", resultadoAnd);
    printf("OR logico: %d\n", resultadoOr);
    printf("NOT logico: %d\n", resultadoNot);

    // Operadores bit a bit
    int andBit = 5 & 3;
    int orBit = 5 | 3;
    int xorBit = 5 ^ 3;
    int notBit = ~5;
    int desplIzq = 5 << 1;
    int desplDer = 5 >> 1;

    printf("\nEjemplo de operadores bit a bit:\n");
    printf("AND bit a bit: %d\n", andBit);
    printf("OR bit a bit: %d\n", orBit);
    printf("XOR bit a bit: %d\n", xorBit);
    printf("NOT bit a bit: %d\n", notBit);
    printf("Desplazamiento a la izquierda: %d\n", desplIzq);
    printf("Desplazamiento a la derecha: %d\n", desplDer);
}

void ejemploSizeof()
{
    printf("\nEjemplo de sizeof:\n");
    printf("Tamanio de int: %lu bytes\n", sizeof(int));
    printf("Tamanio de float: %lu bytes\n", sizeof(float));
    printf("Tamanio de double: %lu bytes\n", sizeof(double));
    printf("Tamanio de char: %lu bytes\n", sizeof(char));

    int numero = 10;
    float decimal = 3.14;
    double grande = 3.1415926535;
    char letra = 'A';

    printf("Tamanio de int: %lu bytes\n", sizeof(numero));
    printf("Tamanio de float: %lu bytes\n", sizeof(decimal));
    printf("Tamanio de double: %lu bytes\n", sizeof(grande));
    printf("Tamanio de la variable letra: %lu bytes\n", sizeof(letra));
}

int main()
{
    printf("Demostración de conceptos de la Clase 2:\n");

    // Variables globales y locales
    mostrarGlobal();
    ejemploVariables();

    // Tipos de datos
    ejemploTiposDeDatos();

    // Operadores
    ejemploOperadores();

    // Uso de sizeof
    ejemploSizeof();

    return 0;
}
