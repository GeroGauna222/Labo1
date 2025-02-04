#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ej1() {
    int c, ch, pago1 = 0, pago2 = 0, pago3 = 0, pago4 = 0, ch2, max_v, libros, hora, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count_tot = 0, count_dia, count1_dia, count2_dia, count3_dia, count4_dia;
    char clase_De_libro[50];


    for(int i=0 ; i < 7 ; i++) {
        count_dia = 0;
        count1_dia = 0;
        count2_dia = 0;
        count3_dia = 0;
        count4_dia = 0;
        printf("DIA %d DE VENTAS\n", i+1);
        do {
            printf("Ingrese quien vino a retirar un libro\n1) Socio 1 \n2) Socio 2 \n3) Socio 3 \n4) Socio 4 \nSi quiere detener el ingreso de este dia, presione 'F' \n");
            scanf("%d", &ch);
            getchar();
            while(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 'F') {
                printf("Ingreso un valor no valido");
                printf("Ingrese quien vino a retirar un libro\n1) Socio 1 \n2) Socio 2 \n3) Socio 3 \n4) Socio 4 \nSi quiere detener el ingreso de este dia, presione 'F' \n");
                scanf("%d", &ch);
                getchar();
            }

            if (ch == 'F') {
                printf("\n------------Finaliza el dia--------------\n");
            }
            else {
                printf("Ingrese el genero de libro que busca: ");
                fgets(clase_De_libro, sizeof(clase_De_libro), stdin);
                if(strchr(clase_De_libro, '\n') == NULL) {
                    while ((c = getchar()) != '\n' && c != EOF);
                } else {
                    clase_De_libro[strcspn(clase_De_libro,"\n")] = '\0';
                }
                
                printf("Ingrese cuantos libros desea llevar (1 a 3): ");
                scanf("%d", &libros);
                getchar();
                
                while(libros < 1 || libros > 3) {
                    printf("Ingreso un valor no valido");
                    printf("Ingrese cuantos libros desea llevar (1 a 3): ");
                    scanf("%d", &libros);
                    getchar();
                }

                switch (ch) {
                case 1:
                    if (count1_dia + libros > 3) {
                        printf("Usted superaria la cantidad diaria permitida de libros para llevarse, por lo que su ingreso es invalidado\n");
                        ch2 = 0;
                    }
                    else {
                        printf("Ingrese el horario de retiro: ");
                        scanf("%d", &hora);
                        getchar();
                        
                        while(hora < 8 || hora > 18) {
                            printf("Ingreso un valor no valido");
                            printf("Ingrese el horario de retiro: ");
                            scanf("%d", &hora);
                            getchar();
                            }
                        ch2 = 1;
                    }
                    break;
                case 2:
                    if (count2_dia + libros > 3) {
                        printf("Usted superaria la cantidad diaria permitida de libros para llevarse, por lo que su ingreso es invalidado\n");
                        ch2 = 0;
                    }
                    else {
                        printf("Ingrese el horario de retiro: ");
                        scanf("%d", &hora);
                        getchar();
                        
                        while(hora < 8 || hora > 18) {
                            printf("Ingreso un valor no valido");
                            printf("Ingrese el horario de retiro: ");
                            scanf("%d", &hora);
                            getchar();
                            }
                        ch2 = 1;
                    }
                    break;
                case 3:
                    if (count3_dia + libros > 3) {
                        printf("Usted superaria la cantidad diaria permitida de libros para llevarse, por lo que su ingreso es invalidado\n");
                        ch2 = 0;
                    }
                    else {
                        printf("Ingrese el horario de retiro: ");
                        scanf("%d", &hora);
                        getchar();
                        
                        while(hora < 8 || hora > 18) {
                            printf("Ingreso un valor no valido");
                            printf("Ingrese el horario de retiro: ");
                            scanf("%d", &hora);
                            getchar();
                            }
                        ch2 = 1;
                    }
                    break;
                case 4:
                    if (count4_dia + libros > 3) {
                        printf("Usted superaria la cantidad diaria permitida de libros para llevarse, por lo que su ingreso es invalidado\n");
                        ch2 = 0;
                    }
                    else {
                        printf("Ingrese el horario de retiro: ");
                        scanf("%d", &hora);
                        getchar();
                        
                        while(hora < 8 || hora > 18) {
                            printf("Ingreso un valor no valido");
                            printf("Ingrese el horario de retiro: ");
                            scanf("%d", &hora);
                            getchar();
                            }
                        ch2 = 1;
                    }
                    break;
                }

                if(ch2 == 0) {
                    break;
                }
                
                switch (ch) {
                case 1:
                    count1 += libros;
                    count1_dia += libros;
                    break;
                case 2:
                    count2 += libros;
                    count2_dia += libros;
                    break;
                case 3:
                    count3 += libros;
                    count3_dia += libros;
                    break;
                case 4:
                    count4 += libros;
                    count4_dia += libros;
                    break;
                }

                printf("Socio nro %d\n", ch);
                printf("Hora de retiro: %d\n", hora);
                printf("Cantidad de libros retirados: %d\n", libros);
                printf("Clase de libro: %s\n", clase_De_libro);
            }

        } while(ch != 0);

        printf("-------------------\nFIN DEL DIA\n---------------------------\n");
        
        printf("Retiros socio 1: %d\nRetiros socio 2: %d\nRetiros socio 3: %d\nRetiros socio 4: %d\n", count1_dia, count2_dia, count3_dia, count4_dia);
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

    if(count1 > 10) {
        pago1 = (count1 - 10) * 1000;
    }
    else {
        pago1 = 0;
    }
    if(count2 > 10) {
        pago2 = (count2 - 10) * 1000;
    }
    else {
        pago2 = 0;
    }
    if(count3 > 10) {
        pago3 = (count3 - 10) * 1000;
    }
    else {
        pago3 = 0;
    }
    if(count4 > 10) {
        pago4 = (count4 - 10) * 1000;
    }
    else {
        pago4 = 0;
    }

    printf("TOTAL ALQUILERES: %d \nQUIEN MAS ALQUILO: Socio %d \nDeuda socio 1: %d\nDeuda socio 2: %d\nDeuda socio 3: %d\nDeuda socio 4: %d", count_tot, max_v, pago1, pago2, pago3, pago4);

}

void ej2() {
    
}

void ej3() {

    char palabra[50] = {0};
    int count_cons = 0, i = 0, c;

    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);
    if(strchr(palabra, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF);
    } else {
        palabra[strcspn(palabra,"\n")] = '\0';
    }

    // Contamos cuántas consonantes hay en la palabra
    while(palabra[i] != '\0') {
        if (palabra[i] < 65 && palabra[i] > 90) {
            palabra[i] = palabra[i] + 32;
        }
        
        switch (palabra[i]) {
        case 'j':
            palabra[i] = '1';
            break;
        case 'a':
            palabra[i] = '4';
            break;
        case 'o':
            palabra[i] = '0';
            break;
        case 'b':
            palabra[i] = '6';
            break;
        default:
            break;
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