#include <iostream>
#include <string>

int main(){
    std::string teste1 = "Sávio"; // Utf8
    std::cout<<teste1.size()<<std::endl;
    std::u16string teste2 = u"Sávio"; // Utf16
    std::cout<<teste2.size()<<std::endl;
    return 0;
}