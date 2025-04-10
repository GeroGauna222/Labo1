# Clase 4: Librerías en C

## ¿Qué son las librerías en C?

Las librerías en C son colecciones de código precompilado que contienen funciones, declaraciones y tipos de datos que pueden ser utilizados por un programa. Estas librerías facilitan el desarrollo de software al proporcionar funcionalidades comunes que no necesitan ser escritas desde cero.

### Tipos de librerías en C

- **Librerías Estándar**: Son parte de la especificación del lenguaje C y están disponibles en todos los entornos de desarrollo de C. Ejemplos: `stdio.h`, `stdlib.h`, `math.h`.
  
- **Librerías Externas**: Son desarrolladas por terceros y proporcionan funcionalidades adicionales que no están incluidas en las librerías estándar. Ejemplos: GTK, SDL, OpenGL.

### Cómo incluir librerías

Para utilizar una librería en C, se emplea la directiva de preprocesador `#include`:

```c
#include <libreria.h>      // Para librerías estándar
#include "mi_libreria.h"   // Para librerías propias o específicas del proyecto
```

## Librerías Estándar Comunes en C

### stdio.h (Standard Input/Output)

La librería `stdio.h` proporciona funciones para realizar operaciones de entrada y salida.

#### Funciones principales

- **`printf()`**: Imprime texto formateado en la salida estándar.
  ```c
  printf("El valor es: %d\n", 10);
  ```

- **`scanf()`**: Lee datos formateados desde la entrada estándar.
  ```c
  int numero;
  scanf("%d", &numero);
  ```

- **`fopen()`**, **`fclose()`**: Funciones para abrir y cerrar archivos.
  ```c
  FILE *archivo = fopen("texto.txt", "r");
  // Operaciones con el archivo
  fclose(archivo);
  ```

### stdlib.h (Standard Library)

La librería `stdlib.h` proporciona funciones para gestión de memoria, conversiones, y algoritmos generales.

#### Funciones principales

- **`malloc()`**, **`free()`**: Funciones para asignación y liberación dinámica de memoria.
  ```c
  int *arreglo = (int *)malloc(10 * sizeof(int));
  // Usar el arreglo
  free(arreglo);
  ```

- **`rand()`**, **`srand()`**: Funciones para generar números aleatorios.
  ```c
  srand(time(NULL)); // Inicializar generador con semilla basada en tiempo
  int aleatorio = rand() % 100; // Número aleatorio entre 0 y 99
  ```

- **`atoi()`**, **`atof()`**: Funciones para convertir cadenas en números.
  ```c
  int num = atoi("123");        // Convierte a entero
  double decimal = atof("3.14"); // Convierte a double
  ```

### time.h (Time Library)

La librería `time.h` proporciona funciones para manipular información relacionada con fecha y tiempo.

#### Funciones principales

- **`time()`**: Retorna el tiempo actual en segundos desde el epoch (1 de enero de 1970).
  ```c
  time_t tiempoActual;
  time(&tiempoActual);
  printf("Tiempo en segundos desde epoch: %ld\n", tiempoActual);
  ```

- **`difftime()`**: Calcula la diferencia en segundos entre dos tiempos.
  ```c
  time_t inicio = time(NULL);
  // Realizar operaciones...
  time_t fin = time(NULL);
  double diferencia = difftime(fin, inicio);
  printf("Tiempo transcurrido: %.2f segundos\n", diferencia);
  ```

- **`localtime()`**: Convierte un tiempo en una estructura tm con componentes de fecha y hora locales.
  ```c
  time_t ahora = time(NULL);
  struct tm *tiempo_info = localtime(&ahora);
  printf("Fecha actual: %02d/%02d/%04d\n", 
         tiempo_info->tm_mday, tiempo_info->tm_mon + 1, tiempo_info->tm_year + 1900);
  ```

- **`strftime()`**: Formatea una estructura tm en una cadena según un formato especificado.
  ```c
  char buffer[80];
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", tiempo_info);
  printf("Fecha y hora formateada: %s\n", buffer);
  ```

### math.h (Mathematics Library)

La librería `math.h` proporciona funciones matemáticas comunes.

#### Funciones principales

- **`sqrt()`**: Calcula la raíz cuadrada de un número.
  ```c
  double raiz = sqrt(16.0); // Resultado: 4.0
  ```

- **`pow()`**: Calcula la potencia de un número (x^y).
  ```c
  double potencia = pow(2.0, 3.0); // Resultado: 8.0 (2^3)
  ```

- **`sin()`**, **`cos()`**, **`tan()`**: Funciones trigonométricas.
  ```c
  double angulo = 45.0 * M_PI / 180.0; // Convertir grados a radianes
  printf("Seno: %f\n", sin(angulo));
  printf("Coseno: %f\n", cos(angulo));
  printf("Tangente: %f\n", tan(angulo));
  ```

- **`log()`**, **`log10()`**: Logaritmos naturales y en base 10.
  ```c
  double logNatural = log(2.718); // Logaritmo natural (base e)
  double log10Valor = log10(100); // Logaritmo base 10
  ```

- **`ceil()`**, **`floor()`**, **`round()`**: Funciones de redondeo.
  ```c
  printf("Techo de 3.2: %f\n", ceil(3.2));     // Resultado: 4.0
  printf("Piso de 3.8: %f\n", floor(3.8));     // Resultado: 3.0
  printf("Redondeo de 3.5: %f\n", round(3.5)); // Resultado: 4.0
  ```

### string.h (String Library)

La librería `string.h` proporciona funciones para manipular cadenas de caracteres.

#### Funciones principales

- **`strlen()`**: Retorna la longitud de una cadena.
  ```c
  char texto[] = "Hola mundo";
  size_t longitud = strlen(texto); // Resultado: 10
  ```

- **`strcpy()`**, **`strncpy()`**: Copian una cadena a otra.
  ```c
  char destino[20];
  char origen[] = "Programación en C";
  strcpy(destino, origen);      // Copia completa
  strncpy(destino, origen, 12); // Copia limitada a 12 caracteres
  ```

- **`strcat()`**, **`strncat()`**: Concatenan cadenas.
  ```c
  char completo[50] = "Hola, ";
  char nombre[] = "estudiante";
  strcat(completo, nombre);      // Resultado: "Hola, estudiante"
  strncat(completo, "!", 1);     // Resultado: "Hola, estudiante!"
  ```

- **`strcmp()`**, **`strncmp()`**: Comparan cadenas.
  ```c
  char str1[] = "abc";
  char str2[] = "abd";
  int resultado = strcmp(str1, str2); // Resultado negativo: str1 < str2
  ```

- **`strchr()`**, **`strstr()`**: Buscan caracteres o subcadenas dentro de una cadena.
  ```c
  char frase[] = "Programación en C";
  char *posicion = strchr(frase, 'a');    // Busca el primer 'a'
  char *subcadena = strstr(frase, "en");  // Busca "en" en frase
  ```

### ctype.h (Character Type Library)

La librería `ctype.h` proporciona funciones para clasificar y transformar caracteres individuales.

#### Funciones principales

- **Funciones de clasificación de caracteres**:
  ```c
  char c = 'A';
  printf("¿Es letra? %d\n", isalpha(c));      // Verifica si es una letra
  printf("¿Es dígito? %d\n", isdigit(c));     // Verifica si es un dígito
  printf("¿Es alfanumérico? %d\n", isalnum(c)); // Verifica si es letra o dígito
  printf("¿Es espacio? %d\n", isspace(' '));  // Verifica si es espacio en blanco
  printf("¿Es letra mayúscula? %d\n", isupper(c)); // Verifica si es mayúscula
  printf("¿Es letra minúscula? %d\n", islower('a')); // Verifica si es minúscula
  printf("¿Es caracter de control? %d\n", iscntrl('\n')); // Verifica si es control
  printf("¿Es caracter imprimible? %d\n", isprint(c)); // Verifica si es imprimible
  printf("¿Es caracter de puntuación? %d\n", ispunct('.')); // Verifica si es puntuación
  ```

- **Funciones de transformación de caracteres**:
  ```c
  char minuscula = 'a';
  char mayuscula = 'Z';
  
  printf("Minúscula a mayúscula: %c\n", toupper(minuscula)); // Convierte a mayúscula
  printf("Mayúscula a minúscula: %c\n", tolower(mayuscula)); // Convierte a minúscula
  ```

- **Ejemplo de uso práctico**:
  ```c
  char texto[] = "Hola123!";
  int letras = 0, digitos = 0, otros = 0;
  
  for (int i = 0; texto[i] != '\0'; i++) {
      if (isalpha(texto[i]))
          letras++;
      else if (isdigit(texto[i]))
          digitos++;
      else
          otros++;
  }
  
  printf("Letras: %d, Dígitos: %d, Otros caracteres: %d\n", letras, digitos, otros);
  ```

## Ejemplo de uso combinado de librerías

A continuación, un ejemplo que ilustra el uso combinado de varias librerías:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main() {
    // Uso de time.h para inicializar la semilla aleatoria
    srand(time(NULL));
    
    // Uso de stdlib.h para generar números aleatorios
    double numero1 = (double)(rand() % 100) / 10.0;
    double numero2 = (double)(rand() % 100) / 10.0;
    
    printf("Números generados: %.1f y %.1f\n", numero1, numero2);
    
    // Uso de math.h para operaciones matemáticas
    printf("Suma: %.2f\n", numero1 + numero2);
    printf("Raíz cuadrada de %.1f: %.2f\n", numero1, sqrt(numero1));
    
    // Uso de string.h para manipulación de cadenas
    char resultado[50];
    sprintf(resultado, "El resultado es %.2f", numero1 + numero2);
    
    printf("Longitud de la cadena resultado: %lu\n", strlen(resultado));
    printf("Mensaje final: %s\n", resultado);
    
    return 0;
}
```

## Documentación de referencia

Para obtener información detallada sobre todas las librerías estándar de C y sus funciones, se recomienda consultar la siguiente documentación de referencia:
[C Standard Library Reference](https://en.cppreference.com/w/c/header)

Esta documentación en línea proporciona una descripción completa de todas las cabeceras (headers) estándar de C, junto con ejemplos de uso y detalles técnicos de cada función.

## Conclusión

Las librerías en C son componentes fundamentales para el desarrollo eficiente de programas. Proporcionan funcionalidades predefinidas que simplifican tareas comunes como operaciones de entrada/salida, manipulación de cadenas, cálculos matemáticos y gestión del tiempo. El conocimiento de estas librerías y sus funciones principales es esencial para cualquier programador de C, ya que permite escribir código más conciso, legible y mantenible.

Es importante consultar la documentación oficial para utilizar correctamente las funciones de las librerías y aprovechar al máximo sus capacidades.
