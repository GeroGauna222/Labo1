# Ejercicios de Bajo Nivel (3): Manipulación de Strings y ASCII

## Reglas Generales para los 3 Ejercicios

* **Prohibido** el uso de `<ctype.h>` (no me vengas con usar `toupper`, `tolower`, `isdigit`, etc.).
* **Ojo!!!** El ingreso de datos debe ser **robusto** (usar `fgets` y limpiar el salto de línea residual).
* Se debe trabajar directamente con los valores de la **Tabla ASCII** y comparaciones de rangos.

---

## Protocolo de Telemetría Médica

**Temática:** Un dispositivo de monitoreo cardíaco envía señales encriptadas para proteger la privacidad del paciente. Tu tarea es desarrollar el decodificador de bajo nivel.

**Consigna:**
Leer una cadena de caracteres (máx. 100) y transformarla según las siguientes reglas:

1. **Vocales minúsculas:** Reemplazarlas por su posición en la lista de vocales: `'a'→'1'`, `'e'→'2'`, `'i'→'3'`, `'o'→'4'`, `'u'→'5'`.
2. **Consonantes (Mayúsculas y Minúsculas):** Desplazarlas **+2 posiciones** en el abecedario manteniendo su caso original.
* *Comportamiento Circular:* Si es `'y'`, pasa a ser `'a'`. Si es `'Z'`, pasa a ser `'B'`.


3. **Espacios:** Reemplazarlos por el carácter de numeral `'#'`.
4. **Dígitos originales (números):** Deben ser eliminados de la cadena o reemplazados por un punto `'.'`.
5. **Símbolos:** Cualquier otro carácter no mencionado debe permanecer igual.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    
    printf("Ingrese telemetría: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0'; // Limpieza del \n

    for (int i = 0; msg[i] != '\0'; i++) {
        char c = msg[i];

        // 1. Para vocales minúsc
        if (c == 'a') msg[i] = '1';
        else if (c == 'e') msg[i] = '2';
        else if (c == 'i') msg[i] = '3';
        else if (c == 'o') msg[i] = '4';
        else if (c == 'u') msg[i] = '5';
        
        // 2. Ahora consonantes (y letras en general, las vocales ya salieron arriba)
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Manejo circular para 'y', 'z', 'Y', 'Z'
            if (c == 'y') msg[i] = 'a';
            else if (c == 'z') msg[i] = 'b';
            else if (c == 'Y') msg[i] = 'A';
            else if (c == 'Z') msg[i] = 'B';
            else msg[i] = c + 2;
        }
        
        // 3. Espacios
        else if (c == ' ') msg[i] = '#';
        
        // 4. Digitos originales
        else if (c >= '0' && c <= '9') msg[i] = '.';
    }

    printf("Mensaje Decodificado: %s\n", msg);
    return 0;
}
```

---

## Cifrado de la Sonda Voyager 3

**Temática:** Una sonda espacial ha enviado un reporte de estado, pero la radiación cósmica invirtió la lógica de los bytes según su posición.

**Consigna:**
Procesar un string basando la transformación en el **índice (posición)** de cada carácter:

1. **Si el índice es PAR:**
* Si el carácter es una letra, **invertir su caso** (Mayúscula a minúscula y viceversa).
* *Pista:* La distancia entre 'A' y 'a' es de **32** posiciones.


2. **Si el índice es IMPAR:**
* Si es una letra, desplazarla **-5 posiciones** (hacia la izquierda) de forma circular.
* *Ejemplo:* `'f'→'a'`, `'b'→'w'`. Si el resultado es menor al límite inferior, sumar $26$.


3. **Dígitos (0-9):** Sin importar la posición, reemplazarlos por su **complemento a 9**.
* *Ejemplo:* `'0'→'9'`, `'3'→'6'`, `'9'→'0'`.


4. **Símbolos especiales:** No deben ser modificados.

---

## Parche del Kernel Legacy

**Temática:** Estás recuperando comandos de un servidor de 1980. El sistema utiliza un filtro de limpieza para normalizar instrucciones de bajo nivel.

**Consigna:**
Analizar el string ingresado y aplicar el siguiente filtro secuencial:

1. **Cifrado ROT13:** * Letras entre `'A'` y `'M'` (y sus minúsculas) se desplazan **+13**.
* Letras entre `'N'` y `'Z'` (y sus minúsculas) se desplazan **-13**.


2. **Limpieza de Símbolos:** Cualquier carácter que **NO** sea una letra ni un espacio debe reemplazarse por un guion bajo `'_'`.
3. **Regla de Estado (Compresión básica):** Si un carácter es exactamente igual al carácter anterior, el segundo debe reemplazarse por un asterisco `'*'`.
* *Requisito:* Usar una variable `char letra_anterior` inicializada en `'\0'`.


4. **Visualización:** Al finalizar, imprimir el string resultante y la cantidad total de caracteres que fueron modificados.

