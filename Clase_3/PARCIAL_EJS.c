Para costear el viaje a los juegos panamericanos del equipo nacional de ping pong, el plantel (compuesto por 8 jugadores) decidi� llevar a cabo una venta de rifas.
se entrega a cada comprador un numero de rifa aleatorio del 1 al 1000. No se tiene en cuenta la posibilidad de vender m�s de 1000 rifas, pues el equipo lo ve imposible.

Requerimientos: Deber�n ingresarse por cada comprador:
- Qui�n le vendi� (el n�mero del jugador que complet� la venta; un entero del 1 al 8)
- Qu� n�mero de rifa escogi� el comprador (no es aleatorio).
Tener en cuenta:
- No pueden haber dos compradores con el mismo numero de rifa.
- No puede ingresarse un numero de jugador no v�lido.
El programa deber� llevar la cuenta de cuantas ventas lleva cada jugador (cada uno tiene un numero asignado, son 8 jugadores).
El ingreso de datos finaliza al presionar el 0 en el numero de jugador que vendi� la rifa.
Al realizar cada ingreso debera imprimirse en pantalla:

...
Comprador numero ---
numero de rifa: ---
Vendedor: Jugador nro ---
...

Al finalizar, deber� imprimirse en pantalla cu�ntas ventas complet� cada jugador, quien vendi� m�s y el total recaudado entre todos (cada rifa tiene un precio de 200 pesos).

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int rifas_vendidas [1000] = {0};


Ayuda: Una forma de chequear que el numero de rifa est� vendido o no es llenando un espacio en el array de enteros rifas_vendidas.

+++++++++++++++++++++++++++++++++++++++++++++++++

Una biblioteca tiene una lista especial de 4 socios ultra premium, quienes mensualmente pagan una cuota mensual que les brind� varios beneficios. Entre estos, uno es la posibilidad de llevarse hasta 10 libros por semana gratuitamente a modo de prestados, pero de estos solo hasta 3 por d�a.
Se necesita un programa para llevar registro diario de cuantos libros se lleva cada socio; deben saber que tipo de libros fueron llevados y la hora del dia en la que ocurri� (entero del 8 al 18).

Requerimientos: Cada d�a se ingresar�n datos seg�n los socios que tomen libros (aunque puede ser que ese d�a ninguno tome un libro). En cada uno se tienen en cuenta los siguientes datos:
- Numero de socio
- Cantidad de libros llevados
- Horario del retiro
Tener en cuenta:
- El horario es un entero de 8 a 18
- el numero de socio es un entero entre 1 y 4
- Que la cantidad de libros tomados por un socio en un d�a no puede ser mayor a 3 (ni menor a cero)
- Que podr�an no ingresarse datos alguno de los 7 d�as de la semana

El ingreso de datos finaliza al presionar la letra 'F'
Al finalizar cada dia debera imprimirse en pantalla:

****
Socio numero ...
Cantidad de libros el d�a [numero de dia]: ...
Horario de retiro: ...
****

Una vez se haya procesado toda la semana, se deber�n mostrar en pantalla:
- Cu�ntos alquileres realizo cada socio en total. Si este numero es mayor a 10, se deber� calcular cuanto cobrarle al socio (el precio es de 1000 pesos por libro)
- Cu�l de los socios realiz� m�s alquileres
- El dinero recaudado por alquiler de libros a socios (puede ser 0)
- Cantidad total de alquileres a socios

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Un puestito de comida en la puerta de un boliche de Mar del Plata vende comida todas las noches de la semana en verano.
Debido a esto deciden pedirte un programa donde ingresar las ventas.
Los costos que maneja el puestito son:
Pizza = 5000
Pancho = 2000
Hamburguesa completa = 5000
Lomito a la plancha = 4000
Bebida = 1500
Debido a la alta demanda, cada persona puede cada vez que va a la caja a pagar, comprar solamente un producto.
Cada noche se realizan multiples ingresos de pedidos en los que se tiene:
numero de ticket (hasta la semana anterior se llevan hechos 1762 tickets, el primer comprador de la semana sera el ticket siguiente, el siguiente el segundo y asi, numeros enteros)
opcion escogida (que decidio comprar)
cuanto pago
si decidio pagar con efectivo o transferencia 
Al iniciar cada dia debe imprimirse en pantalla "DIA [numero de dia] DE LA SEMANA"

Luego de cada ingreso debe imprimirse:
...
Numero de ticket: X 
Opcion escogida: XXX
Pago: $XXX
Tipo de pago: (transferencia o efectivo)
...

Al finalizar la semana, debe imprimirse en pantalla el total de ventas, la plata recaudada, que cosa fue la mas vendida y que metodo de pago fue el mas utilizado


--------------------------------------------------------------------------------------------------------------------

Un programa al que se ingresa una palabra, y de esta cambia las consonantes por numeros a elecci�n del usuario.
Por ejemplo se ingresa "Arbol", las consonantes son r, b y l. El programa debe ser capaz de pedirle al usuario
que ingrese 3 numeros (y chequee que sean numeros) , que deberian aparecer de la siguiente manera: "A35o4"
Ayuda: Los numeros en la tabla ASCII comprenden desde la posicion 48 a la 57

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


Un programa al que se ingresen numeros del 0 al 9, y devuelva los valores en texto de esta forma:
Ingreso: 12345
Imprime en pantalla: "uno dos tres cuatro cinco"

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

En la guerra de las galaxias, Anakin debe pasar un mensaje a Obi-Wan por algun medio. R2-D2 tiene la funcionalidad de enviar el mensaje,
pero necesitan un c�digo para resguardar el mensaje en caso de que los sid intercepten el mensaje. Deciden utilizar el c�digo ASCII.
Crear un programa que para todas las letras de un ingreso las convierta en su numero en ASCII, cada letra separada por un espacio.
No se traducir�n a ASCII todos los signos, solamente las letras, mayusculas y minusculas.

Ayuda: las letras mayusc comprenden desde la posici�n 65 a la 90, las minusc desde la 97 a la 122. Tener en cuenta que este mensaje
codificado mostrar� los espacios y signos (como ��?!) con normalidad.
Ejemplo:
    ingreso: "Obi Wan respondeme porfavor!!!"
    salida: 79 98 105   87 97 110   114 101 112 111 110 100 101 109 101   112 111 114 102 97 118 111 114 ! ! !


-------------------------------------------------------------------------------------------------------------------------

Un programa que simula un juego de lanzamiento de dados. Se lanzan 2 dados de seis caras. Las reglas son las siguientes:
- se gana si en ambos dados sale el mismo numero
- se pierde cuando sumando lo que sali� en ambos dados da un numero impar
- en cualquier otro caso se repite la tirada

Ayuda: para las tiradas de dados, hara falta hacer uso de: rand() % 6 + 1

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

"Adivina el n�mero secreto"
Este es un juego cl�sico en el que la computadora genera un n�mero aleatorio y el jugador tiene que adivinarlo.
El programa genera un n�mero secreto aleatorio entre 1 y 100.
El usuario tiene un n�mero limitado de intentos (5 intentos) para adivinarlo.
Por cada intento, el programa indicar� si el n�mero ingresado es mayor o menor que el n�mero secreto:
    - si esta alejado por mas de 10, "indicara mucho mayor/menor", si es por menos de 10, indicara "mayor/menor"
Si el jugador adivina el n�mero, gana el juego. Si no lo adivina en los intentos permitidos, pierde.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Juego: "Aventura en el bosque"
Reglas del juego:

El tesoro se encuentra en una dirección aleatoria (norte, este, oeste, noreste, noroeste).
El jugador tiene 4 intentos para encontrar el tesoro.
Si elige el camino donde está el tesoro, gana (lo decide un aleatorio).
si elige la direccion del pozo de la muerte, cae y pierde (tambien aleatoria)
Si elige un camino diferente, puede seguir intentando.
Si se elige una dirección no válida, se lo debe corregir para que escoja una válida.
