#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VEHICULOS 30

int es_letra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int es_mayuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

void ej_1() {
    int numeroTicket[MAX_VEHICULOS], horas[MAX_VEHICULOS];
    char patente[MAX_VEHICULOS][7], tipo[MAX_VEHICULOS];
    float monto[MAX_VEHICULOS];

    float recaudacionDiaAutos[7] = {0}, recaudacionDiaMotos[7] = {0};
    int cantidadDiaAutos[7] = {0}, cantidadDiaMotos[7] = {0};
    float recaudacionDiaTotal[7] = {0}, recaudacionTotal = 0;
    int cantidadTotalAutos = 0, cantidadTotalMotos = 0;
    int diaMayorRecaudacion = 0;

    int i, j, contador, horasActual;

    for (i = 0; i < 7; i++) {
        contador = 0;
        numeroTicket[0] = 1007;

        printf("\n--- DIA %d ---\n", i + 1);

        printf("Ingrese las horas estacionado (0 para finalizar): ");
        scanf("%d", &horasActual);

        while (horasActual != 0 && contador < MAX_VEHICULOS) {
            while (horasActual < 1 || horasActual > 24) {
                printf("Horas invalidas. Ingrese un valor entre 1 y 24: ");
                scanf("%d", &horasActual);
            }

            horas[contador] = horasActual;

            printf("Ingrese la patente (formato AAA000): ");
            scanf("%s", patente[contador]);
            while (strlen(patente[contador]) != 6) {
                printf("La patente debe tener 6 caracteres. Ingrese nuevamente: ");
                scanf("%s", patente[contador]);
            }

            printf("Ingrese el tipo de vehiculo (A para auto, M para moto): ");
            scanf(" %c", &tipo[contador]);
            while (tipo[contador] != 'A' && tipo[contador] != 'a' && tipo[contador] != 'M' && tipo[contador] != 'm') {
                printf("Tipo de vehiculo invalido. Ingrese A para auto o M para moto: ");
                scanf(" %c", &tipo[contador]);
            }

            if (tipo[contador] == 'A' || tipo[contador] == 'a') {
                monto[contador] = horas[contador] * 1000;
                recaudacionDiaAutos[i] += monto[contador];
                cantidadDiaAutos[i]++;
            } else {
                monto[contador] = horas[contador] * 500;
                recaudacionDiaMotos[i] += monto[contador];
                cantidadDiaMotos[i]++;
            }

            recaudacionDiaTotal[i] += monto[contador];

            printf("\n--- TICKET ---\n");
            printf("Numero de ticket: %d\n", numeroTicket[contador]);
            printf("Patente: %s\n", patente[contador]);
            printf("Horas: %d\n", horas[contador]);
            printf("Monto total recaudado este dia hasta el momento: $%.2f\n", recaudacionDiaTotal[i]);

            contador++;
            if (contador < MAX_VEHICULOS) {
                numeroTicket[contador] = numeroTicket[contador-1] + 1;
            }

            printf("\nIngrese las horas estacionado (0 para finalizar): ");
            scanf("%d", &horasActual);
        }

        printf("\n--- RESUMEN DEL DIA %d ---\n", i + 1);
        printf("Recaudacion por motos: $%.2f\n", recaudacionDiaMotos[i]);
        printf("Recaudacion por autos: $%.2f\n", recaudacionDiaAutos[i]);
        printf("Cantidad de autos: %d\n", cantidadDiaAutos[i]);
        printf("Cantidad de motos: %d\n", cantidadDiaMotos[i]);

        recaudacionTotal += recaudacionDiaTotal[i];
        cantidadTotalAutos += cantidadDiaAutos[i];
        cantidadTotalMotos += cantidadDiaMotos[i];

        if (recaudacionDiaTotal[i] > recaudacionDiaTotal[diaMayorRecaudacion]) {
            diaMayorRecaudacion = i;
        }
    }

    printf("\n--- RESUMEN SEMANAL ---\n");
    for (i = 0; i < 7; i++) {
        printf("Dia %d - Recaudacion: $%.2f - Autos: %d - Motos: %d\n",
               i + 1, recaudacionDiaTotal[i], cantidadDiaAutos[i], cantidadDiaMotos[i]);
    }

    printf("\nTotal recaudado en la semana: $%.2f\n", recaudacionTotal);
    printf("Total de autos en la semana: %d\n", cantidadTotalAutos);
    printf("Total de motos en la semana: %d\n", cantidadTotalMotos);
    printf("Dia de mayor recaudacion: %d ($%.2f)\n", diaMayorRecaudacion + 1, recaudacionDiaTotal[diaMayorRecaudacion]);
}

void ej_2() {
    char opcionUsuario[10], opcionComputadora[10];
    int opcionComputadoraNum;
    int victoriasUsuario = 0, victoriasComputadora = 0, empates = 0;

    srand(time(NULL));

    printf("\n--- JUEGO DE PIEDRA, PAPEL O TIJERA ---\n");
    printf("Ingrese su eleccion (piedra, papel, tijera) o F para terminar: ");
    scanf("%s", opcionUsuario);

    while (opcionUsuario[0] != 'F' && opcionUsuario[0] != 'f') {
        opcionComputadoraNum = rand() % 3;

        if (opcionComputadoraNum == 0)
            strcpy(opcionComputadora, "piedra");
        else if (opcionComputadoraNum == 1)
            strcpy(opcionComputadora, "papel");
        else
            strcpy(opcionComputadora, "tijera");

        printf("La computadora eligio: %s\n", opcionComputadora);

        if (strcmp(opcionUsuario, opcionComputadora) == 0) {
            printf("Empate!\n");
            empates++;
        }
        else if ((strcmp(opcionUsuario, "piedra") == 0 && strcmp(opcionComputadora, "tijera") == 0) ||
                 (strcmp(opcionUsuario, "papel") == 0 && strcmp(opcionComputadora, "piedra") == 0) ||
                 (strcmp(opcionUsuario, "tijera") == 0 && strcmp(opcionComputadora, "papel") == 0)) {
            printf("Ganaste!\n");
            victoriasUsuario++;
        }
        else {
            printf("Perdiste!\n");
            victoriasComputadora++;
        }

        printf("\nIngrese su eleccion (piedra, papel, tijera) o F para terminar: ");
        scanf("%s", opcionUsuario);

        while(strcmp(opcionUsuario, "piedra") != 0 &&
              strcmp(opcionUsuario, "papel") != 0 &&
              strcmp(opcionUsuario, "tijera") != 0 &&
              opcionUsuario[0] != 'F' && opcionUsuario[0] != 'f') {
            printf("Opcion invalida. Ingrese piedra, papel, tijera o F para terminar: ");
            scanf("%s", opcionUsuario);
        }

    }

    printf("\n--- RESULTADOS FINALES ---\n");
    printf("Victorias del usuario: %d\n", victoriasUsuario);
    printf("Victorias de la computadora: %d\n", victoriasComputadora);
    printf("Empates: %d\n", empates);

    if (victoriasUsuario > victoriasComputadora)
        printf("El ganador final es el USUARIO!\n");
    else if (victoriasComputadora > victoriasUsuario)
        printf("El ganador final es la COMPUTADORA!\n");
    else
        printf("El juego termino en EMPATE!\n");
}

void ej_3() {
    char mensaje[1000];
    int clave;
    int i = 0;

    printf("\n--- CIFRADO CESAR ---\n");

    printf("Ingrese el mensaje a cifrar: ");
    getchar();
    fgets(mensaje, sizeof(mensaje), stdin);
    mensaje[strcspn(mensaje, "\n")] = '\0';

    printf("Ingrese la clave de desplazamiento (entero positivo): ");
    scanf("%d", &clave);
    while (clave <= 0) {
        printf("La clave debe ser un entero positivo. Ingrese nuevamente: ");
        scanf("%d", &clave);
    }

    while (mensaje[i] != '\0') {
        if (es_letra(mensaje[i])) {
            if (es_mayuscula(mensaje[i])) {
                mensaje[i] = ((mensaje[i] - 'A') + clave) % 26 + 'A';
            } else {
                mensaje[i] = ((mensaje[i] - 'a') + clave) % 26 + 'a';
            }
        }
        i++;
    }

    printf("Mensaje cifrado: %s\n", mensaje);
}

int main() {
    int opcion;

    printf("PARCIAL C\n\n");
    printf("1. Control de Estacionamiento\n");
    printf("2. Piedra, Papel o Tijera\n");
    printf("3. Cifrado Cesar\n");
    printf("\nSeleccione el ejercicio a ejecutar (1-3): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            ej_1();
            break;
        case 2:
            ej_2();
            break;
        case 3:
            ej_3();
            break;
        default:
            printf("Opcion invalida\n");
    }

    return 0;
}
