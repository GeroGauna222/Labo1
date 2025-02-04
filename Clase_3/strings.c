#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//int main() {
//
//    char nombre[20]; // entran 19 chars y '\0'
//    char nombre2[20];
//    char nombre3[20];

    // INGRESOS POR TECLADO

//    printf("Ingrese su nombre y apellido: ");
//    scanf("%s", nombre);
//
//    for(int i=0 ; i<20 ; i++) { // �Que voy a ver? �que sucedera con las posiciones restantes? 1) valores basura - 2) todos valores nulos
//        printf("%d) %c\n", i, nombre[i]);
//    }
//
//    printf("escriba otra palabra: ");
//    scanf("%s", nombre2);
//    printf("- SCAN: %s\n", nombre2);

    // scanf deja de leer al encontrar un espacio, \t, \n (enter en Linux) o \r\n (enter en Windows, en realidad es por el \n pero \r no queda escrito en el string)
    // ser�n nulos cuando haya inicializado el array, si lo escribo yo, lo que queda ah� es basura













    /* Miremos el scanf....
    no tiene & !!!!! �Por qu�?
    */

    /* UN ARRAY ES UN PUNTERO
    Un puntero es una variable que almacena la direcci�n de memoria de otra variable.
    En lugar de guardar un valor directamente, un puntero guarda la direcci�n donde se encuentra ese valor.
    Tiene un TIPO, es decir int char float etc
    - & (Operador de Direcci�n): Se usa para obtener la direcci�n de memoria de una variable. Por ejemplo, &x da la direcci�n de x.
    - * (Operador de Desreferenciaci�n): Se usa para acceder al valor en la direcci�n de memoria que el puntero est� almacenando.
                                         Por ejemplo, si p es un puntero, *p da el valor almacenado en la direcci�n a la que p apunta.
    */












//    int x = 1;
//    int *p; // declaro puntero a int
//    p = &x; // guarda la direccion de x, cuando ponga *p me da el valor en x(1), cuando pongo p me da la direcci�n
//    printf("Valor de p: %p\n", p);
//    printf("Valor de x, al que apunta p: %d\n", *p);
//    *p = 10;
//    printf("NUEVO Valor de x, al que apunta p: %d\n", *p);
//    printf("NUEVO Valor de x: %d\n", x);

    /* si tengo...
    char nombre[20];
    Esto es un array. Cuando lo paso como argumento a un scanf, paso directamente el nombre (pues apunta a una direccion de memoria)
    Nombre es, esencialmente, un puntero al primer elemento del array
    Entonces nombre funciona como &nombre[0]
    al usarlo en un printf, %s pide un puntero a char, busca el caracter '\0' desde la posicion de memoria que se le pasa,
    si le paso nombre le estoy pasando &nombre[0]
    */

//    printf("Escribo nombre: ");
//    scanf("%s", nombre3);
//
//    printf("- SCAN nombre[]: %s\n", nombre3);
//
//    for(int i=0 ; i<20 ; i++) {
//        printf("%d) %c\n", i, nombre3[i]);
//    }











    /* LIMITACIONES SCANF()
        - Solo leer�a UNA palabra
        - Puede llevar al DESBORDAMIENTO DEL BUFFER DE ENTRADA
    */

    // �QUE ES EL DESBORDAMIENTO DEL BUFFER?
//    printf("Ingrese palabra o algo de 19 letras o menos:  ");
//    scanf("%s", nombre3);
//
//    for(int i=0 ; i<40 ; i++) {
//        printf("%d) %c\n", i, nombre[i]);
//    }












    /* �Por qu� sigue escribiendo? �Y esos espacios en blanco?

    Desbordamiento del buffer: scanf est� escribiendo en memoria fuera de los l�mites de nombre. Esto puede causar que datos sean escritos en �reas
    de memoria que no est�n relacionadas con 'nombre', no hay garantia de que los datos desbordados se guarden en las posiciones siguientes

    Memoria no inicializada: Las posiciones 20 a 23 del array nombre no han sido tocadas por el scanf, porque ya sobrepasaste su tama�o en memoria
    y el comportamiento ser� INDEFINIDO

    Dado que no hay datos espec�ficos en esas posiciones, su contenido podr�a ser cualquier cosa, incluyendo lo que parecen ser "espacios en blanco"
    (aunque en realidad pueden ser valores nulos \0 o simplemente bytes sin inicializar que no se representan visualmente).

    - LLEVA A PROBLEMAS DE SEGURIDAD Y A FALLOS EN EL CODIGO
    */

     //�C�MO EVITO DESBORDAR EL BUFFER?
    //scanf("%19s", nombre);  // da un limite al ingreso
    // peroooooo y el problema de los espacios?...








//    char str[20];
//    char str2[20];
    // GETS()
//    gets() lee hasta encontrar \n
    //fflush(stdin);
//    printf("escribe el gets: ");
//    gets(str);
//    printf("\n%s\n", str);
    //fflush(stdin);
//    printf("Escribe el segundo gets: ");
//    gets(str2);
//    printf("%s\n", str2);
//// no evita el desbordamiento: unsafe function





//    /*FGETS()
//        funci�n que se usa para leer una l�nea de texto desde un flujo de entrada (como stdin, que representa la entrada est�ndar,
//        generalmente el teclado). A diferencia de gets, fgets es m�s seguro porque permite especificar un tama�o m�ximo de caracteres
//        a leer, lo que previene desbordamientos de buffer.
//    */
//
//    char str3[20];
//    fflush(stdin);
//    printf("ingrese una palabra: ");
//    fgets(str3, sizeof(str3), stdin);
// donde guardo  tama�o       de donde lo leo

// lee esa cantidad de chars o hasta encontrar \n
// si escribo 20 letras fgets no lee las 20, pues esta la reserva para '\0'
// pero si escribo menos? debo rellenar antes con '\0', inicializamos con = {0}








// Problema: incluye el \n �Como lo rescuelvo? string.h
//str3[strcspn(str3, "\n")] = '\0';
//printf("%s", str3);
// halla el s[x] en el que esta \n y pone un \0, strcspn lo que devuelve es la posici�n de str3 en la que '\n' se encuentra (devuelve la posici�n de \
// y sobreescribe con '\0', sobreescribiendo por defecto n).






/* Funciones
una funci�n es un bloque de c�digo que realiza una tarea espec�fica.
Las funciones ayudan a dividir un programa en partes m�s peque�as y manejables,
lo que facilita la escritura, el entendimiento y el mantenimiento del c�digo. Las funciones
tambi�n permiten reutilizar el c�digo sin tener que reescribirlo cada vez que se necesita.

DRY : DONT REPEAT YOURSELF

Una funci�n en C se compone de varias partes:

Tipo de Retorno: Especifica el tipo de dato que la funci�n devolver� despu�s de ejecutarse.
                 Si no devuelve ning�n valor, se utiliza void.

Nombre de la Funci�n: Es un identificador que se utiliza para llamar a la funci�n.

Par�metros (Opcional): Son variables que se pasan a la funci�n para que trabaje con ellas.
                       Los par�metros se encierran entre par�ntesis. Si no se necesitan par�metros, se dejan los par�ntesis vac�os.

Cuerpo de la Funci�n: Es un bloque de c�digo encerrado entre llaves { } que contiene las
                      instrucciones que se ejecutar�n cuando se llame a la funci�n y, de ser
                      necesario, un retorno.
*/

//int sumar(int a, int b) {
//    int resultado = a + b;
//    return resultado;
//}
//
//void imprimirMensaje() {
//    printf("Hola, esta es una funci�n que no devuelve nada.\n");
//}















//}
