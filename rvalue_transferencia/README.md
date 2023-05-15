# Referência rvalue, semântica de transferência e encaminhamento perfeito

## O que é a técnica Small String Optimization (SSO) utilizada em algumas implementações de linguagens de programação, como C++? Quais as vantagens e desvantagens dessa técnica?
Small string otimization é uma técnica que evita a aloação de memória para strings pequenas (menores que 23 bytes). Ao invés de aloada no heap, um buffer interno é reservado no objeto que contém a string.

As principais vantagens é o ganho no desempenho e uso eficiente de memória uma vez que não a alocação na heap e acesso ao dados de forma direta, uma vez que não há a neessidade de se criar um ponteiro para a heap. A desvantagem é complexidade de implementações de SSO, uma vez que requer tratamento especial em onstrutores, destrutores, operadores de atribuição e outros métodos realcionados à manipulação de strings. 

## O que é a otimização Named Return Value Optimization (NRVO)?
Named return Value é uma técnica de otimização que tem como objetivo reduzir a cópia desnecessária de objetos retornados por valor em funções. Essa técnica constroi o objeto diretamente no local de destino sem a necessidade de copia.

## O que é a técnica “copy and swap” e quais são as suas vantagens e desvantagens? Escreva um código de uma classe qualquer que implemente essa técnica?
A técnica copy and swap é a implementação de um operador de atribuição (=) de uma classe que envolve copiar um objeto temporário usando o construtor de cópia e em seguida trocar os conteúdos do objeto atual com a do objeto temporário usando o método swap. As vantagens são : é uma implementação simples , segura e eficiente uma vez que utiliza o método swap() que é implementado de forma eficiente. Entretanto a desvantagem é sobrecarga da memória quando se tem objetos que são muito grandes.

## A função std::sort da STL faz uso da função swap para realizar trocas entre os elementos de um container (por exemplo, std::vector) durante a ordenação. Isso nos leva a pensar que, ao ordenar um container, não serão criadas cópias temporárias caso exista uma definição especializada de swap para o tipo dos objetos armazenados no container. Porém, isso não é verdade. a função std::sort faz algumas cópias ao invés de trocas. (a) Escreva um código para testar essa situação. (b) Explique o porquê desse comportamento de std::sort.

```C++
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


```
```
././build/app
Construtor chamado para 3
Construtor chamado para 1
Construtor de movimento chamado para 3
Construtor chamado para 2
Construtor de movimento chamado para 3
Construtor de movimento chamado para 1
Construtor de movimento chamado para 1
Operador de atribuição por movimento chamado para 3
Operador de atribuição por movimento chamado para 1
Construtor de movimento chamado para 2
Operador de atribuição por movimento chamado para 3
Operador de atribuição por movimento chamado para 2
Valores ordenados:
1 2 3 
```
O código apresentado foi implementada um função própria da classe exemplo para realizar a troca entre os objetos. Entretando, não foi chamada nenhuma vez pela função std::sort durante a ordenação dos elementos. Isso se deu pelo fato de que a função não utiliza o swat e sim o move. É feita a movimentação dos elementos e não a troca o que pode envolver cópias.

A função sort, quando possível utiliza a função move ao invés da função swat a fim de evitar cópias desnecessárias. Quando não é possível ele realiza a cópia pelo método swat.

## O que significa a transferência de um tipo primitivo?

--- 

## Atividade 
Implemente uma classe com nome Racional, a qual será utilizada para representar números racionais de
maneira exata. Para isso, a ele deverá representar os valores em um formato de fração irredutível, ou seja,
internamente a classe deverá ter um atributo inteiro para representar o numerador e outro atributo para
representar o denominador. Caso o valor representado seja negativo, o numerador é quem deverá ser negativo.
Além disso, a classe Racional deverá implementar:

• Construtor padrão (construtor que não recebe nenhum argumento), o qual deverá produzir um objeto de
Racional que represente o valor zero.

• Construtor que receba dois números inteiros sendo, respectivamente, o numerador e o denominador.

• Construtor de cópia (construtor que recebe uma referência de lvalue constante para o mesmo tipo da classe).

• Construtor de transferência (construtor que recebe uma referência de rvalue para o mesmo tipo da classe).

• Destrutor, caso seja necessário desalocar algum recurso dinâmico alocado pela classe.
    
• Operadores de atribuição por cópia e por transferência.

• Operadores relacionais <, <=, >, >=, e ==. Tais operadores devem ser métodos constantes, pois não modificam o objeto.

• Operadores aritméticos +, –, *, /, +=, –=, *=, /=, ++ (pré-fixado e pós-fixado), –– (pré-fixado e pós-fixado), e o operador – (unário). Os operadores aritméticos que não modificam o objeto devem ser
implementados como métodos constantes.

• Métodos constantes numerador() e denominador() que retornem referências constantes para o numerador e denominador, respectivamente.

• Métodos (não constantes) numerador(int num) e denominador(int den) que alterem os valores do numerador e do denominador, respectivamente.

• Um método constante valor() que retorne um valor do tipo double referente ao valor representado pelo objeto de Racional.

Após a implementação da classe Racional, crie um std::vector<Racional> com alguns objetos de Racional e em seguida, ordene esse vector usando o método std::sort da STL. A partir dos valores presentes no vector, calcule o somatório, gerando um objeto do tipo Racional como resultado.
