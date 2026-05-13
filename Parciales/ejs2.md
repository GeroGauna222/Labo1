## "Infiltración en la Fortaleza"

**Temática:** Sos un espía intentando hackear un servidor central. Tenés que atravesar 4 niveles de seguridad.

* **Stats Iniciales:** Energía = 100, Alerta = 0.
* **Condición de Derrota:** Energía $\le 0$ o Alerta $\ge 100$.
* **Dinámica:** En cada nivel, el sistema genera un **Sistema de Defensa (Random 1-10)**:
1. **1-4: Cámaras de Seguridad.**
2. **5-8: Patrulla de Guardias.**
3. **9-10: Escáner Biométrico.**


* **Acciones:** (1) Hackear, (2) Esconderse, (3) Correr.
* **Efecto:** Cada combinación tiene un rango de daño a la Energía y aumento de la Alerta.

* **Evento: Cámaras de Seguridad (Random 1-4)**
* **Hackear:** Pierde [10 a 15] de Energía. Suma 0 de Alerta.
* **Esconderse:** Pierde 5 de Energía. Suma [5 a 10] de Alerta.
* **Correr:** Pierde 10 de Energía. Suma [20 a 30] de Alerta.


* **Evento: Patrulla de Guardias (Random 5-8)**
* **Hackear:** Pierde 20 de Energía. Suma [10 a 15] de Alerta.
* **Esconderse:** Pierde 15 de Energía. Suma [2 a 5] de Alerta.
* **Correr:** Pierde 20 de Energía. Suma [30 a 50] de Alerta.


* **Evento: Escáner Biométrico (Random 9-10)**
* **Hackear:** Pierde [25 a 30] de Energía. Suma 0 de Alerta.
* **Esconderse:** Pierde 5 de Energía. Suma [40 a 60] de Alerta.
* **Correr:** Pierde 15 de Energía. Suma [80 a 100] de Alerta.

---

## "Estabilización del Núcleo"

**Temática:** Sos un ingeniero en una planta nuclear. El núcleo está inestable y tenés 4 turnos para dejar la presión en el rango de seguridad **[45 - 55]**. Si terminas fuera de ese rango, la planta explota.

* **Estado Inicial:** Presión = 50.
* **Dinámica:** En cada turno (de un total de 4), ocurre un **Evento de Inestabilidad** aleatorio que suma o resta presión:
* `rand() % 21 - 10` (Genera un valor entre -10 y 10).


* **Acciones del Usuario:**
1. **Válvula de Escape:** Resta 10 de presión.
2. **Inyección de Vapor:** Suma 10 de presión.
3. **Mantener:** No altera la presión manualmente.

**La idea:** Ocurre evento --> Jugador hace acción.


* **Evaluación:** Al final de los 4 turnos, informar si el núcleo quedó estable o si hubo una catástrofe.

### Resolución (Ej Nucleo)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int presion = 50, accion, inestabilidad;

    printf("=== CONTROL DE NUCLEO ===\n");
    for (int t = 1; t <= 4; t++) {
        inestabilidad = (rand() % 21) - 10;
        presion += inestabilidad;
        printf("Turno %d: Inestabilidad de %d. Presión actual: %d\n", t, inestabilidad, presion);

        do {
            printf("Acción: (1) Escape [-10], (2) Vapor [+10], (3) Mantener: ");
            scanf("%d", &accion);
        } while (accion < 1 || accion > 3);

        if (accion == 1) presion -= 10;
        else if (accion == 2) presion += 10;
        
        printf("Presion post-ajuste: %d\n\n", presion);
    }

    if (presion >= 45 && presion <= 55) printf("SISTEMA ESTABILIZADO. Buen trabajo.\n");
    else printf("BOOM!!!! Presión final %d fuera de rango [45-55].\n", presion);

    return 0;
}

```

---

## "Hack Overload"

**Temática:** Estas robando archivos de un servidor corporativo. Cada archivo tiene un peso aleatorio. Si te pasas del límite del buffer (**21 MB**), el Firewall te detecta y perdés todo.

* **Dinamica Jugador:** El usuario elige "Descargar" o "Plantarse". Cada descarga suma entre **1 y 11** MB. Si supera 21, pierde automáticamente.
* **Dinámica CPU (Firewall):** Si el jugador se planta, el Firewall empieza a descargar datos para intentar superar al jugador sin pasarse de 21. La CPU se planta cuando llega a **17 MB** o más.
* **Evaluación:** Comparar quien quedó más cerca de 21 sin pasarse.

* Blackjack basically

### Resolución (Ej Hack)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int jugador = 0, cpu = 0;
    char op;

    printf("=== HACK ===\n");
    // Turno player
    while (1) {
        int d = (rand() % 11) + 1;
        jugador += d;
        printf("Descargaste %d MB. Total: %d MB. ", d, jugador);
        if (jugador > 21) {
            printf("\n¡OVERFLOW! El Firewall te atrapó.\n");
            return 0;
        }
        printf("¿Seguir? (s/n): ");
        scanf(" %c", &op);
        if (op == 'n') break;
    }

    // Turno CPU
    printf("\nTurno del Firewall...\n");
    while (cpu < 17) {
        int d = (rand() % 11) + 1;
        cpu += d;
        printf("Firewall descarga %d MB. Total CPU: %d MB\n", d, cpu);
    }

    // Resultado
    if (cpu > 21 || jugador > cpu) printf("HACKEO EXITOSO!\n");
    else if (jugador == cpu) printf("EMPATE: Acceso denegado por seguridad.\n");
    else printf("EL FIREWALL GANO. Perdiste.\n");

    return 0;
}

```

---

## "Logistica del Desierto"

**Temática:** Tenés que gestionar los recursos de tu base durante 3 días. El clima afecta el consumo de forma drastica.

* **Recursos:** Agua (50) y Comida (50).
* **Clima (Random 1-10):**
* **1-3: Ola de Calor.** El consumo de Agua se triplica.
* **4-6: Frío Extremo.** El consumo de Comida se triplica.
* **7-10: Clima Templado.** Consumo normal.


* **Acciones (Racionamiento):**
1. **Ración Normal:** Gasta 5 de Agua y 5 de Comida.
2. **Priorizar Agua:** Gasta 2 de Agua y 8 de Comida.
3. **Priorizar Comida:** Gasta 8 de Agua y 2 de Comida.


* El consumo base de la racion se multiplica segun el clima. Si algun recurso llega a 0, la misión falla.

### Resolución (Ej Desierto)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int agua = 50, comida = 50, clima, accion, c_agua, c_comida;

    for (int dia = 1; dia <= 3; dia++) {
        printf("--- DIA %d ---\n", dia);
        clima = (rand() % 10) + 1;
        
        if (clima <= 3) printf("CLIMA: Ola de Calor (Agua x3)\n");
        else if (clima <= 6) printf("CLIMA: Frío Extremooooo (Comida x3)\n");
        else printf("CLIMA: Templado (Normal)\n");

        do {
            printf("Ración: (1) Normal, (2) +Comida/-Agua, (3) +Agua/-Comida: ");
            scanf("%d", &accion);
        } while (accion < 1 || accion > 3);

        // Defino base
        if (accion == 1) { c_agua = 5; c_comida = 5; }
        else if (accion == 2) { c_agua = 8; c_comida = 2; }
        else { c_agua = 2; c_comida = 8; }

        // Aplico modif de clima
        if (clima <= 3) c_agua *= 3;
        else if (clima <= 6) c_comida *= 3;

        agua -= c_agua; comida -= c_comida;
        printf("CONSUMO: Agua -%d | Comida -%d\n", c_agua, c_comida);
        printf("RESTANTE: Agua %d | Comida %d\n\n", agua, comida);

        if (agua <= 0 || comida <= 0) {
            printf("MISION FALLIDA: Recursos agotados el dia %d.\n", dia);
            return 0;
        }
    }
    printf("¡SOBREVIVISTE!\n");
    return 0;
}

```

---

### "Misión de Rescate: Abismo Submarino"

**Temática:** Un submarino de investigación quedó atrapado. Tenés que bajar 3 niveles de profundidad para rescatarlos.

* **Stats Iniciales:** Oxígeno = 150, Integridad del Casco = 100.
* **Condición de Derrota:** Oxígeno $\le 0$ o Casco $\le 0$.
* **Dinámica:** En cada profundidad hay un **Obstáculo Marino (Random 1-10)**:
1. **1-5: Corriente Fuerte.**
2. **6-8: Presión Extrema.**
3. **9-10: Calamar Gigante.**


* **Acciones:** (1) Propulsión a fondo, (2) Reforzar escudos, (3) Maniobra evasiva.
* **Efecto:** Deben calcular daños variables usando la fórmula `rand() % (max - min + 1) + min`.

* **Evento: Corriente Fuerte (Random 1-5)**
* **Propulsión:** Gasta [20 a 30] de Oxígeno. Daño al Casco: 0.
* **Escudos:** Gasta 10 de Oxígeno. Daño al Casco: [10 a 20].
* **Maniobra:** Gasta [15 a 20] de Oxígeno. Daño al Casco: [5 a 10].


* **Evento: Presión Extreme (Random 6-8)**
* **Propulsión:** Gasta [40 a 50] de Oxígeno. Daño al Casco: 0.
* **Escudos:** Gasta 20 de Oxígeno. Daño al Casco: [15 a 25].
* **Maniobra:** Gasta 30 de Oxígeno. Daño al Casco: [20 a 30].


* **Evento: Calamar Gigante (Random 9-10)**
* **Propulsión:** Gasta 60 de Oxígeno. Daño al Casco: [30 a 50].
* **Escudos:** Gasta 30 de Oxígeno. Daño al Casco: [5 a 15].
* **Maniobra:** Gasta [40 a 50] de Oxígeno. Daño al Casco: [20 a 40].

---

### "Supervivencia en Marte"

**Temática:** Tu rover quedó varado y tenes que recorrer 3 sectores para llegar a la base antes de que se acabe la nafta.

* **Stats Iniciales:** Batería = 120, Integridad del Rover = 100.
* **Condición de Derrota:** Batería $\le 0$ o Rover $\le 0$.
* **Dinámica:** En cada sector aparece un **Clima Marciano (Random 1-10)**:
1. **1-4: Tormenta de Polvo.**
2. **5-8: Terreno Rocoso.**
3. **9-10: Lluvia de Meteoritos.**


* **Acciones:** (1) Desplazamiento lento, (2) Turbo, (3) Reparación en marcha.
* **Efecto:** Los rangos deben ser bien marcados.

* **Evento: Tormenta de Polvo (Random 1-4)**
* **Lento:** Gasta [10 a 20] de Batería. Quita [5 a 10] de Integridad.
* **Turbo:** Gasta [40 a 50] de Batería. Quita [2 a 5] de Integridad.
* **Reparar:** Gasta 30 de Batería. **Suma** [10 a 15] de Integridad.


* **Evento: Terreno Rocoso (Random 5-8)**
* **Lento:** Gasta [20 a 30] de Batería. Quita [10 a 20] de Integridad.
* **Turbo:** Gasta 50 de Batería. Quita [30 a 40] de Integridad.
* **Reparar:** Gasta 40 de Batería. **Suma** [5 a 10] de Integridad.


* **Evento: Lluvia de Meteoritos (Random 9-10)**
* **Lento:** Gasta 30 de Batería. Quita [40 a 60] de Integridad.
* **Turbo:** Gasta 60 de Batería. Quita [10 a 20] de Integridad.
* **Reparar:** Gasta 50 de Batería. **Suma** [15 a 25] de Integridad.

---

### Recuerdennnnnn

1. **Inicialización de la semilla:** Que no se olviden del `srand(time(NULL))`.


2. **Lógica de rangos:** Si ponen `rand() % 100`, les va a dar cualquier cosa. Tienen que usar la fórmula del rango para los daños.


3. **Manejo del estado:** Tener en cuenta cómo mostrar el reporte despues de cada turno (qué paso, cuánto perdio, totales actuales).


4. 
**Corte del bucle:** Si muere en la Zona 1, el programa no puede seguir a la Zona 2!!!!!
