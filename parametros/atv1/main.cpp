#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char** argv){
    std::ofstream outfile;
    outfile.open("original.txt", std::ios::out);

    if(!outfile) std::cout<<"Erro ao abrir o arquivo"<<std::endl;

    for(int i =1; i<argc; i++){
        outfile<< argv[i] << " ";
    }

    outfile.close();  

    return 0;
}