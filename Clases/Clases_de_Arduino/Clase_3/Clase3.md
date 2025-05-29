# Clase 3: Sensores, Actuadores y Librerías en Arduino

## Sensores en Arduino

Los sensores son dispositivos que permiten a Arduino percibir el mundo físico. Convierten magnitudes físicas (temperatura, luz, sonido, distancia) en señales eléctricas que Arduino puede interpretar.

### Tipos de sensores según su salida

- **Sensores digitales**: Proporcionan salidas de tipo ON/OFF (0 o 1)
  - Ejemplos: botones, interruptores, sensores de movimiento PIR, sensores de inclinación
  
- **Sensores analógicos**: Entregan un rango continuo de valores
  - Ejemplos: potenciómetros, fotoresistencias (LDR), sensores de temperatura, sensores de presión
  
- **Sensores con interfaces específicas**: Utilizan protocolos como I2C, SPI, o One-Wire
  - Ejemplos: acelerómetros, giroscopios, sensores de humedad capacitivos, sensores barométricos

## Sensor Ultrasónico HC-SR04

El HC-SR04 es un sensor que mide distancia mediante ultrasonido, enviando pulsos sonoros y midiendo el tiempo que tarda el eco en regresar.

### Características del HC-SR04

- **Rango de medición**: 2cm a 400cm
- **Precisión**: ~3mm
- **Ángulo de medición**: 15 grados
- **Voltaje de operación**: 5V
- **Frecuencia de trabajo**: 40kHz

### Conexiones

- **VCC**: Conectar a 5V
- **Trig (Trigger)**: Pin que inicia la medición (salida de Arduino)
- **Echo**: Pin que recibe el eco (entrada de Arduino)
- **GND**: Conectar a tierra

### Funcionamiento

1. Se envía un pulso de 10µs al pin Trigger
2. El sensor envía 8 pulsos ultrasónicos a 40kHz
3. La señal regresa y el pin Echo se pone en HIGH
4. La duración del pulso en Echo es proporcional a la distancia

### Ejemplo: Medición de distancia con HC-SR04

#### Componentes necesarios
- Arduino UNO
- Sensor ultrasónico HC-SR04
- Cables

#### Circuito
- Conectar VCC del sensor a 5V de Arduino
- Conectar GND del sensor a GND de Arduino
- Conectar Trig del sensor al pin 9 de Arduino
- Conectar Echo del sensor al pin 10 de Arduino

#### Código

```cpp
// Definimos los pines para el sensor ultrasónico
const int trigPin = 9;
const int echoPin = 10;

// Variables para cálculos
long duracion;
float distancia;

void setup() {
  // Configuramos los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Iniciamos comunicación serial
  Serial.begin(9600);
  Serial.println("Sensor de distancia ultrasónico iniciado");
}

void loop() {
  // Limpiamos el pin Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Enviamos un pulso de 10µs
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Medimos el tiempo en que el pin Echo está en HIGH
  duracion = pulseIn(echoPin, HIGH);
  
  // Calculamos la distancia: Velocidad del sonido (343m/s) / 2 (ida y vuelta)
  // 343m/s * 100cm/m * duracion/1000000s / 2 = duracion * 0.01715
  distancia = duracion * 0.01715;
  
  // Mostramos el resultado
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Esperamos antes de la siguiente medición
  delay(500);
}
```

## Sensor de Temperatura y Humedad DHT11/DHT22

Los sensores DHT11 y DHT22 son sensores digitales que miden tanto temperatura como humedad relativa. El DHT22 ofrece mayor precisión y rango que el DHT11.

### Características

| Característica | DHT11 | DHT22 |
|----------------|-------|-------|
| Rango de temperatura | 0°C a 50°C | -40°C a 80°C |
| Precisión temperatura | ±2°C | ±0.5°C |
| Rango de humedad | 20% a 80% | 0% a 100% |
| Precisión humedad | ±5% | ±2% |
| Velocidad de muestreo | 1Hz (1 muestra/segundo) | 0.5Hz (1 muestra cada 2 segundos) |

### Conexiones

- **VCC**: Conectar a 3.3V-5V
- **DATA**: Pin de datos (requiere resistencia pull-up de 4.7kΩ-10kΩ)
- **GND**: Conectar a tierra

### Ejemplo: Lectura de temperatura y humedad con DHT11

#### Componentes necesarios
- Arduino UNO
- Sensor DHT11 (o DHT22)
- Resistencia de 10kΩ
- Cables

#### Circuito
- Conectar VCC del sensor a 5V de Arduino
- Conectar GND del sensor a GND de Arduino
- Conectar DATA del sensor al pin 2 de Arduino
- Conectar una resistencia de 10kΩ entre DATA y VCC

#### Código

```cpp
#include <DHT.h>

// Definimos el pin y el tipo de sensor
#define DHTPIN 2
#define DHTTYPE DHT11  // Cambiar a DHT22 si se usa ese sensor

// Inicializamos el sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba de sensor DHT");
  
  // Inicializamos el sensor
  dht.begin();
}

void loop() {
  // Esperamos entre lecturas (el DHT11 necesita al menos 1s)
  delay(2000);
  
  // Leemos la humedad
  float h = dht.readHumidity();
  // Leemos la temperatura en Celsius
  float t = dht.readTemperature();
  // Leemos la temperatura en Fahrenheit
  float f = dht.readTemperature(true);
  
  // Verificamos si alguna lectura falló
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error al leer el sensor DHT!");
    return;
  }
  
  // Calculamos el índice de calor (sensación térmica)
  float hic = dht.computeHeatIndex(t, h, false);
  float hif = dht.computeHeatIndex(f, h);
  
  // Mostramos los resultados
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print("°C / ");
  Serial.print(f);
  Serial.print("°F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print("°C / ");
  Serial.print(hif);
  Serial.println("°F");
}
```

## Actuadores en Arduino

Los actuadores son dispositivos que permiten a Arduino actuar sobre el entorno físico, transformando señales eléctricas en acciones físicas.

### Tipos comunes de actuadores

- **Motores DC**: Motores de corriente continua que giran según la polaridad aplicada
- **Servomotores**: Motores que pueden posicionarse en un ángulo específico
- **Motores paso a paso**: Motores que giran en incrementos precisos
- **Relés**: Interruptores electromagnéticos para controlar circuitos de mayor potencia
- **Displays**: LCD, OLED, matrices de LEDs para mostrar información
- **Altavoces/Buzzers**: Para producir sonidos y alertas

## Control de un Motor DC con Transistor

### Componentes necesarios
- Arduino UNO
- Motor DC pequeño (3-6V)
- Transistor NPN (ej. 2N2222, BC547)
- Diodo 1N4007 (protección)
- Resistencia de 1kΩ
- Fuente externa (si el motor requiere más corriente)
- Cables

### Circuito
- Conectar la base del transistor a un pin digital (ej. pin 3) a través de una resistencia de 1kΩ
- Conectar el emisor del transistor a GND
- Conectar un terminal del motor al colector del transistor
- Conectar el otro terminal del motor a VCC (5V o fuente externa)
- Colocar el diodo en paralelo con el motor (cátodo hacia VCC)

### Código

```cpp
// Pin para controlar el motor
const int motorPin = 3;

void setup() {
  // Configuramos el pin como salida
  pinMode(motorPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Control de motor DC");
  Serial.println("Comandos: 'e' (encender), 'a' (apagar), '1-9' (velocidad)");
}

void loop() {
  // Verificamos si hay datos en el puerto serial
  if (Serial.available() > 0) {
    char comando = Serial.read();
    
    // Procesamos el comando
    if (comando == 'e') {
      // Encendemos el motor
      analogWrite(motorPin, 200);
      Serial.println("Motor encendido");
    }
    else if (comando == 'a') {
      // Apagamos el motor
      analogWrite(motorPin, 0);
      Serial.println("Motor apagado");
    }
    else if (comando >= '1' && comando <= '9') {
      // Ajustamos la velocidad (1-9 -> 25-225)
      int velocidad = (comando - '0') * 25;
      analogWrite(motorPin, velocidad);
      Serial.print("Velocidad ajustada a: ");
      Serial.println(velocidad);
    }
  }
}
```

## Control de un Servomotor

### Componentes necesarios
- Arduino UNO
- Servomotor (ej. SG90)
- Potenciómetro de 10kΩ (opcional, para control manual)
- Cables

### Circuito
- Conectar el cable rojo (VCC) del servo a 5V
- Conectar el cable marrón/negro (GND) del servo a GND
- Conectar el cable naranja/amarillo (señal) del servo al pin 9
- Si se usa potenciómetro: conectar extremos a 5V y GND, y el pin central a A0

### Código

```cpp
#include <Servo.h>

// Creamos un objeto servo
Servo miServo;

// Pin donde está conectado el servo
int servoPin = 9;

// Pin para potenciómetro (opcional)
int potPin = A0;

// Variables
int angulo = 0;

void setup() {
  // Conectamos el servo al pin correspondiente
  miServo.attach(servoPin);
  
  Serial.begin(9600);
  Serial.println("Control de servomotor");
  Serial.println("Envía un valor entre 0 y 180 para mover el servo");
}

void loop() {
  // Verificamos si hay datos en el puerto serial
  if (Serial.available() > 0) {
    // Leemos el ángulo enviado
    String entrada = Serial.readStringUntil('\n');
    angulo = entrada.toInt();
    
    // Limitamos el ángulo entre 0 y 180
    if (angulo < 0) angulo = 0;
    if (angulo > 180) angulo = 180;
    
    // Movemos el servo
    miServo.write(angulo);
    
    Serial.print("Servo movido a: ");
    Serial.println(angulo);
  }
  
  // Alternativa: control con potenciómetro
  // Descomentar si se usa potenciómetro
  /*
  int valorPot = analogRead(potPin);
  angulo = map(valorPot, 0, 1023, 0, 180);
  miServo.write(angulo);
  delay(15);
  */
}
```

## Display LCD con I2C

### Componentes necesarios
- Arduino UNO
- Display LCD 16x2 con adaptador I2C
- Cables

### Circuito
- Conectar SDA del módulo I2C a pin A4 (SDA) de Arduino
- Conectar SCL del módulo I2C a pin A5 (SCL) de Arduino
- Conectar VCC del módulo a 5V
- Conectar GND del módulo a GND

### Código

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Crear objeto LCD con dirección I2C 0x27, 16 columnas y 2 filas
// Nota: La dirección puede variar (0x27, 0x3F, etc.)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables para almacenar tiempo
unsigned long tiempoInicio;

void setup() {
  // Iniciar el LCD
  lcd.init();
  // Encender la luz de fondo
  lcd.backlight();
  
  // Mensaje inicial
  lcd.setCursor(0, 0);
  lcd.print("Arduino LCD I2C");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  
  // Guardamos el tiempo de inicio
  tiempoInicio = millis();
  
  // Iniciamos comunicación serial
  Serial.begin(9600);
  Serial.println("Display LCD I2C iniciado");
}

void loop() {
  // Calculamos el tiempo transcurrido en segundos
  unsigned long tiempoActual = millis();
  unsigned long segundos = (tiempoActual - tiempoInicio) / 1000;
  
  // Actualizamos la segunda línea del LCD cada segundo
  lcd.setCursor(0, 1);
  lcd.print("Tiempo: ");
  lcd.print(segundos);
  lcd.print(" s    ");
  
  // Pequeña pausa
  delay(1000);
  
  // Si recibimos datos por serial, los mostramos en el LCD
  if (Serial.available() > 0) {
    // Limpiamos la primera línea
    lcd.setCursor(0, 0);
    lcd.print("                ");
    
    // Leemos el mensaje y lo mostramos
    String mensaje = Serial.readStringUntil('\n');
    lcd.setCursor(0, 0);
    lcd.print(mensaje);
    
    // Eco por serial
    Serial.print("Mostrando en LCD: ");
    Serial.println(mensaje);
  }
}
```

## Librerías en Arduino

Las librerías son colecciones de código que extienden la funcionalidad de Arduino, simplificando tareas complejas y facilitando el uso de hardware específico.

### ¿Por qué usar librerías?

- **Ahorro de tiempo**: Evitan escribir código repetitivo
- **Código probado**: Suelen estar bien probadas y optimizadas
- **Abstracción**: Ocultan detalles complejos de implementación
- **Comunidad**: Aprovechan el conocimiento colectivo de la comunidad

### Tipos de librerías

1. **Librerías integradas**: Vienen con el IDE de Arduino
   - Ejemplos: `Wire.h` (I2C), `SPI.h`, `Servo.h`

2. **Librerías del gestor de librerías**: Se instalan desde el IDE
   - Accesibles desde Sketch > Incluir Librería > Administrar Bibliotecas

3. **Librerías externas**: Descargadas de GitHub u otras fuentes
   - Se instalan manualmente en la carpeta de librerías

### Cómo instalar una librería

#### Desde el gestor de librerías:
1. En el IDE de Arduino: Sketch > Incluir Librería > Administrar Bibliotecas
2. Buscar la librería deseada
3. Hacer clic en "Instalar"

#### Manualmente:
1. Descargar la librería (archivo ZIP)
2. En el IDE: Sketch > Incluir Librería > Añadir biblioteca .ZIP
3. Seleccionar el archivo descargado

#### Ubicación de las librerías:
- Windows: Documents/Arduino/libraries/
- macOS: ~/Documents/Arduino/libraries/
- Linux: ~/Arduino/libraries/

### Cómo usar una librería

```cpp
// 1. Incluir la librería
#include <NombreLibreria.h>

// 2. Crear objetos si es necesario
NombreLibreria miObjeto;

void setup() {
  // 3. Inicializar si es necesario
  miObjeto.begin();
}

void loop() {
  // 4. Usar las funciones de la librería
  miObjeto.funcionUtil();
}
```

## Ejemplo de Uso de Librerías: Sensor BME280 (I2C)

El BME280 es un sensor ambiental que mide temperatura, presión atmosférica y humedad relativa con alta precisión.

### Componentes necesarios
- Arduino UNO
- Sensor BME280 (módulo I2C)
- Cables

### Circuito
- Conectar VCC del sensor a 3.3V de Arduino
- Conectar GND del sensor a GND de Arduino
- Conectar SCL del sensor al pin A5 (SCL) de Arduino
- Conectar SDA del sensor al pin A4 (SDA) de Arduino

### Instalación de la librería
1. En el IDE: Sketch > Incluir Librería > Administrar Bibliotecas
2. Buscar "Adafruit BME280"
3. Instalar "Adafruit BME280 Library" y sus dependencias

### Código

```cpp
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Crear objeto BME280
Adafruit_BME280 bme;

// Variable para almacenar presión de referencia (nivel del mar)
float presionNivelMar = 1013.25; // hPa, ajustar según pronóstico local

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba de sensor BME280");
  
  // Inicializar BME280
  if (!bme.begin(0x76)) {  // Dirección I2C (puede ser 0x76 o 0x77)
    Serial.println("No se encontró el sensor BME280, verifica el cableado!");
    while (1);
  }
  
  Serial.println("Sensor BME280 encontrado!");
}

void loop() {
  // Leer valores del sensor
  float temperatura = bme.readTemperature();
  float presion = bme.readPressure() / 100.0F; // convertir Pa a hPa
  float altitud = bme.readAltitude(presionNivelMar);
  float humedad = bme.readHumidity();
  
  // Mostrar resultados
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  Serial.print("Presión: ");
  Serial.print(presion);
  Serial.println(" hPa");
  
  Serial.print("Altitud aproximada: ");
  Serial.print(altitud);
  Serial.println(" m");
  
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");
  
  Serial.println("----------------------------------------");
  
  // Esperar antes de la siguiente lectura
  delay(2000);
}
```

## Creación de tu propia librería

Crear tu propia librería te permite organizar tu código, hacerlo reutilizable y compartirlo con otros.

### Estructura básica de una librería

