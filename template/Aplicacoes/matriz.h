#pragma once
#include <iostream>
//classe template
template<typename T>
class Matriz{
    public:
        Matriz(int l, int c);
        ~Matriz();
        T& operator()(int l, int c);
    private:
        T** dados_;
        int nl_, nc_;
};