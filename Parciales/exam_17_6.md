# Examen 1: Ciberpunk & Netrunning

## Ejercicio 1: Central de Datos de Megacorporación

El Desafío: El menú tiene un sistema de "Bloqueo por Intentos Incorrectos". Si el usuario ingresa una opción inválida 3 veces consecutivas, el programa se cierra por seguridad simulando una contramedida informática.

Consigna: Implementar un sistema de gestión por menú interactivo para registrar las intrusiones a los servidores.

1. Registrar Intrusión: Solicitar Tipo de Ataque (1: DDoS, 2: Inyección de Malware, 3: Phishing Corporativo), Nivel de Gravedad (1 al 5) y el Alias del Hacker (numeric menor a 10.000). Validar absolutamente todas las entradas numéricas mediante bucles.

2. Reporte de Estado: Mostrar la cantidad total de ataques registrados y el promedio del nivel de gravedad general.

3. Auditoría de Daños (El Filtro): Informar si el promedio de gravedad de los ataques tipo 2 (Inyección de Malware) superó el valor de 3.5. Si no se registraron ataques de ese tipo, advertir "Sin datos de Malware".

4. Salir.

## Ejercicio 2: Hackeo de Terminal Portátil

El Desafío: A diferencia del Blackjack tradicional, aquí hay un multiplicador aleatorio latente. Si sale un número par, el puntaje obtenido en esa tirada vale el doble, aumentando el riesgo de pasarse repentinamente.

Consigna: Estás vulnerando el cifrado de un puerto de enlace antes de que te rastreen.

Mecánica Jugador: El usuario decide si sigue inyectando código ("Hackear") o si se planta. Cada intento genera un pulso aleatorio entre 1 y 10. Si el pulso es par, se duplica debido a la resonancia del Firewall. Si el acumulado total supera 25 puntos, el sistema se bloquea por Buffer Overflow y el jugador pierde la partida de inmediato.

Mecánica CPU (Seguridad de la Red): Si el jugador se planta con éxito, la IA de seguridad intenta superarlo. La CPU genera números estándar (sin multiplicador par) entre 1 y 10 y se planta obligatoriamente al alcanzar o superar 18 puntos.

Evaluación: Determinar el ganador evaluando quién quedó más cerca de 25 sin pasarse.

## Ejercicio 3: Decodificador del Mercado Negro

Consigna: Leer una línea de texto encriptada (máx. 100 caracteres) y procesar byte a byte de forma directa sin usar <ctype.h> ni funciones de búsqueda de <string.h>:

Letras Minúsculas: Desplazarlas de forma circular +4 posiciones en la tabla ASCII (ej: 'z' pasa a 'd').

Letras Mayúsculas: Invertir su caso (pasarlas a minúsculas), luego restarles 4 posiciones tambien circular.

Espacios: Reemplazarlos por el carácter de barra vertical '|'.

Símbolos (Cualquier carácter que NO sea letra ni espacio): no cambian

# Examen 2: Cazadores de Monstruos

## Ejercicio 1: Gremio de Cazarrecompensas

El Desafío: El sistema aplica un "Impuesto del Gremio" variable. Cada vez que se registra una recompensa, el dinero neto guardado en el acumulador descuenta un 10% si el monstruo es de peligro alto, forzando a aplicar condicionales dentro de la carga de datos.

Consigna: Crear un software para administrar los contratos del gremio.

1. Cargar Contrato: Solicitar Clasificación de la Criatura (1: Bestia Común, 2: Dragón Antiguo, 3: Espectro), Recompensa en Oro (validar que sea mayor a 0) y Nvl. del Cazador asignado (1 al 5).

2. Estadísticas Globales: Mostrar el total de oro acumulado total (neto con el descuento aplicado del gremio 10%) y el porcentaje de contratos que fueron asignados a la categoría 2 (Dragón Antiguo).

3. Héroe del Gremio: Mostrar cuál fue la recompensa individual más alta registrada durante toda la ejecución del programa y qué tipo de criatura era.

4. Salir.

## Ejercicio 2: El Tablón de Dados de la Taberna

El Desafío: El rango objetivo no es fijo. Al comenzar el juego, el programa genera de forma aleatoria el "Punto de Equilibrio" entre 40 y 60. El alumno debe lograr que la energía de su hechizo quede exactamente en un rango de [Equilibrio - 5, Equilibrio + 5] en 4 turnos.

Consigna: Estás canalizando maná para abrir un cofre rúnico.

Estado Inicial: Maná inicial = 20.

Dinámica: En cada uno de los 4 turnos, el flujo ambiental inestable altera el maná sumando o restando un valor generado por la fórmula rand() % 17 - 8 (valores entre -8 y 8).

Acciones del Mago:

Piedra de Canalización: Suma 12 puntos de maná fijas.

Disipación Arcana: Resta 12 puntos de maná fijas.

Meditar: No altera el maná manualmente en este turno (aleatorio entre -5 y 5).

Evaluación: Al finalizar el cuarto turno, verificar si el valor final del maná se encuentra dentro de la ventana de estabilidad generada al inicio, en tal caso ganaste.

## Ejercicio 3: Inscripciones de la Espada Rúnica

Consigna: Leer una línea de texto inscripta en la espada (máx. 100 caracteres) y codificarla de forma directa sin usar <ctype.h> ni funciones de búsqueda de <string.h>:

Letras Minúsculas: Desplazarlas de forma circular +6 posiciones en la tabla ASCII (ej: 'z' pasa a 'f'.

Letras Mayúsculas: Invertir su caso (pasarlas a minúsculas), luego restarles 6 posiciones tambien circular.

Espacios: Reemplazarlos por el carácter de barra vertical '|'.

Símbolos (Cualquier carácter que NO sea letra ni espacio): no cambian.
