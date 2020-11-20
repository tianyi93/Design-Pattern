//
// Created by Tianyi Zhang on 11/9/20.
//
//referencer : https://refactoring.guru/design-patterns/singleton/cpp/example#example-1

#ifndef DESIGN_PATTERN_SINGLETON_PATTERN_H
#define DESIGN_PATTERN_SINGLETON_PATTERN_H
#include <string>
#include <memory>
#include <iostream>

class Singleton{
private:
    std::string value_;
    static std::mutex mutex_;
    static std::shared_ptr<Singleton> singleton_;
    Singleton(std::string value):value_(value){}

public:
    static std::shared_ptr<Singleton> getInstance(std::string value);
    void print(){
        std::cout<<value_<<std::endl;
    }
};

/**
 * Static methods should be defined outside the class.
 */
std::shared_ptr<Singleton> Singleton::singleton_= nullptr;
std::shared_ptr<Singleton> Singleton::getInstance(std::string value){
    if(singleton_ == nullptr) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (singleton_ == nullptr)
            singleton_ = std::shared_ptr<Singleton>(new Singleton(value));
        return singleton_;
    }
    return singleton_;
}
std::mutex Singleton::mutex_;

#endif //DESIGN_PATTERN_SINGLETON_PATTERN_H
