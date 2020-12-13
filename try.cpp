#include <iostream>
#include <memory>
//
// Created by Tianyi Zhang on 10/28/20.
//
struct ItemType{
    ItemType(int id){}
    ItemType(ItemType const& i) = delete;
    ItemType(ItemType&& i) = default;
    ~ItemType(){std::cout<<"destructed"<<std::endl;}
    std::string Id = "fdsafdsfjjklkjlkjljlk";
};
template <typename T>
void foo(T&& a, std::string b = ""){
    std::cout<<a.Id<<std::endl;
}
void foo1(ItemType && item){
    ItemType b = std::move(item);
}
int main(){
    ItemType item0(0);
    //std::cout<<item0.Id<<std::endl;
    auto uniquePtr = std::make_unique<ItemType>(std::move(item0));
    //foo(std::move(item0));
    //foo1(std::move(item0));
    std::cout<<uniquePtr->Id<<"aaa"<<std::endl;
    std::cout<<item0.Id<<std::endl;
    return 0;
}
