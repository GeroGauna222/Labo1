# Ejercicios: Estructuras Condicionales y Librerías en C

Los siguientes ejercicios te permitirán practicar el uso de estructuras condicionales junto con las librerías estándar de C.

## Ejercicio 1: Calculadora Avanzada

Desarrolla una calculadora que solicite al usuario dos números y una operación a realizar. Implementa las siguientes operaciones:
- Suma
- Resta
- Multiplicación
- División
- Potencia (x^y)
- Raíz cuadrada de x
- Logaritmo natural de x
- Logaritmo base 10 de x

**Requisitos:**
- Utilizar `stdio.h` para entrada/salida
- Utilizar `math.h` para operaciones matemáticas
- Implementar un menú usando `switch-case`
- Validar errores (como división por cero) usando estructuras `if-else`
- Para la raíz cuadrada y logaritmos, asegúrate de validar que el número sea positivo

## Ejercicio 2: Analizador de Números

Crea un programa que solicite al usuario un número y analice sus características:
- Determinar si es positivo, negativo o cero
- Verificar si es par o impar
- Comprobar si es primo (para números pequeños, usar condicionales)
- Mostrar el valor absoluto usando la librería math.h
- Clasificarlo como entero, decimal o científico según el formato de entrada

**Requisitos:**
- Utilizar `stdio.h` para entrada/salida
- Utilizar `math.h` para funciones matemáticas (abs, floor, ceil)
- Implementar estructuras `if-else` anidadas para clasificación
- Utilizar el operador módulo (%) para verificar si es par/impar
- Utilizar el operador ternario para algunas respuestas

## Ejercicio 3: Sistema de Autenticación Básico

Desarrolla un programa que simule un sistema simple de autenticación y autorización:
- Definir credenciales predeterminadas (usuario: "admin", contraseña: "1234")
- Solicitar al usuario que ingrese nombre de usuario y contraseña
- Validar si las credenciales son correctas
- Mostrar diferentes mensajes según el tipo de usuario (admin, invitado, etc.)
- Simular niveles de acceso según el usuario autenticado

**Requisitos:**
- Utilizar `stdio.h` para entrada/salida
- Utilizar `string.h` para comparar cadenas (strcmp)
- Implementar estructuras `if-else` para validar credenciales
- Utilizar `switch-case` para determinar el nivel de acceso
- Emplear operadores lógicos (&&, ||) para condiciones compuestas

## Ejercicio 4: Validador de Fecha

Desarrolla un programa que solicite al usuario una fecha (día, mes y año) y realice las siguientes tareas:
- Validar si la fecha es correcta (considerando años bisiestos)
- Mostrar el día de la semana correspondiente
- Calcular cuántos días faltan para fin de año
- Indicar si la fecha corresponde a alguna temporada (primavera, verano, otoño, invierno)

**Requisitos:**
- Utilizar `stdio.h` para entrada/salida
- Utilizar estructuras `if-else if-else` anidadas para validar el día según el mes
- Implementar una función para verificar si un año es bisiesto
- Utilizar `time.h` para comparar con la fecha actual (opcional)
- Utilizar `switch-case` para mostrar el nombre del mes

## Ejercicio 5: Conversor de Divisas

Crea un programa que funcione como un conversor de divisas con las siguientes características:
- Permitir al usuario seleccionar la moneda de origen y destino (al menos 5 monedas diferentes)
- Solicitar la cantidad a convertir
- Mostrar el resultado de la conversión con 2 decimales
- Ofrecer la opción de realizar otra conversión o salir

**Requisitos:**
- Utilizar `stdio.h` para entrada/salida
- Utilizar `math.h` para redondeo de valores
- Implementar un menú con `switch-case` para seleccionar monedas
- Validar entradas del usuario con `if-else`
- Utilizar constantes o variables globales para almacenar las tasas de cambio
- Utilizar el operador ternario para alguna validación simple



