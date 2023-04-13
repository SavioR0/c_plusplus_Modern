#pragma once
#include <vector>
#include <iostream>

bool is_number(std::string line){
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

std::vector<std::string> searchComponents(std::string value){
    const std::vector<std::string> delins{"://", ":", "/", "\0"/* "?","#" */};
    int index = 0;
    std::vector<std::string> elements{};
    
    size_t start = 0;
    size_t end = value.find(delins[index], start)+3;
    elements.push_back(value.substr(start, (end-3) - start));

    index++;

    while (index < 4){
        start = value.find_first_not_of(delins[index], end);
        //if(start == std::string::npos) break;
        end = value.find(delins[index], start);

        index++;
        if(end == std::string::npos ) {/* elements.push_back(" "); */end = start-1;continue;}
        if(value.substr(start, (end) - start)!= "" ) elements.push_back(value.substr(start, (end) - start));
        end++;
    }

    if(end < (value.length())) elements.push_back(value.substr(start, value.length() - start));
    return elements;
}

void printVector(std::vector<std::string> elements){
    std::cout<<"=============Tokenização============="<<std::endl;
    for (auto &&i : elements){std::cout<<"\t-"<<i<<std::endl;}
}
