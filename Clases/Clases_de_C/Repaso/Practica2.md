# Examen de Programación en C

**Instrucciones:**

* Lea atentamente cada ejercicio.
* Comente su código para explicar la lógica.
* Preste atención a los formatos de entrada y salida.
* Valide las entradas del usuario según se indique.

---

## Ejercicio 1: Gestión de Torneo de Videojuegos

Se necesita un programa para gestionar inscripciones y puntuaciones de un torneo semanal de videojuegos (5 días, hasta 20 jugadores).

**Requerimientos:**

1.  **Registro de Jugadores:**
    * ID de Jugador (entero, automático desde 1).
    * Nombre del Jugador (máximo 30 caracteres).
2.  **Puntuaciones Diarias:**
    * Ingresar puntuación por cada jugador inscrito (0-1000). Ingresar -1 si no participó.
    * El ingreso de puntuaciones de un día finaliza con ID de jugador 0 (Este requerimiento puede adaptarse si el flujo del programa gestiona los jugadores inscritos día por día de forma automática).
3.  **Reporte Diario (al finalizar cada día):**
    * Encabezado del día (Ej: `*** DIA X ***`).
    * Para cada participante: Nombre y Puntuación del Día.
4.  **Reporte Semanal (al finalizar los 5 días):**
    * **Puntuación Total:** Nombre y suma total de puntos por jugador.
    * **Campeón:** Nombre del jugador con más puntos.
    * **Días Jugados:** Cantidad de días que participó cada jugador.
    * **Promedio de Puntos por Día Jugado:** Puntuación total / días jugados (0 si no jugó).

**Consideraciones:**
* Validar puntuaciones (0-1000 o -1).
* Manejar caso sin jugadores inscritos.

---

## Ejercicio 2: Juego de "Piedra, Papel o Tijeras Avanzado"

Implementar "Piedra, Papel o Tijeras" contra la computadora con una estrategia básica.

**Reglas:**

1.  **Jugador Elige:** Piedra (1), Papel (2), o Tijeras (3).
2.  **Computadora Elige:**
    * **Ronda 1:** Al azar.
    * **Siguientes Rondas:**
        * Si PC ganó antes: 50% repite su jugada anterior (la que le dio la victoria), 50% al azar.
        * Si Jugador ganó antes: PC juega para vencer la jugada anterior del jugador.
3.  **Victoria:** Piedra > Tijeras, Tijeras > Papel, Papel > Piedra.
4.  **Continuar:** El juego sigue hasta que el jugador ingrese 0 para no continuar.
5.  **Marcador:** Llevar cuenta de Ganadas (Jugador), Ganadas (PC), Empates.

**Requerimientos del Programa:**

* Pedir y validar elección del jugador (1, 2, o 3).
* Generar elección de la PC según estrategia.
* Mostrar ambas elecciones.
* Anunciar resultado de la ronda.
* Actualizar y mostrar marcador tras cada ronda.
* Preguntar si desea jugar otra ronda (1=Sí, 0=No).
* Al final, mostrar marcador final.

**Ayuda:**
* Usar `rand()` y `srand(time(NULL))`.

---

## Ejercicio 3: Codificador Alfanumérico Simple (Modificado)

Se desea un programa que codifique o decodifique un mensaje simple. La transformación se aplica carácter por carácter dentro de cada palabra de una oración.

**Proceso de Codificación por Palabra:**

1.  Convertir la palabra a minúsculas (para la lógica de transformación). La salida de las letras transformadas también será en minúsculas.
2.  **Vocales:** Cada vocal se reemplaza por un número específico:
    * `a` se reemplaza por `1`
    * `e` se reemplaza por `2`
    * `i` se reemplaza por `3`
    * `o` se reemplaza por `4`
    * `u` se reemplaza por `5`
3.  **Consonantes:** Cada consonante se reemplaza por la siguiente consonante en el alfabeto inglés (b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, y, z). El reemplazo es circular (la `z` se reemplaza por `b`).
    * Ejemplo de transformación de consonantes: `b` -> `c`, `m` -> `n`, `z` -> `b`.

**Proceso de Decodificación por Palabra:**

1.  **Números (vocales codificadas):** Cada número (del 1 al 5) se reemplaza por su vocal original:
    * `1` se reemplaza por `a`
    * `2` se reemplaza por `e`
    * `3` se reemplaza por `i`
    * `4` se reemplaza por `o`
    * `5` se reemplaza por `u`
2.  **Letras (consonantes codificadas):** Cada letra (que se asume es una consonante codificada y está en minúsculas) se reemplaza por la consonante anterior en el alfabeto inglés. El reemplazo es circular (`b` se reemplaza por `z`).
    * Ejemplo de transformación de consonantes: `c` -> `b`, `n` -> `m`, `b` -> `z`.

**Requerimientos del Programa:**

1.  Ingresar una oración (puede contener múltiples palabras y terminar con un punto u otros signos).
2.  Preguntar al usuario si desea (C)odificar o (D)ecodificar.
3.  Procesar cada palabra de la oración según la opción elegida. Una "palabra" se considera una secuencia de letras.
4.  Los caracteres que no son letras (espacios, números no procesables en decodificación, signos de puntuación) se mantienen en su posición original y no se modifican, a menos que sean los números del 1 al 5 durante la decodificación.
5.  Mostrar la oración resultante.



---