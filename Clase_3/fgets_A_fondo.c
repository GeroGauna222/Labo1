#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main() {
//    /* HOY
//    - fflush y bucle getchar
//    - atoi
//    - atof
//    - sscanf
//    - strcat, strcmp, strcpy
//    - Modelo parcial
//    */
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//    char buffer[10];
//    int c;
//
//    // Uso de atoi
//    printf("Ejemplo de atoi:\n");
//    printf("Ingresa un número entero: ");
//    fgets(buffer, 10, stdin);
//    buffer[strcspn(buffer,"\n")] = '\0';
//    while ((c = getchar()) != '\n' && c != EOF);
//
//    /* QUE ES ESTE BUCLE?????
//    Si lees solo "Hola" (por ejemplo, con scanf("%4s", buffer);), o con fgets ingresas mas valores que los esperados por la funciona, el buffer todavía contiene algo, como por ejemplo " Mundo\n".
//    */
//
//    int numeroEntero = atoi(buffer);  // Convierte la cadena a un número entero
//    printf("Número entero convertido: %d\n\n", numeroEntero);
//
//    // Uso de atof
//    printf("Ejemplo de atof:\n");
//    printf("Ingresa un número decimal: ");
//    fgets(buffer, 10, stdin);
//    buffer[strcspn(buffer,"\n")] = '\0';
//    while ((c = getchar()) != '\n' && c != EOF);
//    float numeroDecimal = atof(buffer);  // Convierte la cadena a un float
//    printf("Número decimal convertido: %.2f\n\n", numeroDecimal);
//
//    // Uso de sscanf
//    char nombre[20];
//    int edad;
//    printf("Ingresa tu nombre y edad (ejemplo: Juan 30): ");
//    fgets(buffer, 50, stdin);
//    buffer[strcspn(buffer,"\n")] = '\0';
//    while ((c = getchar()) != '\n' && c != EOF);
//    printf("Nombre y edad %s\n\n", buffer);
//
//    printf("Ingresa tu nombre y edad (ejemplo: Juan 30): ");
//    sscanf(stdin, "%s %d", nombre, &edad);
//    while ((c = getchar()) != '\n' && c != EOF);
//    printf("Nombre: %s, Edad: %d\n\n", nombre, edad);
//
//
//
//
//
//    // Uso de strcat y strcpy
//    char saludo[50] = {0}, copia[] = "Hola, ";
//    strcpy(saludo, copia);  // Copia "Hola, " en la variable saludo
//    strcat(saludo, nombre);    // Concatenamos el nombre a la variable
//    printf("%s\n\n", saludo);
//
//
//
//
//
//
//
//
//
//
//    // Uso de strcmp
//    printf("Ingresa una palabra para comparar con 'Hola': ");
//    fgets(buffer, 50, stdin);
//    if (strcmp(buffer, "Hola") == 0) {
//// Compara la cadena ingresada con "Hola", si es igual me devuelve 0, si la primer letra diferente (en ASCII) es mayor la de la primer palabra, devuelve mayor a 0
//        printf("Las cadenas son iguales.\n\n");
//    } else {
//        printf("Las cadenas son diferentes.\n\n");
//    }











//
//
//
//     Modelo de parcial!
//    int end, ab, quali, sum_A, sum_B, count_A, count_B, count_tot = 0, max_ano;
//    float prom_A, prom_B, max_prom = 0;
//    char max_ab;
//
//    for(int i=0 ; i < 7 ; i++) {
//
//            printf("AÑO nro %d\n---------------------------", i+1);
//
//            sum_A = 0;
//            sum_B = 0;
//            count_A = 0;
//            count_B = 0;
//            prom_A = 0;
//            prom_B = 0;
//
//            do {
//                printf("Ingrese division\n1) A\n2) B");
//                scanf("%d", &ab);
//                while(ab != 1 && ab != 2) {
//                    printf("Ingreso un valor no valido");
//                    printf("Ingrese division\n1) A\n2) B");
//                    scanf("%d", &ab);
//                }
//
//                printf("Ingrese la nota del alumno: ");
//                scanf("%d", &quali);
//                while(quali < 0 || quali > 10) {
//                    printf("Ingreso un valor no valido");
//                    printf("Ingrese la nota: ");
//                    scanf("%d", &quali);
//                }
//                if (ab == 1) {
//                    count_A++;
//                    sum_A += quali;
//                    // sum_A = sum_A + quali;
//                }
//                else {
//                    count_B++;
//                    sum_B += quali;
//                }
//
//                printf("Ingrese 0 para finalizar el ingreso de este año\nCualquier otra tecla para continuar");
//                scanf("%d", &end);
//
//                count_tot++;
//
//            } while(end != 0);
//
//            prom_A = (float)sum_A / count_A;
//            prom_B = (float)sum_B / count_B;
//
//            printf("AÑO %d - promedio gral:\nA = %.2f\nB = %.2f\n", i+1, prom_A, prom_B);
//
//            if (prom_A > max_prom) {
//                max_prom = prom_A;
//                max_ano = i + 1;
//                max_ab = 'A';
//            }
//            if (prom_B > max_prom) {
//                max_prom = prom_B;
//                max_ano = i + 1;
//                max_ab = 'B';
//            }
//
//    }
//
//    printf("TOTAL DE LEGAJOS: %d \nPROMEDIO MAXIMO: %.2f \nAÑO: %d \nDIVISION: %c", count_tot, max_prom, max_ano, max_ab);
//
//
//
//
//
//
//
//
//
//
//
//
//
//// Piedra papel o tijera
//
//    int opcionComputadora, c;
//    char ppt;
//    srand(time(NULL)); // Inicializar generador de números aleatorios
//// Obtener elección aleatoria de la computadora (0 - piedra, 1 - papel, 2 - tijera)
//    opcionComputadora = rand() % 3;
//    printf("%d\n", opcionComputadora);
//
//    printf("I) PIEDRA \nA) PAPEL\nT) TIJERA\n");
//    printf("Piedra, papel o tijera...\n");
//    printf("YA! ");
//    scanf("%c", &ppt);
//    while ((c = getchar()) != '\n' && c != EOF);
//    while (ppt != 'I' && ppt != 'T' && ppt != 'A') {
//        printf("Epa, las opciones son: \nI) PIEDRA \nA) PAPEL\nT) TIJERA\n");
//        scanf("%c", &ppt);
//        while ((c = getchar()) != '\n' && c != EOF);
//    }
//    printf("ELECCION MAQUINA | ELECCION USUARIO\nRESULTADO\n");
//
//    if(opcionComputadora==0 && ppt=='I') {
//        printf("PIEDRA | PIEDRA\n");
//        printf("clasico...\n");
//    }
//    else if(opcionComputadora==1 && ppt=='I') {
//        printf("PAPEL | PIEDRA\n");
//        printf("como te va a ganar el papel\n");
//    }
//    else if(opcionComputadora==2 && ppt=='I') {
//        printf("TIJERA | PIEDRA\n");
//        printf("ganaste paaa\n");
//    }
//    else if(opcionComputadora==0 && ppt=='A') {
//        printf("PIEDRA | PAPEL\n");
//        printf("ganaste paaa\n");
//    }
//    else if(opcionComputadora==1 && ppt=='A') {
//        printf("PAPEL | PAPEL\n");
//        printf("empate verde!\n");
//    }
//    else if(opcionComputadora==2 && ppt=='A') {
//        printf("TIJERA | PAPEL\n");
//        printf("perdedorrrrrrr\n");
//    }
//    else if(opcionComputadora==0 && ppt=='T') {
//        printf("PIEDRA | TIJERA\n");
//        printf("perdiste con la piedra...#respect\n");
//    }
//    else if(opcionComputadora==1 && ppt=='T') {
//        printf("PAPEL | TIJERA\n");
//        printf("ganadorrrrrr\n");
//    }
//    else if(opcionComputadora==2 && ppt=='T') {
//        printf("TIJERA | TIJERA\n");
//        printf("quack\n");
//    }
//
//
//
//
//    return 0;
//}
