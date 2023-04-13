#include "url.hpp"
#include "utils.hpp"

Url::Url(){};
//Construtor que recebe todos os parâmetro separadamente
Url::Url(std::string value, std::string esquema , std::string dominio, std::string porta, std::string caminho){
    this->value = value;
    this->esquema = esquema;
    this->dominio = dominio;
    this->porta = porta;
    this->caminho = caminho;
};
//Contrutor cópia
Url::Url(const Url &url){
    this->value = url.value;
    this->esquema = url.esquema;
    this->dominio = url.dominio;
    this->porta = url.porta;
    this->caminho = url.caminho;
}


Url::Url(std::string value,  long unsigned int size){
    std::vector<std::string> elements = searchComponents(value);
    //printVector(elements);
    this->value = value;
    this->esquema = elements[0];
    this->dominio = elements[1];

    if(elements.size()==3){
        if(is_number(elements[2])) this->porta = elements[2];
        else this->caminho = elements[2];
    }else if(elements.size()==4){this->porta = elements[2]; this->caminho= elements[3];}
    size--;
};

std::string Url::getValue(){ return this->value;}
std::string Url::getEsquema(){ return this->esquema;}
std::string Url::getDominio(){ return this->dominio;}
std::string Url::getPorta(){ return this->porta;}
std::string Url::getCaminho(){ return this->caminho;}




