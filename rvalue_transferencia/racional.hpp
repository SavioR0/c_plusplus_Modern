#pragma once
#include <iostream>


class Racional{
private:
    int numerador;
    int denominador;
public:
    Racional();
    Racional(const Racional& racional);
    Racional(Racional&& racional);
    Racional(int num, int den);
  /*   Racional(int&& num, int&& den); */
    ~Racional();

    Racional& operator=(Racional& racional){
        this->setNumerador(racional.numerador);
        this->setDenominador(racional.denominador);
        return *this;
    }
    Racional& operator=(Racional&& racional){
        this->setNumerador(racional.numerador);
        this->setDenominador(racional.denominador);
        return *this;
    }

    Racional& operator+(Racional& racional);
    Racional& operator-(Racional& racional);
    Racional& operator*(Racional& racional);
    Racional& operator/(Racional& racional);

    Racional& operator+=(Racional racional);
    Racional& operator-=(Racional racional);
    Racional& operator*=(Racional racional);
    Racional& operator/=(Racional racional);
    Racional& operator++();
    Racional operator++(int);
    Racional& operator--();
    Racional operator--(int);
    
    bool operator==(const Racional& o);
    bool operator<(const Racional& o);
    bool operator<=(const Racional& o);
    bool operator>(const Racional& o);
    bool operator>=(const Racional& o);

    const int& getNumerador();
    const int& getDenominador();
    void setNumerador(int num);
    void setDenominador(int num);

    double valor();

};



