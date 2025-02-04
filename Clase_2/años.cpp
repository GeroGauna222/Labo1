#include<stdio.h>
// HALLAR ERRORES
int main(){
int age, days_age, days, weeks, weeks_age;

days = 365;
days_age = age * days;
weeks = 12*4;

printf("Ingrese su edad: ");
scanf("%d", age);

weeks_age = age * weeks;

printf("años de vida: %d\nsemanas de vida: %d\ndias de vida: \n", age, weeks_age, days);

return 0;
}

