#include <stdio.h>
#include <math.h>
#define cuadrado(x) (x*x)

double root(double x);
double root2(double x);

int main(){
    printf("%f",root(3));
    printf("\n%f",root2(3));
    printf("\n%f",sqrt(3));
    return 0;
}

double root(double x){
    long double a[9];
    long double b[9]={1.0,0.1,0.01,0.001,0.0001,0.00001,0.000001};

    int i=0;
    for(i=0;i<9;i++){
       a[i]=0.0;
    }

    i=-1;
    while(a[i]*a[i]!=x){
        if(i==8)
            i=-1;
        i++;
        a[i]+=b[i];
        if(a[6]*a[6]>x)
            return a[6];
        else if(a[5]*a[5]==x)
            return a[5];
        else if(a[4]*a[4]==x)
            return a[4];
    }
    return a[i];
}

double root2(double x) {

    double factor = 1;
    while (cuadrado(factor) < x) factor *= 10;
    while (factor && cuadrado(factor) > x) factor /= 10;

    double raiz = factor;
    while (cuadrado(raiz) <= x) {
        while (cuadrado(raiz) <= x) {
            double ant = raiz;
            raiz += factor;
            if (raiz == ant)
                return raiz;
            }


         raiz -= factor;
         factor /= 10;
        }

    return raiz;
}
