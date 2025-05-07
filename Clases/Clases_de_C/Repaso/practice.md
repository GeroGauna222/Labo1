## Ejercicio 1: Dieta del Deportista (versión menú de opciones)

Un nutricionista lleva el control de lo que come un deportista *durante una semana*. Cada día, el deportista ingresa su consumo de en cada comida, siempre ingresa las 4 comidas.

Escriba un programa que implemente un **menú** con las siguientes opciones:

1. Ingresar alimentos (nombre y calorías) del día actual. Si repite esta opción, se debe sobreescribir lo ingresado previamente
2. Finalizar el día.
3. Mostrar el total de calorías consumidas este día.
4. Mostrar el total de calorías de la semana hasta el momento.
5. Mostrar el día con mayor consumo calórico hasta el momento.

El programa debe:

* Calcular la cantidad total de calorías ingeridas por día.
* Al final de cada día, imprimir:

```
**** DIA [número del día] ****
Desayuno: [nombre], [calorías]
Almuerzo: ...
Merienda: ...
Cena: ...
Total calorías: [total]
```

* El ingreso de alimentos por día termina cuando el usuario selecciona la opción 2, pero no se puede finalizar un día sin haber ingresado alimentos.
* Repetir este proceso durante 7 días.
* Al finalizar la semana, imprimir:

  * Día con mayor consumo calorico.
  * Día con menor consumo calorico
  * Total de calorías consumidas en la semana.
  * Si, **en promedio**, el atleta consumio mas de 3000 calorias por dia.
  * Si hubo algún día que no comió (cals 0)

**Validaciones:**

* Las calorías deben ser mayores o iguales a cero.
* Controlar que la opción elegida sea válida (entre 1 y 5).
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
