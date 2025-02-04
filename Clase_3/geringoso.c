#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//
//int main() {
//
//    /* Como arranco?
//    - Que quiero hacer?
//    El geringoso despues de cada vocal pone un "p+(esa vocal)"
//    quiero agregar eso
//    Entonces en un str quiero tener lo que ingrese la persona y lo ingresado quiero analizarlo y encontrarle DONDE poner estas silabas p+(vocal)
//    Como reviso lo ingresado letra por letra???? con un ciclo!!!
//    Ahora, tengo que tener una variable donde guardo lo ingresado por teclado, en otra lo que sería la palabra "editada", es decir en geringoso!
//    */
//
//    char input[100] = {0};  // inicializo en caracteres nulos
//    char geringoso[200] = {0}; // Espacio adicional para lo que agregue
//    int j = 0; // ahora veremos para que lo usamos
//
//    // Piso al usuario que ingrese una frase
//    printf("Ingresa una frase (en minúsculas): ");
//    fgets(input,sizeof(input),stdin);
//    input[strcspn(input,"\n")] = '\0';
//
//    // Convierto a geringoso
//    for (int i = 0; i < strlen(input); i++) {
//// strlen() encuentra el largo del string, es decir que devuelve un entero, este entero es la cantidad de caracteres hasta encontrar un '\0'
//        geringoso[j] = input[i]; // j la uso para moverme adentro de la variable geringoso, en un inicio vale 0
//        // le estoy dando a la letra numero j de geringoso el valor de la letra i de lo ingresado
//        j++;
//        // sumo uno a j, pues ya le di valor al anterior posicion de geringoso! (la primer iteración: j valia 0, geringoso[0]=input[0], ahora j vale 1, i todavia vale 0)
//        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
//            // ahora, si la letra en la que estoy parado en la frase ingresada es vocal...
//            geringoso[j] = 'p'; // en la letra j actual (ya le sume uno al j recien), pongo una p
//            j++; // ya le di valor al anterior j, le sumo para agregar la vocal en la posicion i del ingreso del usuario
//            geringoso[j] = input[i];
//            j++; // ya habiendo puesto la vocal despues de la p, me muevo a la proxima posicion para ingresar la proxima letra
//        }
//    }
//    geringoso[j] = '\0'; // Agrego el carácter nulo al final
//
//    // Mostrar la palabra en geringoso
//    printf("Vos escribiste \"%s\", que en geringoso es: %s\n", input, geringoso);
//
//    return 0;
//}
//
