//#include <stdio.h>
//#include <math.h>
//
//int main(){
//    int op, op2;
//    float side_1, side_2, side_3;
//    printf("Ingrese que desea armar: \n1) cuadrado \n2) triangulo rectángulo\n");
//    scanf("%d", &op);
//
//    if (op==1){
//        printf("ingrese la medida del lado: ");
//        scanf("%f", &side_1);
//
//        printf("ingrese 1 para calcular area, 2 para calcular perímetro: ");
//        scanf("%d", &op2);
//
//        if (op2==1){
//            float area = pow(side_1, 2);
//            printf("el area es %.2f", area);
//        }
//        else if (op2==2){
//            float perim = side_1 * 2;
//            printf("el perimetro es %.2f", perim);
//        }
//        else{
//            printf("ingreso un valor no valido\n");
//        }
//
//    }
//    else if (op==2){
//        printf("ingrese la medida del cateto 1: ");
//        scanf("%f", &side_1);
//
//        printf("ingrese la medida del cateto 2: ");
//        scanf("%f", &side_2);
//
//        printf("ingrese la medida de la hipotenusa: ");
//        scanf("%f", &side_3);
//
//        // verifico que sea un triangulo valido haciendo pitágoras
//        float valid = sqrt(pow(side_1,2) + pow(side_2,2));
//        // Pitagoras: el cuadrado de la hipotenusa es igual a la suma de los cuadrados de los catetos
//
//        if (valid == side_3){
//            printf("ingrese 1 para calcular area, 2 para calcular perímetro: ");
//            scanf("%d", &op2);
//
//            if (op2==1){
//                float area = (side_1*side_2)/2;
//                printf("el area es %.2f\n", area);
//            }
//            else if (op2==2){
//                float perim = side_1 + side_2 + side_3;
//                printf("el perimetro es %.2f\n", perim);
//            }
//            else{
//                printf("ingreso un valor no valido\n");
//            }
//        }
//        else{
//            printf("el triangulo rectángulo que ingresaste no es posible de armar");
//        }
//    }
//
//    else{
//        printf("ingreso un valor no valido");
//    }
//
//    return 0;
//}
