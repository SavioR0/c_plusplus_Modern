#pragma once
#include <iostream>
#include "vector"
#include <string>
#include <algorithm>
#include <cctype>

class BigInt{
    private:
        std::vector<int> value;
        bool signal;
    public:
        BigInt(std::string value);
        BigInt(std::vector<int> value);
        BigInt(const BigInt& o);
        BigInt();

        bool getSignal();
        void setSignal(bool signal);

        BigInt operator=(const BigInt& o){
            if(this != &o){
                this->value = o.value;
                this->signal = o.signal;
            }
            return *this;
        }

        bool operator<(const BigInt& o);
        bool operator>(const BigInt& o);
        bool operator!=(const BigInt& o);
        bool operator==(const BigInt& o);

        

        BigInt operator+(const BigInt& o){
            if(this->signal != o.signal) return *this - o;
            BigInt* aux_BigInt = new BigInt();
            int sum = 0 ;

            //int next_value= 0;
            int max = std::max(o.value.size(), this->value.size()); 
            int min = std::min(o.value.size(), this->value.size());

            for(int i = 0; i<max; i++){
                sum = 0;
                (i< min)?
                    sum = o.value[o.value.size() -(1+i)] + this->value[this->value.size()-(1+i)] :
                     static_cast<int>(o.value.size() )> min ? sum = o.value[o.value.size() -(1+i)] : sum= this->value[this->value.size()-(1+i)];
                if(sum >= 10){ 
                    if(i < static_cast<int>(aux_BigInt->value.size())){
                        (*aux_BigInt).value[0] = (1 + sum)%10;
                        aux_BigInt->value.insert(aux_BigInt->value.begin(),1);
                    }else  aux_BigInt->value.insert(aux_BigInt->value.begin(),{1, sum%10});
                }else {
                    if( i < static_cast<int>(aux_BigInt->value.size())) {
                        (*aux_BigInt).value[0] = (1 + sum)%10;
                        if((1 + sum)%10 == 0 ) aux_BigInt->value.insert(aux_BigInt->value.begin(), 1);
                    }else aux_BigInt->value.insert(aux_BigInt->value.begin(), sum%10);
                }
            }
            return *aux_BigInt;
        }

        BigInt operator-(const BigInt& o){
            BigInt* aux_BigInt = new BigInt();
            int sub = 0 ;
            
            if(*this < o) aux_BigInt->setSignal(false);
            
            BigInt aux_min = (*this < o) ? *this : o;
            BigInt aux_max = (*this < o) ? o:*this;

            if(aux_min == aux_max) return BigInt("0");

            if(aux_min.value[aux_min.value.size()] >= aux_min.value[aux_min.value.size()]){
                for(int i = 0; i< static_cast<int>(aux_max.value.size()); i++){
                    if(i> static_cast<int>(aux_min.value.size())) *aux_BigInt->value.insert(aux_BigInt->value.begin(),aux_max.value[aux_max.value.size()-(1+i)]);
                    else if(aux_min.value[aux_min.value.size()-(1+i)] <= aux_max.value[aux_max.value.size()-(1+i)]){
                        sub = aux_max.value[aux_max.value.size()-(1+i)]- aux_min.value[aux_min.value.size() -(1+i)];
                        aux_BigInt->value.insert(aux_BigInt->value.begin(),sub);
                    }else if((i+1)< static_cast<int>(aux_max.value.size())){
                        int aux = 0;
                        while (aux_max.value[aux_max.value.size()-(2+i+aux)]==0) aux++;
                        aux_max.value[aux_max.value.size()-(2+i+aux)] -= 1;
                        if(aux == 0) {aux_max.value[aux_max.value.size()-(1+i)] += 10;}
                        while (aux!=0){
                            aux_max.value[aux_max.value.size()-(1+i+aux)] += 9 ;aux--;
                            if(aux == 0) aux_max.value[aux_max.value.size()-(1+i)] += 10;
                        }
                        sub = aux_max.value[aux_max.value.size()-(1+i)]- aux_min.value[aux_min.value.size() -(1+i)];
                        aux_BigInt->value.insert(aux_BigInt->value.begin(),sub);
                    }
                }
            }
            if (!(aux_BigInt->value.empty())) while(aux_BigInt->value[0] == 0) aux_BigInt->value.erase(aux_BigInt->value.begin());
            return *aux_BigInt; 
        }

        BigInt operator*(const BigInt& o){
            BigInt aux_max = (*this < o) ? o:*this;
            BigInt aux_min = (*this < o) ? *this : o;
            if(aux_max == BigInt("0") || aux_min ==  BigInt("0")) return BigInt("0");
            BigInt* aux_result = new BigInt();
            if(aux_min.value[0]>0)*aux_result = *aux_result + aux_max;
            while(aux_min != BigInt("1")){
                *aux_result = *aux_result + aux_max;
                aux_min = aux_min - BigInt("1");
            }
            return *aux_result;
        }

        BigInt operator/(const BigInt& o){
            BigInt* aux_result = new BigInt();
            BigInt aux_min =  o;
            if(*this < aux_min) return BigInt("0");
            BigInt aux_max = *this;
            BigInt aux_sub = aux_max;
            *aux_result->value.insert(aux_result->value.begin(), 1);
            while(aux_sub > o){
                aux_sub = aux_sub - o;
                *aux_result = *aux_result + BigInt("1");
            }
            return *aux_result;
        }

        void printValue();

};