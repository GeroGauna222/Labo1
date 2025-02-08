#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ej1() {
    int rifas_vendidas [1000] = {0}, ch, max_v, rifa, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count_tot = 0, count_dia, count1_dia, count2_dia, count3_dia, count4_dia;

for(int i=0 ; i < 7 ; i++) {
    count_dia = 0;
    count1_dia = 0;
    count2_dia = 0;
    count3_dia = 0;
    count4_dia = 0;
    printf("DIA %d DE VENTAS\n", i+1);
    do {
        printf("Ingrese quien le vendio la rifa\n1) Jugador 1 \n2) Jugador 2 \n3) Jugador 3 \n4) Jugador 4 \nSi quiere detener el ingreso de este dia, presione 0 \n");
        scanf("%d", &ch);
        getchar();
        while(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 0) {
            printf("Ingreso un valor no valido");
            printf("Ingrese quien le vendio la rifa\n1) Jugador 1 \n2) Jugador 2 \n3) Jugador 3 \n4) Jugador 4 \nSi quiere detener el ingreso de este dia, presione 0 \n");
            scanf("%d", &ch);
            getchar();
        }

        if (ch == 0) {
            printf("\n------------Finaliza el dia--------------\n");
        }
        else {
            printf("Ingrese que numero desea comprar (1 al 1000): ");
            scanf("%d", &rifa);
            getchar();
            while(rifa < 1 || rifa > 1000) {
                printf("Ingreso un valor no valido");
                printf("Ingrese la rifa que desea: ");
                scanf("%d", &rifa);
                getchar();
            }
            // chequea que la rifa no haya sido vendida
            while (rifas_vendidas[rifa-1] == 1)
            {
                printf("Esta rifa ya se vendio, escoja otra: ");
                scanf("%d", &rifa);
                getchar();

                while(rifa < 1 || rifa > 1000) {
                printf("Ingreso un valor no valido\n");
                printf("Ingrese la rifa que desea: ");
                scanf("%d", &rifa);
                getchar();
                }
            }

            rifas_vendidas[rifa-1] = 1;
            
            switch (ch) {
            case 1:
                count1++;
                count1_dia++;
                break;
            case 2:
                count2++;
                count2_dia++;
                break;
            case 3:
                count3++;
                count3_dia++;
                break;
            case 4:
                count4++;
                count4_dia++;
                break;
            }

            count_dia++;
            count_tot++;

            printf("Comprador nro %d\n", count_tot);
            printf("Numero de rifa: %d\n", rifa);
            printf("Vendedor: Jugador nro %d\n", ch);
        }

    } while(ch != 0);

    if (i == 5) {
        printf("-------------------\nYa falta un dia!!!!\n---------------------------\n");
    }
    else if (i == 6) {
        printf("-------------------\nYa esta, fue el ultimo dia!!!!\n---------------------------\n");
    }
    else {
        printf("-------------------\nDia terminado, ya faltan %d dias!!!\n---------------------------\n", 7-(i+1));
    }
    
    printf("Dinero recaudado hoy: %d\nVentas jug 1: %d\nVentas jug 2: %d\nVentas jug 3: %d\nVentas jug 4: %d\n", count_dia * 200, count1_dia, count2_dia, count3_dia, count4_dia);
}

if (count1 > count2 && count1 > count3 && count1 > count4) {
    max_v = 1;
}
if (count2 > count1 && count2 > count3 && count2 > count4) {
    max_v = 2;
}
if (count3 > count2 && count3 > count1 && count3 > count4) {
    max_v = 3;
}
if (count4 > count2 && count4 > count3 && count4 > count1) {
    max_v = 4;
}

printf("Los chicos se van!!!\n");

printf("TOTAL RECAUDADO: %d \nMAXIMO VENDEDOR: Jugador %d \nVentas jug 1: %d\nVentas jug 2: %d\nVentas jug 3: %d\nVentas jug 4: %d", count_tot * 200, max_v, count1, count2, count3, count4);

}

void ej2() {
    int numero_secreto, numero_usuario, i;

    // semilla
    srand(time(NULL));

    // número secreto aleatorio entre 1 y 100
    numero_secreto = rand() % 100 + 1;
    printf("%d\n", numero_secreto);
    printf("He elegido un numero entre 1 y 100. \nTenes 5 intentos para adivinarlo.\n");

    for(i = 1 ; i <= 5 ; i++) {

        printf("\nIntento numero %d de 5: Ingresa tu numero: ", i);
        scanf("%d", &numero_usuario);
        getchar();

        if (numero_usuario == numero_secreto) {
            printf("¡Felicidades! Adivinaste el numero secreto: %d\n", numero_secreto);
            // si el jugador gana
            return;
        } else if (numero_usuario > numero_secreto) {
            if (numero_usuario - numero_secreto > 10) {
                printf("Tu ingreso fue mucho mayor!\n");
            } else {
                printf("Tu ingreso fue mayor!\n");
            }
        } else {
            if (numero_secreto - numero_usuario > 10) {
                printf("tu ingreso fue mucho menor!\n");
            } else {
                printf("tu ingreso fue menor!\n");
            }
        }
    }

    // Si se agotan los intentos, el jugador pierde
    printf("\nLo siento, has perdido. El número secreto era: %d\n", numero_secreto);

}

void ej3() {

    char palabra[50] = {0};
    int count_cons = 0, i = 0;

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    getchar();

    // Contamos cuántas consonantes hay en la palabra
    while(palabra[i] != '\0') {
        if (palabra[i] != 'a' && palabra[i] != 'A' && palabra[i] != 'e' && palabra[i] != 'E' && palabra[i] != 'i' && palabra[i] != 'I' && palabra[i] != 'o' && palabra[i] != 'O' && palabra[i] != 'u' && palabra[i] != 'U') {
            count_cons++;
            do {
            printf("Ingrese el numero que ira a la posicion de consonante numero %d: ", count_cons);
            scanf("%c", &palabra[i]);
            getchar();
            if (palabra[i] < 48 || palabra[i] > 57) {
                printf("Numero invalido. Debe ser entre 0 y 9.\n");
            }
            } while (palabra[i] < 48 || palabra[i] > 57);
        }
        i++;
    }

    // Imprimir la palabra resultante
    printf("La palabra modificada es: %s\n", palabra);

}

int main() {
    ej3();
    return 0;
}
