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
            if(this != &o){}
            return *this;
        }

        BigInt operator+(const BigInt& o){
            BigInt* aux_BigInt = new BigInt();
            int sum = 0 ;

            //int next_value= 0;
            int max = std::max(o.value.size(), this->value.size()); 
            int min = std::min(o.value.size(), this->value.size());

            for(int i = 0; i<max; i++){
                std::cout<<"\ni: "<<i<<std::endl;
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

            bool order = false;
            int i= 0;

            if(this->value.size() < o.value.size()){ order = true; aux_BigInt->setSignal(false);
            }else if (this->value.size() == o.value.size()){
                while (i != static_cast<int>(this->value.size()) || i != static_cast<int>(o.value.size())){
                    if(this->value[i] > o.value[i]){
                        order = true;
                        aux_BigInt->setSignal(false);
                        break;
                    }
                    i++;
                }
            }
            std::cout<<"order :"<< order<<std::endl;

            
            BigInt aux_o = (order==false) ? o : *this;
            BigInt aux_value = (order==true) ? o : *this;

            //int next_value= 0;
            int max = std::max(aux_o.value.size(), aux_value.value.size()); 

            if(aux_o.value[aux_o.value.size()] >= aux_o.value[aux_o.value.size()]){
                for(int i = 0; i<max; i++){
                    std::cout<<" Comapração - "<<aux_value.value[aux_value.value.size()-(1+i)]<<"<="<< aux_o.value[aux_o.value.size() -(1+i)]<<std::endl;
                    if(i> aux_o.value.size()) *aux_BigInt->value.insert(aux_BigInt->value.begin(),aux_value.value[aux_value.value.size()-(1+i)]);
                    else if(aux_o.value[aux_o.value.size()-(1+i)] <= aux_value.value[aux_value.value.size()-(1+i)]){
                        std::cout<<"sub :"<<aux_value.value[aux_value.value.size()-(1+i)]<<"-"<< aux_o.value[aux_o.value.size() -(1+i)]<<std::endl;
                        sub = aux_value.value[aux_value.value.size()-(1+i)]- aux_o.value[aux_o.value.size() -(1+i)];
                        
                        std::cout<<"sub :"<<sub<<std::endl;
                        aux_BigInt->value.insert(aux_BigInt->value.begin(),sub);
                        std::cout<<"Teste4"<<std::endl;

                    }else{
                        std::cout<<"Teste9"<<std::endl;
                        if((i+1)<max){
                            int aux = 0;
                            while (aux_value.value[aux_value.value.size()-(2+i+aux)]==0) aux++;

                            aux_value.value[aux_value.value.size()-(2+i+aux)] -= 1;
                            std::cout<<"Dezena :"<<aux_value.value[aux_value.value.size()-(2+i+aux)]<<std::endl;

                            std::cout<<"Aux :"<<aux<<std::endl;

                            if(aux == 0) {aux_value.value[aux_value.value.size()-(1+i)] += 10;}
                            std::cout<<"Teste2"<<std::endl;

                            while (aux!=0){
                                aux_value.value[aux_value.value.size()-(1+i+aux)] += 9 ;aux--;
                                if(aux == 0) aux_value.value[aux_value.value.size()-(1+i)] += 10;
                            }
                            std::cout<<"Teste3"<<std::endl;

                            //std::cout<<aux_value.value[aux_value.value.size()-(1+i)]<<std::endl;
                            sub = aux_value.value[aux_value.value.size()-(1+i)]- aux_o.value[aux_o.value.size() -(1+i)];
                            //std::cout<<"sub :"<<sub<<std::endl;
                            aux_BigInt->value.insert(aux_BigInt->value.begin(),sub);
                        }
                    }
                }
            }
            if (!(aux_BigInt->value.empty())) while(aux_BigInt->value[0] == 0) aux_BigInt->value.erase(aux_BigInt->value.begin());
            
            return *aux_BigInt; 
        }

        //BigInt operator*(const BigInt& o){}

        //BigInt operator/(const BigInt& o){}

        void printValue();

};