# Simulacro

## Ejercicio 1: "Food Truck del Campus" 
> (Menú con cupo y acumuladores)

Un nuevo Food Truck se instaló en el campus y vende tres combos principales: 
- Tasty:
  - Doble ($4000)
  - Simple ($3000)
- Pancho:
  - c/ Papitas ($2000)
  - Simple ($1000)
- Papas:
  - Simples ($1000)
  - c/ Bacon ($2000)

Implementar un programa por menú para registrar las ventas del turno mediodía.

### Reglas y límites
Por cuestiones de stock, el total de ítems vendidos en el turno no puede superar las **80 unidades**.
Cada venta registra un solo tipo de producto y su respectiva cantidad.

### Menú:
1. Registrar Venta
  - Pedir producto: (1) Hamburguesa, (2) Pancho, (3) Papas Fritas.
  - Pedir variante (1/2)
  - Pedir cantidad (entero > 0).
Si la cantidad ingresada hace superar el límite de 80 ítems totales en el día, rechazar la operación y avisar al usuario.
Si hay stock suficiente, registrar la venta y acumular la cantidad y el dinero recaudado.

2. Estado de Caja
 - Mostrar las cantidades vendidas acumuladas por cada producto base y la recaudación total del día (cuánta plata hay en la caja).

3. Producto Estrella
  - Indicar claramente cuál de los tres productos fue el más vendido en cantidad de unidades (no contemplar casos de empate).

4. Finalizar Turno
  - Imprimir un ticket de cierre con: Total de ítems vendidos, recaudación total, y terminar el programa.

### Notas
Usar al menos una estructura do...while para el menú y switch para las opciones.  Validar las entradas (opciones del 1 al 4, cantidades mayores a 0).

## Ejercicio 2: "Escape de Chernobyl"

Sos el ultimo cientifico que queda intentando escapar de la Central Nuclear de Chernobyl, tenes que escaparte pasando por 3 Zonas.

### Inicio y Condiciones

**Vida:** 100

**Tiempo:** 200

Si tu vida **llega a 0** o bien **el tiempo llega a 0** en ese caso **perdes**

### Zona

Cada Zona tiene un *Monstruo Nuclear*

Random del 1 al 10 por zona:
- 1 al 4: *Pajaro Nuclear*
- 5 al 7: *Perro Nuclear*
- 8 al 10: *Oso Nuclear*

Elegir:
1. *Correr*
2. *Pelear*
3. *Sigilo*

### Pajaro
- Correr: perdes [25 a 35] Vida || [5 a 10] Tiempo
- Pelear: perdes [5 a 20] Vida || [20 a 30] Tiempo
- Sigilo: perdes [0 a 20] Vida || [30 a 40] Tiempo

### Perro
- Correr: perdes [35 a 65] Vida || [5 a 10] Tiempo
- Pelear: perdes [5 a 30] Vida || [20 a 50] Tiempo
- Sigilo: perdes [0 a 20] Vida || [40 a 60] Tiempo

### Oso
- Correr: perdes [35 a 100] Vida || [5 a 10] Tiempo
- Pelear: perdes [25 a 100] Vida || [20 a 70] Tiempo
- Sigilo: perdes [0 a 100] Vida || [40 a 80] Tiempo

### Condiciones
- Despues de cada zona mostrar que Monstruo enfrentaste, que accion decidiste tomar, cuanto puntos perdiste de timepo y visa y totales actuales
- Si perdes, informar totales y zona de derrota
- Si ganas informar totales finales
- **Usar srand y rand para aleatorios teniendo en cuenta los rangos**

## Ejercicio 3
Sos un hacker, tenes que interceptar mensajes de Anthropic y codificarlos para complicar el trabajo interno de la compañía. Debe transformarse el mensaje siguiendo las siguientes reglas:

1. Minúsculas: se pasan a Mayus y se desplazan 3 a la derecha en el abecedario
2. Mayúsculas: se pasan a Minus y se desplazan 2 a la izquierda en el abecedario
3. **SI CON EL MOVIMIENTO TE PASAS DE LA ULTIMA/PRIMERA LETRA DEL ABECEDARIO** dar la vuelta empezar desde el lado contrario ('*a*' a la izquierda es '*z*')
4. Espacios: se vuelven guiones bajos si la letra previa es Mayus, sino se vuelven '*&*'
5. Digitos y otros simbolos **NO CAMBIAN**

### Condicion
**ESTA PROHIBIDO EL USO DE ctype.h**
{
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <string.h>
    #include <ctype.h>
    
    void ej1(){
    
        int opcion = 0, opcion2 = 0, variante = 0, cantidad = 0, total_items = 0,total_ventas = 0, total_panchos = 0, total_hamburguesas = 0, total_papas = 0, precio = 0;
    
        do {
            printf("***********************************************\n");
            printf("           CAJERO DEL FOOD TRUCK         \n");
            printf("***********************************************\n");
            printf("1. Registrar Venta\n");
            printf("2. Estado de Caja\n");
            printf("3. Producto Estrella del día\n");
            printf("4. Fin de Turno\n");
    
            do {
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion);
                if (opcion < 1 || opcion > 4){
                    printf("Opción Invalida. Ingrese un numero del 1 al 4\n");
                }
            } while (opcion < 1 || opcion > 4);
    
            switch (opcion) {
                case 1:
                    printf("----- NUEVA VENTA -----\n");
                    printf("1. Hamburguesa\n");
                    printf("2. Pancho\n");
                    printf("3. Papas Fritas\n");
    
                    do {
                        printf("Ingrese una opcion: ");
                        scanf("%d", &opcion2);
                        if (opcion2 < 1 || opcion2 > 3){
                            printf("Opción Invalida. Ingrese un numero del 1 al 3\n");
                        }
                    } while (opcion2 < 1 || opcion2 > 3);
    
                    switch (opcion2) {
                        case 1:
                            printf("1. Doble\n");
                            printf("2. Simple\n");
    
                            do {
                                printf("Ingrese una opcion: ");
                                scanf("%d", &variante);
                                if (variante < 1 || variante > 2){
                                    printf("Opción Invalida. Ingrese 1 o 2\n");
                                }
                            } while (variante < 1 || variante > 2);
    
    
                            do {
                                printf("Ingresar cantidad del producto: ");
                                scanf("%d", &cantidad);
                                if (cantidad <= 0){
                                    printf("Entrada inválida, no podes pedir cero o menos\n");
                                }
                            } while (cantidad <= 0);
    
                            if (total_items + cantidad > 80) {
                                printf("Se rechazó la venta porque no hay stock para realizar la misma\n");
                                printf("Items vendidos: %d \nVenta Rechazada: %d\n", total_items, cantidad);
                            } else {
                                if (variante == 1) {
                                    total_ventas += cantidad * 4000;
                                } else {
                                    total_ventas += cantidad * 3000;
                                }
    
                                total_hamburguesas += cantidad;
                                total_items += cantidad;
    
                                printf("Items vendidos: %d \nHamburguesas vendidas: %d\n", total_items, total_hamburguesas);
                            }
    
                            break;
                        case 2:
                            printf("1. c/Papitas\n");
                            printf("2. Simple\n");
    
                            do {
                                printf("Ingrese una opcion: ");
                                scanf("%d", &variante);
                                if (variante < 1 || variante > 2){
                                    printf("Opción Invalida. Ingrese 1 o 2\n");
                                }
                            } while (variante < 1 || variante > 2);
    
    
                            do {
                                printf("Ingresar cantidad del producto: ");
                                scanf("%d", &cantidad);
                                if (cantidad <= 0){
                                    printf("Entrada inválida, no podes pedir cero o menos\n");
                                }
                            } while (cantidad <= 0);
    
                            if (total_items + cantidad > 80) {
                                printf("Se rechazó la venta porque no hay stock para realizar la misma\n");
                                printf("Items vendidos: %d \nVenta Rechazada: %d\n", total_items, cantidad);
                            } else {
                                if (variante == 1) {
                                    total_ventas += cantidad * 2000;
                                } else {
                                    total_ventas += cantidad * 1000;
                                }
    
                                total_panchos += cantidad;
                                total_items += cantidad;
    
                                printf("Items vendidos: %d \nPanchos vendidas: %d\n", total_items, total_panchos);
                            }
                            break;
                        case 3:
                            printf("1. Comunes\n");
                            printf("2. c/Bacon\n");
    
                            do {
                                printf("Ingrese una opcion: ");
                                scanf("%d", &variante);
                                if (variante < 1 || variante > 2){
                                    printf("Opción Invalida. Ingrese 1 o 2\n");
                                }
                            } while (variante < 1 || variante > 2);
    
    
                            do {
                                printf("Ingresar cantidad del producto: ");
                                scanf("%d", &cantidad);
                                if (cantidad <= 0){
                                    printf("Entrada inválida, no podes pedir cero o menos\n");
                                }
                            } while (cantidad <= 0);
    
                            if (total_items + cantidad > 80) {
                                printf("Se rechazó la venta porque no hay stock para realizar la misma\n");
                                printf("Items vendidos: %d \nVenta Rechazada: %d\n", total_items, cantidad);
                            } else {
                                if (variante == 1) {
                                    total_ventas += cantidad * 1000;
                                } else {
                                    total_ventas += cantidad * 2000;
                                }
    
                                total_papas += cantidad;
                                total_items += cantidad;
    
                                printf("Items vendidos: %d \nPapas vendidas: %d\n", total_items, total_papas);
                            }
                            break;
                    }
                    break;
                case 2:
                    printf("-----ESTADO DE CAJA-----\n");
                    printf("Cantidad vendida de cada producto: \n");
                    printf("Hamburguesas: %d\n", total_hamburguesas);
                    printf("Panchos: %d\n", total_panchos);
                    printf("Papas: %d\n", total_papas);
                    printf("---------------------------\n");
                    printf("Acumulacion del Turno: %d\n", total_ventas);
                    break;
                case 3:
                    printf("-----PRODUCTO ESTRELLA-----\n");
                    if (total_items == 0) {
                        printf("No hay ventas registradas todavia\n");
                    } else {
                        printf("El producto mas vendido es: \n");
                        if (total_hamburguesas > total_panchos && total_hamburguesas > total_papas) {
                            printf("Burgas\n");
                        } else if (total_panchos > total_hamburguesas && total_panchos > total_papas){
                            printf("Panchos\n");
                        } else if (total_papas > total_hamburguesas && total_papas > total_panchos){
                            printf("Papas\n");
                        } else {
                            printf("No hay producto estrella único por el momento\n");
                            printf("Hamburguesas: %d\n", total_hamburguesas);
                            printf("Panchos: %d\n", total_panchos);
                            printf("Papas: %d\n", total_papas);
                        }
                    }
                    break;
                case 4:
                    printf("Gracias por operar el Turno del Mediodia.\n");
                    printf("---------------------------\n");
                    printf("Items Vendidos del Turno: %d\n", total_items);
                    printf("---------------------------\n");
                    printf("Recaudaciones Finales del Turno: %d\n", total_ventas);
                    break;
                default:
                    printf("Opción invalida.\n");
            }
        } while (opcion != 4);
    
    }
    
    void ej2(){
        srand(time(NULL));
        int vida = 100, tiempo = 200;
        int evento, accion;
        int daño_vida = 0, gasto_tiempo = 0;
    
        for (int zona = 1; zona <=3; zona++){
            printf("INGRESANDO A ZONA %d\n", zona);
            evento = (rand() % 10) + 1;
    
            if (evento >= 1 && evento <= 4) {
                printf("Aparecio un PAJARO NUCLEAR\n");
            } else if (evento >= 5 && evento <= 7) {
                printf("Aparecio un PERRO NUCLEAR\n");
            } else {
                printf("Aparecio un imponente OSO NUCLEAR\n");
            }
    
            do {
                printf("\nQue vas a hacer?\n");
                printf("1. Correr\n");
                printf("2. Pelear\n");
                printf("3. Sigilo\n");
                printf("Tu eleccion: ");
                scanf("%d", &accion);
    
                if (accion < 1 || accion > 3) {
                    printf("Opcion invalida. Decidite rapido que la radiacion subeeeeee\n");
                }
            } while (accion < 1 || accion > 3);
    
            if (evento >= 1 && evento <= 4) { // PAJARO
                switch(accion) {
                    case 1: // Correr
                        daño_vida = (rand() % (35 - 25 + 1)) + 25;
                        gasto_tiempo = (rand() % (10 - 5 + 1)) + 5;
                        break;
                    case 2: // Pelear
                        daño_vida = (rand() % (20 - 5 + 1)) + 5;
                        gasto_tiempo = (rand() % (30 - 20 + 1)) + 20;
                        break;
                    case 3: // Sigilo
                        daño_vida = (rand() % (20 - 0 + 1)) + 0;
                        gasto_tiempo = (rand() % (40 - 30 + 1)) + 30;
                        break;
                }
            }
            else if (evento >= 5 && evento <= 7) { // PERRO
                switch(accion) {
                    case 1: // Correr
                        daño_vida = (rand() % (65 - 35 + 1)) + 35;
                        gasto_tiempo = (rand() % (10 - 5 + 1)) + 5;
                        break;
                    case 2: // Pelear
                        daño_vida = (rand() % (30 - 5 + 1)) + 5;
                        gasto_tiempo = (rand() % (50 - 20 + 1)) + 20;
                        break;
                    case 3: // Sigilo
                        daño_vida = (rand() % (20 - 0 + 1)) + 0;
                        gasto_tiempo = (rand() % (60 - 40 + 1)) + 40;
                        break;
                }
            }
            else { // OSO
                switch(accion) {
                    case 1: // Correr
                        daño_vida = (rand() % (100 - 35 + 1)) + 35;
                        gasto_tiempo = (rand() % (10 - 5 + 1)) + 5;
                        break;
                    case 2: // Pelear
                        daño_vida = (rand() % (100 - 25 + 1)) + 25;
                        gasto_tiempo = (rand() % (70 - 20 + 1)) + 20;
                        break;
                    case 3: // Sigilo
                        daño_vida = (rand() % (100 - 0 + 1)) + 0;
                        gasto_tiempo = (rand() % (80 - 40 + 1)) + 40;
                        break;
                }
            }
    
            // Sumamos el efecto de la zona
            vida -= daño_vida;
            tiempo -= gasto_tiempo;
    
            printf("\n--- REPORTE DE ZONA %d ---\n", zona);
            printf("Perdiste %d puntos de Vida y %d unidades de Tiempo.\n", daño_vida, gasto_tiempo);
    
            // Chequeamos condición de derrota
            if (vida <= 0 || tiempo <= 0) {
                printf("MUERTO EN LA ZONA %d\n", zona);
                if (vida <= 0) {
                    printf("Motivo: Los ataques acabaron con tu vida\n");
                    printf("ESTADO ACTUAL -> Vida: 0 | Tiempo: %d\n\n", tiempo);
                }
                if (tiempo <= 0) {
                    printf("Motivo: Te quedaste sin tiempo y el reactor colapso\n");
                    printf("ESTADO ACTUAL -> Vida: %d | Tiempo: 0\n\n", vida);
                }
                break;
            }
            printf("ESTADO ACTUAL -> Vida: %d | Tiempo: %d\n\n", vida, tiempo);
        }
        if (vida > 0 && tiempo > 0) {
            printf("Felicitaciones Campeon Ganaste!!!\n");
        }
    }
    
    void ej3(){
        // Buffer
        char mensaje[200];
    
        // Variable para recordar el carácter anterior (para la regla de los espacios)
        // Se inicializa en '\0' para que el primer carácter no rompa la lógica.
        char letra_previa = '\0';
    
        printf("=== TERMINAL DE INTERCEPCIÓN ===\n");
        printf("Ingrese el texto plano a ofuscar:\n> ");
    
        // Leemos de forma segura con fgets
        if (fgets(mensaje, sizeof(mensaje), stdin) != NULL) {
    
            // Iteramos hasta encontrar el fin de la cadena o el salto de línea de fgets
            for (int i = 0; mensaje[i] != '\0' && mensaje[i] != '\n'; i++) {
    
                // Guardamos el carácter original ANTES de modificarlo,
                // Lo necesitamos conocer para evaluar la letra_previa en la siguiente vuelta.
                char original = mensaje[i];
                char c = mensaje[i];
    
                // REGLA 1: Minúsculas -> Pasan a Mayusculas y se desplazan +3
                if (c >= 'a' && c <= 'z') {
                    // Truco ASCII: La distancia entre minúsculas y mayúsculas es de 32 posiciones, equivalente a decir 'a' - 'A'.
                    c = c - ('a' - 'A');
                    c = c + 3;
    
                    // Comportamiento circular (si se pasa de la 'Z')
                    if (c > 'Z') {
                        c = c - 26; // Restamos el largo del abecedario
                    }
                    mensaje[i] = c;
                }
                // REGLA 2: Mayúsculas -> Pasan a Minúsculas y se desplazan -2
                else if (c >= 'A' && c <= 'Z') {
                    c = c + ('a' - 'A'); // A minúscula
                    c = c - 2;
    
                    // Comportamiento circular (si cae por debajo de la 'a')
                    if (c < 'a') {
                        c = c + 26; // Sumamos el largo del abecedario
                    }
                    mensaje[i] = c;
                }
                // REGLA 3: Espacios -> Dependen de la 'letra_previa'
                else if (c == ' ') {
                    if (letra_previa >= 'A' && letra_previa <= 'Z') {
                        mensaje[i] = '_';
                    } else {
                        // en caso de que la frase arranque con espacio caeria aca, porque
                        //'la letra previa a la primera' es '\0' (no existe)
                        mensaje[i] = '&';
                    }
                }
                // REGLA 4: Dígitos y símbolos no cambian, no hacemos nada :)
    
                // Actualizamos la variable de letra_previa para la próxima iteración
                // usando el carácter ORIGINAL ( no el encriptado ;) )
                letra_previa = original;
            }
    
            printf("\n----------------ENCRIPTACIÓN COMPLETADA-----------------\n");
            printf("Mensaje: %s\n", mensaje);
        } else {
            printf("Error al leer el mensaje.\n");
        }
    }
    
    int main(){
        // ej1();
        // ej2();
        // ej3();
        return 0;
    }
}
