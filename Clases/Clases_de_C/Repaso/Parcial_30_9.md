# EXAMEN PARCIAL - PROGRAMACIÓN I

---

### PAUTAS GENERALES DE EVALUACIÓN
1. **Compilación Limpia:** El código debe compilar bajo estándar ANSI C sin errores ni advertencias.
2. **Prohibiciones Explícitas:**
   * Prohibido el uso de `<ctype.h>` (cualquier manipulación de caracteres debe realizarse mediante operaciones sobre la tabla ASCII).
3. **Manejo Seguro de Entrada:** Todo ingreso de texto o teclado debe prevenir desbordamientos y manejar correctamente el buffer.

---

## EJERCICIO 1: "Estación de Peaje Fluvial"

Una concesionaria fluvial administra el paso de embarcaciones por una esclusa navegable. Se solicita desarrollar un programa en C interactivo mediante un menú (`do-while` y `switch`) que gestione los tránsitos durante un turno de guardia.

### Tarifas Base por Embarcación:
* **1. Lancha / Bote Motor:** $3.500
* **2. Velero Comercial:** $6.000
* **3. Barcaza de Carga:** $12.000

### Reglas de Capacidad y Negocio:
* La esclusa tiene una capacidad operativa máxima de **60 embarcaciones por turno**. Si un nuevo registro supera dicho límite, debe rechazarse la operación y advertir al usuario.
* **Sobretasa de Urgencia:** Al registrar el paso, se consulta si la embarcación solicita "Paso Prioritario" (1: Sí, 2: No). En caso afirmativo, la tarifa base de dicha operación tiene un recargo del **25%**.

### Estructura del Menú:
1. **Registrar Tránsito:**
   * Validar Tipo de Embarcación (1 al 3).
   * Validar Prioridad (1 o 2).
   * Solicitar cantidad de unidades (entero > 0). Si la suma de las unidades supera el cupo de 60, rechazar el ingreso. De lo contrario, procesar el cobro acumulado y descontar el cupo disponible.
2. **Estado de Recaudación:**
   * Mostrar el dinero total recaudado hasta el momento.
   * Mostrar el total acumulado de embarcaciones registradas por cada categoría (Lanchas, Veleros, Barcazas).
3. **Estadística Operativa:**
   * Mostrar qué categoría de embarcación aportó el mayor monto de dinero a la recaudación total (sin considerar empates).
4. **Cierre de Turno:**
   * Imprimir un reporte final con: Total de embarcaciones atendidas, total recaudado en pesos y porcentaje de operaciones con paso prioritario sobre el total de registros realizados. Terminar el programa.

---

## EJERCICIO 2: "Incursión en las Profundidades de Moria" (Gestión de Recursos y Azar)

Un grupo de exploradores enanos recorre un túnel subterráneo a lo largo de **3 tramos consecutivos**[cite: 4]. Deben gestionar dos recursos vitales:
* **Resistencia del Escudo:** Inicia en **100**.
* **Antorchas (Luz):** Inicia en **120**.

**Condición de Fin:** Si en cualquier momento el Escudo llega a 0 (o menos) o las Antorchas llegan a 0 (o menos), la expedición fracasa y el programa termina inmediatamente indicando el tramo de derrota.

### Dinámica por Tramo (1 al 3):
Al ingresar a cada tramo, se determina de forma aleatoria el **Peligro Ambiental** utilizando `rand()` en el rango `[1 a 10]`:
* **1 a 4: Derrumbe Rocoso**
* **5 a 7: Emboscada de Trasgos**
* **8 a 10: Presencia del Troll de las Cavernas**

El usuario debe elegir obligatoriamente una de las siguientes **3 Acciones Tácticas** (validar entrada 1 a 3):
1. **Formación Defensiva Cerrada:**
   * *Derrumbe:* Daño al Escudo: `[15 a 25]`. Gasto de Antorchas: `[10 a 15]`.
   * *Trasgos:* Daño al Escudo: `[10 a 20]`. Gasto de Antorchas: `[20 a 30]`.
   * *Troll:* Daño al Escudo: `[30 a 45]`. Gasto de Antorchas: `[15 a 25]`.
2. **Carga Ofensiva:**
   * *Derrumbe:* Daño al Escudo: `[30 a 40]`. Gasto de Antorchas: `[5 a 10]`.
   * *Trasgos:* Daño al Escudo: `[5 a 15]`. Gasto de Antorchas: `[10 a 15]`.
   * *Troll:* Daño al Escudo: `[40 a 60]`. Gasto de Antorchas: `[5 a 15]`.
3. **Retirada Rápida bajo Fuego:**
   * *Derrumbe:* Daño al Escudo: `[5 a 10]`. Gasto de Antorchas: `[25 a 35]`.
   * *Trasgos:* Daño al Escudo: `[20 a 30]`. Gasto de Antorchas: `[30 a 40]`.
   * *Troll:* Daño al Escudo: `[10 a 20]`. Gasto de Antorchas: `[45 a 60]`.

### Requisitos:
* Utilizar `srand(time(NULL))` al inicio del programa.
* Calcular todas las variaciones de daño y consumo utilizando estrictamente la fórmula de rangos acotados: `(rand() % (max - min + 1)) + min`.
* Tras cada tramo, imprimir qué peligro se presentó, la acción tomada, las pérdidas exactas sufridas en el turno y los valores actuales de Escudo y Antorchas.
* Si el equipo sobrevive a los 3 tramos, imprimir el mensaje de victoria y el balance final de recursos.

---

## EJERCICIO 3: "Cifrador de Mensajería Táctica (Dither Sec)" (Bajo Nivel / ASCII)

Se ha capturado una trama de comunicación interna de una corporación rival. Se debe crear un módulo de ofuscación que procese una cadena de texto (máximo 100 caracteres) aplicando reglas de transformación directa sobre la tabla ASCII.

### Reglas de Conversión:
1. **Entrada de Datos:** Leer la línea completa de texto con `fgets` y neutralizar el salto de línea `\n`.
2. **Mayúsculas ('A' a 'Z'):** 
   * Se transforman a **minúsculas** (`+ 32`).
   * Se desplazan **+3 posiciones** en el abecedario de forma circular (ejemplo: `'a'` pasa a `'d'`, `'z'` pasa a `'c'`).
3. **Minúsculas ('a' a 'z'):** 
   * Se transforman a **MAYÚSCULAS** (`- 32`).
   * Se desplazan **-4 posiciones** en el abecedario de forma circular (ejemplo: `'D'` pasa a `'Z'`, `'A'` pasa a `'W'`).
4. **Espacios en Blanco (' '):** 
   * Se reemplazan por el carácter especial `'#'`.
5. **Dígitos Numéricos ('0' a '9'):** 
   * Se sustituyen por su **complemento a 9** (ejemplo: `'0'` se transforma en `'9'`, `'2'` en `'7'`, `'9'` en `'0'`).
6. **Otros Símbolos (puntuación, operadores, etc.):** 
   * No deben alterarse en el array, pero al finalizar el procesamiento se debe reportar la **cantidad total de símbolos que quedaron intactos**.

### Restricción Absoluta:
* **Prohibido el uso de `<ctype.h>`** (no usar `isalpha`, `isdigit`, `toupper`, `tolower`, etc.)[cite: 4]. Toda validación y conversión debe realizarse por cálculo y comparación directa de rangos en código ASCII[cite: 4].
* El recorrido de la cadena debe detenerse estrictamente al detectar el carácter nulo centinela `\0`[cite: 4, 8].
