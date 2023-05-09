#include "big_int.hpp"

BigInt::BigInt(){
    this->signal = true;
}

BigInt::BigInt(std::vector<int> value){
    this->value = value;
    this->signal = true;
}

//Construtor por cópia
BigInt::BigInt(const BigInt& o){
    this->value = o.value;
    this->signal = o.signal;
}

bool BigInt::getSignal(){
    return this->signal;
}

void BigInt::setSignal(bool signal){
    this->signal = signal;
}

BigInt::BigInt(std::string value){
    if(!isalnum(value[0])){
        value[0] =='-' ?  this->signal = false :  this->signal = true;
        value.erase(0,1);
    }else this->signal = true;
    while (!(value.empty())){   
        this->value.emplace(this->value.begin(), atoi(&(value.back())));
        value.pop_back();
    }
};


void BigInt::printValue(){
    std::cout<<"====== Vetor ======"<<std::endl;
    this->signal == true ? std::cout<<"+ " : std::cout<<" -";
    for (auto &&i : this->value){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
