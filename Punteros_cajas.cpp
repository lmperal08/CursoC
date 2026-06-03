#include <iostream>
#include <memory>

class Caja {
private:
    int contenido_; // Solo usamos 'int' para guardar el número entero

public:
    // Añadimos el constructor para poder recibir el número 50
    Caja(int valor) : contenido_(valor) {}

    // Añadimos una función para poder leer qué hay dentro de la caja
    int obtenerContenido() const { 
        return contenido_; 
    }
};

int main() { // 'main' siempre va en minúscula
    // 1. Creas el puntero original apuntando a una caja con un 50
    std::unique_ptr<Caja> punteroOriginal = std::make_unique<Caja>(50);
    
    // 2. Transfieres la propiedad correctamente con std::move
    std::unique_ptr<Caja> nuevoPuntero = std::move(punteroOriginal);
    
    // 3. Usamos '->' para entrar al objeto y llamar a su función
    std::cout << "El contenido de la caja es: " << nuevoPuntero->obtenerContenido() << std::endl;

    return 0;
}