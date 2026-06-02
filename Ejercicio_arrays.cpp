#include <iostream>

int main() {
    int numeros[100];
    int contador = 0;
    int n;

    do {
        std::cout << "Introduce un numero (0 para terminar): ";
        std::cin >> n;
        if (n != 0 && contador < 100)
            numeros[contador++] = n;
    } while (n != 0);

    std::cout << "\nNumeros introducidos:\n";
    for (int i = 0; i < contador; i++)
        std::cout << numeros[i] << "\n";

    return 0;
}
