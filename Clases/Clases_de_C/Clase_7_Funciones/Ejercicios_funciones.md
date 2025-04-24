# Ejercicios: Funciones en Lenguaje C

Los siguientes ejercicios te permitirán practicar la implementación y uso de funciones en C, aplicando los conceptos vistos en clase.

## Ejercicio 1: Biblioteca de Operaciones Matemáticas

Creá una biblioteca de funciones matemáticas que incluya:
- Función para calcular el factorial de un número
- Función para verificar si un número es primo
- Función para calcular la potencia de un número
- Función para calcular la serie de Fibonacci hasta n términos
- Una función principal que muestre un menú para elegir la operación a realizar

**Requisitos:**
- Creá prototipos de todas las funciones al inicio del programa
- Implementá al menos una función recursiva (factorial o Fibonacci)
- Validá los datos de entrada (números negativos, etc.)
- Implementá un menú interactivo usando funciones
- Documentá cada función con comentarios explicando su propósito, parámetros y valor de retorno

## Ejercicio 2: Sistema de Gestión de Estudiantes

Desarrollá un sistema para gestionar información de estudiantes con las siguientes funciones:
- Registrar estudiante (nombre, ID, promedio)
- Buscar estudiante por ID
- Mostrar todos los estudiantes
- Calcular el promedio general del curso
- Encontrar el estudiante con mayor y menor promedio

**Requisitos:**
- Utilizá un arreglo de estructuras para almacenar los datos
- Implementá funciones independientes para cada operación
- Pasá arreglos como parámetros a las funciones
- Utilizá variables globales solo cuando sea estrictamente necesario
- Implementá funciones con múltiples parámetros

## Ejercicio 3: Manipulador de Cadenas

Creá un programa que ofrezca diversas operaciones con cadenas de caracteres, cada una implementada como una función separada:
- Contar la cantidad de vocales en una cadena
- Invertir una cadena
- Verificar si una cadena es palíndromo (se lee igual de izquierda a derecha y viceversa)
- Convertir una cadena a mayúsculas o minúsculas
- Contar ocurrencias de una subcadena dentro de otra

**Requisitos:**
- Utilizá funciones de la biblioteca `string.h` cuando sea apropiado
- Creá tus propias funciones cuando sea necesario
- Implementá funciones que devuelvan diferentes tipos de datos (int, char*, bool)
- Validá entradas y manejá casos límite
- Pasá cadenas como parámetros entre funciones

## Ejercicio 4: Conversor Universal

Desarrollá un programa que permita convertir entre diferentes unidades utilizando funciones:
- Conversiones de temperatura (Celsius, Fahrenheit, Kelvin)
- Conversiones de longitud (metros, pies, pulgadas, yardas)
- Conversiones de masa (kilogramos, libras, onzas)
- Conversiones de volumen (litros, galones, pies cúbicos)
- Conversiones de tiempo (segundos, minutos, horas, días)

**Requisitos:**
- Creá una función independiente para cada tipo de conversión
- Implementá funciones que reciban variables por valor
- Agrupá funciones relacionadas conceptualmente
- Implementá una función principal que presente un menú de opciones
- Documentá todas las fórmulas utilizadas con comentarios

## Ejercicio 5: Analizador de Datos Estadísticos

Creá una aplicación para analizar conjuntos de datos numéricos con las siguientes funciones:
- Calcular la media aritmética
- Calcular la mediana
- Calcular la moda (valor más frecuente)
- Calcular la desviación estándar
- Encontrar el valor máximo y mínimo
- Ordenar los datos (implementá al menos dos algoritmos de ordenamiento diferentes)

**Requisitos:**
- Implementá cada operación estadística como una función independiente
- Creá funciones que operen sobre arreglos
- Utilizá variables estáticas cuando sea apropiado
- Implementá al menos una función recursiva para alguna operación
- Validá la entrada de datos y manejá posibles errores
- Creá una función de visualización para mostrar los resultados de manera clara