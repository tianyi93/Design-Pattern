//
// Created by Tianyi Zhang on 4/4/21.
//

#include "19.Interpreter_pattern.h"
#include <iostream>

int main() {
    auto person1 = std::make_shared<TerminalExpression>("p1");
    auto person2 = std::make_shared<TerminalExpression>("p2");
    auto isSingle = std::make_shared<OrExpression>(person1, person2);

    std::cout<<isSingle->interpreter("p1")<<std::endl;
    std::cout<<isSingle->interpreter("p2")<<std::endl;
    std::cout<<isSingle->interpreter("p3")<<std::endl;


    auto person3 = std::make_shared<TerminalExpression>("p3");
    auto person4 = std::make_shared<TerminalExpression>("p4");
    auto isCommitted = std::make_shared<AndExpression>(person3, person4);

    std::cout<<isCommitted->interpreter("p4, p3")<<std::endl;
    std::cout<<isCommitted->interpreter("p4")<<std::endl;

    auto integer1 = std::make_shared<Integer>("10");
    auto integer2 = std::make_shared<Integer>("20");
    auto sum = std::make_shared<AddExpression>(integer1, integer2);
    std::cout<<"sum of integer 1 and integer 2 is : "<<sum->eval()<<std::endl;
    return 0;
}