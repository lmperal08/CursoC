#include <iostream>
#include <memory>
#include <string>

class Mascota {
    std::string nombre_;
public:
    Mascota(std::string nombre) : nombre_(nombre) {
        std::cout << "-> [Nace] Mascota creada: " << nombre_ << "\n";
    }
    ~Mascota() {
        std::cout << "-> [Muere] Mascota destruida: " << nombre_ << "\n";
    }
    void hacerSonido() const {
        std::cout << nombre_ << " dice: ¡Guau!\n";
    }
};

int main() {
    std::cout << "=== PASO 1: Creando un puntero inteligente ===\n";
    // std::make_unique reserva memoria y mete al perro "Firulais" dentro.
    // El puntero 'punteroOriginal' guarda la DIRECCIÓN de Firulais.
    std::unique_ptr<Mascota> punteroOriginal = std::make_unique<Mascota>("Firulais");

    // Usamos el operador '->' para entrar a la dirección y llamar al método
    punteroOriginal->hacerSonido();

    std::cout << "\n=== PASO 2: Intentar copiar (¡Esto dará error si lo descomentas!) ===\n";
    // Un unique_ptr es un "dueño único". No permite que dos personas tengan su dirección.
    // std::unique_ptr<Mascota> intentoDeCopia = punteroOriginal; // ¡ERROR DE COMPILACIÓN!

    std::cout << "\n=== PASO 3: Transferir la propiedad (std::move) ===\n";
    // Con std::move, 'punteroOriginal' le regala la dirección a 'nuevoPuntero'.
    // 'punteroOriginal' se queda VACÍO (apunta a la nada / nullptr).
    std::unique_ptr<Mascota> nuevoPuntero = std::move(punteroOriginal);

    // Comprobamos quién tiene al perro ahora:
    if (punteroOriginal == nullptr) {
        std::cout << "punteroOriginal ahora está VACÍO.\n";
    }
    
    if (nuevoPuntero != nullptr) {
        std::cout << "nuevoPuntero ahora TIENE el control de la mascota.\n";
        nuevoPuntero->hacerSonido(); // Funciona perfectamente
    }

    std::cout << "\n=== PASO 4: Fin del programa ===\n";
    // Al llegar al final de main(), 'nuevoPuntero' se destruye. 
    // Como es inteligente, él solo libera la memoria automáticamente.
    return 0;
}