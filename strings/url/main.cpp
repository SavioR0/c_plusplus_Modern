#include <iostream>
#include "url.hpp"


Url operator"" _url(const char* value , long unsigned int size ){
    return Url(value, size);
}

int main(){
    Url u3 = "https://cefetplusplus.github.io/"_url;
    Url u2 = "https://www.cefetmg.br/"_url;
    Url u1 = "https://www.cefetmg.br:443/"_url;
    Url u0 = "https://pt.wikipedia.org/wiki/URL"_url;
    Url u = "https://pt.wikipedia.org:658/wiki/URL#citenote4"_url;



    std::cout<<"\n\n============="<<u3.getValue()<<"================"<<std::endl;

    std::cout << " Esquema U3 : "<<u3.getEsquema()<<std::endl;
    std::cout << " Dominio U3 : "<<u3.getDominio()<<std::endl;
    std::cout << " Caminho U3 : "<<u3.getCaminho()<<std::endl;
    std::cout << " Porta U3 : "<<u3.getPorta()<<std::endl;
    std::cout<<"============================================================="<<std::endl;

    std::cout<<"\n\n=============="<<u2.getValue()<<"==============="<<std::endl;

    std::cout << " Esquema U2 : "<<u2.getEsquema()<<std::endl;
    std::cout << " Dominio U2 : "<<u2.getDominio()<<std::endl;
    std::cout << " Caminho U2 : "<<u2.getCaminho()<<std::endl;
    std::cout << " Porta U2 : "<<u2.getPorta()<<std::endl;
    std::cout<<"===================================================="<<std::endl;

    std::cout<<"\n\n============="<<u1.getValue()<<"================"<<std::endl;

    std::cout << " Esquema U1 : "<<u1.getEsquema()<<std::endl;
    std::cout << " Dominio U1 : "<<u1.getDominio()<<std::endl;
    std::cout << " Caminho U1 : "<<u1.getCaminho()<<std::endl;
    std::cout << " Porta U1 : "<<u1.getPorta()<<std::endl;
    std::cout<<"========================================================"<<std::endl;

    std::cout<<"\n\n=============="<<u0.getValue()<<"==============="<<std::endl;

    std::cout << " Esquema U0 : "<<u0.getEsquema()<<std::endl;
    std::cout << " Dominio U0 : "<<u0.getDominio()<<std::endl;
    std::cout << " Caminho U0 : "<<u0.getCaminho()<<std::endl;
    std::cout << " Porta U0 : "<<u0.getPorta()<<std::endl;
    std::cout<<"=============================================================="<<std::endl;

    std::cout<<"\n\n============="<<u.getValue()<<"================"<<std::endl;

    std::cout << " Esquema U : "<<u.getEsquema()<<std::endl;
    std::cout << " Dominio U : "<<u.getDominio()<<std::endl;
    std::cout << " Caminho U : "<<u.getCaminho()<<std::endl;
    std::cout << " Porta U : "<<u.getPorta()<<std::endl;
    std::cout<<"============================================================================"<<std::endl;

    return 0;
}