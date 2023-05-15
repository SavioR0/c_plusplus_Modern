#include <iostream>
#include <vector>
#include <algorithm>

class Exemplo {
private:
    int valor;

public:
    Exemplo(int v) : valor(v) {
        std::cout << "Construtor chamado para " << valor << std::endl;
    }

    Exemplo(const Exemplo& other) : valor(other.valor) {
        std::cout << "Construtor de cópia chamado para " << valor << std::endl;
    }

    Exemplo(Exemplo&& other) noexcept : valor(other.valor) {
        other.valor = 0;
        std::cout << "Construtor de movimento chamado para " << valor << std::endl;
    }

    Exemplo& operator=(const Exemplo& other) {
        valor = other.valor;
        std::cout << "Operador de atribuição por cópia chamado para " << valor << std::endl;
        return *this;
    }

    Exemplo& operator=(Exemplo&& other) noexcept {
        valor = other.valor;
        other.valor = 0;
        std::cout << "Operador de atribuição por movimento chamado para " << valor << std::endl;
        return *this;
    }

    int getValor() const {
        return valor;
    }

    bool operator<(const Exemplo& other) const {
        return valor < other.valor;
    }
};

int main() {
    std::vector<Exemplo> vec;
    vec.emplace_back(3);
    vec.emplace_back(1);
    vec.emplace_back(2);

    std::sort(vec.begin(), vec.end());

    std::cout << "Valores ordenados:" << std::endl;
    for (const auto& e : vec) {
        std::cout << e.getValor() << " ";
    }
    std::cout << std::endl;

    return 0;
}
