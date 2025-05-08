#include <stdio.h>
#include <stdlib.h> // Para rand, srand
#include <string.h> // Para funciones de cadenas (strcpy, strlen, strcat, etc.)
#include <time.h>   // Para time (para srand)

char minuscula(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

int es_vocal(char c)
{
    c = minuscula(c);
    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int es_consonante(char c)
{
    c = minuscula(c);
    return ((c >= 'a' && c <= 'z') && !es_vocal(c));
}

void ej1()
{
    char nombre_jugadores[20][31];
    int puntuaciones[20][5];
    int total_jugador[20] = {0};
    int dias_jugador[20] = {0};
    int cant_jugadores = 0;

    printf("Registro de jugadores(max 20)\n");
    for (int i = 0; i < 20; i++)
    {
        printf("Ingrese el nombre del jugador %d (o 'FIN' para terminar):", i + 1);
        fgets(nombre_jugadores[i], sizeof(nombre_jugadores[i]), stdin);
        nombre_jugadores[i][strcspn(nombre_jugadores[i], "\n")] = '\0';

        if (strcmp(nombre_jugadores[i], "FIN") == 0 || strcmp(nombre_jugadores[i], "fin") == 0)
        {
            break;
        }
        cant_jugadores++;
    }
    if (cant_jugadores == 0)
    {
        printf("No se inscribio nadie.");
        return;
    }

    for (int i = 0; i < 5; i++)
    { // Para dias 0-4
        printf("\n *** DIA %d ***\n", i + 1);
        for (int j = 0; j < cant_jugadores; j++)
        { // Para los jugadores
            printf(" Ingresar puntuacion para %s (0-1000, -1 si no jugo): ", nombre_jugadores[j]);
            scanf("%d", &puntuaciones[j][i]);
            getchar();
            while ((puntuaciones[j][i] < 0 || puntuaciones[j][i] > 1000) && puntuaciones[j][i] != -1)
            {
                printf(" Puntuacion invalida (0-1000 o -1 si no jugo): ");
                scanf("%d", &puntuaciones[j][i]);
                getchar();
            }
            if (puntuaciones[j][i] != -1)
            {
                total_jugador[j] += puntuaciones[j][i];
                dias_jugador[j]++;
            }
        }

        printf(" Reporte del dia %d:\n", i + 1);
        for (int j = 0; j < cant_jugadores; j++)
        {
            if (puntuaciones[j][i] != -1)
            {
                printf(" Jugador: %s, Puntuacion: %d\n", nombre_jugadores[j], puntuaciones[j][i]);
            }
        }
    }
    printf("\n --- REPORTE SEMANAL --- \n");
    printf("\n ** Puntuaciones totales **\n");
    for (int j = 0; j < cant_jugadores; j++)
    {
        printf(" Jugador: %s, Puntuacion Total: %d\n", nombre_jugadores[j], total_jugador[j]);
    }

    int max_puntos = -1, id_campeon = -1;
    for (int j = 0; j < cant_jugadores; j++)
    {
        if (total_jugador[j] > max_puntos)
        {
            max_puntos = total_jugador[j];
            id_campeon = j;
        }
    }
    printf("\n** Campeon de la semana: %s con %d puntos **\n", nombre_jugadores[id_campeon], max_puntos);
    printf("\n** Dias Jugados por jugador **\n");
    for (int j = 0; j < cant_jugadores; j++)
    {
        printf(" Jugador: %s, Dias Jugados: %d\n", nombre_jugadores[j], dias_jugador[j]);
    }

    printf("\n** Promedio de puntos por dia jugado **\n");
    for (int j = 0; j < cant_jugadores; j++)
    {
        float promedio = (float)total_jugador[j] / dias_jugador[j];
        printf(" Jugador: %s, Promedio: %.2f\n", nombre_jugadores[j], promedio);
    }
}

void ej3()
{
    printf("\n--- Ejercicio 3 ---\n");
    char oracion[500];
    char oracion_procesada[500];
    char modo_operacion;
    int i = 0;
    printf("Ingrese la oracion: ");
    fgets(oracion, sizeof(oracion), stdin);
    oracion[strcspn(oracion, "\n")] = '\0';

    do
    {
        printf("Queres (C)odificar o (D)ecodificar?: ");
        scanf(" %c", &modo_operacion);
        getchar();
        modo_operacion = minuscula(modo_operacion);
        if (modo_operacion != 'c' && modo_operacion != 'd')
        {
            printf("Opcion invalida.\n");
        }
    } while (modo_operacion != 'c' && modo_operacion != 'd');

    for (i = 0; oracion[i] != '\0' && i < 499; i++)
    {
        char caracter_actual = oracion[i];
        caracter_actual = minuscula(caracter_actual);
        char caracter_procesado = caracter_actual;

        if (modo_operacion == 'c')
        {
            if (es_vocal(caracter_actual))
            {
                switch (caracter_actual)
                {
                case 'a':
                    caracter_procesado = '1';
                    break;
                case 'e':
                    caracter_procesado = '2';
                    break;
                case 'i':
                    caracter_procesado = '3';
                    break;
                case 'o':
                    caracter_procesado = '4';
                    break;
                case 'u':
                    caracter_procesado = '5';
                    break;
                }
            } // abcdefghj...yz
            else if (es_consonante(caracter_actual))
            {
                if (caracter_actual != 'z')
                {
                    if (es_vocal(caracter_actual + 1))
                    {
                        caracter_procesado = caracter_actual + 2;
                    }
                    else
                    {
                        caracter_procesado = caracter_actual + 1;
                    }
                }
                else
                {
                    caracter_procesado = 'b';
                }
            }
        }
        else
        {
            if (caracter_actual >= '1' && caracter_actual <= '5')
            {
                switch (caracter_actual)
                {
                case '1':
                    caracter_procesado = 'a';
                    break;
                case '2':
                    caracter_procesado = 'e';
                    break;
                case '3':
                    caracter_procesado = 'i';
                    break;
                case '4':
                    caracter_procesado = 'o';
                    break;
                case '5':
                    caracter_procesado = 'u';
                    break;
                }
            }
            else if (es_consonante(caracter_actual))
            {
                if (caracter_actual != 'b')
                {
                    if (es_vocal(caracter_actual - 1))
                    {
                        caracter_procesado = caracter_actual - 2;
                    }
                    else
                    {
                        caracter_procesado = caracter_actual - 1;
                    }
                }
                else
                {
                    caracter_procesado = 'z';
                }
            }
        }
        oracion_procesada[i] = caracter_procesado;
    }
    oracion_procesada[i] = '\0';
    printf("Oracion original: %s\n", oracion);
    printf("Oracion procesada: %s\n", oracion_procesada);
}

void ej2()
{
    printf("\n ** EJERCICIO 2 ** \n");

    int eleccion_jugador, eleccion_computadora;
    int ganadas_jugador = 0, ganadas_compu = 0, empates = 0;
    int eleccion_jugador_anterior = 0;
    int eleccion_pc_anterior = 0;
    int ganador_anterior = 0; // 0 empate, 1 jugador, 2 pc
    int jugar_otra_vez = 1;
    srand(time(NULL));

    do
    {
        printf(" ** Nueva ronda **\n");
        printf("1:Piedra, 2:Papel, 3:Tijeras: ");
        scanf("%d", &eleccion_jugador);
        getchar();

        while (eleccion_jugador < 1 || eleccion_jugador > 3)
        {
            printf("Eleccion invalida, 1:Piedra, 2:Papel, 3:Tijeras: ");
            scanf("%d", &eleccion_jugador);
            getchar();
        }

        if (ganador_anterior == 2)
        {
            if (rand() % 2 == 0)
            {
                eleccion_computadora = eleccion_pc_anterior;
            }
            else
            {
                eleccion_computadora = rand() % 3 + 1;
            }
        }
        else if (ganador_anterior == 1)
        {
            if (eleccion_jugador_anterior == 1)
                eleccion_computadora = 2;
            else if (eleccion_jugador_anterior == 2)
                eleccion_computadora = 3;
            else
                eleccion_computadora = 1;
        }
        else
        {
            eleccion_computadora = rand() % 3 + 1;
        }

        printf("Jugador eligio: ");
        if (eleccion_jugador == 1)
            printf("Piedra\n");
        else if (eleccion_jugador == 2)
            printf("Papel\n");
        else
            printf("Tijeras\n");
        printf("Computadora eligio: ");
        if (eleccion_computadora == 1)
            printf("Piedra\n");
        else if (eleccion_computadora == 2)
            printf("Papel\n");
        else
            printf("Tijeras\n");

        eleccion_pc_anterior = eleccion_computadora;

        if (eleccion_jugador == eleccion_computadora)
        {
            printf("Empate\n");
            empates++;
            ganador_anterior = 0;
        }
        else if (eleccion_jugador == 1 && eleccion_computadora == 3 ||
                 eleccion_jugador == 2 && eleccion_computadora == 1 ||
                 eleccion_jugador == 3 && eleccion_computadora == 2)
        {
            printf("Gano jugador\n");
            ganadas_jugador++;
            ganador_anterior = 1;
            eleccion_jugador_anterior = eleccion_jugador;
        }
        else
        {
            printf("Gano computadora\n");
            ganadas_compu++;
            ganador_anterior = 2;
        }

        printf("Marcador: Jugador %d - Computadora %d - Empates %d\n", ganadas_jugador, ganadas_compu, empates);
        printf("Queres jugar otra ronda? (1 para si, 0 para no)");
        scanf("%d", &jugar_otra_vez);
        getchar();
    } while (jugar_otra_vez == 1);
}
int main()
{
    ej2(); // ej1(); ej3();
    return 0;
}
