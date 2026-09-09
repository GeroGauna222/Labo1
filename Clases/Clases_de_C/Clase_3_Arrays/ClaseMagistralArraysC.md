# **Clase Magistral: Memoria, Buffers y Arrays en C**

*De la arquitectura de hardware al control profesional de estructuras de datos y flujos de entrada*

## **Bloque 0: Cimientos de Hardware y Compilación**

### **1\. El Pipeline de Construcción (Build Process)**

Al compilar un archivo fuente (.c), la cadena de herramientas (toolchain) ejecuta cuatro etapas secuenciales indispensables:

\[ archivo.c \]  
      │  
      ▼  (1) PREPROCESADOR: Resuelve directivas '\#' (\#include, \#define) y purga comentarios.  
\[ archivo.i \]  
      │  
      ▼  (2) COMPILADOR: Chequea tipos de datos, sintaxis y traduce a Assembly.  
\[ archivo.s \]  
      │  
      ▼  (3) ENSAMBLADOR: Traduce Assembly a instrucciones de máquina (Código Objeto).  
\[ archivo.o / .obj \]  
      │  
      ▼  (4) LINKER / ENLAZADOR: Enlaza llamadas externas (ej. printf) con la biblioteca estándar (libc).  
\[ ejecutable final (.exe / .out) \]

### **2\. La Arquitectura de la Memoria RAM**

La memoria RAM se estructura como una secuencia contigua e indexada de casillas de 1 Byte (8 bits). Cada casilla física cuenta con un identificador único e inmutable: su Dirección de Memoria, expresada habitualmente en base hexadecimal (por ejemplo, 0x7ffee4b0).

| Tipo de Dato | Tamaño Típico | Rango / Representación |
| :---- | :---- | :---- |
| char | 1 Byte (8 bits) | \-128 a 127 (o un carácter de la tabla ASCII) |
| int | 4 Bytes (32 bits) | \-2.147.483.648 a 2.147.483.647 |
| float | 4 Bytes (32 bits) | Precisión simple (\~6 a 7 dígitos significativos) |
| double | 8 Bytes (64 bits) | Doble precisión (\~15 a 17 dígitos significativos) |

 

### **3\. El Stack y la 'Basura en Memoria'**

Las variables locales declaradas dentro de cualquier función residen en el Stack (Pila de ejecución). Conviene desmitificar cómo opera:

> * **Declaración (int x;):** El compilador desplaza el puntero del stack (Stack Pointer) reservando 4 bytes contiguos. Ni el compilador ni el sistema operativo limpian dicho bloque por razones de rendimiento. Lo que residía allí con anterioridad (fragmentos de programas previos) se interpreta como el valor inicial: la denominada **Basura en Memoria**.  
> * **Inicialización (x \= 0;):** Es la acción deliberada y obligatoria de escribir un valor confiable sobre esa posición física antes de intentar consumirlo.

### **4\. El Operador de Dirección (&)**

Para inspeccionar la dirección física donde fue ubicada una variable se antepone el operador &. El estándar ANSI/ISO de C establece que para imprimir una dirección con printf debe utilizarse el especificador %p casteando el puntero a (void\*):

\#include \<stdio.h\>

int main(void) {  
    int valor \= 42;  
    printf("Contenido: %d\\n", valor);  
    printf("Direccion en memoria: %p\\n", (void\*)\&valor);  
    return 0;  
}

## **Bloque 1: Arrays Unidimensionales (Vectores)**

### **1\. Definición Formal**

Un **array** es una colección finita y homogénea de elementos del mismo tipo, almacenados de forma **estrictamente contigua** en la memoria física.

### **2\. Disposición Física en Memoria**

Consideremos la declaración int edades\[4\] \= {18, 25, 30, 42}; en un sistema de 32 o 64 bits con enteros de 4 bytes:

Dirección Base: 0x1000        0x1004        0x1008        0x100C  
             ┌─────────────┬─────────────┬─────────────┬─────────────┐  
Contenido:   │     18      │     25      │     30      │     42      │  
             └─────────────┴─────────────┴─────────────┴─────────────┘  
Índice:         edades\[0\]     edades\[1\]     edades\[2\]     edades\[3\]  
               (Offset: 0B)  (Offset: 4B)  (Offset: 8B)  (Offset: 12B)

### **3\. La Matemática del Índice (¿Por qué arranca en 0?)**

El índice en C no denota orden ordinal, sino un **desplazamiento (offset)** en bytes respecto al inicio del bloque:  
**Dirección(array\[i\]) \= Dirección\_Base \+ (i \* sizeof(tipo))**

> * Para el primer elemento (i \= 0): 0x1000 \+ (0 \* 4\) \= 0x1000. Está a cero bytes de distancia.  
> * Para el segundo elemento (i \= 1): 0x1000 \+ (1 \* 4\) \= 0x1004. Desplazado exactamente 4 bytes.

### **4\. Demostración Práctica de Contigüidad**

\#include \<stdio.h\>

int main(void) {  
    int v\[4\] \= {10, 20, 30, 40};

    printf("Tamano de un 'int' en este sistema: %zu bytes\\n\\n", sizeof(int));  
    for (int i \= 0; i \< 4; i++) {  
        printf("Indice \[%d\] | Valor: %2d | Direccion: %p\\n",   
               i, v\[i\], (void\*)\&v\[i\]);  
    }  
    return 0;  
}

## **Bloque 2: Reglas de Declaración e Inicialización**

En C existen cinco escenarios fundamentales a la hora de crear arrays:

// 1\. Inicialización explícita completa:  
int nums\[3\] \= {10, 20, 30};

// 2\. Tamaño deducido por el compilador:  
int datos\[\] \= {1, 2, 3, 4}; // Longitud fija en 4

// 3\. Inicialización completa a CERO (Regla de higiene recomendada):  
int limpios\[100\] \= {0}; // Garantiza que los 100 enteros queden en 0

// 4\. Inicialización parcial garantizada por el estándar:  
int parcial\[5\] \= {9, 8}; // parcial\[0\]=9, parcial\[1\]=8; parcial\[2..4\] valen 0

// 5\. Sin inicializar (PELIGRO):  
int sucios\[5\]; // Las 5 posiciones contienen basura residual

### **Cálculo Idiomático del Tamaño en Tiempo de Compilación**

Los arrays en C no guardan metadatos sobre su propia longitud. Para no fijar constantes rígidas que provoquen desincronización en el código, se calcula la cantidad de elementos con sizeof:

int vector\[\] \= {4, 8, 15, 16, 23, 42};  
size\_t longitud \= sizeof(vector) / sizeof(vector\[0\]);

printf("Cantidad de elementos: %zu\\n", longitud); // Imprime 6

## **Bloque 3: Strings (Cadenas de Caracteres)**

### **1\. En C no existe el tipo "string"**

Una cadena de texto es sencillamente un **array de char que finaliza obligatoriamente con el carácter nulo \\0 (ASCII 0\)**. Este carácter actúa como un centinela: como las funciones desconocen la capacidad máxima del array donde reside la palabra, iteran byte a byte hasta chocar con el byte nulo.

### **2\. Representación en Memoria de "HOLA"**

char palabra\[5\] \= "HOLA"; // 4 caracteres útiles \+ 1 byte para el centinela '\\0'

Índice:        \[0\]     \[1\]     \[2\]     \[3\]     \[4\]  
Contenido:   ┌───────┬───────┬───────┬───────┬───────┐  
             │  'H'  │  'O'  │  'L'  │  'A'  │ '\\0'  │  
             └───────┴───────┴───────┴───────┴───────┘  
Código ASCII:   72      79      76      65       0

### **3\. La Diferencia Fundamental: sizeof vs. strlen**

> * **sizeof(cadena):** Consulta al compilador el tamaño total del estante físico en bytes.  
> * **strlen(cadena):** Recorre en ejecución la memoria contando caracteres hasta encontrar el centinela \\0 (no lo incluye en la cuenta).

\#include \<stdio.h\>  
\#include \<string.h\>

int main(void) {  
    char saludo\[50\] \= "Hola";  
    printf("sizeof: %zu bytes reservados\\n", sizeof(saludo)); // 50  
    printf("strlen: %zu caracteres utiles\\n", strlen(saludo)); // 4  
    return 0;  
}

### **4\. Funciones Críticas de \<string.h\>**

| Función | Comportamiento |
| :---- | :---- |
| strlen(s) | Devuelve el recuento de caracteres previos al \\0. |
| strcpy(dest, orig) | Copia una cadena (insegura si dest no posee la capacidad requerida). |
| strncpy(dest, orig, n) | Copia acotada hasta n bytes para mitigar desbordes. |
| strcat(dest, orig) | Concatena la cadena orig al final de dest. |
| strcmp(s1, s2) | Compara lexicográficamente; devuelve 0 si ambas cadenas son idénticas. |
| strcspn(s, "\\n") | Determina el índice del primer salto de línea para purgarlo. |

 

## **Bloque 4: La Batalla de los Buffers de Entrada (stdin y stdout)**

### **1\. El Buffer stdin como "Cinta Transportadora"**

Las pulsaciones de teclado no ingresan de inmediato a las variables: se encolan en un buffer administrado por el Sistema Operativo llamado stdin. Al teclear 42 y presionar ENTER, viajan a la cola tres elementos: \['4', '2', '\\n'\].

### **2\. Las Fallas Clásicas de scanf()**

> * **La "resaca" del salto de línea (\\n):** Al ejecutar scanf("%d", \&edad);, la función consume los dígitos numéricos pero **abandona el carácter '\\n' en el buffer**. La posterior lectura de cadenas interpretará ese salto residual como un Enter inmediato, salteándose la interacción del usuario.  
> * **Desbordamiento de Buffer (Buffer Overflow):** Al hacer scanf("%s", buffer);, la función no acota la cantidad de caracteres recibidos. Si el usuario ingresa más caracteres de los reservados, corrompe variables contiguas del Stack. Además, detiene la lectura en el primer espacio en blanco.

### **3\. El Estándar Seguro de la Industria: fgets() \+ sscanf()**

La arquitectura robusta desacopla la lectura del flujo respecto a la interpretación de los datos:

> 1. **fgets():** Lee una línea completa de forma acotada y segura garantizando que nunca se exceda el tamaño del array.  
> 2. **sscanf():** Analiza esa cadena ya resguardada en memoria local y extrae los tipos de datos requeridos.

\#include \<stdio.h\>  
\#include \<string.h\>

int main(void) {  
    char linea\[128\];  
    char nombre\[50\];  
    int edad;

    // 1\. Lectura robusta de cadena (admite espacios y limpia el Enter)  
    printf("Ingrese su nombre completo: ");  
    if (fgets(linea, sizeof(linea), stdin) \!= NULL) {  
        linea\[strcspn(linea, "\\n")\] \= '\\0'; // Reemplazo del salto de línea por el centinela  
        strncpy(nombre, linea, sizeof(nombre) \- 1);  
        nombre\[sizeof(nombre) \- 1\] \= '\\0';  
    }

    // 2\. Lectura robusta de números a prueba de entradas erróneas  
    printf("Ingrese su edad: ");  
    if (fgets(linea, sizeof(linea), stdin) \!= NULL) {  
        if (sscanf(linea, "%d", \&edad) \== 1\) {  
            printf("\\nExito \-\> Nombre: %s | Edad: %d\\n", nombre, edad);  
        } else {  
            printf("\\nError: Entrada numerica invalida.\\n");  
        }  
    }

    return 0;  
}

## **Bloque 5: Los Cuatro Errores Críticos con Arrays**

> 1. **Error por Uno (Off-by-One):** Iterar hasta i \<= N en lugar de i \< N, escribiendo un byte más allá del límite permitido.  
> 2. **Cadena sin Terminador Nulo:** Construir un vector de caracteres sin reservar espacio para \\0. Funciones como printf("%s") imprimirán basura continua hasta provocar un fallo de segmentación (Segmentation Fault).  
> 3. **Corrupción Silenciosa de Variables:** Escribir fuera de los límites de un array en el Stack sobrescribe de manera inadvertida variables adyacentes declaradas a continuación.  
> 4. **Array Decay en Funciones:** Al recibir un array como argumento de función, este decae a un puntero hacia su primer elemento. En ese ámbito, sizeof(arr) devuelve el tamaño del puntero (4 u 8 bytes) y no la dimensión real de la estructura. Se debe pasar siempre un argumento adicional con el tamaño: void procesar(int arr\[\], size\_t n).

## **Bloque 6: Ejercitaciones de Laboratorio**

### **Ejercicio 1: Inversión In-Place de un Vector**

Invertir los elementos de un array directamente sobre su bloque de memoria sin recurrir a estructuras auxiliares:

\#include \<stdio.h\>  
\#define N 6

int main(void) {  
    int arr\[N\] \= {10, 20, 30, 40, 50, 60};

    for (int i \= 0; i \< N / 2; i++) {  
        int temp \= arr\[i\];  
        arr\[i\] \= arr\[N \- 1 \- i\];  
        arr\[N \- 1 \- i\] \= temp;  
    }

    printf("Vector invertido: ");  
    for (int i \= 0; i \< N; i++) printf("%d ", arr\[i\]);  
    printf("\\n");  
    return 0;  
}

### **Ejercicio 2: Cifrado por Desplazamiento Directo en ASCII**

Transformar caracteres minúsculas desplazándolos 3 posiciones en el abecedario de manera circular sin librerías externas de clasificación:

\#include \<stdio.h\>  
\#include \<string.h\>

int main(void) {  
    char buffer\[128\];

    printf("Ingrese texto: ");  
    if (fgets(buffer, sizeof(buffer), stdin) \!= NULL) {  
        buffer\[strcspn(buffer, "\\n")\] \= '\\0';

        for (int i \= 0; buffer\[i\] \!= '\\0'; i++) {  
            if (buffer\[i\] \>= 'a' && buffer\[i\] \<= 'z') {  
                buffer\[i\] \= buffer\[i\] \+ 3;  
                if (buffer\[i\] \> 'z') {  
                    buffer\[i\] \= buffer\[i\] \- 26;  
                }  
            }  
        }  
        printf("Mensaje procesado: %s\\n", buffer);  
    }  
    return 0;  
}  
