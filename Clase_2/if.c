//#include <stdio.h>
//
//int main() {
//    int a, b;
//    printf("Ingresa dos n�meros enteros:\n");
//    scanf("%d %d", &a, &b);
//
//    // Primer bloque if-else: Compara si a es mayor que b
//    if (a > b) {
//        printf("%d es mayor que %d\n", a, b);
//    } else if (a < b) {
//        printf("%d es menor que %d\n", a, b);
//    } else {
//        printf("%d es igual a %d\n", a, b);
//    }
//
//    // Segundo bloque if-else: Realiza operaciones aritm�ticas simples
//    if ((a + b) > 10) {
//        printf("La suma de %d y %d es mayor que 10\n", a, b);
//    } else if ((a * b) == 0) {
//        printf("El producto de %d y %d es 0\n", a, b);
//    } else {
//        printf("La suma de %d y %d es menor o igual que 10, y su producto no es 0\n", a, b);
//    }
//
//    // Tercer bloque if-else: Usa la divisi�n para verificar si uno es m�ltiplo del otro
//    if (b != 0 && a % b == 0) {
//        printf("%d es m�ltiplo de %d\n", a, b);
//    } else if (a != 0 && b % a == 0) {
//        printf("%d es m�ltiplo de %d\n", b, a);
//    } else {
//        printf("Ninguno de los n�meros es m�ltiplo del otro\n");
//    }
//
//    return 0;
//}
