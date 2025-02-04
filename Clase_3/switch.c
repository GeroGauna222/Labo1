//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    char op;
//    float result, num1, num2;
//
//    printf("ingrese un numero: ");
//    scanf("%f", &num1);
//    printf("ingrese otro numero: ");
//    scanf("%f", &num2);
//    fflush(stdin);  // limpio el buffer
//
//    printf("ingrese segun lo que desee hacer:\n"
//           "+ para sumar\n"
//           "- para restar (primero menos segundo ingreso)\n"
//           "* para multiplicar\n"
//           "/ para dividir (primero sobre segundo ingreso)\n"
//           "P para hacer el primero elevado a la potencia del segundo ingreso\n");
//    scanf("%c", &op); // leo un caracter
//
//    switch (op) // switch evalúa con ese caracter que ingrese
//    {
//        case '+':
//            result = num1 + num2;
//            printf("%.2f + %.2f = %.2f", num1, num2, result );
//            break;
//        // siempre pongo los break para salir del switch una vez entre en un case
//        // SIEMPRE VA AL FINAL DEL CASE, para que se ejecute todo el case antes de salir del switch
//        case '-':
//            printf("%.2f - %.2f = %.2f", num1, num2, num1-num2 );
//            // otra forma válida de implementar la resta
//            break;
//        case '/':
//            if (num2==0){
//                printf("%.2f/0 es un valor invalido", num1);
//            }
//            else{
//                result = num1 / num2;
//                printf("%.2f / %.2f = %.2f", num1, num2, result );
//            }
//            break;
//        case '*':
//            result = num1 * num2;
//            printf("%.2f * %.2f = %.2f", num1, num2, result );
//            break;
//        case 'P':
//            result = pow(num1,num2);
//            printf("%.2f a la %.2f = %.2f", num1, num2, result );
//            break;
//        default:
//            printf("opcion no valida");
//    }
//    return 0;
//}
