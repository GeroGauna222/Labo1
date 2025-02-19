# Labo1
Repo de contenidos para la materia Laboratorio de Computación 1
Buen día a todos! Antes de comenzar, les deseamos que la materia les sea leve y la puedan disfrutar, es al menos lo que nosotros buscamos. Nuestro objetivo es que terminen este cuatrimestre sabiendo un poco más de lo que hoy saben, y con todas las ganas de seguir aprendiendo acerca de este mundo nerd tan interesante que es la ciencia de datos.
Los contenidos que veremos, y que deberán dominar (mentira, tampoco tanto) para aprobar, son los siguientes:
- **Manejo de planillas de cálculo**: los contenidos abarcan 4 clases y un examen. Aprenderemos herramientas interesantes y aplicables en el día a día.
- **Programación en C**: la parte más extensa de la materia se la dedicaremos a que den sus primeros pasos en la escritura de código. En esta materia utilizaremos el lenguaje C, con el cual aprenderán las bases generales sobre la programación para luego poder extrapolarlos a otros lenguajes en el futuro.
- **Arduino**: Para finalizar, el último módulo consta de contenidos apuntados al manejo de dispositivos Arduino. Lo interesante será el ver cómo lo que escribimos en la computadora es capaz de extrapolar al mundo real, siendo posible que una srie de línea de código prendan y apaguen una luz, por ejemplo. A nuestra disposición tendremos modelos Arduino UNO, los cuales el alumno utilizará para diseñar junto con un grupo de trabajo un proyecto final de la materia. La aprobación del mismo posibilitará la promoción de la materia (es decir, no ir a final). Cabe recalcar que la nota siempre es *INDIVIDUAL, y NO GRUPAL*

Tendrán a su disposición bibliografía complementaria para facilitarles los contenidos, sumado a videos y lo trabajado en clase. Tambien les facilitamos parciales viejos de la materia, no se preocupen ;)

Ya sentadas las bases, comencemos

# ***Posterior al módulo de Hojas de Cálculo***

# Introducción a C
## ¿Qué es programar?
Programar es darle una serie de instrucciones a un sistema, el cual es capaz de procesarlas, entenderlas y responder en base a las mismas. Para sentirnos más piola, los que lo hacemos lo rebautizamos 'codear' ;)
## ¿Y un sistema?
Un sistema es un conjunto de elementos que trabajan de manera integrada para un fin común. Son varios elementos que se relacionan y funcionan como un todo, casi todo a nuestro alrededor puede verse como un sistema.
## ¿Qué es un lenguaje?
En el contexto de la programación, un lenguaje nos permite escribir programas que la maquina entiende. Con este, le damos órdenes al hardware.
Lo dividimos en 3 categorías:
- Maquina (ojo, 'lenguaje')
- de Alto Nivel
- de Bajo Nivel

### Código máquina
Lo que realmente comprende el cerebro de la máquina (el microprocesador)
Lenguaje en base al código binario, entiende solo 2 estados: 0 y 1
Todo lo que realizamos en la computadora se traduce a esto

![Codigo maquina](https://github.com/GeroGauna222/Labo1/blob/main/xExtra/codmaquina.jpg).

### Codificación binaria
El sistema binario es el que permite el funcionamiento de los ordenadores. Como ya mencionamos, utiliza dos condiciones: 0 y 1.
el que solo existan dos posibilidades significa que se esta trabajando en base 2. Ahora bien, para entender esto:

  En nuestro día a día, cuando contamos y pensamos en numeros, conocemos 10 posibilidades, del 0 al 9. Los demás números los formamos con combinaciones de estos. Esta es la conocida como *base decimal*, pero también existen otras bases:
  
- la *hexagesimal*
- la *quintal*
- la *duodecimal*

La *base binaria* es la que utilizan los sistemas digitales

### ¿Que sería un bit?
El término bit significa dígito binario, y corresponde al número 0 o 1 en la numeración binaria. Es la unidad de información más pequeña que puede manipular una máquina digital.

![Codificacion Informacion](https://github.com/eCanayUnsam/Labo-1/blob/main/Imagenes/Codificacion_Informacion.jpg)

Lógicamente , con dos bits se pueden obtener 4 combinaciones (o como se las llama realmente, condiciones) diferentes (2x2): 00 10 11 01

Con 3, tengo 8 (2x2x2): 000 001 011 111 110 100 101 010

Con 4, hay 16 (2x2x2x2)

¿Se entiende por donde viene la mano? **Con n bits, puedo representar 2^n valores**

Entonces teniendo n bits puedo representar 2^n numeros diferentes. ¿Y cómo escribo en binario?

En un número binario, el valor de cada bit depende de su posición, y se lo arma empezando desde la derecha.

![Escritura Binaria](https://github.com/GeroGauna222/Labo1/blob/main/xExtra/binary.png).

Podemos ver que el numero más a la derecha será el que represente al 2^0 (= 1), el de su izquierda 2^1 (= 2), el siguiente 2^2 (=4) y así...

Para escribir un número como el 5 sé que me harán falta por lo menos 3 bits, pues con 2 bits solo puedo representar 4 combinaciones:

- 0 -> 00 -> [2^1 x 0] + [2^0 x 0]
- 1 -> 10 -> [2^1 x 0] + [2^0 x 1]
- 2 -> 01 -> [2^1 x 1] + [2^0 x 0]
- 3 -> 11 -> [2^1 x 1] + [2^0 x 1]

5 -> tengo [2^2 x 1] + [2^1 x 0] + [2^0 x 1] = 4 + 0 + 1 = 5 -> el decimal 5 es en binario 101

entonces si me dan el numero binario 10011001, sé que al tener 8 digitos binarios lo tendría que armar así:

[2^7 x 1] + [2^6 x 0] + [2^5 x 0] + [2^4 x 1] + [2^3 x 1] + [2^2 x 0] + [2^1 x 0] + [2^0 x 1]

Todo lo que es x0 lo puedo ignorar, me importa lo multiplicado x1

2^7 + 2^4 + 2^3 + 2^0 = 128 + 16 + 8 + 1 = 149 en decimal

¡Así de fácil!

El de recién fue un numero de 8 bits, a esto se lo llama **un Byte**. **Un byte es la mínima unidad direccionable de memoria en la mayoría de las computadoras modernas**. Una computadora con memoria direccionable por bytes no puede almacenar una pedazo individual de datos más pequeño que un byte. Osea, guardo cosas de a bytes

Para un byte, el menor número posible es 0 (representado por ocho ceros: 00000000), y el mayor es 255 (representado por ocho unos: 11111111), que permite la creación de 256 valores diferentes.

Así como tenemos el Byte (8 bits), tenemos el Kilobyte (1024 Bytes), el Megabyte (1024 Kilobytes), un Gigabyte (1024 Megabytes), un Terabyte (1024 GB), etc.

### Tabla ASCII
Queda claro entonces que la maquina solamente entiende numeros, y entonces llega la cuestión: de alguna manera represento, por ejemplo, una 'a'. Así, cada entrada tiene su representación interna, y está dada por la Tabla ASCII.

El código ASCII se creó en la década de 1960 como un estándar para la transferencia de datos entre computadoras. Es un estándar mundialmente conocido y utilizado.

[Tabla ASCII](https://github.com/eCanayUnsam/Labo-1/blob/main/Imagenes/tascii.pdf)

### Bajo Nivel
Acá ubicamos el lenguaje ensamblador, este es lo más cercano al código maquina que uno puede escribir. Un programa assembler se ocupa de traducirlo a maquina según el micro con el que el cuenta el sistema. Escribir en assembler tiene la limitación de que hay que conocer sobre el hardware específico de la máquina, y si lo hacemos mal se pueden generar fallos críticos en el sistema (¡pum!)

![Assembler](https://github.com/GeroGauna222/Labo1/blob/main/xExtra/assem.png)

### Alto Nivel
Ahora sí. Para facilitarnos la vida, llegaron los lenguajes de alto nivel, son los que ustedes conocen como lenguajes de programación. Python, Java y C son de este tipo, y son lo que estaremos utilizando en este curso, más precisamente lenguaje C. Claramente, el hecho de que sea más fácil para nosotros el escribir en lenguajes de alto nivel, conlleva más pasos y procesos por los que las instrucciones deberán pasar para llegar a algo que la maquina comprenda.
El proceso parece complicado, pero realmente no lo es (porque se ocupa sola la compu, vos solo te sentas y esperas unos milisegundos).
Como nosotros trabajaremos con C, mostraremos como funciona en el caso de este lenguaje, y lo simplificaremos en los siguientes pasos:

![Compilacion](https://github.com/eCanayUnsam/Labo-1/blob/main/Imagenes/Compilador.jpg)

**Codigo Fuente** o *source code* es lo que uno escribió con la sintaxis de C

**El preproceador**
El preprocesador acepta el código fuente como entrada y es responsable de:
- quitar los comentarios
- interpretar las directivas del preprocesador, las cuales inician con #.

  - #include -- incluye el contenido del archivo nombrado. Estos son usualmente
llamados archivos de cabecera (header).
    - #include <math.h> -- Archivo de la biblioteca estándar de matemáticas.
    - #include <stdio.h> -- Archivo de la biblioteca estándar de Entrada/Salida.
  - #define -- define un nombre simbólico o constante. Sustitución de macros.
    - #define TAM_MAX_ARREGLO 100

**Compilador de C**
El compilador de C traduce a código deensamblador.

**Ensamblador**
El ensamblador crea los archivos objeto .o.

**Enlazador** 
Si algún archivo fuente hace referencia a funciones de una biblioteca o de funciones que están definidas en otros archivos fuentes, el enlazador combina estas funciones (con main()) para crear un archivo ejecutable. Las referencias a variables externas en esta etapa son resueltas.

En la práctica, terminamos haciendo este proceso incontables veces hasta que nos dejen de saltar errores (si, hasta a los senior les pasa), pero como esto lo hace la maquina sin que nos enteremos de nada (encima nos va a decir DONDE estan los errores) y, además, vamos a estar ayudados por un debugger (gracias IDE), no nos tenemos que procupar mucho. 

##
Okey, ya empezamos con las definiciones, pero no nos vayamos por las ramas con conceptos complicados y palabras raras. Mejor vayamos un poco mas a lo importante, a lo que a nosotros nos gusta y nos va a entretener en la materia...

Se nombraron una serie de palabras que tal vez para algunos sean un poco chino. Así que tiremos estas palabras al aire, junto con otros que también estaría bueno conocer antes de empezar:

*Comentarios* : Texto que se agrega al código fuente para facilitar su comprensión y mantenimiento. Los comentarios son ignorados por el compilador y se escriben en lenguaje natural, son útiles para recordar detalles importantes, explicar el propósito de un bloque de código, documentar el código y colaborar con otros programadores. 

*Debugger* : herramienta que ayuda a los programadores (si, VOS) a detectar y corregir errores en el código de un programa

*Funciones* : Son bloques de código que están preparados para cumplir con cierta función, reciben ciertos datos para luego devolver otros. Sirven para realizar tareas concretas y simplificar el programa a la vista, además de evitar tener que escribir el mismo pedacito de código varias veces.

*Directivas de pre-procesador (**#**)* : Se utilizan para modificar el código fuente antes de que el compilador lo procese, se identifican por el signo **#** al principio de la línea. 

*Headers (**.h** files)* : Parte vital del lenguaje C, .h es una simple extensión para identificar un tipo de archivo y significa header (cabecera). Se lo incluye con la sentencia #include.
Contiene tipos de datos, constantes, macros, funciones, definiciones de las clases. Su objetivo es que el programa donde se incluya ese header conozca esa información y la pueda utilizar.

Pasamos al concepto de **libraries**, archivos .o que incluyen estas funciones y demás que ya fueron pre-definidas en el archivo *.h* . Conlleva mucha explicación para esta altura, pero quedemonos con el siguiente concepto, para utilizar las librerías que contienen ciertas funciones, debemos incluir el archivo .h indicado para la misma. Tenemos las llamadas ***Standard Libraries*** de C

[Referencia ANSI C](https://github.com/eCanayUnsam/Labo-1/blob/main/GUIA%20REF%20C.pdf).

*Macros* : conjunto de comandos que se pueden ejecutar con una palabra clave. Son útiles para automatizar tareas repetitivas y ahorrar tiempo

*Variable* : un espacio en la memoria de un ordenador que almacena datos. Los datos que se almacenan en una variable pueden ser de cualquier tipo, como números, cadenas de texto, objetos o booleanos. Se identifican en el codigo con un **nombre *unico***

*IDE* : una aplicación que ayuda a los programadores a desarrollar software. Combina herramientas como editores de código, compiladores, depuradores, entre otras, en una sola interfaz.

*Framework* : es un marco de trabajo, proporciona un conjunto de herramientas, librerías y estructuras predefinidas que ayudan a desarrollar aplicaciones, para tareas específicas, de manera más rápida y eficiente.

## Tipos de datos

Cuando usamos un programa es muy importante manejar datos. En C podemos almacenar los datos en variables, como ya dijimos. El contenido de las variables se puede ver o cambiar en cualquier momento. Estas variables pueden ser de distintos tipos dependiendo del dato que queramos meter. No es lo mismo guardar un nombre que un número.
