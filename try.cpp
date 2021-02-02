#include <iostream>
#include <memory>
#include <functional>
//
// Created by Tianyi Zhang on 10/28/20.
//
template<typename ...T>
using FunctionCall1 = void(T const&...);

typedef void(*FunctionCall)(int const&);
void foo(int const& a){
    std::cout<<&a<<std::endl;
}

void foo2(std::function<void(int const&)> func){
    std::cout<<&func<<std::endl;
}

void foo3(FunctionCall1<int> const& func){
    std::cout<<func<<std::endl;
}
int main(){
    std::cout<<foo<<std::endl;
    foo2(&foo);

    foo3(foo);

    std::string a = "abcd";
    auto f = [&](){
        std::cout<<a<<std::endl;
    };
    a= "fdasf";
    f();

    return 0;
}
