//#include<stdio.h>
//
//int main(){
//    int age, days_age, days, weeks, weeks_age, year;
//
//    days = 365;
//
//    weeks = 12*4;
//
//    printf("Ingrese su edad: ");
//    scanf("%d", &age);
//    printf("Ingrese el a�o actual: ");
//    scanf("%d", &year);
//
//    weeks_age = age * weeks;
//    days_age = age * days;
//
//    printf("a�os de vida: %d\nsemanas de vida: %d\ndias de vida: \n", age, weeks_age, days);
//
//    // verificamos si cumpli� este a�o ya
//    int answer, age_year;
//
//    printf("Ya cumpliste este a�o?(1 para si, 0 para no) ");
//    scanf("%d", &answer);
//    age_year = 2024 - age;
//
//    if (answer == 1){ // si cumplio...
//        printf("naciste en %d", age_year);
//    }
//    else if (answer == 0){ // si no cumpli�...
//        age_year--;
//        printf("naciste en %d", age_year);
//    }
//    else{ // si no ingreso 1 o 2...
//        printf("ingresaste un valor invalido");
//    }
//
//    return 0;
//}
//
