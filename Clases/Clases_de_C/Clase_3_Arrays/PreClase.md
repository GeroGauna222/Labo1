# Antes de Empezar, Repasamos

## 🛠️ 1. El Compilador: El Traductor
Antes de programar, hay que entender que la computadora no habla "C", habla binario (ceros y unos). El **compilador** es el arquitecto que traduce tus ideas a instrucciones reales para el procesador.

### El proceso de construcción (Build):
1.  **Preprocesador:** Lee las líneas que arrancan con `#` (como `#include`). Es un "copy-paste" automático de librerías antes de empezar.
2.  **Compilador:** Traduce el código a lenguaje de máquina. Aquí es donde se definen los **Tipos de Datos**.
3.  **Linker (Enlazador):** Une tu código con funciones externas (como `printf`).
4.  **Ejecutable:** El archivo final (`.exe` o `.out`) que la PC puede correr.

---

## 🧠 2. La Memoria RAM en el Lenguaje C
Imaginen la RAM como una biblioteca infinita de estanterias. Cada estante es un **Byte** (con sus bits) y su número es la **Dirección de Memoria**.

* **Variables = Etiquetas:** Una variable es un nombre amigable para una dirección de memoria, es una forma de llamarla y que quede mas lindo (nadie te llama por tu documento, Lauti)
* **Tipos de Datos como Moldes:** Declarar un `int` (N bytes) o un `char` (1 byte) le dice al sistema exactamente cuánto espacio físico reservar para esa variable: si Lauti pesa 100kg, no lo vamos a meter en una cuna...
* **C es "Cercano al Metal":** Usamos el símbolo `&` para obtener la dirección física de una variable, la dirección del estante donde lo voy a guardar.
* **Basura en Memoria:** Si declarás una variable y no le das un valor, C no limpia el espacio. Lo que haya dejado el programa anterior sigue ahí. **Siempre inicializá tus variables.**

---

Basicamente, para entender C (y sistemas en sí) hay que dejar de pensar en "variables" como nombres mágicos y empezar a verlas como **posiciones físicas** en el hardware (EXISTEN, SON REALES). Esta sección profundiza en cómo la computadora gestiona la energía y los transistores para guardar tu información.

### 1. La Arquitectura de la Memoria (La Gran Calle)
Imaginá que la memoria RAM es una calle infinitamente larga. Cada casa en esa calle tiene:
1.  **Una Dirección (Address):** Un número único los vamos a ver como hexadecimal, `0x7ffee4b2`) que identifica esa ubicación exacta.
2.  **Un Contenido:** Los datos que viven dentro de esa dirección.

### El Byte: La Unidad de Vivienda
En esta "calle", cada casa tiene el tamaño exacto de **1 Byte (8 bits)**. 
* Si declarás un `char`, ocupás **1 casa**.
* Si declarás un `int`, el compilador reserva un bloque de **4 casas seguidas** (4 bytes).
* La "dirección de la variable" es siempre la dirección de la **primera casa** de ese bloque.

---

## 2. El Ciclo de Vida: Declaración vs. Inicialización
Este es el concepto más importante para evitar errores lógicos:

### Declaración (Reserva de espacio)
Cuando escribís `int x;`, el Sistema Operativo busca en la "calle" un espacio de 4 bytes que esté vacío y le pone el cartel "Aquí vive X". 
**¡OJO!:** El sistema NO limpia la casa pibe, ocupate, acá no está mamá para que tires esa. Si el programa que usó esa memoria antes dejó un `1452`, tu variable `x` empezará valiendo `1452`. Esto es lo que llamamos **Basura en Memoria**.

### Inicialización (Limpieza y asignación)
Cuando hacés `x = 0;`, recién ahí entrás a la casa y ponés el valor que querés, sino simplemente estas apuntando a un **valor basura** 
> **Regla de Oro:** Nunca uses una variable sin haberle asignado un valor primero. En C, la suerte no existe; solo existe lo que quedó escrito antes (xd).

---

## 3. El Operador de Dirección (`&`)
C te da la "llave" para mirar la calle y acceder a esa casa. El símbolo `&` (ampersand) se lee como **"la dirección de"**.

```c
int numero = 10;
printf("El valor es: %d\n", numero);   // Imprime 10
printf("La casa es la: %p\n", &numero); // Imprime algo como 0x7ffd...
```
Entender esto es la base de los **Punteros**, que vamo a ver más adelante. Por ahora, pensalo así: `numero` te da el numero en sí, y `&numero` te da su dirección para que lo encuentres.

---

## 4. El Mapa de Memoria: Stack (Pila)
Las variables que declaramos dentro de una función (como `main`) viven en una zona llamada **Stack**.
* Es extremadamente rápida.
* Es automática: cuando la función termina, el cartel con el nombre de la variable se saca y el espacio queda libre (pero la "basura" del valor se queda ahí hasta que alguien más la use).

---

## 5. Corrupción de Memoria
¿Qué pasa si intentás entrar a una casa que no te pertenece?
Si tenés un array de 5 posiciones y tratás de escribir de más, vas a poder, así corrompes datos

---

## 6. Visualización Física
| Dirección (Hex) | Nombre | Contenido (Binario/Valor) |
| :--- | :--- | :--- |
| `0x001` | `char a` | `01000001` ('A') |
| `0x002` | `int x` (byte 1) | `00000000` |
| `0x003` | `int x` (byte 2) | `00000000` |
| `0x004` | `int x` (byte 3) | `00000000` |
| `0x005` | `int x` (byte 4) | `00001010` (10) |
| `0x006` | (Disponible) | `11010101` (BASURA) |

---

### Resumen para cerrar (ponele):
1.  **La RAM es contigua:** Todo vive uno al lado del otro.
2.  **C no limpia:** Vos sos responsable de inicializar.
3.  **Los tipos definen el tamaño:** Un `int` no es solo un número, son 4 bytes de espacio físico.
4.  **No te pases de los límites:** Tocar memoria ajena es el fin de tu ejecución.
