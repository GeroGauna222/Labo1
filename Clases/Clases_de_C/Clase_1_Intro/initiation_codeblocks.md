# **INSTALACION DE CODEBLOCKS**

En el curso, tendrán la libertad de usar los siguientes IDEs:
- Visual Studio Code (para los más atrevidos)
- Code::Blocks (el que se usa en la bibliografía de la materia)

Ambos funcionan, con ambos van a poder aprender. Quédense tranquilos. A continuación paso a explicarles como descargar el Code::Blocks,
es muy sencillo y tambien lo encuentran en la bibliografia (C for Dummies).

Bueno, arrancamos siguiendo este link: https://www.codeblocks.org/downloads/ 

Ahí se van a encontrar con *Download the binary release*, hacen click y buscan su sistema operativo (Windows MACOS Linux). Bajan el que 
corresponda a SU maquina

## **Abrimos Code:Blocks**
Bueno, estamos adentro, okey, muchas cosas, interfaz que parece de Windows XP, pero no nos asustemos. Organicemonos

Vemos varias areas en la pantalla, todas las vamos a usar (no todas sus herramientas porque son millones).

Lo normal sería usar un text editor, un compilador y un linker. Todo se podría manejar desde el terminal, 
escribiendo comandos para editar compilar, linkear, correr. 
Bueno, el IDE tiene todo eso integrado, yyyyy un debugger, ademas de otras herramientas extra.

### Vamos ahora a crear **nuestro primer proyecto**
Bueno, el IDE tiene un potencial grandísimo, sin embargo en este curso vamos a ir a lo simple, básico y consciso.

Ya abrimos el IDE, podemos ver que empezamos en una hoja con el logo del programa, el *start here*, y vemos que cuenta con un par de links.
Vamos a tocar **New Project**.

Un proyecto en Code::Blocks es una *estructura organizada* que agrupa todos los archivos relacionados con un programa (código fuente, archivos de cabecera, bibliotecas, etc.) dentro de sí. Cuando creas un proyecto, Code::Blocks agrupa varios componentes en una carpeta para mantener todo organizado. Estos son los principales:

Archivos de código fuente:
Lo que nosotros escribimos en lenguaje C. Estos archivos suelen tener extensión .c (por ejemplo, main.c).

Archivos útiles:
Como imagenes o demás que podemos estar utilizando en nuestro proyecto

Archivos de configuración:
Code::Blocks genera un archivo especial (con extensión .cbp) que guarda información sobre cómo debe compilar (traducir) y ejecutar tu programa.

Archivos binarios (compilados):
Cuando se construye (o compila) tu programa, Code::Blocks crea un archivo que la computadora puede entender (generalmente dentro de una carpeta llamada bin o output).

Nos va a saltar otra ventana, *New from template*
Que opción tomamos? Hay un millon, si ya se. Bueno, para empezar el template es basicamente un *molde* para el proyecto, dependiendo de cual sea el fin del
mismo, uno podría elegir este o el otro. Vienen con cosas predefinidas para ciertos usos. Para nosotros que estamos arrancando, elegimos *Console Application*

Nos salta el Wizard

Elegimos C como lenguaje

Nombre de proyecto y ubicación, creemos una carpeta para guardar los proyectos!!

Ya seleccionado eso, vamos a next, elegimos el compilador GNU CC y vamos a checkear las opciones de Debug y Release.

Finish y listo, tengo mi proyecto

A la izquierda en el Management vemos que aparece algo ahora, si tocamos la carpeta Source vamos a ver un archivo *main.c*. Este archivo de texto plano es un archivo de codigo fuente, si hacemos doble click lo vamos a ver en el panel más grande, el editor de texto. Vemos el codigo todo colorido, lindo. Si Gero lo que quieras hermoso todo... pero que significa????? 



Obvio, chino básico POR AHORA. Desglocemos...

Vemos arriba unos #, las directivas del preprocesador. Ya hablamos de estos include, estamos trayendo librerias, las podemos ver en la [Referencia ANSI C](https://github.com/eCanayUnsam/Labo-1/blob/main/GUIA%20REF%20C.pdf). Ahí vamos a ver las funciones y macros que traen estas librerias.

### main(){ ???

main() es el punto de entrada de todo programa en C, y es una función. Ya sé, todavía no hablamos de qué es una función a fondo, ahora hacemos una breve introducción. Cuando ejecutas el programa, el sistema operativo busca automáticamente el main para empezar la ejecución.

Desglose de int main():
- int: Indica que la función main() devuelve un número entero.
- main: Es el nombre de la función principal. TIENE QUE SER main, NO LO CAMBIES
- (): Indica que es una función. Acá irían los *parámetros* de la función, valores de entrada que necesita la función, yo le doy algo para que me devuelve algo más, después lo vamos a ir viendo más a fondo.
- {}: Marca el inicio y final del bloque de código que pertenece a main().
- return 0: es la devolución de la función, si devuelve el 0, es que todo funcionó como corresponde

Dentro de la función vemos un par de cosas:
- Está tabeado
- Un printf()
- ;

**printf** ya lo vimos en la libreria, es una función. Podemos jugar poniendo otras!!

El tabeo se utiliza para ordenar el código. Funcionaría sin estos? Sin problema. Los tenemos que usar? Si, sino el día que alguien quiera leer lo que escribiste
va a tener que hacer un laburo esclavizante para entenderlo (no queremos eso, la esclavitud ya se abolió hace rato).

Lo que sí es obligatorio es usar ';', esta indica el final de una orden o *statement*. Son parte importante de la sintaxis del lenguaje y el mal uso de estos 
generará errores en el código cuando quiera compilarlo.

Ya sabiendo todo esto, estamos listos para ver magia. Si tocamos en la ToolBar de arriba el botón de Build lo que voy a estar haciendo es compilar y linkear. Despues tengo el botón Run y el botón Build and Run. Toquemos ese último y vemos que pasa

Así se termina viendo el proyecto en su ubicación en la pc:

📂 MiProyecto/         <-- Carpeta principal del proyecto

 ├── 📄 main.c               <-- Archivo con tu código
 
 ├── 📄 MiProyecto.cbp <-- Archivo de configuración del proyecto, le dice al IDE como ejecutar tu programita
 
 ├── 📂 bin/                 <-- Carpeta donde se guarda el programa final
 
 └── 📂 obj/                 <-- Carpeta con archivos intermedios
