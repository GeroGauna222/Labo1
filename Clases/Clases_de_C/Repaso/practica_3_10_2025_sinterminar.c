
// No se olviden... esto está sin terminar y es MUY mejorable... trabajen sobre esto y fijense la mejor implementación o la más conveniente... 
// tambien acuerdense de venir con sus ideas de casa ya trabajadas... les juro les ahorra siglos de quilombo. Mucha suerte 

#include <stdio.h>
#include <stdlib.h> // Para rand, srand
#include <string.h> // Para funciones de cadenas (strcpy, strlen, strcat, etc.)
#include <time.h>   // Para time (para srand)
#define MAX_ITEMS 200


void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void ej2(){
    int hp=100, dado, dano, op;
    char event[20] = {0};
    srand(time(NULL));

    for(int i=0; i<3; i++) {
        printf("tirada de dado numero %d\n toque enter para tirar el dado\n", i+1);
        getchar();
        dado = (rand() % 10) + 1;
        printf("saco %d\n",dado);

        if (dado<5) { // trampa
            strcpy(event,"trampa");
            printf("TRAMPA\nEscoja una de las siguientes opciones:\n Correr (tocar 1)\n Desactivar (tocar 0)\n");
            do {
                scanf("%d", &op);
                limpiarBuffer();
            } while (op < 0 || op > 1);

            if (op==1) { // correr
                dano = 5 + (rand() % 11);
                printf("da�o recibido: %d\n", dano);
            } else { // desactivar
                printf("toque enter para tirar el dado\n");
                getchar();
                dado = (rand() % 6) + 1;
                printf("saco %d\n",dado);
                if (dado < 4) {
                    printf("no recibe da�o\n");
                    dano = 0;
                }
                else {
                    dano = 10 + (rand() % 11);
                    printf("da�o recibido: %d\n", dano);
                }
            }
        } else if(dado > 7) { // dragon
            strcpy(event,"dragon");
            printf("BEBE DRAGON\nEscoja una de las siguientes opciones:\n Correr hacia el (tocar 1)\n Esconderse (tocar 0)\n");
            do {
                scanf("%d", &op);
                limpiarBuffer();
            } while (op < 0 || op > 1);

            if (op==1) {
                int safe;
                safe = 1 + (rand() % 2);
                if (safe == 1) {
                    dano = 35;
                    printf("da�o recibido: %d", dano);
                } else {
                    dano = 0;
                    printf("da�o recibido: %d", dano);
                }
            } else {
                dano = rand() % 51;
                printf("da�o recibido: %d", dano);
            }
        } else { // cofre
            strcpy(event,"cofre");
            printf("COFRE\nEscoja una de las siguientes opciones:\n Abrir)\n Ignorar (tocar 0)\n");
            do {
                scanf("%d", &op);
                limpiarBuffer();
            } while (op < 0 || op > 1);

            if (op==1) { // Abrir
                int safe;
                safe = 1 + (rand() % 2);
                if (safe == 1) { // pocion
                    printf("Pocion de vida!!!!!");
                    dano = -(10 + (rand() % 16));
                    printf("hp recibido: %d", -dano);
                } else { // bomba
                    dano = 5 + (rand() % 11);
                    printf("da�o recibido: %d", dano);
                }
            } else { // Ignorar
                dano = 0;
                printf("Cofre ignorado", dano);
            }
        }
        hp -= dano;
        if (hp <= 0) {
            printf("perdiste");
            return;
        }
        printf("HP: %d\nEVENTO: %s\nNIVEL: %d\n", hp, event, i+1);
    }
    printf("ganaste");
}

void ej1(){
    int op, item, cantidad_item, total_dia=0, cantidad_cafe=0, cantidad_tost=0, cantidad_ml=0, cantidad_jugo=0;
    int scan_max_ventas[4]={0};
    float cantidad_pedidos=0;

    do {
        printf("*************************************\n");
        printf("-----------------MENU--------------------\n");
        printf("*************************************\n");
        printf("elija una opci�n :\n 1) Ingresar un pedido \n2) Mostrar Subtotal \n3) Mostrar item mas vendido \n4) Mostrar ticket promedio del dia \n 5) Fin de la jornada \n");
        scanf("%d", &op);
        switch(op) {
        case 1:
            do {
                printf("elija una opci�n:\n 1)Cafe \n2)Medialuna \n3)Tostado  \n4)Jugo \n");
                scanf("%d", &item);
                if (item < 1 || item > 4) {
                    printf("\n**OPCION INVALIDA**\n");
                }
            } while(item < 1 || item > 4);

            do {
                printf("qu� cantidad desea de este item?\n");
                scanf("%d", &cantidad_item);
                if (cantidad_item < 1) {
                    printf("\n**CANTIDAD INVALIDA**\n");
                }
            } while(cantidad_item < 1);

            total_dia += cantidad_item;
            if (total_dia > MAX_ITEMS) {
                printf("se excede la cantidad de items a vender en el d�a, cantidad vendida: %d", total_dia);
                total_dia -= cantidad_item;
                break;
            }

            switch(item) {
            case 1:
                cantidad_cafe += cantidad_item;
                break;
            case 2:
                cantidad_ml += cantidad_item;
                break;
            case 3:
                cantidad_tost += cantidad_item;
                break;
            case 4:
                cantidad_jugo += cantidad_item;
                break;
            }

            cantidad_pedidos += 1;

            break;
        case 2:
            printf("Cantidades de ventas:\nCafes: %d\nMLs: %d\nTostados: %d\nJuguitos: %d\n", cantidad_cafe, cantidad_ml, cantidad_tost, cantidad_jugo);
            break;
        case 3:
            // a resolver
            break;
        case 4:
            if (cantidad_pedidos == 0) {
                printf("sin datos\n");
            } else {
                float promedio;
                promedio = total_dia / cantidad_pedidos;
                printf("promedio: %.2f\n", promedio);
            }
            break;
        case 5:
            printf("Fin de la jornada\n");
            break;
        default:
            printf("++++++++++OPCION INV�LIDA++++++++++++\n");
            break;
        }

    } while(op!=5);

    // lo que pasa al finalizar el dia
    return;
}


int main()
{
    ej2(); // ej3();
    return 0;
}
