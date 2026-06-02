#include <iostream>
#include <vector>
#include <memory>

class IFigura {
public:
    virtual ~IFigura() = default;
    virtual double Area() const = 0;
    virtual int Color() const = 0;
    virtual void Imprimir() const = 0;
};

class Cuadrado : public IFigura {
    double lado_;
    int color_;
public:
    Cuadrado(double lado, int color) : lado_(lado), color_(color) {}
    double Area() const override { return lado_ * lado_; }
    int Color() const override { return color_; }
    void Imprimir() const override {
        std::cout << "Cuadrado | area: " << Area() << " | color: " << color_ << "\n";
    }
};

class Circulo : public IFigura {
    double radio_;
    int color_;
public:
    Circulo(double radio, int color) : radio_(radio), color_(color) {}
    double Area() const override { return 3.14159265358979 * radio_ * radio_; }
    int Color() const override { return color_; }
    void Imprimir() const override {
        std::cout << "Circulo | area: " << Area() << " | color: " << color_ << "\n";
    }
};

class Canvas {
    std::vector<std::unique_ptr<IFigura>> figuras_;
public:
    void Add(std::unique_ptr<IFigura> figura) {
        figuras_.push_back(std::move(figura));
    }
    void ImprimirFiguras() const {
        for (const auto& f : figuras_)
            f->Imprimir();
    }
};

int main() {
    Canvas canvas;
    canvas.Add(std::make_unique<Cuadrado>(4.0, 1));
    canvas.Add(std::make_unique<Circulo>(2.0, 2));
    canvas.Add(std::make_unique<Cuadrado>(1.5, 3));

    canvas.ImprimirFiguras();
    return 0;
}