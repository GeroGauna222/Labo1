# PARCIAL C — Programación I
## Temática: STRANGER THINGS

---

## Ejercicio 1 — Inventario del Laboratorio Hawkins (MENÚ)

El laboratorio de Hawkins necesita controlar el uso de tres tipos de equipamiento:

- **1) Linterna**
- **2) Radio**
- **3) Sensor**

El laboratorio dispone inicialmente de:

- 30 linternas
- 20 radios
- 15 sensores

Durante el día se prestan y devuelven equipos.

Crear un programa con el siguiente menú:

1. **Prestar equipo**
   - Pedir tipo de equipo.
   - Pedir cantidad.
   - La cantidad debe ser mayor que 0.
   - No se puede prestar una cantidad mayor a la disponible.
   - Si el préstamo es válido, descontar del stock y sumar a la cantidad actualmente prestada.

2. **Devolver equipo**
   - Pedir tipo.
   - Pedir cantidad.
   - No se puede devolver más equipamiento del que actualmente está prestado.
   - Si es válido, aumentar stock disponible y reducir cantidad prestada.

3. **Mostrar inventario**
   - Mostrar para cada equipo:
     - disponible,
     - prestado.

4. **Equipo más prestado**
   - Llevar además un contador histórico de unidades prestadas durante el día.
   - Mostrar cuál fue el equipo con mayor cantidad de préstamos acumulados.
   - Si hay empate, informar `HUBO EMPATE`.

5. **Cerrar laboratorio**
   - Mostrar stock final, cantidades actualmente prestadas y total de unidades prestadas durante la jornada.

### Requisitos técnicos
- Usar `do...while`.
- Usar `switch`.
- Validar las opciones y cantidades.
- Utilizar acumuladores separados por tipo de equipo.

---

## Ejercicio 2 — Escape del Upside Down

El jugador debe atravesar **4 zonas** del Upside Down.

Comienza con:

- **Vida = 100**
- **Batería = 100**

Si la vida llega a **0 o menos**, pierde.

En cada zona aparece aleatoriamente una amenaza. Generar un número entre **1 y 10**:

- 1 a 4 → **Demobat**
- 5 a 7 → **Enredaderas**
- 8 a 10 → **Demogorgon**

El jugador puede elegir:

1. Correr
2. Esconderse
3. Atacar

### Demobat
- Correr: Batería −[6..12], Vida −[2..8]
- Esconderse: Batería −[2..6], Vida −[0..5]
- Atacar: Batería −[10..16], Vida −[3..10]

### Enredaderas
- Correr: Batería −[8..15], Vida −[4..12]
- Esconderse: Batería −[3..7], Vida −[2..8]
- Atacar: Batería −[9..15], Vida −[5..14]

### Demogorgon
- Correr: Batería −[12..20], Vida −[8..18]
- Esconderse: Batería −[6..12], Vida −[4..14]
- Atacar: Batería −[15..25], Vida −[10..25]

### Evento especial
Después de cada zona hay una probabilidad del **30%** de encontrar un paquete de suministros.

Si aparece:
- recuperar entre **5 y 15 puntos de batería**
- recuperar entre **5 y 12 puntos de vida**

La vida y la batería no pueden superar 100.

### Fin del juego
Después de cada zona mostrar amenaza, acción, vida y batería.

Si el jugador supera las cuatro zonas:
`ESCAPASTE DEL UPSIDE DOWN`

Si la vida llega a 0:
`EL UPSIDE DOWN TE ATRAPO`

### Requisitos técnicos
- Usar `for`.
- Usar `switch` o bloques `if` anidados.
- Validar acción 1–3.
- Usar `rand()` y `srand(time(NULL))`.

---

## Ejercicio 3 — Código de Hawkins

Los chicos de Hawkins reciben mensajes cifrados por radio.

El cifrado se realizó aplicando las siguientes reglas:

### Letras en posición par del texto
Considerar la primera posición como posición **0**.

Si el carácter es una letra y se encuentra en una posición par:
- se desplazó **3 lugares hacia adelante**.

### Letras en posición impar del texto
Si el carácter es una letra y se encuentra en una posición impar:
- se desplazó **2 lugares hacia atrás**.

Los desplazamientos son circulares dentro del alfabeto.

### Dígitos
Los dígitos fueron invertidos:
`0↔9`, `1↔8`, `2↔7`, `3↔6`, `4↔5`

### Espacios
Los espacios se reemplazaron por el carácter:
`#`

### Otros símbolos
No fueron modificados.

### Consigna
Crear un programa que reciba una línea cifrada y reconstruya el mensaje original.

Para desencriptar:
- letra en posición par → desplazar **3 hacia atrás**,
- letra en posición impar → desplazar **2 hacia adelante**,
- dígitos → aplicar nuevamente el espejo `9 - digito`,
- `#` → convertir nuevamente en espacio,
- otros símbolos → dejar iguales.

### Importante
La posición se calcula sobre el texto cifrado completo, incluyendo números, símbolos y `#`.

### Restricciones
- No utilizar `ctype.h`.
- Mantener mayúsculas y minúsculas.
- Leer una línea completa.
- Recorrer la cadena utilizando índices.

---

## Criterios generales
- Validaciones correctas.
- Buen uso de acumuladores y stock en Ejercicio 1.
- Uso de aleatoriedad y bloques anidados en Ejercicio 2.
- Recorrido correcto de strings e índices en Ejercicio 3.
- Código claro y ordenado.
