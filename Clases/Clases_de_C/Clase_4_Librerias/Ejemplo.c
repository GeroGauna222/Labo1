#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main() {
    // Uso de time.h para inicializar la semilla aleatoria
    srand(time(NULL));
    
    // Uso de stdlib.h para generar números aleatorios
    double numero1 = (double)(rand() % 100) / 10.0;
    double numero2 = (double)(rand() % 100) / 10.0;
    
    printf("Números generados: %.1f y %.1f\n", numero1, numero2);
    
    // Uso de math.h para operaciones matemáticas
    printf("Suma: %.2f\n", numero1 + numero2);
    printf("Raíz cuadrada de %.1f: %.2f\n", numero1, sqrt(numero1));
    
    // Uso de string.h para manipulación de cadenas
    char resultado[50];
    sprintf(resultado, "El resultado es %.2f", numero1 + numero2);
    
    printf("Longitud de la cadena resultado: %lu\n", strlen(resultado));
    printf("Mensaje final: %s\n", resultado);
    
    return 0;
}