# Clase 2: Entradas Analógicas, PWM y Comunicación Serial

## Entradas Analógicas en Arduino

A diferencia de las entradas digitales (que solo detectan HIGH o LOW), las entradas analógicas pueden medir un rango continuo de voltajes, lo que permite detectar sensores que producen salidas variables como potenciómetros, sensores de luz, temperatura, etc.

### Características de las Entradas Analógicas

- **Resolución**: Arduino UNO tiene un ADC (Convertidor Analógico-Digital) de 10 bits, lo que significa que convierte voltajes entre 0-5V en valores enteros entre 0-1023
- **Pines**: Arduino UNO tiene 6 pines de entrada analógica (A0-A5)
- **Rango de voltaje**: Normalmente de 0V a 5V (o al voltaje de referencia)
- **Velocidad de muestreo**: Aproximadamente 10,000 muestras por segundo

### Función `analogRead()`

La función `analogRead()` se utiliza para leer valores de los pines analógicos:

```cpp
int valorSensor = analogRead(A0); // Lee el valor del pin A0 (0-1023)
```

### Ejemplos de sensores analógicos comunes

- **Potenciómetro**: Resistencia variable que cambia según la posición
- **LDR (Light Dependent Resistor)**: Resistencia que varía con la intensidad de la luz
- **Termistor**: Resistencia que varía con la temperatura
- **Sensor de distancia infrarrojo**: Proporciona voltaje según la distancia
- **Acelerómetros**: Miden la aceleración y orientación

## PWM (Pulse Width Modulation)

PWM es una técnica que permite simular una señal analógica utilizando una señal digital, controlando el tiempo que la señal permanece en estado alto versus el tiempo en estado bajo.

### Características del PWM en Arduino

- **Resolución**: Arduino utiliza una resolución de 8 bits para PWM (valores de 0 a 255)
- **Pines compatibles**: En Arduino UNO, los pines con capacidad PWM son 3, 5, 6, 9, 10 y 11 (marcados con ~)
- **Frecuencia**: En la mayoría de los pines de Arduino UNO es aproximadamente 490 Hz
- **Aplicaciones**: Control de brillo de LEDs, control de velocidad de motores, generación de tonos, etc.

### Función `analogWrite()`

La función `analogWrite()` se utiliza para generar una señal PWM:

```cpp
analogWrite(pin, valor); // pin: pin PWM, valor: 0-255
```

### Ciclo de trabajo (Duty Cycle)

El ciclo de trabajo representa la proporción del tiempo que la señal está en estado alto:

- `analogWrite(pin, 0)` → 0% ciclo de trabajo (siempre apagado)
- `analogWrite(pin, 127)` → 50% ciclo de trabajo (mitad encendido, mitad apagado)
- `analogWrite(pin, 255)` → 100% ciclo de trabajo (siempre encendido)

## Comunicación Serial

La comunicación serial permite que Arduino intercambie datos con la computadora u otros dispositivos, enviando bits de forma secuencial.

### Características de la Comunicación Serial

- **Velocidad**: Se mide en baudios (bits por segundo), comúnmente 9600 baudios
- **Pines**: En Arduino UNO, los pines 0 (RX) y 1 (TX) se utilizan para comunicación serial
- **Buffer**: Arduino tiene un buffer de recepción de 64 bytes
- **Monitor Serial**: Herramienta en el IDE que permite ver y enviar datos seriales

### Funciones Básicas de Comunicación Serial

```cpp
Serial.begin(9600);     // Inicia comunicación serial a 9600 baudios
Serial.print("Texto");  // Envía texto sin nueva línea
Serial.println("Texto"); // Envía texto con nueva línea al final
Serial.write(valor);    // Envía un byte o una serie de bytes
int dato = Serial.read(); // Lee un byte del buffer serial (-1 si no hay datos)
int disponible = Serial.available(); // Devuelve la cantidad de bytes disponibles
```

## Ejemplo 1: Lectura de un Sensor Analógico

Este ejemplo muestra cómo leer un potenciómetro y enviar el valor por comunicación serial.

### Componentes necesarios
- Arduino UNO
- Potenciómetro de 10kΩ
- Cables

### Circuito
- Conectá el pin central del potenciómetro al pin A0
- Conectá uno de los pines externos del potenciómetro a 5V
- Conectá el otro pin externo del potenciómetro a GND

### Código

```cpp
// Definimos el pin para el potenciómetro
const int potPin = A0;

// Variable para almacenar el valor leído
int valorPot = 0;

void setup() {
  // Iniciamos comunicación serial a 9600 baudios
  Serial.begin(9600);
  Serial.println("Lectura de potenciómetro iniciada");
}

void loop() {
  // Leemos el valor del potenciómetro
  valorPot = analogRead(potPin);
  
  // Enviamos el valor por el monitor serial
  Serial.print("Valor del potenciómetro: ");
  Serial.println(valorPot);
  
  // Pequeña pausa para no saturar el monitor
  delay(100);
}
```

## Ejemplo 2: Control de LED con PWM

Este ejemplo muestra cómo utilizar PWM para crear un efecto de respiración en un LED.

### Componentes necesarios
- Arduino UNO
- LED
- Resistencia de 220Ω
- Cables

### Circuito
- Conectá una resistencia de 220Ω al pin 9 de Arduino
- Conectá el ánodo del LED (pata larga) a la resistencia
- Conectá el cátodo del LED (pata corta) a GND

### Código

```cpp
// Definimos el pin para el LED
const int ledPin = 9; // Pin con capacidad PWM

// Variables para el efecto
int brillo = 0;    // Valor de brillo (0-255)
int incremento = 5; // Cantidad de cambio en cada paso

void setup() {
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  // Iniciamos comunicación serial
  Serial.begin(9600);
  Serial.println("Efecto respiración LED iniciado");
}

void loop() {
  // Aplicamos el brillo actual al LED
  analogWrite(ledPin, brillo);
  
  // Enviamos el valor al monitor serial
  Serial.print("Brillo actual: ");
  Serial.println(brillo);
  
  // Cambiamos el brillo para el siguiente ciclo
  brillo = brillo + incremento;
  
  // Invertimos la dirección cuando llegamos a los límites
  if (brillo <= 0 || brillo >= 255) {
    incremento = -incremento;
    // Aseguramos que el valor se mantenga en el rango
    if (brillo < 0) brillo = 0;
    if (brillo > 255) brillo = 255;
  }
  
  // Pequeña pausa para ver el efecto
  delay(30);
}
```

## Ejemplo 3: Comunicación Serial Bidireccional

Este ejemplo demuestra cómo recibir comandos desde el monitor serial para controlar un LED.

### Componentes necesarios
- Arduino UNO
- LED
- Resistencia de 220Ω
- Cables

### Circuito
- Conectá una resistencia de 220Ω al pin 13 de Arduino
- Conectá el ánodo del LED a la resistencia
- Conectá el cátodo del LED a GND

### Código

```cpp
const int ledPin = 13;
char comando;

void setup() {
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  // Iniciamos comunicación serial
  Serial.begin(9600);
  Serial.println("Control LED por comandos seriales");
  Serial.println("Comandos disponibles:");
  Serial.println("'e' - Encender LED");
  Serial.println("'a' - Apagar LED");
  Serial.println("'p' - LED parpadeante");
}

void loop() {
  // Verificamos si hay datos disponibles para leer
  if (Serial.available() > 0) {
    // Leemos un byte del buffer serial
    comando = Serial.read();
    
    // Procesamos el comando recibido
    switch(comando) {
      case 'e': // 'e' para encender
        digitalWrite(ledPin, HIGH);
        Serial.println("LED encendido");
        break;
      case 'a': // 'a' para apagar
        digitalWrite(ledPin, LOW);
        Serial.println("LED apagado");
        break;
      case 'p': // 'p' para parpadeo
        Serial.println("LED parpadeante (5 veces)");
        for (int i = 0; i < 5; i++) {
          digitalWrite(ledPin, HIGH);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
        break;
      default:
        // Si recibimos otro carácter, mostramos ayuda
        if (comando != '\n' && comando != '\r') { // Ignoramos retornos
          Serial.println("Comando no reconocido");
          Serial.println("Usa 'e' para encender, 'a' para apagar, 'p' para parpadeo");
        }
    }
  }
  
  // Pequeña pausa para estabilidad
  delay(10);
}
```

## Ejemplo 4: Control de Servomotor con Entrada Analógica

Este ejemplo muestra cómo utilizar un potenciómetro para controlar la posición de un servomotor.

### Componentes necesarios
- Arduino UNO
- Servomotor
- Potenciómetro de 10kΩ
- Cables

### Circuito
- Conectá el cable de señal del servo al pin 9
- Conectá el cable de alimentación (+) del servo a 5V
- Conectá el cable de tierra (-) del servo a GND
- Conectá el pin central del potenciómetro al pin A0
- Conectá un pin externo del potenciómetro a 5V
- Conectá el otro pin externo del potenciómetro a GND

### Código

```cpp
#include <Servo.h> // Incluimos la librería para servomotores

// Creamos un objeto servo
Servo miServo;

// Definimos los pines
const int servoPin = 9;
const int potPin = A0;

// Variables para almacenar valores
int valorPot;    // Valor del potenciómetro (0-1023)
int angulo;      // Ángulo para el servo (0-180)

void setup() {
  // Conectamos el servo al pin correspondiente
  miServo.attach(servoPin);
  
  // Iniciamos comunicación serial
  Serial.begin(9600);
  Serial.println("Control de servo con potenciómetro iniciado");
}

void loop() {
  // Leemos el valor del potenciómetro
  valorPot = analogRead(potPin);
  
  // Convertimos el valor (0-1023) a un ángulo (0-180)
  angulo = map(valorPot, 0, 1023, 0, 180);
  
  // Movemos el servo a la posición correspondiente
  miServo.write(angulo);
  
  // Enviamos información al monitor serial
  Serial.print("Potenciómetro: ");
  Serial.print(valorPot);
  Serial.print(" | Ángulo: ");
  Serial.println(angulo);
  
  // Pequeña pausa para estabilidad
  delay(15);
}
```

## Sensor de Temperatura LM35

El LM35 es un sensor analógico de temperatura de precisión cuyo voltaje de salida es proporcional a la temperatura en grados Celsius.

### Características del LM35
- **Rango**: Típicamente de -55°C a 150°C
- **Precisión**: ±0.5°C (a 25°C)
- **Sensibilidad**: 10mV/°C
- **Voltaje de operación**: 4V a 30V

### Conexión básica
- Pin izquierdo (visto de frente) a 5V
- Pin central a un pin analógico (ej. A0)
- Pin derecho a GND

### Código para leer temperatura con LM35

```cpp
const int sensorPin = A0;
float temperatura;
int lecturaADC;

void setup() {
  Serial.begin(9600);
  Serial.println("Lectura de temperatura con LM35");
}

void loop() {
  // Leemos el valor del sensor
  lecturaADC = analogRead(sensorPin);
  
  // Convertimos la lectura a voltaje (0-1023 a 0-5V)
  float voltaje = lecturaADC * (5.0 / 1023.0);
  
  // Convertimos el voltaje a temperatura (10mV/°C)
  temperatura = voltaje * 100.0;
  
  // Enviamos la información al monitor serial
  Serial.print("ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje, 2); // 2 decimales
  Serial.print("V | Temperatura: ");
  Serial.print(temperatura, 1); // 1 decimal
  Serial.println("°C");
  
  delay(1000); // Lectura cada segundo
}
```

## Comunicación Serial Avanzada

### Parsing de Datos Seriales

Para procesar datos más complejos que llegan por el puerto serial:

```cpp
String mensajeRecibido = "";
boolean mensajeCompleto = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema listo para recibir mensajes");
}

void loop() {
  // Leemos caracteres del puerto serial
  while (Serial.available() > 0) {
    char caracterRecibido = Serial.read();
    
    // Si recibimos un fin de línea, el mensaje está completo
    if (caracterRecibido == '\n') {
      mensajeCompleto = true;
    } else {
      // Agregamos el caracter al mensaje
      mensajeRecibido += caracterRecibido;
    }
  }
  
  // Si tenemos un mensaje completo, lo procesamos
  if (mensajeCompleto) {
    Serial.print("Mensaje recibido: ");
    Serial.println(mensajeRecibido);
    
    // Aquí procesaríamos el mensaje según la aplicación
    procesarMensaje(mensajeRecibido);
    
    // Reseteamos para el siguiente mensaje
    mensajeRecibido = "";
    mensajeCompleto = false;
  }
}

void procesarMensaje(String mensaje) {
  // Ejemplo: si el mensaje es "LED:ON", encendemos un LED
  if (mensaje == "LED:ON") {
    digitalWrite(13, HIGH);
    Serial.println("LED encendido");
  } 
  // Si es "LED:OFF", apagamos el LED
  else if (mensaje == "LED:OFF") {
    digitalWrite(13, LOW);
    Serial.println("LED apagado");
  }
  // En caso contrario, indicamos que no reconocemos el comando
  else {
    Serial.println("Comando no reconocido");
  }
}
```

## Recursos Adicionales

- [Referencia de Arduino: analogRead()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)
- [Referencia de Arduino: analogWrite()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
- [Tutorial de comunicación serial de Arduino](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [Tutorial sobre sensores analógicos](https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput)
- [Documentación de la biblioteca Servo](https://www.arduino.cc/reference/en/libraries/servo/)
- [Arduino y sensores de temperatura](https://www.arduino.cc/en/Tutorial/LibraryExamples/TemperatureSensor)
