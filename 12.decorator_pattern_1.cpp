//
// Created by Tianyi Zhang on 1/31/21.
//

#include "12.decorator_pattern_1.h"
int main(){
/**
   * This way the client code can support both simple components...
   */
    auto simple = std::make_shared<ConcreteComponent>();
    std::cout << "Client: I've got a simple component:\n";
    std::cout<<simple->Operation();
    std::cout << "\n\n";
    /**
     * ...as well as decorated ones.
     *
     * Note how decorators can wrap not only simple components but the other
     * decorators as well.
     */
    auto decorator1 = std::make_shared<ConcreteDecoratorA>(simple);
    auto decorator2 = std::make_shared<ConcreteDecoratorB>(decorator1);
    std::cout << "Client: Now I've got a decorated component:\n";
    std::cout<<decorator2->Operation();
    std::cout << "\n\n";

}