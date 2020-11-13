//
// Created by Tianyi Zhang on 11/9/20.
//

#include "singleton_pattern.h"
#include <thread>

void thread1(){
    auto singleton = Singleton::getInstance("singleton instance");
    singleton->print();
}
void thread2(){
    auto singleton2 = Singleton::getInstance("singleton instance2");
    singleton2->print();
}
int main(){
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
