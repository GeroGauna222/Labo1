## Ejercicio 1: Dieta del Deportista

Un nutricionista lleva el control de lo que come un deportista durante una semana. Cada día, el deportista ingresa su consumo de alimentos, con un máximo de 5 alimentos por día.

Escriba un programa que:

* Permita ingresar, por día, los alimentos consumidos (nombre y cantidad de calorías).
* Calcule la cantidad total de calorías ingeridas por día.
* Al final de cada día, imprima:

```
**** DIA [número del día] ****
Alimento 1: [nombre], [calorías]
Alimento 2: ...
Total calorías: [total]
```

* El ingreso termina cuando se ingresa como nombre "FIN" o cuando se llega a 5 alimentos.
* Al final de la semana (7 días), imprimir:

  * Día con mayor consumo calórico
  * Total de calorías consumidas en la semana

**Validaciones:**

* Las calorías deben ser mayores a cero y menores a 5000.
* No ingresar "FIN" como primer alimento del día (debe haber al menos uno).

---

## Ejercicio 2: Juego de adivinanza de números

Escriba un programa que:

* Genere un número secreto aleatorio entre 1 y 50 (utilice `rand()` y `srand(time(NULL))`).
* El usuario tiene 5 intentos para adivinarlo.
* Por cada intento debe mostrar si el número ingresado es:

  * “Muy bajo”
  * “Muy alto”
  * “Correcto”
* Si adivina antes de los 5 intentos, se muestra un mensaje de felicitación.
* Si no lo logra, se muestra el número secreto.

**Validación:**

* El número ingresado debe estar entre 1 y 50.

---

## Ejercicio 3: Convertidor de texto a minúsculas y sin vocales

Realizar un programa que:

* Reciba una frase por teclado (hasta 100 caracteres).
* Genere una nueva cadena donde:

  * Todas las letras se convierten a minúscula.
  * Se eliminan las vocales (`a`, `e`, `i`, `o`, `u`, mayúsculas y minúsculas).
* Imprima el resultado.

**Ejemplo:**
Entrada: "Hola Mundo"
Salida: "hl mnd"

---

## Resoluciones sugeridas
