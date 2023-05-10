#include <iostream>
#include "big_int.hpp"
#include <string.h>


BigInt operator"" _bi(const char* value , long unsigned int size [[maybe_unused]] ){
    return BigInt(value);
}

int main(){

    BigInt in1 = "100"_bi;
    BigInt in2 = "25"_bi;

    std::cout<<"-------- Soma ---------"<<std::endl;
    BigInt int3 = in1 + in2;
    int3.printValue();
    std::cout<<"------ Subtração ------"<<std::endl;
    int3 = in1 - in2;
    int3.printValue();
    std::cout<<"---- Multiplicação ----"<<std::endl;
    int3 = in1 * in2;
    int3.printValue();
    std::cout<<"------ Divisão ------"<<std::endl;
    int3 = in1 / in2;
    int3.printValue();


    return 0;
}