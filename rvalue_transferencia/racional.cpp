#include "racional.hpp"

Racional::Racional():numerador(0), denominador(1){}
Racional::Racional(const Racional& racional):numerador(racional.numerador), denominador(racional.denominador){}
Racional::Racional(Racional&& racional){
    this->numerador = racional.numerador;
    this->denominador = racional.denominador;
}
Racional::Racional(int numerador, int denominador) : numerador(numerador), denominador(denominador){
    if(denominador == 0){
        std::cout<<" ERRO: Racional inválido"<<std::endl; 
    }
    if(denominador < 0){
        this->numerador *= -1;
        this->denominador *= -1;
    }
}
/* Racional::Racional(int&& numerador, int&& denominador){
    this->numerador = numerador;
    this->denominador = denominador;
} */


Racional::~Racional(){};

Racional irredutivel(Racional& racional){
    //std::cout <<"Result : "<<racional.getNumerador()<<"/"<<racional.getDenominador()<<std::endl;
    for(int i = std::min(racional.getDenominador(), racional.getNumerador()); i>1; i--){
        if(racional.getNumerador()%i == 0 && racional.getDenominador()%i == 0){
            racional.setDenominador(racional.getDenominador()/i);
            racional.setNumerador(racional.getNumerador()/i);
            i = std::min(racional.getDenominador(), racional.getNumerador());      
        }
    }
    //std::cout <<"Result : "<<racional.getNumerador()<<"/"<<racional.getDenominador()<<std::endl;

    return racional;
}

 //Operadores
Racional& Racional::operator+(Racional& racional){
    Racional* r = new Racional();
    if(this->denominador == racional.denominador) {
        r->numerador = this->numerador + racional.numerador;
        r->denominador = this->numerador;
    }else{
        r->denominador = this->denominador * racional.denominador;
        r->numerador = (r->denominador / this->denominador ) + (r->denominador / racional.denominador );
    }
    irredutivel(*r);
    return *r;
};
Racional& Racional::operator-(Racional& racional){
    Racional* r = new Racional();
    if(this->denominador == racional.denominador) {
        r->numerador = this->numerador - racional.numerador;
        r->denominador = this->numerador;
    }else{
        r->denominador = this->denominador * racional.denominador;
        r->numerador = (r->denominador / this->denominador ) - (r->denominador / racional.denominador );
    }
    irredutivel(*r);
    return *r;
};
Racional& Racional::operator*(Racional& racional){
    Racional* r = new Racional();
    r->numerador = racional.numerador * this->numerador;
    r->denominador = racional.denominador * this->denominador;
    irredutivel(*r);
    return *r;
};
Racional& Racional::operator/(Racional& racional){
    Racional* r = new Racional();
    r->numerador = this->numerador * racional.denominador;
    r->denominador = this->denominador * racional.numerador;
    irredutivel(*r);
    return *r;
};

Racional& Racional::operator+=(Racional racional){
    *this = *this + racional;
    return *this;
};
Racional& Racional::operator-=(Racional racional){
    *this = *this - racional;
    return *this;
};
Racional& Racional::operator*=(Racional racional){
    *this = *this * racional;
    return *this;
};
Racional& Racional::operator/=(Racional racional){
    *this = *this / racional;
    return *this;
};
// Soma
Racional& Racional::operator++(){
    this->numerador += this->denominador;
    irredutivel(*this);
    return *this;
};
Racional Racional::operator++(int){
    return (*this)++;
};

// Sub
Racional& Racional::operator--(){
    this->numerador -= this->denominador;
    irredutivel(*this);
    return *this;
};
Racional Racional::operator--(int){
    return (*this)--;
};


bool Racional::operator==(const Racional& o){
    return ((this->numerador /this->denominador)== (o.numerador /o.denominador));
}
bool Racional::operator<(const Racional& o){
    return (static_cast<float>(this->numerador)/this->denominador)<(static_cast<float>(o.numerador)/o.denominador);
}
bool Racional::operator>(const Racional& o){
    return (static_cast<float>(this->numerador)/this->denominador)>(static_cast<float>(o.numerador)/o.denominador);
}
bool Racional::operator<=(const Racional& o){
    return ((this->numerador /this->denominador)<= (o.numerador /o.denominador));
}

 bool Racional::operator>=(const Racional& o){
    return ((this->numerador /this->denominador)>= (o.numerador /o.denominador));
}

const int& Racional::getNumerador(){return this->numerador;}
const int& Racional::getDenominador(){return this->denominador;}
void Racional::setNumerador(int num){this-> numerador = num;}
void Racional::setDenominador(int num){this->denominador = num;}

double Racional::valor(){return this->numerador / this->denominador;}