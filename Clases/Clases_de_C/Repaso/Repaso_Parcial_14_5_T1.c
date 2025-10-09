#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int es_letra(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    } else {
        return 0;
    }
}

void ej1(){
    int num_ticket[30], horas[30], contador;
    char patente[30][7]; //{"AAA000","BDF987",....}
    char tipo[30];
    char buffer[100];
    float recaudacion_dia[7] = {0};
    float monto_vehiculo[30] = {0};

    float monto_autos[7] = {0};
    float monto_motos[7] = {0};
    int cant_autos[7] = {0};
    int cant_motos[7] = {0};

    float total_recaudado = 0;
    int total_motos = 0;
    int total_autos = 0;

    int dia_mayor_recau = 0; //de 0 a 6 -> el indice del dia que mas se recuado

    for(int i = 0; i < 7; i++){
        contador = 0;
        printf("Ingrese horas (0 para terminar): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &horas[contador]) == 1) {
            } else {
                printf("Error: Entrada invalida.\n");
            }
        }
        while(horas[contador] != 0 && contador < 30){
            while (horas[contador] < 1 || horas[contador] > 24){
                printf("Reingresa la horas, rango invalido: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    if (sscanf(buffer, "%d", &horas[contador]) == 1) {
                    } else {
                        printf("Error: Entrada invalida.\n");
                    }
                }
            }
            printf("Ingresa la patente (AAA000): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%6s", patente[contador]) == 1) {
                } else {
                    printf("Error: Entrada invalida.\n");
                }
            }
            while (strlen(patente[contador]) != 6){
                printf("Reingresa la patente, muy corta o muy larga: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    if (sscanf(buffer, "%6s", patente[contador]) == 1) {
                    } else {
                        printf("Error: Entrada invalida.\n");
                    }
                }
            }

            printf("Ingresa la si es auto o moto (A/M): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%c", &tipo[contador]) == 1) {
                } else {
                    printf("Error: Entrada invalida.\n");
                }
            }
            while (tipo[contador] != 'A' && tipo[contador] != 'M'
                   && tipo[contador] != 'a' && tipo[contador] != 'm'){
                printf("Reingresa la tipo de vehiculo (M/A): ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    if (sscanf(buffer, "%c", &tipo[contador]) == 1) {
                    } else {
                        printf("Error: Entrada invalida.\n");
                    }
                }
            }

            num_ticket[contador] = 1007 + contador;

            if (tipo[contador] == 'A' || tipo[contador] == 'a'){
                monto_vehiculo[contador] = 1000 * horas[contador];
                cant_autos[i]++;
                monto_autos[i] += monto_vehiculo[contador];

            } else {
                monto_vehiculo[contador] = 500 * horas[contador];
                cant_motos[i]++;
                monto_motos[i] += monto_vehiculo[contador];
            }
            recaudacion_dia[i] += monto_vehiculo[contador];

            printf("Numero de ticket: %d\n", num_ticket[contador]);
            printf("Patente: %s\n", patente[contador]);
            printf("Horas: %d\n", horas[contador]);
            printf("Monto recaudado del dia: %.2f\n", recaudacion_dia[i]);


            if (recaudacion_dia[i] > recaudacion_dia[dia_mayor_recau]){
                dia_mayor_recau = i;
            }


            contador++;
            printf("Ingrese horas (0 para terminar): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%d", &horas[contador]) == 1) {
                } else {
                    printf("Error: Entrada invalida.\n");
                }
            }
        }
        printf(" -- DIA %d -- \n\n", i+1);
        printf("Plata por motos: %.2f\n", monto_motos[i]);
        printf("Plata por autos: %.2f\n", monto_autos[i]);
        printf("Cantidad de motos: %d\n", cant_motos[i]);
        printf("Cantidad de autos: %d\n", cant_autos[i]);
    }


    printf("RESUMEN SEMANA \n\n");
    for (int i = 0; i < 7; i++){
        printf("Dia %d se recaudo %.2f, hubieron %d autos y %d motos\n", i+1,monto_motos[i]+monto_autos[i],cant_autos[i],cant_motos[i]);
        total_recaudado+=monto_motos[i]+monto_autos[i];
        total_autos +=cant_autos[i];
        total_motos +=cant_motos[i];
    }
    printf("\n --- \nTotal recaudado: %.2f\n",total_recaudado);
    printf("Total motos: %d\n",total_motos);
    printf("Total autos: %d\n",total_autos);
    printf("El dia que mas se recuado fue el dia %d",dia_mayor_recau+1);
}

void ej2(){
    char buffer[20];
    char usuario[10];
    char compu[10];
    int opcionCompu;
    int victorias_u = 0, victorias_c = 0, empates = 0;

    srand(time(NULL));

    printf("Ingresar piedra, papel, tijera o F para terminar: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%9s", usuario) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }
    while(strcmp(usuario, "papel")!=0 && strcmp(usuario, "tijera")!=0 && strcmp(usuario, "piedra")!=0 && usuario[0] != 'F'){
        printf("La eleccion no es valida, reingresar: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%9s", usuario) == 1) {
            } else {
                printf("Error: Entrada invalida.\n");
            }
        }
    }
    printf("Eleccion: %s\n", usuario);

    while(usuario[0] != 'F'){
        opcionCompu = rand() % 3;
        if (opcionCompu == 0){
            strcpy(compu, "piedra");
        }else if (opcionCompu == 1){
            strcpy(compu, "papel");
        }else {
            strcpy(compu, "tijera");
        }
        printf("Compu: %s\n", compu);
        if (strcmp(usuario, compu) == 0){
            printf("Empate\n");
            empates++;
        }
        else if((strcmp(usuario, "papel") == 0 && strcmp(compu, "piedra") == 0) ||
                (strcmp(usuario, "tijera") == 0 && strcmp(compu, "papel") == 0) ||
                (strcmp(usuario, "piedra") == 0 && strcmp(compu, "tijera") == 0)){
                    printf("Gano usuario\n");
                    victorias_u++;

        }else {
                printf("Gano compu\n");
                victorias_c++;
        }
        printf("Ingresar piedra, papel, tijera o F para terminar: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%9s", usuario) == 1) {
            } else {
                printf("Error: Entrada invalida.\n");
            }
        }
        while(strcmp(usuario, "papel")!=0 && strcmp(usuario, "tijera")!=0 && strcmp(usuario, "piedra")!=0 && usuario[0] != 'F'){
            printf("La eleccion no es valida, reingresar: ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%9s", usuario) == 1) {
                } else {
                    printf("Error: Entrada invalida.\n");
                }
            }
        }
        printf("Eleccion: %s\n", usuario);
    }

    printf("Victorias del usuario: %d\n", victorias_u);
    printf("Victorias de la compu: %d\n", victorias_c);
    printf("Empates: %d\n", empates);

    if (victorias_u > victorias_c){
        printf("GANO EL USUARIO");
    } else if (victorias_u < victorias_c) {
        printf("GANO LA COMPU");
    } else {
        printf("EMPATE");
    }
}

void ej3(){
    char buffer[200];
    char mensaje[100];
    int clave = -1;
    printf("Ingrese mensaje: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%99[^\n]s", mensaje) == 1) {
            printf("Mensaje: %s\n", mensaje);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

    printf("Ingrese clave: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &clave) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }
    while(clave <= 0){
        printf("Ingrese clave (> 0): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &clave) == 1) {

            } else {
                printf("Error: Entrada invalida.\n");
            }
        }
    }

    int i = 0;
    while(mensaje[i] != '\0'){
        if(es_letra(mensaje[i])){
            if (mensaje[i] >= 'A' && mensaje[i] <= 'Z'){
                mensaje[i] = ((mensaje[i] - 'A') + clave ) % 26 + 'a';
            }
            else{
                mensaje[i] = ((mensaje[i] - 'a') + clave ) % 26 + 'A';
            }
        }
        i++;
    }
    printf("Mensaje cifrado: %s\n", mensaje);
}
int main() {
    ej1();

    return 0;
}
