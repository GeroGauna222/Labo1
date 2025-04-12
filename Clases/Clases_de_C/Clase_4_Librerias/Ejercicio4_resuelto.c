/*
    Una posible resolucion del ejercicio 4.
    Fijense que estamos limitados con fechas entre 1970 a 2038 por como funciona la libraria time.h (Epoch)
*/

#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    // Este programa maneja fechas y calcula diferencias entre fechas.
    // Vas a poder ingresar una fecha y comparar con la fecha actual.

    // Variables para manejar las fechas
    time_t tiempo_actual;                                                                              // Acá guardamos el tiempo actual como timestamp
    struct tm fecha_usuario = {0};                                                                     // Estructura para la fecha que vos vas a ingresar
    char buffer[80];                                                                                   // Para formatear fechas como texto
    char entrada[12];                                                                                  // Para guardar lo que ingresás por teclado
    int dia, mes, anio;                                                                                // Variables para separar la fecha ingresada
    char *nombres_dias[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"}; // Días de la semana

    // 1. Obtenemos la hora actual del sistema
    tiempo_actual = time(NULL);

    // Convertimos la hora actual a un formato legible con strftime()
    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", localtime(&tiempo_actual));
    printf("Fecha y hora actual: %s\n", buffer);

    // 2. Te pedimos que ingreses una fecha para comparar
    printf("Ingresa una fecha (DD/MM/AAAA): ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // Sacamos el salto de línea que queda al final

    // Parseamos la fecha que ingresaste para separar día, mes y año
    if (sscanf(entrada, "%2d/%2d/%4d", &dia, &mes, &anio) != 3)
    {
        printf("Formato de fecha invalido. Debe ser DD/MM/AAAA.\n");
        return 1;
    }
    else
    {
        // Verificamos que los valores estén dentro de rangos lógicos
        if (dia > 31 || dia < 1 || mes > 12 || mes < 1)
        {
            printf("Formato de fecha invalido. Se excedio de valores posibles.\n");
            return 1;
        }
    }

    // Armamos la estructura tm con la fecha que ingresaste
    fecha_usuario.tm_mday = dia;         // Día del mes (1-31)
    fecha_usuario.tm_mon = mes - 1;      // En C los meses van de 0-11, por eso restamos 1
    fecha_usuario.tm_year = anio - 1900; // Los años se cuentan desde 1900
    fecha_usuario.tm_hour = 12;          // Ponemos mediodía para evitar quilombos con el horario de verano
    fecha_usuario.tm_min = 0;
    fecha_usuario.tm_sec = 0;
    fecha_usuario.tm_isdst = -1; // Que el sistema decida si es horario de verano

    // Convertimos la estructura a timestamp para poder hacer cálculos
    time_t tiempo_usuario = mktime(&fecha_usuario);

    // Chequeamos si la fecha que pusiste es válida
    if (tiempo_usuario == (time_t)-1)
    {
        printf("Error: La fecha ingresada no es válida o está fuera del rango soportado.\n");
        printf("Posibles razones:\n");
        printf("- El año ingresado está fuera del rango soportado por el sistema.\n");
        printf("- La fecha no existe (por ejemplo, 30/02/2023).\n");
        printf("- Hubo un error en la conversión interna de la fecha.\n");
        return 1;
    }

    // 3. Calculamos las diferencias entre la fecha actual y la que ingresaste
    // Primero sacamos los componentes del tiempo actual
    struct tm *info_actual = localtime(&tiempo_actual);
    int anio_actual = info_actual->tm_year + 1900;
    int mes_actual = info_actual->tm_mon + 1;
    int dia_actual = info_actual->tm_mday;

    // a. Calculamos la diferencia total en días (aproximada)
    double diferencia_segundos = difftime(tiempo_actual, tiempo_usuario);
    long long int dias_dif_total = (long long int)(diferencia_segundos / (60 * 60 * 24));

    // Mostramos cuánto falta o cuánto pasó según corresponda
    if (dias_dif_total > 0)
    {
        printf("Han pasado %lld dias desde esa fecha hasta hoy.\n", dias_dif_total);
    }
    else if (dias_dif_total < 0)
    {
        printf("Faltan %lld dias para esa fecha.\n", -dias_dif_total);
    }
    else
    {
        printf("Es hoy!\n");
    }

    // b. Averiguamos qué día de la semana es/era/será
    int dia_semana = fecha_usuario.tm_wday;

    printf("Esa fecha %s un %s.\n",
           (dias_dif_total > 0) ? "fue" : (dias_dif_total < 0) ? "sera"
                                                               : "es",
           nombres_dias[dia_semana]);

    // c. Ahora calculamos la diferencia más exacta en años, meses y días
    int anios_dif = anio_actual - anio;
    int meses_dif = mes_actual - mes;
    int dias_dif = dia_actual - dia;

    // Ajustamos los cálculos si los días dan negativo
    if (dias_dif < 0)
    {
        meses_dif--;
        dias_dif += 30; // Usamos 30 días por mes como aproximación
    }

    // Ajustamos si los meses dan negativo
    if (meses_dif < 0)
    {
        anios_dif--;
        meses_dif += 12;
    }

    // Elegimos el verbo según si la fecha es pasada o futura
    char *tiempo_verbo;
    double diferencia_tiempo = difftime(tiempo_actual, tiempo_usuario);

    if (diferencia_tiempo > 0)
    {
        tiempo_verbo = "han pasado";
    }
    else if (diferencia_tiempo < 0)
    {
        tiempo_verbo = "faltan";
        // Para fechas futuras, invertimos los valores
        anios_dif = -anios_dif;
        meses_dif = -meses_dif;
        dias_dif = -dias_dif;

        // Y volvemos a ajustar para que todo quede positivo
        if (dias_dif < 0)
        {
            meses_dif--;
            dias_dif += 30;
        }

        if (meses_dif < 0)
        {
            anios_dif--;
            meses_dif += 12;
        }

        // Nos aseguramos que todo sea positivo
        if (anios_dif < 0)
            anios_dif = -anios_dif;
        if (meses_dif < 0)
            meses_dif = -meses_dif;
        if (dias_dif < 0)
            dias_dif = -dias_dif;
    }
    else
    {
        tiempo_verbo = "transcurren";
    }

    // Mostramos el resultado final bien detallado
    printf("Exactamente %s %d anios, %d meses y %d dias.\n",
           tiempo_verbo, anios_dif, meses_dif, dias_dif);

    return 0;
}
