//
// Created by Tianyi Zhang on 1/2/21.
//

#include "strategy_pattern.h"
int main(){
    auto quack = std::make_shared<Quack>();
    auto muteQuack = std::make_shared<MuteQuack>();

    auto flyWithWings = std::make_shared<FlyWithWings>();
    auto flyNoWay = std::make_shared<FlyNoWay>();

    auto realDuck = std::make_shared<RealDuck>();
    realDuck->setFlyBehavior(flyWithWings);
    realDuck->setQuackBehavior(quack);
    realDuck->display();
    realDuck->performQuack();
    realDuck->performFly();

    std::cout<<std::endl;

    auto fakeDuck = std::make_shared<FakeDuck>();
    fakeDuck->setFlyBehavior(flyNoWay);
    fakeDuck->setQuackBehavior(muteQuack);
    fakeDuck->display();
    fakeDuck->performQuack();
    fakeDuck->performFly();
    return 0;
}