//
// Created by Tianyi Zhang on 4/16/21.
//

#include "20.mediator_pattern.h"
int main(){
    auto displayMediator = std::make_shared<DisplayMediator>();
    auto background = std::make_shared<BackGround>(displayMediator);
    auto font = std::make_shared<Font>(displayMediator);
    displayMediator->withColleague(background,font);

    background->setBackGroundColor(Color::Black);
    background->setBackGroundColor(Color::Black);

    font->setFontColor(Color::White);
    font->setFontColor(Color::Black);


    return 0;
}