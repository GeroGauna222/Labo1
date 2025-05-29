#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_V 30
#define DAYS 7

void ejercicio1_estacionamiento() {
    int tot_days[DAYS] = {0};
    int a_days[DAYS] = {0}, a_days_mount[DAYS] = {0};
    int m_days[DAYS] = {0}, m_days_mount[DAYS] = {0};
    int ticket = 1007;
    char buffer[256] = {0};

    for (int day = 0; day < DAYS; day++) {
        printf("\n--- DIA %d ---\n", day + 1);

        int tot_day = 0;
        int a_day = 0, a_day_mount = 0;
        int m_day = 0, m_day_mount = 0;
        int quant = 0;

        while (quant < MAX_V) {
            int hrs = -1;
            char p[10], type;

            printf("\nHoras estacionado (0 para terminar el dia): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
                sscanf(buffer, "%d", &hrs);
                memset(buffer, 0, sizeof(buffer));
            if (hrs == 0) break;

            while (hrs < 0 || hrs > 24) {
                printf("Hora invalida. Ingrese entre 1 y 24: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    sscanf(buffer, "%d", &hrs);
                    memset(buffer, 0, sizeof(buffer));
                }
            }
            if (hrs == 0) break;

            printf("Ingrese patente (6 caracteres): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';
                sscanf(buffer, "%9s", p);
                memset(buffer, 0, sizeof(buffer));
            }
            while (strlen(p) != 6) {
                printf("Patente invalida. Debe tener 6 caracteres: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    sscanf(buffer, "%9s", p);
                    memset(buffer, 0, sizeof(buffer));
                }
            }

            do {
                printf("Ingrese tipo de vehiculo (A/a para auto, M/m para moto): ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    sscanf(buffer, "%c", &type);
                    type = tolower(type);
                    memset(buffer, 0, sizeof(buffer));
                }
            } while (!(type == 'a' || type == 'm'));

            int cost = 0;
            if (type == 'a') {
                cost = hrs * 1000;
                a_day++;
                a_day_mount += cost;
            } else {
                cost = hrs * 500;
                m_day++;
                m_day_mount += cost;
            }

            tot_day += cost;
            quant++;

            printf("\n--- Ticket generado ---\n");
            printf("Numero de ticket: %d\n", ticket);
            printf("Patente: %s\n", p);
            printf("Horas: %d\n", hrs);
            printf("Monto total recaudado hasta el momento: $%d\n", tot_day);
            ticket++;
        }

        tot_days[day] = tot_day;
        a_days[day] = a_day;
        m_days[day] = m_day;
        a_days_mount[day] = a_day_mount;
        m_days_mount[day] = m_day_mount;

        printf("\n--- Fin del dia %d ---\n", day + 1);
        printf("Recaudacion por autos: $%d\n", a_day_mount);
        printf("Recaudacion por motos: $%d\n", m_day_mount);
        printf("Cantidad de autos: %d\nCantidad de motos: %d\n", a_day, m_day);
    }

    int tot_w = 0;
    int tot_a = 0, tot_m = 0;
    int day_max = 0;

    printf("\n--- Resumen de la semana ---\n");
    for (int i = 0; i < DAYS; i++) {
        printf("Dia %d - Total: $%d | Autos: %d | Motos: %d\n", i + 1, tot_days[i], a_days[i], m_days[i]);
        tot_w += tot_days[i];
        tot_a += a_days[i];
        tot_m += m_days[i];
        if (tot_days[i] > tot_days[day_max]) {
            day_max = i;
        }
    }

    printf("\nTotal recaudado en la semana: $%d\n", tot_w);
    printf("Total de autos estacionados: %d\n", tot_a);
    printf("Total de motos estacionadas: %d\n", tot_m);
    printf("Dia de mayor recaudación: Dia %d\n", day_max + 1);
}

void ejercicio2_ppt() {
    char user[10], elec[10], buffer[256];
    int v_user = 0, v_cpu = 0, draw = 0;

    srand(time(NULL));

    while (1) {
        printf("\nElija piedra, papel o tijera (F para finalizar): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            sscanf(buffer, "%9s", &user);
            memset(buffer, 0, sizeof(buffer));
            for(int i=0; i<strlen(user); i++) {
                user[i] = tolower(user[i]);
            }
        }
        while (strcmp(user, "piedra") != 0 && strcmp(user, "papel") != 0 && strcmp(user, "tijera") != 0 && strcmp(user, "f") != 0) {
            printf("\nElija piedra, papel o tijera (F para finalizar): ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                sscanf(buffer, "%9s", &user);
                memset(buffer, 0, sizeof(buffer));
                for(int i=0; i<strlen(user); i++) {
                    user[i] = tolower(user[i]);
                }
            }
        }
        if (strcmp(user, "f")) break;

        int cpu = rand() % 3;
        if (cpu == 0) strcpy(elec,"piedra");
        else if (cpu == 1) strcpy(elec,"papel");
        else strcpy(elec,"tijera");

        printf("Computadora eligió: %s\n", elec);

        if (strcmp(user, elec) == 0) {
            printf("Empate.\n");
            draw++;
        } else if ((strcmp(user, "piedra") == 0 && strcmp(elec, "tijera") == 0) ||
                   (strcmp(user, "papel") == 0 && strcmp(elec, "piedra") == 0) ||
                   (strcmp(user, "tijera") == 0 && strcmp(elec, "papel") == 0)) {
            printf("Ganaste esta ronda.\n");
            v_user++;
        } else {
            printf("Ganó la computadora.\n");
            v_cpu++;
        }
    }

    printf("\n--- Resultados finales ---\n");
    printf("Usuario: %d victorias\nComputadora: %d victorias\nEmpates: %d\n", v_user, v_cpu, draw);
    if (v_user > v_cpu) printf("Ganador final: Usuario\n");
    else if (v_cpu > v_user) printf("Ganador final: Computadora\n");
    else printf("Empate...\n");
}

void ejercicio3_cifrado_cesar() {
    char inp[256]={0}, cifred[256]={0}, buffer[256];
    int key;

    printf("Ingrese el texto a cifrar: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer, "%[^\n]s", &inp);
        memset(buffer, 0, sizeof(buffer));
    }


    printf("Ingrese la clave de desplazamiento: ");
    scanf("%d", &key);

    for (int i = 0; inp[i] != '\0'; i++) {
        if (inp[i] >= 'A' && inp[i] <= 'Z') {
            cifred[i] = 'A' + (inp[i] - 'A' + key) % 26;
        } else if (inp[i] >= 'a' && inp[i] <= 'z') {
            cifred[i] = 'a' + (inp[i] - 'a' + key) % 26;
        } else {
            cifred[i] = inp[i];
        }
    }

    printf("Texto cifrado: %s\n", cifred);
}

