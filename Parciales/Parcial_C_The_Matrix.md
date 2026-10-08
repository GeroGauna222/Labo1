# PARCIAL C — Programación I
## Variante 1 — THE MATRIX

---

## EJERCICIO 1 — Control de accesos a Zion

Zion registra el ingreso de personas durante el día.

Cada persona pertenece a una categoría:

1. Tripulación
2. Ingeniería
3. Seguridad

El sistema debe permitir ingresar personas hasta que el operador escriba **0** como categoría.

Por cada ingreso se debe pedir:

- Categoría
- Edad
- Nivel de autorización (1 a 5)

### Reglas

- La categoría debe ser 1, 2 o 3. El valor 0 finaliza la carga.
- La edad debe ser mayor o igual a 18.
- El nivel de autorización debe estar entre 1 y 5.
- Un ingreso se considera **crítico** si pertenece a Seguridad con autorización 5, o a Ingeniería con autorización 4 o 5.

### Al finalizar mostrar

- Cantidad total de personas ingresadas.
- Cantidad por categoría.
- Promedio de edad.
- Cantidad de ingresos críticos.
- Categoría con mayor cantidad de ingresos.
- Porcentaje de personas de Seguridad sobre el total.

### Requisitos

- Utilizar un ciclo de carga con valor centinela.
- Validar todos los datos.
- Utilizar acumuladores y contadores.
- No utilizar arreglos.

---

## EJERCICIO 2 — Elegir la píldora correcta

Neo debe superar **5 rondas**.

En cada ronda se generan dos números aleatorios entre 1 y 20:

- `codigo`
- `objetivo`

El jugador elige una acción:

1. Sumar 3 al código
2. Multiplicar el código por 2
3. Restar 4 al código

Luego se compara el resultado con el objetivo.

### Puntaje

- Resultado exacto: **+3 puntos**
- Distancia de 1 o 2: **+2 puntos**
- Distancia de 3 a 5: **+1 punto**
- Distancia mayor a 5: **0 puntos**

### Evento aleatorio

Después de cada ronda existe un **20%** de probabilidad de que aparezca un Agente.

Si aparece:

- si el jugador obtuvo 2 o 3 puntos en esa ronda, pierde 1 punto;
- si obtuvo 0 o 1 punto, no se modifica.

El puntaje total nunca puede ser menor a 0.

### Resultado final

- 10 puntos o más → `NEO DESPIERTA DE LA MATRIX`
- 6 a 9 puntos → `NEO ESCAPA POR POCO`
- Menos de 6 → `NEO QUEDA ATRAPADO`

### Requisitos

- Usar `for`.
- Usar `rand()` y `srand(time(NULL))`.
- Validar la opción elegida.
- Usar condicionales anidados para distancia, puntaje y evento especial.

---

## EJERCICIO 3 — Código del Oráculo

El Oráculo recibe un mensaje cifrado. Cada carácter fue transformado según su posición dentro de la cadena. La primera posición es **0**.

### Cifrado original

Para letras:

- posición múltiplo de 3 → desplazamiento **+1**
- posición con resto 1 al dividir por 3 → desplazamiento **+2**
- posición con resto 2 → desplazamiento **−1**

Los desplazamientos son circulares.

Para dígitos:

- `0→1`, `1→2`, ..., `8→9`, `9→0`

Los espacios se reemplazaron por `_`.

Los demás símbolos no fueron modificados.

### Consigna

Desencriptar aplicando las operaciones inversas:

- posición múltiplo de 3 → **−1**
- resto 1 → **−2**
- resto 2 → **+1**
- dígitos → restar 1 de forma circular
- `_` → espacio

### Requisitos

- Leer una línea completa.
- Mantener mayúsculas y minúsculas.
- No utilizar `ctype.h`.
- Recorrer la cadena utilizando índices.
