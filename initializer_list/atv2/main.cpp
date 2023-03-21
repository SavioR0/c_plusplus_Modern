#include <iostream>
#include <vector>
#include <climits>
#include <initializer_list>
#include "functions.h"


int main(){
    std::initializer_list<int> elements{1,2,3,4};

    int mini = min(elements);
    int maxi = max(elements);
    int soma = sum(elements);

    std::cout<<"Mim : "<<mini<<std::endl;
    std::cout<<"Max : "<<maxi<<std::endl;
    std::cout<<"Sum : "<<soma<<std::endl;

    return 0;
}