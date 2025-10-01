# PARCIAL C — Programación I

## EJERCICIO 1: Cafetería Universitaria — Gestión de Pedidos (MENÚ)

La cafetería del campus quiere registrar los pedidos de un solo mostrador durante un día.  
Cada pedido puede incluir ítems entre: **Café**, **Tostado**, **Jugo**, **Medialuna**.  
Se necesita un sistema por **menú** que permita:

**Menú principal**
1. Ingresar un pedido  
   - Pedir tipo de ítem (1: Café, 2: Tostado, 3: Jugo, 4: Medialuna).  
   - Pedir cantidad (entero positivo).  
   - Sumar al total del día y al total por ítem.  
   - Limitar: el **total de ítems vendidos del día** no puede superar **200**. Si el nuevo ingreso excede, **rechazar** y avisar.
2. Mostrar subtotales por ítem (cantidades acumuladas de cada uno).
3. Mostrar el **ítem más vendido** (si hay empate, informar cualquiera de los máximos e indicar “hubo empate”).
4. Mostrar el **ticket promedio** del día (total de ítems vendidos / cantidad de pedidos realizados). Si no hubo pedidos, indicar “sin datos”.
5. Finalizar la jornada (salir del menú).

**Al finalizar (opción 5), imprimir un resumen:**
- Cantidad total de pedidos realizados.  
- Cantidad total de ítems vendidos.  
- Detalle por ítem (Café, Tostado, Jugo, Medialuna).  
- Porcentaje de participación de cada ítem sobre el total (redondeo simple).

**Notas y restricciones**
- Validar entradas (tipo y cantidad).  
- Usar al menos **un `do…while`** para el menú y **condicionales** para validar.  
- No usar `float` para contar ítems. El promedio puede ser `float`/`double`.  
- Sugerencia: llevar “cantidad de pedidos” independiente de “cantidad de ítems”.

---

## EJERCICIO 2: La Mazmorra del Dragón (JUEGO CON BLOQUES ANIDADOS)

Estás en una mazmorra con **3 niveles**. Empezás con **100 puntos de vida (HP)**.  
En cada nivel enfrentás un evento aleatorio: **Trampa**, **Cofre**, o **Dragón bebé**.  
El objetivo es **sobrevivir** y salir con al menos **1 HP**.

**Reglas del juego (usar `rand()` y `srand(time(NULL))`):**
- Por cada nivel `i = 1..3`:  
  1) Determinar evento:  
     - 1–4: **Trampa**  
     - 5–7: **Cofre**  
     - 8–10: **Dragón bebé**  
     (usar un número aleatorio de 1 a 10)
  2) Según evento, pedir acción del jugador (mostrar submenú):
     - **Trampa**  
       - (1) Correr: recibís daño aleatorio **[5..15]**.  
       - (2) Desactivar: tirás un dado **[1..6]**.  
         - Si ≥ 4, evitas la trampa (0 daño).  
         - Si ≤ 3, la trampa se duplica: daño aleatorio **[10..20]**.  
     - **Cofre**  
       - (1) Abrir: chance 50% de **poción** (+**[10..25]** HP) o **bomba** (−**[5..15]** HP).  
       - (2) Ignorar: no pasa nada.  
     - **Dragón bebé**  
       - (1) Atacar a distancia: daño al dragón **[10..25]**; contraataque **[0..10]** a tu HP.  
       - (2) Cuerpo a cuerpo: daño al dragón **[20..35]**; contraataque **[5..20]** a tu HP.  
       - El dragón tiene **50 HP** al inicio del encuentro: si lo reducís a 0 o menos, **ganás el nivel**; si no, el dragón **huye** y el nivel termina igualmente.  
  3) Si tu HP ≤ 0 en cualquier momento, el juego termina (derrota).

**Requisitos técnicos (enfocar “bloques anidados”):**
- Debe haber **múltiples niveles de anidación**: `for` de niveles → `switch/if` de evento → `switch/if` de acción → sub-condiciones (dados, rangos, etc.).  
- Validar elecciones del usuario con bucles hasta que ingrese una opción válida.  
- Mostrar después de cada nivel: **Nivel, evento, acción, variaciones de HP y HP actual**.

**Al finalizar:**
- Si sobreviviste los 3 niveles, imprimir “¡Victoria!” y el HP final.  
- Si no, imprimir “Derrota” y el nivel alcanzado.

---

## EJERCICIO 3: Criptograma del Museo (DESENCRIPTACIÓN)

El museo publica pistas encriptadas. Implementar la **desencriptación** del siguiente cifrado mixto aplicado **carácter por carácter**:

1. Si es **vocal** (A, E, I, O, U — mayúscula o minúscula), durante el cifrado se **desplazó 3 posiciones hacia la derecha** en el alfabeto (con vuelta circular: X→A si corresponde).  
   - Para **desencriptar**, desplazar **3 hacia la izquierda** (circular).  
   - Ej.: Cifrado ‘D’ ⇢ Original ‘A’ (si fue vocal ‘A’ cifrada).  
2. Si es **consonante** (letra alfabética que no es vocal), durante el cifrado se **invirtió el bloque** dentro de su **trío** en el abecedario:  
   - Se agrupan letras en bloques consecutivos de 3: `ABC | DEF | GHI | JKL | MNO | PQR | STU | VWX | YZ( )`  
     - El último bloque se completa virtualmente como `YZ?` para mantener tamaño 3.  
   - Dentro del bloque, la posición **0↔2** se permuta y la **1** queda igual (efecto espejo).  
   - Para **desencriptar**, aplicar **la misma permutación** (es involutiva).  
   - Ej.: `D(DEF)` ↔ `F(DEF)`, `G(GHI)` ↔ `I(GHI)`, `J(JKL)` ↔ `L(JKL)`.  
3. Si es **dígito** `0–9`, durante el cifrado se aplicó **espejo decimal**: `d → (9 - d)`.  
   - Para **desencriptar**, aplicar lo mismo (involutivo).  
   - Ej.: `8 ↔ 1`, `0 ↔ 9`.  
4. **Espacios y símbolos** (incluye tildes y puntuación) **no cambian**.  
5. El resultado final de la **desencriptación** debe conservar **la misma caja** (mayúsculas/minúsculas) que el texto de entrada.  
6. **No está permitido** usar `ctype.h` (`toupper`, `tolower`, `isalpha`, etc.). Trabajar con rangos ASCII y/o tablas propias.

**El programa debe:**
- Leer una línea (puede incluir espacios y símbolos).  
- Desencriptar según las reglas indicadas.  
- Imprimir el mensaje **desencriptado**.

**Sugerencias de implementación (opcional, no obligatorio):**
- Normalizar el chequeo de letras con rangos `'A'..'Z'` y `'a'..'z'`.  
- Para vocales, conviene detectar si la letra (ignorando caja) es `A/E/I/O/U`.  
- Para la permutación por bloques de 3 en consonantes, calcular índice `0..25` (A→0, B→1, …), luego `bloque = idx/3`, `pos = idx%3`. Si `pos==0` usar `pos=2`, si `pos==2` usar `pos=0`, si `pos==1` queda igual; reconstruir letra respetando la caja.  
- Para el corrimiento circular de vocales, usar desplazamientos mod 26.  
- Para dígitos, restar el código del carácter a `'9'` y sumar `'0'`.

**Ejemplos rápidos (ilustrativos):**
- Entrada: `“Jgnnq, Ugetgv!”` → (desencriptado) → texto legible según reglas combinadas.  
- Entrada: `“Dr3”` → (D↔F por bloque DEF, r↔t por bloque rst, 3↔6) → `“Ft6”`.

---

### Criterios de evaluación generales
- Compila sin warnings (siempre que sea razonable).  
- Validaciones y manejo de errores de entrada.  
- Uso correcto de **estructuras de control** (bucles, condicionales, `switch` donde aplique).  
- Claridad del código (nombres de variables, comentarios breves).  
