#include <iostream>
#include <vector>
#include <memory>

class Recurso {
    std::unique_ptr<int> dato;   // miembro no copiable... salvo que lo hagamos a mano
public:
    Recurso() : dato(std::make_unique<int>(0)) {
        std::cout << "  Constructor por defecto\n";
    }

    Recurso(const Recurso& o)                       // <-- breakpoint aquí
        : dato(std::make_unique<int>(*o.dato)) {
        std::cout << "  Constructor de COPIA\n";
    }

    Recurso(Recurso&& o) NOEXCEPT                    // <-- breakpoint aquí
        : dato(std::move(o.dato)) {
        std::cout << "  Constructor de MOVE\n";
    }
};

int main() {
    std::cout << "Llenando vector y forzando reasignaciones:\n";
    std::vector<Recurso> v;
    for (int i = 0; i < 4; ++i) {
        std::cout << "push_back " << i << " (size=" << v.size()
                  << " cap=" << v.capacity() << ")\n";
        v.push_back(Recurso{});   // el temporal entra por MOVE;
                                  // los ya existentes se reubican según noexcept
    }
}

/*
# MOVE noexcept -> el vector mueve al reasignar
g++ -std=c++17 -O0 -DNOEXCEPT=noexcept demo.cpp -o demo && ./demo

# MOVE SIN noexcept -> el vector COPIA al reasignar (aunque haya unique_ptr)
g++ -std=c++17 -O0 -DNOEXCEPT= demo.cpp -o demo && ./demo
*/