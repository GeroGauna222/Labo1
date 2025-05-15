# Clase 1: Introducción a Arduino y Configuración del Entorno

## ¿Qué es Arduino?

Arduino es una plataforma de **hardware y software libre** diseñada para facilitar el uso de la electrónica en proyectos multidisciplinarios. Consiste en una placa con un microcontrolador y un entorno de desarrollo (IDE) que permite escribir, compilar y cargar programas a la placa.

### Características principales de Arduino

- **Accesibilidad**: Diseñado para personas sin amplia experiencia técnica
- **Multiplataforma**: El IDE funciona en Windows, macOS y Linux
- **Código abierto**: Hardware y software de código abierto y extensible
- **Comunidad activa**: Gran cantidad de tutoriales, librerías y proyectos disponibles
- **Economía**: Placas y componentes relativamente económicos

## Instalación del IDE de Arduino

El IDE (Integrated Development Environment) de Arduino es el software que usaremos para programar nuestra placa. Para instalarlo:

1. Visitá la página oficial de Arduino: [arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Descargá la versión correspondiente a tu sistema operativo
3. Instalá el software siguiendo las instrucciones
4. Conectá tu placa Arduino al USB de tu computadora
5. Seleccioná la placa y puerto correctos en el menú Herramientas

### Interfaz del IDE de Arduino

![Interfaz de Arduino IDE](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj2GfJGT4JzSzo0CGVr8ieBY8-IJ9mzDNxv7eO2ik352e3TY7qecybVayI4te1QdNI4tHVkNmc_h8rlL2CmFEBWe4IykovOLexi0ogIkro9T7TcHwNxKV3rNiQ_OaTYrn3FNpSiQc7MwxjO/s1600/slide_14.jpg)

- **Editor de texto**: Donde escribís tu código
- **Área de mensajes**: Muestra información sobre el proceso de compilación y carga
- **Consola**: Muestra mensajes detallados y errores
- **Barra de herramientas**: Contiene botones para verificar, cargar, crear nuevo sketch, etc.
- **Monitor Serie**: Herramienta para la comunicación entre la placa y la computadora

## Tinkercad como alternativa

[Tinkercad](https://www.tinkercad.com) es una plataforma web que permite simular circuitos Arduino sin necesidad de hardware físico.

### Ventajas de Tinkercad

- No requiere hardware físico
- Ideal para principiantes y prototipado rápido
- Permite compartir proyectos fácilmente
- Incluye componentes virtuales variados
- Tiene un monitor serie virtual integrado

Para usar Tinkercad:
1. Creá una cuenta gratuita en tinkercad.com
2. Ingresá a la sección "Circuitos"
3. Seleccioná "Crear nuevo circuito"
4. Arrastrá un Arduino desde la barra lateral al área de trabajo
5. Añadí componentes y conectalos
6. Escribí tu código en el panel de programación

## Descripción de la placa Arduino UNO

La Arduino UNO es la placa más popular y utilizada de la plataforma. Sus componentes principales son:

![Arduino UNO](https://docs.arduino.cc/190368a69b7b0557ea095ef5187ba598/BoardAnatomy.svg)

- **Microcontrolador**: ATmega328P (cerebro de la placa)
- **Pines digitales (14)**: Pines 0-13, para entrada/salida digital (HIGH/LOW)
- **Pines analógicos (6)**: Pines A0-A5, para lectura de valores analógicos
- **Pines de alimentación**:
  - 5V: salida de 5 voltios
  - 3.3V: salida de 3.3 voltios
  - GND: tierra (0V)
- **Puerto USB**: Para alimentación, programación y comunicación serie
- **Botón de reset**: Reinicia el microcontrolador
- **LED integrado**: Conectado al pin 13
- **LEDs de estado**: Power, TX (transmisión) y RX (recepción)

## Conceptos básicos de electrónica

### Ley de Ohm

La Ley de Ohm es una relación fundamental en electrónica que establece:

```
V = I × R
```

Donde:
- **V**: Voltaje en voltios (V)
- **I**: Corriente en amperios (A)
- **R**: Resistencia en ohmios (Ω)

De esta fórmula podemos despejar:
- Corriente: `I = V / R`
- Resistencia: `R = V / I`

### Componentes electrónicos básicos

#### Resistencia

Una **resistencia** limita el flujo de corriente eléctrica en un circuito.

- Se mide en ohmios (Ω)
- El valor se indica mediante bandas de colores
- Es un componente no polarizado (puede conectarse en cualquier dirección)

#### LED (Light Emitting Diode)

Un **LED** es un diodo que emite luz cuando circula corriente a través de él.

- Es un componente polarizado (tiene ánodo + y cátodo -)
- Requiere una resistencia en serie para limitar la corriente
- El ánodo suele ser la pata más larga
- El cátodo suele estar identificado con un lado plano en la base

La resistencia necesaria para un LED se calcula con la fórmula:

```
R = (Vfuente - Vled) / Iled
```

Donde:
- **Vfuente**: Voltaje de la fuente (5V en Arduino)
- **Vled**: Voltaje de caída del LED (típicamente 2V para LEDs rojos)
- **Iled**: Corriente deseada (típicamente 20mA o 0.02A)

Para un LED rojo común, la resistencia adecuada sería:
```
R = (5V - 2V) / 0.02A = 150Ω
```

Se suele usar 220Ω o 330Ω por ser valores estándar y para mayor protección.

#### Breadboard (Protoboard)

La **breadboard** o protoboard es una placa para prototipar circuitos sin soldadura:

![Protoboard](https://arduinointro.com/images/breadboard-900.jpg)

- Las filas están conectadas horizontalmente (normalmente marcadas con letras)
- Las columnas centrales están conectadas verticalmente (marcadas con números)
- Las columnas laterales (raíles) están conectadas verticalmente (suelen usarse para alimentación)

### Display de 7 segmentos

Un **display de 7 segmentos** es un dispositivo que permite mostrar dígitos y algunos caracteres mediante 7 LEDs dispuestos en forma de "8".

![Display 7 segmentos](https://www.todomicro.com.ar/6702-home_default/display-7-segmentos-catodo-comun-056-.jpg)

- Existen dos tipos: **ánodo común** y **cátodo común**
- Cada segmento se nombra con letras de "a" a "g", más el punto decimal "dp"
- Para mostrar diferentes números, se encienden combinaciones específicas de segmentos

## Primer programa: "Hola Mundo" con un LED

En el mundo de Arduino, el equivalente a un "Hola Mundo" es hacer parpadear un LED.

### Circuito básico

![Circuito LED](https://docs.arduino.cc/static/52c238dba09c2e40b69e0612ff02ef0f/a6d36/circuit.png)

- Conectá una resistencia de 220Ω o 330Ω a pin digital 13
- Conectá el ánodo del LED (pata larga) al otro extremo de la resistencia 
- Conectá el cátodo del LED (pata corta) a GND

### Estructura básica de un sketch de Arduino

Un programa de Arduino (llamado **sketch**) tiene dos funciones principales:

```cpp
void setup() {
  // Se ejecuta una sola vez, al inicio
  // Aquí configuramos los pines, iniciamos comunicación serie, etc.
}

void loop() {
  // Se ejecuta repetidamente después de setup()
  // Aquí va el código principal que se ejecutará continuamente
}
```

### Código para hacer parpadear un LED

```cpp
// Definimos el número del pin donde está conectado el LED
const int ledPin = 13;

// La función setup se ejecuta una vez al inicio
void setup() {
  // Inicializamos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  // Iniciamos la comunicación serie a 9600 baudios
  Serial.begin(9600);
  Serial.println("Arduino encendido. Programa 'Blink' iniciado.");
}

// La función loop se ejecuta repetidamente
void loop() {
  // Encendemos el LED
  digitalWrite(ledPin, HIGH);
  
  // Enviamos un mensaje por el monitor serie
  Serial.println("LED encendido");
  
  // Esperamos 1 segundo (1000 milisegundos)
  delay(1000);
  
  // Apagamos el LED
  digitalWrite(ledPin, LOW);
  
  // Enviamos un mensaje por el monitor serie
  Serial.println("LED apagado");
  
  // Esperamos otro segundo
  delay(1000);
}
```

### Uso del Monitor Serie

El Monitor Serie permite la comunicación entre la placa Arduino y la computadora:

- Se activa con `Serial.begin(9600)` en setup() (9600 es la velocidad en baudios)
- Para enviar mensajes se usa `Serial.print()` o `Serial.println()`
- Para abrir el Monitor Serie en el IDE: "Herramientas" > "Monitor Serie" o presioná el botón con ícono de lupa
- Asegurate de que la velocidad (baudios) coincida con la establecida en el código

## Funciones básicas de Arduino

| Función | Descripción | Ejemplo |
|---------|-------------|---------|
| `pinMode()` | Configura un pin como entrada o salida | `pinMode(13, OUTPUT);` |
| `digitalWrite()` | Escribe un valor HIGH o LOW en un pin digital | `digitalWrite(13, HIGH);` |
| `digitalRead()` | Lee el valor de un pin digital (HIGH o LOW) | `int valor = digitalRead(7);` |
| `analogWrite()` | Escribe un valor PWM (0-255) en un pin compatible | `analogWrite(9, 128);` |
| `analogRead()` | Lee el valor de un pin analógico (0-1023) | `int sensor = analogRead(A0);` |
| `delay()` | Pausa el programa por un tiempo en milisegundos | `delay(1000);` |
| `millis()` | Devuelve el tiempo en milisegundos desde que inició el programa | `unsigned long tiempo = millis();` |
| `Serial.begin()` | Inicia la comunicación serie a una velocidad dada | `Serial.begin(9600);` |
| `Serial.println()` | Envía datos al monitor serie y añade nueva línea | `Serial.println("Hola");` |

## Ejemplo práctico: Control de brillo de un LED

Este ejemplo muestra cómo controlar el brillo de un LED utilizando una resistencia variable (potenciómetro).

### Componentes necesarios
- Arduino UNO
- LED
- Resistencia de 220Ω
- Potenciómetro de 10kΩ
- Cables

### Circuito
- Conectá el potenciómetro: pin central a A0, los otros dos pines a 5V y GND
- Conectá una resistencia de 220Ω al pin 9 de Arduino
- Conectá el ánodo del LED a la resistencia
- Conectá el cátodo del LED a GND

### Código

```cpp
// Definimos los pines que vamos a usar
const int potPin = A0;    // Pin analógico para el potenciómetro
const int ledPin = 9;     // Pin PWM para el LED

// Variables para almacenar los valores
int potValue = 0;        // Valor leído del potenciómetro (0-1023)
int ledBrightness = 0;   // Valor para el brillo del LED (0-255)

void setup() {
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  // Iniciamos la comunicación serie
  Serial.begin(9600);
  Serial.println("Control de brillo de LED iniciado");
}

void loop() {
  // Leemos el valor del potenciómetro
  potValue = analogRead(potPin);
  
  // Convertimos el rango de 0-1023 a 0-255
  ledBrightness = map(potValue, 0, 1023, 0, 255);
  
  // Establecemos el brillo del LED
  analogWrite(ledPin, ledBrightness);
  
  // Mostramos la información en el monitor serie
  Serial.print("Valor del potenciómetro: ");
  Serial.print(potValue);
  Serial.print(" | Brillo del LED: ");
  Serial.println(ledBrightness);
  
  // Pequeña pausa para estabilidad
  delay(100);
}
```

## Ejercicios prácticos

1. **LED Intermitente**: Modificá el ejemplo "Blink" para que el LED parpadee en secuencia: rápido, lento, rápido, lento.

2. **Semáforo**: Creá un semáforo usando tres LEDs (rojo, amarillo y verde) con tiempos apropiados para cada luz.

3. **Contador con Display**: Conectá un display de 7 segmentos a Arduino y creá un programa que cuente de 0 a 9.

4. **LED con Botón**: Conectá un botón que encienda un LED mientras se mantenga presionado.

5. **Monitor de Temperatura**: Usá un sensor de temperatura (si disponés) o simulalo con un potenciómetro, mostrando la lectura en el monitor serie.

## Conclusión

En esta clase hemos aprendido los fundamentos básicos de Arduino:

- Qué es Arduino y cómo instalar el entorno de desarrollo
- Los componentes básicos de la placa Arduino UNO
- Conceptos fundamentales de electrónica (Ley de Ohm, resistencia, LEDs)
- Cómo utilizar una protoboard para conexiones seguras
- La estructura básica de un sketch de Arduino con las funciones setup() y loop()
- Cómo crear nuestro primer programa para hacer parpadear un LED
- El uso del monitor serie para depuración

Con estos conocimientos, ya estás listo para comenzar a experimentar con tus propios proyectos básicos de Arduino. En las siguientes clases, exploraremos sensores, actuadores y técnicas más avanzadas para crear proyectos más complejos e interactivos.

## Recursos adicionales

- [Página oficial de Arduino](https://www.arduino.cc/)
- [Documentación de referencia de Arduino](https://www.arduino.cc/reference/en/)
- [Ejemplos incluidos en el IDE de Arduino](https://docs.arduino.cc/built-in-examples/)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits)
- [Guía de resistencias y código de colores](https://www.digikey.com.ar/es/resources/conversion-calculators/conversion-calculator-resistor-color-code) 