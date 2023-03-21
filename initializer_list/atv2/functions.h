#pragma once

int min(std::initializer_list<int> l){
    int min = INT_MAX;
    for(auto x : l){
        min = (x<min) ? x : min;
    }
    return min;
}
int max(std::initializer_list<int> l){
    int max = INT_MIN;
    for(auto x : l){
        max = (x>max) ? x : max;
    }
    return max;
}
int sum(std::initializer_list<int> l){
    int sum = 0;
    for(auto x : l){
        sum += x;
    }
    return sum;
} 