#pragma once
#include <iostream>
#include <string>

#define MAX 10

template<typename T>
class No{
    public:
    T num;
    struct No *next;
};


template<typename T>
class List{
private:
    No<T> *node;
    int size;
public:
    List();
    void insert_push_front(T value);
    void insert_push_back(T value);
    void insert_index(int index, T value);

    void pop_front();
    void pop_back();
    void pop_index(int index);

    bool search(T value);
    std::string contains(T value);

    void print();


};

template<typename T>
List<T>::List(){
    node = nullptr;
    size = 0;
}

//Inserção

template<typename T>
void List<T>::insert_push_front(T value){
    No<T> *new_node = new No<T>{value, node}; 
    node = new_node;
    size++;
    //std::cout<< node->num<<std::endl;
}

template<typename T>
void List<T>::insert_push_back(T value){
    No<T> *pointer = node;
    while (pointer->next != nullptr) pointer = pointer->next;
    pointer->next = new No<T>{value, nullptr};
    size++;
    //std::cout<< node->num<<std::endl;
}

template<typename T>
void List<T>::insert_index(int index, T value){
    if(index == 0 || index < 0)
        insert_push_front(value);
    else if(index > size)
        insert_push_back(value);
    else{
        No<T> *pointer = node;
        for(int i = 0 ; i<index-1; i++) pointer = pointer->next;

        No<T> *aux = pointer->next;
        pointer->next = new No<T>{value, aux};
        size++;
    }
}

//Remoção
template<typename T>
void List<T>::pop_back(){
    try{
        if(size = 0) throw std::invalid_argument("[ERRO] A lista está vazia, não é possível remover elemento.")
        No<T> *pointer = node;
        while (pointer->next->next != nullptr) pointer = pointer->next;
        pointer->next = nullptr;
        size--;
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
void List<T>::pop_front(){
    try{
        if(size = 0) throw std::invalid_argument("[ERRO] A lista está vazia, não é possível remover elemento.")
        node = node->next;
        size--;
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}


template<typename T>
void List<T>::pop_index(int index){
    try{
        if(size <= index || index < 0){
            throw std::invalid_argument("[ERRO] Index inválido. Não é possivel remover o index " + std::to_string(index));
        }else{
            if(index == 0) pop_front();
            else if( index == size-1) pop_back();
            else{
                No<T> *pointer = node;
                for(int i = 0 ; i<index-1; i++) pointer = pointer->next;

                pointer->next = pointer->next->next;
                size--;
            }
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

// Pesquisa
template<typename T>
bool List<T>::search(T value){
    No<T> *aux = node;
    while (aux != nullptr){
        if(aux->num == value) return true;
        aux = aux->next;
    }
    return false;
}

template<typename T>
std::string List<T>::contains(T value){
    return search(value) ? "Valor encontrado!" : "Valor não está presente na lista";
}

// Impressão
template<typename T>
void List<T>::print(){
    No<T> *pointer = node;
    std::cout<<"Size : "<<size<<"\t [ ";
    while (pointer!= NULL){
        std::cout<<pointer->num<< " ";
        pointer = pointer->next;
    }
    std::cout<<"] "<<std::endl;
}




