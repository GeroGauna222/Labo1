# Recuperatorio — Programación I

**Recordatorio!!! Puntaje:** Ejercicio 1 = 4 puntos · Ejercicio 2 = 3 puntos · Ejercicio 3 = 3 puntos · **Total 10**

---

## Ejercicio 1 — Centro de control del Jurassic Park (4 puntos)

El centro de control del parque administra tres tipos de recursos para las expediciones a la isla cada día. Al iniciar el dia hay:

| Código | Recurso | Unidades disponibles |
|---|---|---|
| 1 | Guardaparques | 10 |
| 2 | Jeeps | 6 |
| 3 | Drones | 5 |

Desarrollar un programa con el siguiente menú, que se repite hasta elegir la opción 4:

```
1) Enviar expedición
2) Estado del centro
3) Estadísticas
4) Cerrar día del centro de control
```

**Opción 1 — Enviar expedición.** Se ingresa el tipo de recurso (1 a 3), la cantidad de unidades (mayor a 0) y la peligrosidad de la zona (1 Baja, 2 Media, 3 Alta). Validar los tres datos.
- Si la peligrosidad es **Alta**, la expedición necesita **1 unidad extra** del mismo recurso como respaldo (+1).
- Si no hay unidades disponibles suficientes (contando la extra, ojo en las Altas), la expedición se **rechaza completa** y se informa.
- Si se acepta: se descuentan las unidades disponibles, se suman a "en uso", se suma 1 a las expediciones activas y se acumula el total de unidades enviadas en el día.

**Opción 2 — Estado del centro.** Mostrar, para cada recurso, las unidades disponibles y en uso, y la cantidad de expediciones activas.

**Opción 3 — Estadísticas.**
- Porcentaje de unidades de **drones** sobre el total de unidades enviadas en el día. Si todavía no se envió nada, mostrar `SIN DATOS`.
- Cantidad de expediciones activas y **si hay o no disponibilidad** de *Jeeps*.

**Opción 4 — Cerrar.** Mostrar un resumen final: disponibles y en uso por recurso, total de unidades enviadas en el día y expediciones activas.

---

## Ejercicio 2 — Cruce del río (3 puntos)

Un explorador tiene que cruzar un río saltando sobre **7 hileras de piedras**. En cada hilera hay dos piedras (izquierda y derecha): una es **firme** y la otra **se hunde**. La piedra firme se elige al azar en cada hilera (usar `rand()` y `srand(time(NULL))`).

El explorador empieza con **3 vidas**, **0 puntos** y **1 bengala**.

En cada hilera mostrar: número de hilera, vidas, puntos y si tiene bengala. Luego el jugador elige:

```
1) Izquierda   2) Derecha   3) Usar bengala
```

- Si elige la piedra firme: **pasa de ronda**. Si elige la que se hunde: **−1 vida**. En ambos casos pasa a la hilera siguiente.
- **Bengala** (un solo uso): el programa le permite **pasar directo de ronda**. No se puede usar si ya la gastó.
- **NIEBLA:** en cada hilera hay un **20 %** de probabilidad de niebla. Se informa al mostrar la hilera. Con niebla elegir la piedra que se hunde resta **2 vidas** en lugar de 1.
- Validar la opción ingresada (1, 2 o 3, y 3 solo si corresponde).
- Si las vidas llegan a 0 o menos, el juego termina en ese momento.

**Resultado final:**
- Vidas en 0 o menos: `ATRAPADO EN EL RIO`
- Termina el recorrido: `REY DEL RIO`

---

## Ejercicio 3 — Señal interceptada (3 puntos)

El centro de control interceptó una señal cifrada desde la isla. Desarrollar un programa que lea el texto cifrado y muestre el mensaje original, aplicando estas reglas caracter por caracter:

- **Letras:** depende de la **posición** del caracter en la cadena (la primera posición es la 0, y se cuentan todos los caracteres, incluidos `-`, dígitos y símbolos):
  - posición **par**: retroceder **3** letras en el alfabeto;
  - posición **impar**: avanzar **1** letra en el alfabeto.
  - El alfabeto es circular (por ejemplo, retroceder 3 desde `b` da `y`; avanzar 1 desde `z` da `a`). Se respetan mayúsculas y minúsculas.
- **Dígitos:** cada dígito `d` se reemplaza por `9 − d` (el 0 pasa a 9, el 7 pasa a 2, etc.).
- El guion `-` se convierte en **espacio**.
- Cualquier otro carácter queda igual.

No se puede usar `ctype.h`.

**Ejemplo:**

```
Señal cifrada: Knoz-Lxmgn-72wby!
Mensaje original: Hola Mundo 27xyz!
```
