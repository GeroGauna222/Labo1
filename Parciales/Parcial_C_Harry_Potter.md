# PARCIAL C — Programación I
## Temática: HARRY POTTER

---

## Ejercicio 1 — Tienda de Pociones (MENÚ)

La tienda de pociones del Callejón Diagon vende tres tipos de pociones:

- **1) Poción de curación** — 15 galeones.
- **2) Poción de energía** — 10 galeones.
- **3) Poción de invisibilidad** — 25 galeones.

Durante el día se pueden vender como máximo **80 pociones** en total.

Realizar un programa con el siguiente menú:

1. **Registrar venta**
   - Pedir tipo de poción.
   - Pedir cantidad.
   - La cantidad debe ser mayor que 0.
   - Si la venta hace superar las 80 pociones vendidas, rechazarla.
   - Si es válida, acumular cantidad vendida e ingreso correspondiente.

2. **Mostrar ventas**
   - Mostrar cuántas unidades se vendieron de cada poción.
   - Mostrar total de pociones vendidas.
   - Mostrar total de galeones recaudados.

3. **Consultar una poción**
   - Pedir un tipo de poción.
   - Mostrar cantidad vendida y dinero recaudado por esa poción.

4. **Mostrar poción más vendida**
   - Informar cuál tiene mayor cantidad acumulada.
   - Si existe empate, mostrar `HUBO EMPATE`.

5. **Cerrar tienda**
   - Mostrar un resumen final y finalizar.

### Requisitos técnicos
- Usar `do...while`.
- Usar `switch`.
- Validar las opciones.
- Utilizar acumuladores independientes para cada poción.
- No permitir superar el máximo diario de 80 unidades.

---

## Ejercicio 2 — Torneo de Magos

Un alumno de Hogwarts debe superar **3 rondas** de un torneo mágico.

Comienza con:

- **Vida = 100**
- **Magia = 80**

Si la vida llega a **0 o menos**, pierde.

En cada ronda aparece aleatoriamente uno de los siguientes enemigos. Generar un número entre **1 y 9**:

- 1 a 3 → **Dementor**
- 4 a 6 → **Troll**
- 7 a 9 → **Araña gigante**

El jugador puede elegir:

1. Hechizo defensivo
2. Hechizo ofensivo
3. Esquivar

### Dementor
- Defensivo: Magia −[8..15], Vida −(0..5]
- Ofensivo: Magia −[15..25), Vida −[4..12)
- Esquivar: Magia −(2..6), Vida −[5..15]

### Troll
- Defensivo: Magia −[6..12), Vida −[3..10]
- Ofensivo: Magia −[12..20], Vida −(6..18)
- Esquivar: Magia −(2..5], Vida −[4..14]

### Araña gigante
- Defensivo: Magia −[5..10), Vida −(2..8)
- Ofensivo: Magia −(10..18], Vida −[5..15]
- Esquivar: Magia −[1..4], Vida −[3..12)

### Poción aleatoria
Después de cada ronda existe una probabilidad del **25%** de encontrar una poción.

Si aparece, generar aleatoriamente:
- 50% → recuperar **[10..20) de vida**
- 50% → recuperar **(8..15] de magia**

Vida máxima: 100.
Magia máxima: 80.

### Final
Después de cada ronda mostrar enemigo, acción elegida, vida restante y magia restante.

Si la magia llega a 0, el jugador puede continuar, pero solo podrá elegir **Esquivar**.

Si supera las 3 rondas con vida mayor que 0:
`TORNEO SUPERADO`

En caso contrario:
`HAS SIDO DERROTADO`

### Requisitos técnicos
Usar:
- `for`
- `switch`
- `if`
- `rand()`
- `srand(time(NULL))`

Debe existir anidamiento entre ronda, enemigo y acción.

---

## Ejercicio 3 — Pergamino Encantado

Un pergamino contiene un mensaje cifrado.

Durante el cifrado se realizaron las siguientes transformaciones:

### Vocales
Las vocales fueron reemplazadas por la siguiente vocal:
`A → E → I → O → U → A`

Lo mismo ocurre para minúsculas.

### Consonantes
Cada consonante fue desplazada **2 posiciones hacia adelante** en el alfabeto.

El desplazamiento es circular:
- `Y → A`
- `Z → B`

### Dígitos
Cada dígito se reemplazó por:
`(digito + 5) % 10`

### Otros caracteres
No fueron modificados.

### Consigna
Crear un programa que reciba el mensaje cifrado y lo **desencripte**.

Para revertirlo:
- Vocales: reemplazar por la vocal anterior.
- Consonantes: desplazar **2 posiciones hacia atrás**.
- Dígitos: restar 5 de forma circular.
- Símbolos: dejar iguales.

Ejemplo de secuencia inversa:
`E → A`, `I → E`, `O → I`, `U → O`, `A → U`

### Condiciones
- Mantener mayúsculas y minúsculas.
- No utilizar `ctype.h`.
- Leer una línea completa.
- Recorrer el texto carácter por carácter.

---

## Criterios generales
- Correcto uso del menú y acumuladores.
- Validación de entradas.
- Uso correcto de `rand()` y estructuras anidadas.
- Correcto manejo de strings y caracteres.
- Claridad general del código.
