# Ejercicios: Librerías en C

A continuación, se presentan una serie de ejercicios para practicar el uso de librerías estándar en C. Los ejercicios están ordenados de menor a mayor dificultad.

## Ejercicio 1: Calculadora de Operaciones Matemáticas (math.h)

**Objetivo:** Crear una calculadora que realice operaciones matemáticas avanzadas.

**Instrucciones:**
1. Solicitar al usuario que ingrese un número positivo.
2. Mostrar:
   - La raíz cuadrada del número
   - El logaritmo natural del número
   - El valor de e elevado al número (e^x)
   - El seno y coseno del número (considerando que el número está en radianes)
   - El valor redondeado hacia arriba y hacia abajo

**Librerías a utilizar:** stdio.h, math.h

## Ejercicio 2: Manipulación de Cadenas (string.h)

**Objetivo:** Crear un programa que manipule cadenas de texto.

**Instrucciones:**
1. Solicitar al usuario que ingrese una frase de hasta 100 caracteres.
2. Mostrar:
   - La longitud de la frase
   - La frase en mayúsculas
   - La frase invertida
3. Solicitar una palabra y verificar si esta palabra está contenida en la frase original.
4. Si la palabra está contenida, mostrar la posición donde comienza.

**Librerías a utilizar:** stdio.h, string.h, ctype.h

## Ejercicio 3: Generador de Números Aleatorios (stdlib.h, time.h)

**Objetivo:** Crear un programa que genere números aleatorios y realice estadísticas básicas.

**Instrucciones:**
1. Solicitar al usuario la cantidad de números aleatorios a generar (n) y el rango (min, max).
2. Generar n números aleatorios entre min y max.
3. Mostrar:
   - Los números generados
   - El promedio de los números
   - El número máximo y mínimo generado
   - El tiempo que tardó en generar todos los números (en milisegundos)

**Librerías a utilizar:** stdio.h, stdlib.h, time.h

## Ejercicio 4: Gestor de Fechas y Tiempos (time.h)

**Objetivo:** Crear un programa que trabaje con fechas y calcule diferencias de tiempo.

**Instrucciones:**
1. Mostrar la fecha y hora actual en formato: "DD/MM/AAAA HH:MM:SS".
2. Solicitar al usuario una fecha en formato DD/MM/AAAA.
3. Calcular y mostrar:
   - Cuántos días han pasado desde esa fecha hasta hoy (o faltan si la fecha es futura)
   - En qué día de la semana caerá/cayó esa fecha (lunes, martes, etc.)
   - Cuántos años, meses y días han pasado/faltan exactamente

**Librerías a utilizar:** stdio.h, time.h, string.h

## Ejercicio 5: Análisis de Texto (stdio.h, string.h, ctype.h)

**Objetivo:** Crear un programa que realice un análisis completo de un texto desde un archivo.

**Instrucciones:**
1. Abrir un archivo de texto cuyo nombre será proporcionado por el usuario.
2. Analizar el texto y mostrar:
   - Número total de caracteres (incluyendo espacios)
   - Número de palabras
   - Número de líneas
   - Frecuencia de cada letra (a-z, sin distinguir entre mayúsculas y minúsculas)
   - Las 5 palabras más frecuentes y su conteo
   - Longitud promedio de las palabras

**Librerías a utilizar:** stdio.h, string.h, ctype.h, stdlib.h

