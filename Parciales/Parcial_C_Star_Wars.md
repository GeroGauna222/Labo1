# PARCIAL C — Programación I
## Temática: STAR WARS

---

## Ejercicio 1 — Hangar Rebelde (MENÚ)

La Alianza Rebelde necesita llevar el control de las naves que salen del hangar durante una misión.

Se pueden despachar tres tipos de naves:

- **1) X-Wing** — consume 12 unidades de combustible por salida.
- **2) Y-Wing** — consume 18 unidades de combustible por salida.
- **3) A-Wing** — consume 9 unidades de combustible por salida.

El hangar comienza la jornada con **600 unidades de combustible**.

Implementar un programa con el siguiente menú:

1. **Registrar salida**
   - Pedir el tipo de nave.
   - Pedir cuántas naves de ese tipo salen.
   - La cantidad debe ser mayor que 0.
   - Calcular cuánto combustible requiere la salida.
   - Si no hay suficiente combustible disponible, rechazar la operación.
   - Si la salida es válida, descontar el combustible y acumular la cantidad de naves enviadas de ese tipo.

2. **Mostrar estado del hangar**
   - Mostrar cuántos X-Wing, Y-Wing y A-Wing fueron enviados.
   - Mostrar la cantidad total de naves despachadas.
   - Mostrar el combustible restante.

3. **Mostrar nave más utilizada**
   - Informar qué tipo de nave tuvo mayor cantidad de salidas.
   - Si hay empate entre dos o más tipos, informar que hubo empate.

4. **Promedio de combustible por salida**
   - Calcular `combustible consumido / cantidad total de naves enviadas`.
   - Si todavía no salió ninguna nave, mostrar `SIN DATOS`.

5. **Finalizar misión**
   - Mostrar un resumen final con cantidad total de naves enviadas, cantidad por tipo, combustible utilizado y combustible restante.

### Requisitos técnicos
- Utilizar `do...while` para mantener activo el menú.
- Utilizar `switch` para procesar las opciones.
- Validar tipo de nave y cantidad.
- No permitir que el combustible disponible sea negativo.

---

## Ejercicio 2 — Escape de la Estrella de la Muerte

Luke intenta escapar de la Estrella de la Muerte atravesando **4 sectores**.

Comienza con:

- **Escudo = 100**
- **Energía = 100**

Si en cualquier momento el escudo llega a **0 o menos**, Luke pierde.

En cada sector ocurre un evento aleatorio. Generar un número entre **1 y 10**:

- 1 a 4 → **TIE Fighters**
- 5 a 7 → **Torreta láser**
- 8 a 10 → **Campo de asteroides**

El jugador debe elegir una acción:

1. Maniobra evasiva
2. Ataque frontal
3. Acelerar

### TIE Fighters
- Maniobra evasiva: Energía −[5..12], Escudo −[0..8]
- Ataque frontal: Energía −[12..20], Escudo −[5..15]
- Acelerar: Energía −[15..25], Escudo −[0..10]

### Torreta láser
- Maniobra evasiva: Energía −[8..15], Escudo −[3..12]
- Ataque frontal: Energía −[10..18], Escudo −[8..20]
- Acelerar: Energía −[12..22], Escudo −[5..16]

### Campo de asteroides
- Maniobra evasiva: Energía −[6..12], Escudo −[2..10]
- Ataque frontal: Energía −[15..22], Escudo −[10..22]
- Acelerar: Energía −[10..18], Escudo −[5..18]

### Evento especial
Después de resolver cada sector existe una probabilidad del **20%** de recibir ayuda de R2-D2.

Si ocurre:
- recuperar entre **8 y 20 puntos de escudo**.

El escudo no puede superar 100.

### Final
Después de cada sector mostrar sector, evento, acción elegida, energía actual y escudo actual.

Si Luke supera los cuatro sectores con escudo mayor que 0:
`ESCAPE EXITOSO`

En caso contrario:
`LA NAVE FUE DESTRUIDA`

### Requisitos técnicos
- Usar `srand(time(NULL))`.
- Utilizar `rand()`.
- Utilizar una estructura anidada del estilo `for → switch/if del evento → switch/if de la acción → evento especial`.
- Validar la acción ingresada.

---

## Ejercicio 3 — Mensaje Rebelde

La Alianza Rebelde interceptó un mensaje codificado.

El mensaje fue cifrado carácter por carácter con las siguientes reglas:

### Letras mayúsculas y minúsculas
- **A-I / a-i** → durante el cifrado se desplazó **+2** posiciones.
- **J-R / j-r** → durante el cifrado se desplazó **−3** posiciones.
- **S-Z / s-z** → durante el cifrado se desplazó **+1** posición.

Los desplazamientos son circulares.

### Dígitos
Los números fueron reemplazados con espejo decimal:
`nuevo_digito = 9 - digito`

### Otros caracteres
Espacios, signos de puntuación y símbolos no fueron modificados.

### Consigna
Realizar un programa que reciba una línea de texto cifrada y muestre el mensaje original.

Para desencriptar:
- A-I → desplazar **−2**
- J-R → desplazar **+3**
- S-Z → desplazar **−1**
- Dígitos → volver a aplicar `9 - digito`

El programa debe respetar mayúsculas y minúsculas.

### Restricciones
- No utilizar `ctype.h`.
- Trabajar con rangos ASCII.
- Leer una línea completa.
- Recorrer la cadena carácter por carácter.

---

## Criterios generales
- Validación de entradas.
- Uso correcto de estructuras repetitivas y condicionales.
- Correcto manejo de acumuladores.
- Uso correcto de `rand()` en el ejercicio 2.
- Correcto recorrido y modificación de strings en el ejercicio 3.
- Código ordenado y legible.
