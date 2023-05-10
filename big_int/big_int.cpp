#include "big_int.hpp"

BigInt::BigInt(){
    this->signal = true;
}

BigInt::BigInt(std::vector<int> value){
    this->value = value;
    this->signal = true;
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
}

//Construtor por cópia
BigInt::BigInt(const BigInt& o){
    this->value = o.value;
    this->signal = o.signal;
}
// Operators
bool BigInt::operator<(const BigInt& o){
    int i= 0;
    if(this->value.size() < o.value.size())return true; 
    else if (this->value.size() == o.value.size()){
        while (i != static_cast<int>(this->value.size())){
            if(this->value[i] < o.value[i])return true;
            else if(this->value[i] > o.value[i])return false;
            i++;
        }
    }
    return false;
}


bool BigInt::operator>(const BigInt& o){
    int i= 0;
    if(this->value.size() > o.value.size())return true; 
    else if (this->value.size() == o.value.size()){
        while (i != static_cast<int>(this->value.size())){
            if(this->value[i] > o.value[i])return true;
            else if(this->value[i] < o.value[i])return false;
            i++;
        }
    }
    return false;
}
bool BigInt::operator!=(const BigInt& o){
    if(this->value != o.value) return true;
    return false;
}
bool BigInt::operator==(const BigInt& o){
    if(this->value == o.value) return true;
    return false;
}


 //GET SET
bool BigInt::getSignal(){return this->signal;}
void BigInt::setSignal(bool signal){this->signal = signal;}



// Print
void BigInt::printValue(){
    this->signal == true ? std::cout<<"+ " : std::cout<<" -";
    for (auto &&i : this->value){
        std::cout<<i<<"";
    }
    std::cout<<std::endl;
}
