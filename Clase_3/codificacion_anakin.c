#include <stdio.h>

int main() {
    char cadena[100];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, 100, stdin); // Leer la cadena incluyendo espacios

    printf("Cadena codificada en ASCII: \n");

    for (int i = 0; cadena[i] != '\0'; i++) {
        if ((65 <= cadena[i] && cadena[i] <= 90) || (97 <= cadena[i] && cadena[i] <= 122)) { // Ignorar espacios y saltos de línea
            printf("%d ", cadena[i]);
        }
        else {
            printf("%c ", cadena[i]);
        }
    }

    printf("\n");

    return 0;
}

