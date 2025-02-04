#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//
//int main() {
//
//    // Leer la cadena de entrada
//    printf("Ingrese una cadena de hasta 100 caracteres:\n");
//    fgets(cadena, 101, stdin);
//
//    // Eliminar el '\n' que fgets agrega al final
//    cadena[strcspn(cadena, "\n")] = '\0';
//
//    for (int i = 0; cadena[i] != '\0'; i++) {
//        // Verificar si es una letra minúscula
//        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
//            if (cadena[i] == 'z') {
//                cadena[i] = 'a';  // Cambiar 'z' por 'a'
//            } else {
//                cadena[i] += 1;  // Cambiar a la siguiente letra
//            }
//        }
//        // Verificar si es una letra mayúscula
//        else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
//            if (cadena[i] == 'Z') {
//                cadena[i] = 'A';  // Cambiar 'Z' por 'A'
//            } else {
//                cadena[i] += 1;  // Cambiar a la siguiente letra
//            }
//        }
//    }
//
//    return 0;
//}
//
//
//
