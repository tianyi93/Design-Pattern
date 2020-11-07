#include <iostream>

//
// Created by Tianyi Zhang on 10/28/20.
//
class A{
public:
    bool a{false};
};
int main(){
    A a;
    int b=2;
    b*= 5+3;
    std::cout<<b;
    std::cout<<a.a;
}
