#pragma once
#include <vector>

class Matriz{
private:
    std::vector<std::vector<int>> list;
public:
    Matriz(std::initializer_list< std::initializer_list<int>> list);
};
