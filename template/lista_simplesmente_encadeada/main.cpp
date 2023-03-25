#include <iostream>
#include "list.h"
#include <vector>
#include <string>


int main(){

    std::cout<<"---------------- DOUBLE ----------------"<<std::endl;
    List<double> list1{};

    list1.insert_push_front(10.2);
    list1.print(Insert_push_front);
    list1.insert_push_back(11.0);
    list1.print(Insert_push_back);
    list1.insert_push_front(9.5);
    list1.print(Insert_push_front);
    list1.insert_push_back(12.7);
    list1.print(Insert_push_back);
    list1.insert_push_front(7.2);
    list1.print(Insert_push_front);
    list1.insert_index(1, 22.1);
    list1.print(Insert_index);

    list1.pop_front();
    list1.print(Pop_front);
    list1.pop_back();
    list1.print(Pop_back);
    list1.pop_index(1);
    list1.print(Pop_index);
    list1.pop_index(-1);

    std::cout<<"\n10.2 - "<<list1.contains(10.2)<<std::endl;
    std::cout<<"12.1 - "<<list1.contains(12.1)<<std::endl;
    std::cout<< "Index 0 - " <<list1.position(0)<<"\n\n"<<std::endl;

    std::cout<<"\n\n---------------- INT ----------------"<<std::endl;

    List<int> list2= List<int>();

    list2.insert_push_front(10);
    list2.print(Insert_push_front);
    list2.insert_push_back(11);
    list2.print(Insert_push_back);
    list2.insert_push_front(9);
    list2.print(Insert_push_front);
    list2.insert_push_back(12);
    list2.print(Insert_push_back);
    list2.insert_push_front(7);
    list2.print(Insert_push_front);
    list2.insert_index(1, 22);
    list2.print(Insert_index);

    list2.pop_front();
    list2.print(Pop_front);
    list2.pop_back();
    list2.print(Pop_back);
    list2.pop_index(1);
    list2.print(Pop_index);
    list2.pop_index(-1);


    std::cout<<"\n11 - "<<list2.contains(11)<<std::endl;
    std::cout<<"12 - "<<list2.contains(12)<<std::endl;

    std::cout<< "Index 2 - " <<list2.position(2)<<"\n\n"<<std::endl;

    return 0;
}