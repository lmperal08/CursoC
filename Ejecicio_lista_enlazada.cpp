#include <iostream>

// Estructura para cada nodo de la lista
struct Nodo {
    int dato; //dato que se quiere guardar
    Nodo* siguiente; //puntero que guarda una dirección de memoria, siguiente valor (crea una variable llamada siguiente que sirve exclusivamente para guardar la dirección de memoria de otro nodo)
};

// Función para agregar un nodo al inicio de la lista, cabeza es el principio de la lista
void agregarAlInicio(Nodo*& cabeza, int nuevoValor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = nuevoValor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Nodo* cabeza = nullptr; // Inicializar lista vacía

    agregarAlInicio(cabeza, 30);
    agregarAlInicio(cabeza, 20);
    agregarAlInicio(cabeza, 10);

    std::cout << "Lista enlazada: ";
    imprimirLista(cabeza);

    return 0;
}