#include <iostream>
int main(){
    int numero;
    std::cout <<"Introduce un número: ";
    std::cin >> numero;

    if (numero % 2 == 0) {
        std::cout <<"El número " <<numero<< " es divisible entre 2";
    } else {
        std::cout <<"El número " <<numero<< " 1no es divisible entre 2";
    }
    
}