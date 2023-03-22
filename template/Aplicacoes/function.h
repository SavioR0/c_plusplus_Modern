#pragma once
#include <iostream>

template <typename T>
void troca(T& x, T& y){
    T aux = x;
    x=y;
    y=aux;
}

template <>
void troca(char*& x, char*& y){
    //int tam = std::strlen(x);
    int tam = 10;
    for(int i = 0; i<tam ; i++){
        troca(x[i], y[i]);
    }
}


template<class X, class Y>
X soma(X a, Y b){
    X res = a+b;
    return res;
}

template<class T, class Comp>
void ordenar(T* dados, Comp comp){

}


