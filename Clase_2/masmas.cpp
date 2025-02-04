#include <iostream>
using namespace std;

int main(){
    int a = 5;

    // escribe a como entero directamente
    cout << "Hola Mundo" << std::endl;

    cout << a << "*2 = " << a*2 << std::endl;

    // Convertimos el valor de 'a' a un carácter
    std::cout << "Valor de a como carácter: " << static_cast<char>(a) << std::endl;

    return 0;
}
