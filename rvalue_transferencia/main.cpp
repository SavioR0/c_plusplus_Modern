#include <iostream>
#include "racional.hpp"
#include <vector>
#include <algorithm>

int main(){


    /* Racional racional1{};

    int den = 2;
    int num = 1;

    Racional racional2{num, den};
    Racional racional = Racional(racional);

    racional2.setNumerador(2);
    racional2.setDenominador(3);

    std::cout<<"Numerador: "<<racional2.getNumerador()<<std::endl;
    std::cout<<"Denominador : "<<racional2.getDenominador()<<std::endl;

    std::cout<<"Valor : "<<racional2.valor()<<std::endl; */

    /* --------------------------------------------------- */

    //Racional racional1 = {1,2};
    //Racional racional2 = {1,2};

    //Racional racional3 = racional1 + racional2;
    //Racional racional3 = racional1 - racional2;
    //Racional racional3 = racional1 * racional2;
    //Racional racional3 = racional1 / racional2;

    //racional2 += racional1;
    //racional2 -= racional1;
    //racional2 *= racional1;
    //racional2 /= racional1;

    //std::cout<<(racional1<racional2)<<std::endl;
    //std::cout<<(racional1>racional2)<<std::endl;
    //std::cout<<(racional1==racional2)<<std::endl;
    //std::cout<<(racional1>=racional2)<<std::endl;
    //std::cout<<(racional1<=racional2)<<std::endl;

    //racional1++;
    //std::cout <<"Result : "<<racional1.getNumerador()<<"/"<<racional1.getDenominador()<<std::endl;
    //Racional racional3 = ++racional1;
    //std::cout <<"Result : "<<racional3.getNumerador()<<"/"<<racional3.getDenominador()<<std::endl;
    //Racional racional3 = --racional1;
    //std::cout <<"Result : "<<racional3.getNumerador()<<"/"<<racional3.getDenominador()<<std::endl;

    Racional racional1 = {1,2};
    Racional racional2 = {1,8};

    std::vector<Racional> vec{Racional{1,2},Racional{1,-8}, Racional{1,4}, Racional{1,16}, Racional{1,-64}, Racional{1,256}, Racional{1,128}};
    std::sort(vec.begin(), vec.end(), [](Racional a , Racional b){return a > b;});

    for (auto elemento : vec) {
        std::cout <<elemento.getNumerador()<<"/"<< elemento.getDenominador() << " ";
    }
    std::cout << std::endl;
    return 0;
}
