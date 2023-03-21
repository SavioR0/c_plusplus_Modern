#include "matriz.hpp"
#include <iostream>

Matriz::Matriz(std::initializer_list<std::initializer_list<int>> list){
    for(auto linha: list){
        this->list.push_back(linha);
        //this->list.emplace_back(linha); // Já chama o construtor da estrutura que está dentro do parênteses
        for(auto valor: linha)
            std::cout<<"Valor : "<<valor<<std::endl;
    }
}
