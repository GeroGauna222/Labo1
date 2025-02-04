#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//
//int main() {
// ARRAYS: Un array es una estructura de datos que permite almacenar
//         múltiples elementos del mismo tipo en una única variable.
//         Los elementos se almacenan en posiciones contiguas en memoria.
//
// ARRAY UNIDIMENSIONAL / VECTOR
//
//número "n" de variables simples del mismo tipo que son denominadas
//los componentes o elementos del array. El número de componentes "n" es, entonces, la
//dimensión del array. De igual manera que en matemáticas, decimos que "A" es un
//vector de dimensión "n"
//
//
// tipo nombreArray[tamaño];















//int array_int[5];  // array que almacena 5 enteros, sin inicializar

//int array_int_2[] = {1,2,3,4,5};

//int array_int_3[5] = {1,2,3,4,5};

//Los arrays en C se indexan desde 0. El primer elemento está en la posición 0 y el último en tamaño-1.
//for(int i=0 ; i<5 ; i++) {
//    printf("array inicializado[%d] = %d \n", i, array_int_2[i]);
//    printf("array NO inicializado[%d] = %d \n", i, array_int[i]);
//    printf("\n");
//}

//int x = array_int_2[3];

// QUE ME PRINTEARÁ ESTO?
//printf("array inicializado[%d] = %d \n", 5, array_int_2[5]);

/*LIMITACIONES
Tamaño Fijo: Una vez definido, el tamaño de un array no se puede cambiar durante la ejecución del programa.
Sin verificación de límites: Acceder a un índice fuera del rango no genera un error en C, pero puede causar comportamientos inesperados.
*/



























// ARRAY DE TIPO CHAR ---> CADENA DE CARACTERES ---> PALABRAS/STRINGS

////Recordemos que '1' no es 1 !!!
//printf("%d\n", 1+2); // int: ocupa 32 bits (4 bytes)
//printf("%c\n", 1); // char: ocupa 8 bits (1 byte)
//printf("%c\n", 49);
//printf("%c\n", '1');



















//char str[] = "Hola mundo"; //después de la letra 'o', hay un '\0' que indica el fin de la cadena
//char strx[] = "Hola mundo\0";
//char strxx[11] = "Hola mundo";
//char str2[] = {'H','o','l','a',' ','m','u','n','d','o','\0'};
//char str3[] = {'H','o','l','a',' ','m','u','n','d','o',0};
//char str4[20] = "Hola mundo";
//
//printf("\nstr: %s", str);
//printf("\nstrx: %s", strx);
//printf("\nstrxx: %s", strxx);
//printf("\nstr2: %s", str2);
//printf("\nstr3: %s", str3);
//printf("\nstr4: %s", str4);
////
//for(int i=0 ; i<20 ; i++) {
//    printf("\nstr4[%d] (ultima posicion): %c", i, str4[i]);
//}

/* No me aparece el caracter '\0'...
El carácter '\0' en C es el carácter nulo, que se usa para marcar el final de una cadena de caracteres. Este carácter no es imprimible y tiene un
valor ASCII de 0. Por eso, cuando intentas imprimirlo con printf, no aparece en la salida, ya que printf trata '\0' como el final de la cadena y no
imprime nada más después de encontrarlo
*/

/* Por qué si printeo los caracteres que sobran estan todos vacios
son todos 0 ('\0')
*/

/* Por que aparecen cosas si me paso del límite del array? Que son?
Cuando accedes a índices fuera del rango de 0 a 19 (como str4[20], str4[21], etc.),
estás accediendo a posiciones de memoria que no están reservadas específicamente para str4, pero que están en la misma área de memoria.
Estas posiciones de memoria pueden contener restos de datos previos o datos que fueron colocados ahí por operaciones anteriores,
como la inicialización de otros arrays o variables.
*/

//printf("\nque pasara?: %s", array_int_3);











// ARRAY DE 2 DIMENSIONES
// ARRAY DE ARRAYS
// Definición de un vector de cadenas
//    char vec[3][10] = {"Hola","Mundo","Chau"};
//
//    for (int i = 0; i < 3; i++) {
//        printf("Cadena %d: %s\n", i, vec[i]);
//    }
//
//    for (int i = 0; i < 3; i++) {
//        printf("Cadena %d: %s %c\n", i, vec[i],vec[i][i]);
//
//        char respuesta[50];
//        printf("ingreso: ");
//        scanf("%s", &respuesta);
//        printf("\n%s\n", respuesta);
//    }



/* rand
de stdlib.h
¿Qué genera? numeros pseudoaleatorios entre 0 y RAND_MAX.
RAND_MAX es una constante definida en stdlib.h, y su valor puede variar dependiendo del sistema, pero generalmente es al menos 32767.
*/

//printf("\n RAND_MAX: %d\n", RAND_MAX);
//printf("\n%d", rand());
//printf("\n%d", rand());
//printf("\n%d", rand());

//int num = rand() % 10; // Genera un número entre 0 y 9
//printf("\nNúmero aleatorio entre 0 y 9: %d\n", num);
//num = (rand() % 100) + 1; // Genera un número entre 1 y 100
//printf("Número aleatorio entre 1 y 100: %d\n", num);










// para cambiar mi secuencia...
//srand(2); // 1 es mi semilla
//printf("\n%d", rand());
//printf("\n%d", rand());
//printf("\n%d", rand());
//printf("\n%d", time(NULL));
//
//srand(time(NULL)); // 1 es mi semilla
//printf("\n%d", rand());
//printf("\n%d", rand());
//printf("\n%d", rand());













// Siempre me sale la misma secuencia :( ¿¿¿¿como tengo un valor MAS aleatorio????
//int semilla;
//srand(semilla);

// obtener la hora actual en segundos desde el "Epoch", es el momento desde el cual se cuentan los segundos para los sistemas,
// en Linux es 00:00:00 UTC del 1 de enero de 1970
// en Windows es el 1 de enero de 1601 a las 00:00:00 UTC

//printf("time(NULL): %d", time(NULL)); // devuelve el tiempo actual y no almacenará el valor en ninguna dirección de memoria específica, por eso NULL o 0



//Armar un menú REPETITIVO de opciones para pedir en McDonalds.
//Que permita las siguientes opciones:
//
//1) Cajita Feliz :) (viene con un juguete que tambien se elige)
//2) Elegir un postre
//3) Elegir una combo
//4) Elegir algo del mcCafe
//5) Salir
//
//CADA VEZ se elige alguna, que se genere un numero
//de pedido que este entre 1 y 1000
//int op, choice;
//char toys[3][20]={"Marcelo tinelli","Moria Casan","Mirtha Legrand"};
//char burger[100];
//srand(time(NULL));
//do {
//    printf("\nBienvenido a McDonalds! ¿Que desea ordenar?\n1) Cajita Feliz :) (viene con un juguete que tambien se elige)\n2) Elegir un postre\n3) Elegir una combo\n4) Elegir algo del mcCafe\n5) Salir\nIngrese que desea ordenar: ");
//    scanf(" %d", &op);
//    switch(op){
//        case 1:
//            printf("Pedirá una cajita feliz! ¿Que juguete desea?: ");
//            for (int i=0 ; i<3 ; i++){
//                    printf("\n%d) %s", i+1, toys[i]);
//            }
//            printf("\n");
//            scanf(" %d", &choice);
//            while(choice<=0 || choice >= 4){
//                printf("ingreso una opcion no válida, intente nuevamente: ");
//                scanf(" %d", &choice);
//            }
//            printf("\nusted escogio el juguete de %s y su numero de pedido es %d\n", toys[choice-1], rand()%1000);
//            break;
//        case 2:
//            printf("Pedirá un postre!! no vayas a pedir un conito...");
//            printf("\nTu numero de pedido es %d", rand()%1000+1);
//            break;
//        case 3:
//            printf("Vas a pedir un combo, bien; ingrese por teclado si tiene alguna observación para su combo: ");
//            scanf(" %s", &burger);
//            printf("Perfecto, su ingreso fue el siguiente: \n%s\nSu numero de ticket es %d", burger, rand()%1000+1);
//            break;
//        case 4:
//            printf("Algo del McCafe.... que tibio\n");
//            printf("Toma tu numero de pedido...%d", rand()%1000+1);
//            break;
//        case 5:
//            printf("\nFin\n");
//            break;
//        default:
//            printf("Escogió un valor NO VALIDO");
//            break;
//    }
//} while(op!=5);
//
//printf("\nSalio del switch!!!!");
//
//return 0;
//}
