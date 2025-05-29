#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define DAYS 7

 int main() {
    ejercicio3_cifrado_cesar();
    return 0;
 }

 void moe() {
    int opt, opt1, tot_day, day_rev[DAYS] = {0}, tot_rev_w = 0, beer_h=0, beer_b=0, beer_u=0, h_today, min_day, max_day, max;
    char who;
    for(int i = 0; i < DAYS; i++) {
        printf("\n**************DIA %d*****************\n", i+1);
        tot_day = 0;
        h_today = 0;
        do {
            printf("\nMENU:\n1. Ingresar pedido\n2. Mostrar dia con mayores ventas\n3. Mostrar total de ventas del dia actual\n4. Mostrar cervezas tomadas por Homero, Barney y otros hasta el momento\n5. Finalizar el dia\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opt);
            getchar();

            switch (opt) {
                case 1:
                    printf("\n1. Mesa de pool - $5000\n2. Cerveza - $3000\n3. Rocola $1000\n4. Llamarada Moe $10.000\nSeleccione una opcion: ");
                    scanf("%d", &opt1);
                    getchar();

                    switch (opt1) {
                        case 1:
                            tot_day += 5000;
                            break;
                        case 2:
                            printf("\nQuien pidio esta cerveza?\n");
                            printf("H/h - Homero\nB/b - Barney\nU/u - Alguien mas\n");
                            scanf("%c", &who);
                            getchar();
                            who = tolower(who);
                            while (who != 'h' && who != 'b' && who != 'u') {
                                printf("ingrese una opcion valida: ");
                                scanf("%c", &who);
                                getchar();
                                who = tolower(who);
                            }
                            if (who == 'b') {
                                beer_b++;
                            }
                            else if (who == 'h') {
                                beer_h++;
                                h_today++;
                            }
                            else {
                                beer_u++;
                            }
                            tot_day += 3000;
                            break;
                        case 3:
                            tot_day += 1000;
                            break;
                        case 4:
                            tot_day += 10000;
                            break;
                        default:
                            printf("Opcion invalida - Volverá al menú ppal");
                    }
                    break;
                case 2:
                    if (i==0) {
                            printf("Estamos en el primer dia, no puedo darte un dia de mayores ventas aun");
                    } else {
                        printf("Dia de mayores ventas: ");
                        max = -1;
                        for (int d = 0; d < DAYS; d++) {
                            if (day_rev[d] > max){
                                max_day = d + 1;
                                max = day_rev[d];
                            }
                        }
                        printf("[Dia %d]", max_day);
                    }
                    break;
                case 3:
                    printf("TOTAL DE VENTAS HOY: [$%d]", tot_day);
                    break;
                case 4:
                    printf("CERVEZAS\nHOMERO:[%d]\nBARNEY:[%d]\nOTROS:[%d]\n", beer_h, beer_b, beer_u);
                    break;
                case 5:
                    if (h_today == 0) {
                        printf("El dia no finaliza sin que Homero beba cerveeeeeza");
                        opt = 1;
                    } else {
                        printf("\n*********FIN DEL DIA***********\n");
                    }
                    break;
                default:
                    printf("Opcion Invalida, volvera al menu ppal");
            }
        } while(opt != 5);
        day_rev[i] = tot_day;
        tot_rev_w += tot_day;
        printf("\nVentas del dia: $%d\nCervezas bebidas por Homero: %d\nTotal acumulado hasta ahora: $%d\n", tot_day, h_today, tot_rev_w);
    }
    max = -1;
    for (int d = 0; d < DAYS; d++) {
        if (day_rev[d] > max){
        max_day = d + 1;
        max = day_rev[d];
        }
    }
    int min = max;
    for (int d = 0; d < DAYS; d++) {
        if (day_rev[d] < min){
        min_day = d + 1;
        min = day_rev[d];
        }
    }
    printf("\n********** Semana finalizada ***********\n");
    printf("Dia de mayores ventas: Dia %d\n", max_day);
    printf("Dia de menores ventas: Dia %d\n", min_day);
    printf("Total recaudado en la semana: $%d\n", tot_rev_w);
    printf("Total de ventas de cerveza a Barney: $%d\n", beer_b * 3000);
 }

void calabozos_y_dragones() {
    int hp = 30, dice, less_ten = 0, btwn = 0, high_tw = 0, damage;

    srand(time(NULL));

    for (int i = 1; i <= 4; i++) {
        printf("\nTirada %d: ", i);
        dice = rand() % 32 + 1;
        getchar();
        printf("Sacaste: %d\n", dice);

        if (dice < 10) {
            less_ten = 1;
        } else if (dice >= 20) {
            high_tw = 1;
        }
        else {
            btwn = 1;
        }

        if (less_ten && btwn && high_tw) {
            printf("\nPUUUUUUUUMMMMMMMPLAF¡Mataste al dragon! GANASTE.\n");
            return;
        }

        damage = rand() % 10 + 1;
        hp -= damage;
        printf("El dragon te ataco e hizo %d de danio", damage);

        if (hp <= 0) {
            printf("\nAGHHHHHHHH.... MORISTE. El dragon te vencio.\n");
            return;
        }
        printf("\nVida restante: %d\n", hp);
    }

    printf("\nNo lograste matar al dragon... pero huiste con %d de vida.\n", hp);
}

void et_descifrar() {
    char message[100], decifre[100];
    printf("Ingrese mensaje cifrado: ");
    scanf("%[^\n]s", message);

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') message[i] = message[i] + 32;
        if (message[i] == 'a') {
            decifre[i] = 'z';
        } else if (message[i] > 'a' && message[i] <= 'z') {
            decifre[i] = message[i] - 1;
        } else {
            decifre[i] = message[i];
        }
    }

    printf("Mensaje descifrado: %s\n", decifre);
}
