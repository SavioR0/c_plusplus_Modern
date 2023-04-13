#ifndef URL_H__
#define URL_H__
#include <string>
#include "iostream"
#include <vector>

class Url{
private:
    std::string value;
    std::string esquema;
    std::string dominio;
    std::string porta;
    std::string caminho;

public:
    Url();
    Url(std::string value, std::string esquema , std::string dominio, std::string porta, std::string caminho);
    Url(std::string value, long unsigned int size);
    Url(const Url &url);
    
    std::string getValue();
    std::string getEsquema();
    std::string getDominio();
    std::string getPorta();
    std::string getCaminho();
};


#endif



