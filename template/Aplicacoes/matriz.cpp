#include "matriz.h"

template<typename T>
Matriz<T>::Matriz(int l, int c): nl_(l), nc_(c){
    dados_ =  new T*[l];
    for (int i = 0; i < nl_; i++){
        dados_[i] = new T[c];
    }
    
}

template<typename T>
Matriz<T>::~Matriz(){
    for (int i = 0; i < nl_; i++){
        delete[] dados_[i];
    }
    delete[] dados_;
    
}

template<typename T>
Matriz<T>::operator(int l, int c){
    return dados_[l][c];    
}