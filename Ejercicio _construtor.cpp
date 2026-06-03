#include <iostream>
#include <vector>
#include <memory>
#include <utility>

class MiClase {
private:
    int* datos;

public:
    MiClase() {
        datos = new int(0);
        std::cout << "Constructor por defecto\n";
    }

    MiClase(const MiClase& otro) {
        datos = new int(*otro.datos);
        std::cout << "Constructor de copia (Punto de interrupcion aqui)\n"; // <- PONER BREAKPOINT AQUI
    }

    MiClase(MiClase&& otro) noexcept {
        datos = otro.datos;
        otro.datos = nullptr;
        std::cout << "Constructor de movimiento (Punto de interrupcion aqui)\n"; // <- PONER BREAKPOINT AQUI
    }

    ~MiClase() {
        delete datos;
    }
};

int main() {
    std::cout << "--- PRUEBA COPIA CON VECTOR ---\n";
    std::vector<MiClase> lista;
    MiClase objeto1;
    
    lista.push_back(objeto1); 

    std::cout << "\n--- PRUEBA MOVIMIENTO CON UNIQUE_PTR ---\n";
    std::unique_ptr<MiClase> ptr1 = std::make_unique<MiClase>();
    
    std::unique_ptr<MiClase> ptr2 = std::move(ptr1); 

    return 0;
}