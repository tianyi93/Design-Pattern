//
// Created by Tianyi Zhang on 10/18/20.
//
#include "abstract_factory.h"
#include <iostream>
int main(){
    WindowsUIFactory windowsUiFactory;
    auto windowsButton = windowsUiFactory.buildButton();
    auto windowsWindow = windowsUiFactory.buildWindow();
    std::cout<<windowsButton->getOSName()<<windowsButton->getType()<<windowsWindow->getOSName()<<windowsWindow->getWidth()<<std::endl;

    MacUIFactory macUiFactory;
    auto macButton = macUiFactory.buildButton();
    auto macWindow = macUiFactory.buildWindow();
    std::cout<<macButton->getOSName()<<macButton->getType()<<macWindow->getOSName()<<macWindow->getWidth()<<std::endl;
    return 0;
}
