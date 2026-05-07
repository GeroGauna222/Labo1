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
