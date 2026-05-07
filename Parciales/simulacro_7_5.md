# Simulacro: Ejercicio 1

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



