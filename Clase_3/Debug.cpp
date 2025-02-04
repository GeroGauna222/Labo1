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
//    printf("Ingrese el año actual: ");
//    scanf("%d", &year);
//
//    weeks_age = age * weeks;
//    days_age = age * days;
//
//    printf("años de vida: %d\nsemanas de vida: %d\ndias de vida: \n", age, weeks_age, days);
//
//    // verificamos si cumplió este año ya
//    int answer, age_year;
//
//    printf("Ya cumpliste este año?(1 para si, 0 para no) ");
//    scanf("%d", &answer);
//    age_year = 2024 - age;
//
//    if (answer == 1){ // si cumplio...
//        printf("naciste en %d", age_year);
//    }
//    else if (answer == 0){ // si no cumplió...
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
