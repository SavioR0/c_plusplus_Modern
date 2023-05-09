#include <iostream>
#include "big_int.hpp"
#include <string.h>


BigInt operator"" _bi(const char* value , long unsigned int size [[maybe_unused]] ){
    return BigInt(value);
}

int main(){



    BigInt in1 = "123456789"_bi;
    BigInt in2 = "6789"_bi;

    //std::cout<<in1.getSignal()<<std::endl;


    //BigInt int3 = in1 + in2;
    BigInt int3 = in1 - in2;

    int3.printValue();


    return 0;
}