#include <stdio.h>
//
//int sumar(int a, int b);
//void imprimirMensaje();
//float divition(float a, float b);
//
//int main() {
//    int x, y, op, r;
//    float d;
//    printf("ingrese x: ");
//    scanf("%d", &x);
//    printf("ingrese y: ");
//    scanf("%d", &y);
//    do {
//        printf("elegi una :\n 1) sumar\n 2) dividir\n 3) imprimir mensaje random\n 4) Salir");
//        scanf("%d", &op);
//        switch(op) {
//        case 1:
//            r = sumar(x, y);
//            printf("el resultado de la suma es: %d", r);
//            break;
//        case 2:
//            d = divition(x, y);
//            printf("el resultado de la div es: %f", d);
//            break;
//        case 3:
//            imprimirMensaje();
//            break;
//        case 4:
//            printf("Fin");
//            break;
//        default:
//            printf("ingreso un valor no valido");
//            break;
//        }
//
//    } while(op!=4);
//
//    return 0;
//}
//
//int sumar(int a, int b) {
//    int r = a + b;
//    printf("entre a la funcion sumar\n");
//    return r;
//}
//
//float divition(float a, float b) {
//    float r = a/b;
//    printf("entre a div\n");
//    return r;
//}
//
//void imprimirMensaje() {
//    printf("Hola, esta es una funci�n que no devuelve nada.\n");
//}

/*
Crear un programa en C que presente un men� con tres minijuegos diferentes.
El usuario seleccionar� uno de los juegos usando un switch, y cada juego
ser� implementado en una funci�n separada.

Descripci�n de los Minijuegos:
Adivina el n�mero: El programa genera un n�mero aleatorio entre 1 y 10,
y el usuario debe adivinarlo.
El programa da pistas si el intento es demasiado alto o bajo.
Piedra, papel o tijeras: El usuario juega contra la computadora en una
ronda de "Piedra, papel o tijeras".
Cuenta las vocales: El usuario ingresa una cadena, y el programa cuenta cu�ntas
vocales tiene, y dice si la cantidad es par o impar, y si es multiplo de 3.

Explicaci�n:
Cada minijuego est� implementado como una funci�n separada.
rand() se utiliza en los minijuegos para generar n�meros aleatorios.
El programa se ejecuta en un bucle do-while para permitir que el usuario
juegue repetidamente hasta que elija salir.

*/
