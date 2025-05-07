#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(){
    ej3();
    return 0;
}

void ej1(){
    int op, cals[4], input, cals_day, cals_week = 0, most_cals_day = 0;
    char des[20]={0}, alm[20]={0}, mer[20]={0}, cen[20]={0}, food[4][20];

    for (int i=1; i<=7; i++) {
        printf("DIA %d\n", i);
        input = 0;
        cals_day = 0;
        do {
            printf("*************************************\n");
            printf("-----------------MENU--------------------\n");
            printf("*************************************\n");
            printf("elija una opción :\n 1) Ingresar alimentos\n2) FINALIZAR DIA\n3) CALS del dia\n4) CALS de la semana\n 5) DIA CON + CALS\n");
            scanf("%d", &op);
            switch(op) {
            case 1:
                for (int j=1; j<=4; j++) {
                    printf("Ingrese su %d° comida del dia: ", j);
                    fgets(food[j],sizeof(food[j]),stdin);
                    des[strcspn(food[j], "\n")] = '\0';
                    printf("ingrese calorias: ");
                    scanf("%d", cals[j]);
                }
                input = 1;
                cals_day = cals[0] + cals[1] + cals[2] + cals[3];
                break;
            case 2:
                printf("FINALIZADO EL DIA\n");
                break;
            case 3:
                if (input == 1) {
                    printf("cals del dia: %d\n", cals_day);
                }
                else {
                    printf("ingrese su ingesta del dia\n");
                }
                break;
            case 4:
                printf("cals de la semana: %d\n", cals_week);
                break;
            case 5:
                printf("dia de mas cals de la semana: %d\n", most_cals_day);
                break;
            default:
                printf("++++++++++OPCION INVÁLIDA++++++++++++\n");
                if (input == 0) {
                    printf("+++++DEBERA INGRESAR UN CONSUMO DE ALIMENTOS+++++");
                }
                break;
            }

        } while(op!=2 || input == 0);
        cals_week = cals_week + cals_day;
        if (cals_day > most_cals_day) {
            most_cals_day = cals_day;
        }
    }
}

void ej2(){
    int ran, i=1, answer, success;
    srand(time(NULL));
    ran = rand() % 50 +1;
    printf("%d", ran);

    printf("Debera adivinar el numero secreto para que no explote la bomba, este numero esta entre 1 y 50 (inclusive)\nTendrá 5 intentos\n");

    do {
        printf("Intento nro %d\n", i);
        printf("Ingrese su rta: ");
        scanf("%d", &answer);
        while (answer < 1 || answer > 50) {
            printf("Este valor no es valido, debe ser entre 1 y 50 inclusives\n");
            printf("Ingrese su rta: ");
            scanf("%d", &answer);
        }
        if (answer == ran) {
            printf("Lograste desconectar la bomba, que bien... ;/\n");
            success = 1;
        } else if (answer < ran) {
            printf("Es muy bajoooo\n");
            i++;
            success = 0;
        } else {
            printf("Es muy graaande\n");
            i++;
            success = 0;
        }
    } while(success == 0 && i <= 5);

    if (i > 5) {
        printf("PUM");
    }
    else {
        printf("Felicitaciones...te tomo %d intentos", i);
    }
}

void ej3(){
    char words[101]={0}, final_word[101]={0};
    int j=0;

    printf("ingresa frase: \n");
    fgets(words, sizeof(words),stdin);
    words[strcspn(words, "\n")] = '\0';

    for(int i=0 ; words[i] != '\0' ; i++) {
        if (words[i] >= 65 && words[i] <= 90) {
            printf("letra %c preconvertir a minuscula - ", words[i]);
            words[i] = words[i] + 32;
            printf("letra %c convertida a minuscula\n", words[i]);
        }
        if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u') {
            printf("Chequeo vocal: %c\n", words[i]);
        }
        else if (words[i] == 32) {
            printf("Encontre un espacio en la posicion %d de la palabra", i);
        }
        else {
            printf("letra no vocal a palabra final: %c\n", words[i]);
            final_word[j] = words[i];
            j++;
            printf("palabra final por el momento: %s\n", final_word);
        }
    }

    printf("PALABRA FINAL: %s", final_word);
}
