#include <stdio.h>
#include <math.h>

//int main() {


/* ESTRUCTURAS DE CONTROL
Una estructura de control en C es un componente del lenguaje de programaci�n que permite alterar
    el flujo de ejecuci�n del programa bas�ndose en condiciones l�gicas o expresiones.
Estas estructuras son fundamentales para crear programas que tomen decisiones, elijan diferentes caminos de ejecuci�n o repitan tareas.

Las hay de 3 tipos...
*/


























// ESTRUCTURA DE CONTROL CONDICIONAL
// permiten que se ejecuten diferentes bloques de c�digo dependiendo del resultado de una condici�n l�gica o expresion.

// IF: se maneja en base al resultados de una condicion booleana
//
//    int x;
//    printf("ingrese un numero entero: ");
//    scanf("%d", &x);
//
//    if (x % 2 == 0) {
//        printf("par\n");
//            if (x > 0) {
//                printf("Mayor a cero\n");
//                    if (x == 5){
//                        printf("X es 5\n");
//                    }
//                    else {
//                        printf("X no es 5\n");
//                    }
//            }
//            else {
//                printf("Menor a cero");
//                if (x == -5){
//                        printf("X es -5\n");
//                    }
//                    else {
//                        printf("X no es -5\n");
//                    }
//            }
//    }
//    else {
//        printf("impar\n");
//        if (x > 0) {
//                printf("Mayor a cero\n");
//                    if (x == 5){
//                        printf("X es 5\n");
//                    }
//                    else {
//                        printf("X no es 5\n");
//                    }
//            }
//            else {
//                printf("Menor a cero");
//                if (x == -5){
//                        printf("X es -5\n");
//                    }
//                    else {
//                        printf("X no es -5\n");
//                    }
//            }
//    }
//return 0;
//}

// SWITCH: Permite tomar decisiones entre m�ltiples opciones en funci�n del valor de una expresi�n, generalmente una variable

//int opcion = 2;
//
//switch(opcion) {
//    case 1:
//        printf("Opci�n 1 seleccionada.\n");
//        break;
//    case 2:
//        printf("Opci�n 2 seleccionada.\n");
//        break;
//    case 3:
//        printf("Opci�n 3 seleccionada.\n");
//        break;
//    default:
//        printf("Opci�n no v�lida.\n");
//        break;
//}
//return 0;
//}
















// ESTRUCTURAS DE CONTROL ITERATIVAS / BUCLE : Permiten repetir un bloque de c�digo reiteradas veces hasta que se cumpla una condici�n
// Tenemos WHILE, DO WHILE y FOR




















// WHILE: Repite un bloque de c�digo mientras una condici�n sea verdadera, puede hacerse infinito (ojooooo) o podr�a suceder que nunca se ingrese al bucle

//    while(condicion) {
//        // evitar que sea infinito!!!!!
//    }


//int i = 1;  // Inicializaci�n
//
//while (i <= 5) {
//    printf("Numero: %d\n", i);
//    i++;  // Incremento
//}
//return 0;
//}




// Un uso com�n del bucle while es leer entradas del usuario y corregir hasta que se introduzca un valor v�lido.

//int numero;
//
//    // Bucle para asegurar que el usuario ingresa un n�mero positivo
//    printf("Ingrese un n�mero positivo mayor a cero: ");
//    scanf("%d", &numero);
//
//    while (numero <= 0) {
//        printf("El n�mero debe ser positivo. Int�ntelo de nuevo: ");
//        scanf(" %d", &numero);
//    }
//
//    printf("�Gracias! El n�mero ingresado es: %d\n", numero);
//
//return 0;
//}













// DO WHILE: Igual que while PERO garantiza que el bloque de c�digo dentro se ejecute aunque sea una vez
//

//    do {
//        // se ejecuta si o si una vez!!!
//    }while(condicion);



















//
//    int password, correct_password = 4;
//
//    do {
//        printf("Adivine el numero del 1 al 10: ");
//        scanf("%d", &password);
//        if (password != correct_password) {
//            printf("Contrase�a incorrecta, intente nuevamente\n");
//        }
//    } while (password != correct_password);
//
//    printf("Contrase�a correcta\n");
//
//
//
//    printf("Adivine el numero del 1 al 10: ");
//    scanf("%d", &password);
//
//    while (password != correct_password) {
//        printf("Contrase�a incorrecta, intente nuevamente\n");
//        printf("Adivine el numero del 1 al 10: ");
//        scanf(" %d", &password);
//    }
//
//    printf("Contrase�a correcta\n");
//
//return 0;
//}



















// FOR: para cuando conozco la cantidad de iteraciones que quiero hacer...
//    for(inicializo variable ; condicion ; actualizacion) {
//
//    }
//    for(;;)









//    int sum = 10;
//    for (int i = 1; i <= 10; i++) {
//        sum += i;
//        // sum = sum + i;
//    }
//
//    printf("La suma de los primeros 10 numeros es: %d\n", sum);
//
//    return 0;
//}



















    /* TODOS FUNCIONAN PARA CUALQUIER CASO DE ITERACION, PERO SON PREFERIBLES PARA CIERTAS SITUACIONES:
    FOR: Cantidad de iteraciones conocida
    WHILE: No conozco la cantidad de iteraciones y no necesito que se entre al bucle obligatoriamente
    DO WHILE: al menos una vez quiero que se muestre ---->(MENUS)<----
    */













/* - ESTRUCTURAS DE CONTROL DE SALTO

Permiten alterar el flujo del programa saltando a otras partes del c�digo

break: Rompe la estructura, saliendo de ella inmediatamente.
continue: Salta la iteraci�n actual de un bucle y pasa a la siguiente.
goto: Salta a una etiqueta espec�fica en el c�digo.
return: Sale de una funci�n y opcionalmente devuelve un valor.
*/





//    int par=0, impar=0, cont=1, x;
//    for (int i = 1; i <= 10; i++) { // El `for` se ejecuta 10 veces MAXIMO
//        printf("Ingrese un numero (intento n%c %d de 10): ", 167, i);
//        scanf("%d", &x);
//
//        // Verificamos si el n�mero es par o impar
//        if (x % 2 == 0) {
//            par++;
//        }
//        else {
//            impar++;
//        }
//
//        while (cont != 0) { // El `while` espera una confirmaci�n del usuario, se ocupa de que ingrese un valor v�lido
//            printf("%cQuiere seguir ingresando n�meros? (1 para si / 0 para no): ", 168);
//            scanf("%d", &cont);
//
//            if (cont == 0) {
//                break;  // Sale del while
//            } else if (cont == 1) {
//                break;  // Sale del while para continuar con el siguiente n�mero
//            } else {
//                printf("Entrada invalida. Intente de nuevo.\n");
//            }
//        }
//
//        if (cont == 0) {
//            break;  // Sale del for si el usuario no quiere continuar
//        }
//    }
//
//    printf("Total de n�meros pares: %d\n", par);
//    printf("Total de n�meros impares: %d\n", impar);
//
//    return 0;
//}


//WHILE:
//Desarrolle un algoritmo que le permita leer un valor entero positivo N
//y calcule su factorial.

//int int i=1, n;
//unsigned int fact=1;
//
//printf("ingrese un entero positivo: ");
//scanf("%d", &n);
//
//while(n<=0) {
//    printf("te dije entero positivo: ");
//    scanf("%d", &n);
//}
//
//while(i<=n) {
//    fact *= i;
//    // fact = fact * i
//    i++;
//}
//
//printf("el factorial de %d es %u", n, fact);
//
//return 0;
//}


//FOR:
//5! (se lee "factorial de cinco") es igual al producto 5.4.3.2.1. De manera similar,
//8! = 8.7.6.5.4.3.2.1. Escribe un programa que calcule el factorial de un n�mero
//que se ingresa por teclado (ten en cuenta el tipo de dato para obtener el resultado).

//fact=1
//
//printf("ingrese un entero positivo: ");
//scanf("%d", &n);
//
//while(n<=0) {
//    printf("te dije entero positivo: ");
//    scanf("%d", &n);
//}
//
//for(int i=1 ; i<=n ; i++) {
//    fact *= i;
//}
//
//
//printf("el factorial de %d es %ld", n, fact);
//
//return 0;
//}
//
//
//
//    int valor, valor_aux, res;
//    do{
//        printf("Ingrese un valor entero positivo: ");
//        scanf("%d", &valor);
//
//        if (valor <= 0){
//            printf("ERROR! no ha ingresado un valor aceptable.\n");
//        }
//    }while(valor <= 0);
//
//    valor_aux = valor - 1;
//    res = valor;
//    while(valor_aux > 0){
//        res = res * valor_aux;
//        valor_aux -= 1;
//    }
//    printf("El resultado del factorial de %d es: %d \n",valor ,res);

// OTRO EJEMPLO DE LO MISMO, MAS LINDO A LA VISTA

//    int num, i, factorial=1;
//
//    printf("Ingrese un numero para calcular su factorial: \n");
//    scanf("%d", &num);
//
//    while (num <= 0) {
//        printf("El numero tiene que ser un entero positivo: \n");
//        scanf("%d",&num);
//    }
//
//    for (i=1; i<=num; i++){
//        if (i==1) {
//            printf ("%d! =", num);
//        }
//        factorial *= i;
//        if (i > 1){
//            printf (" * ");
//        }
//        printf(" %d ", i);
//    }
//    printf("= %d", factorial);
//
//

//    return 0;
//}
