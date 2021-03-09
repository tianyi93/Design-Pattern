//
// Created by Tianyi Zhang on 3/7/21.
//

#ifndef DESIGN_PATTERN_STATE_PATTERN_H
#define DESIGN_PATTERN_STATE_PATTERN_H

#include <iostream>
#include <memory>

// THE STATE PATTERN allows an object to alter its behavior when its internal state changes.
// The object will appear to change its class

//without this pattern the following class GamballMachine will be full of if statement, not closed for modification when adding more state
//so we localizing the behavior in class State
struct State;
struct GamballMachineFactory;

struct GamballMachine{

    std::shared_ptr<State> hasQuarterState;
    std::shared_ptr<State> noQuarterState;
    std::shared_ptr<State> soldOutState;
    std::shared_ptr<State> soldState;

    std::shared_ptr<State> CurState;
    int BallCount;

    void insertQuarter();
    void ejectsQuarter();
    void turnCrank();
    void dispenseGumball();

    friend class GamballMachineFactory;

private:
    GamballMachine() = default;
};

struct State{
    std::shared_ptr<GamballMachine> gamballMachine_;
    virtual void insertQuarter(){
        invalidBehavior();
    }
    virtual void ejectsQuarter(){
        invalidBehavior();
    }
    virtual void turnCrank(){
        invalidBehavior();
    }
    virtual void dispenseGumball(){
        invalidBehavior();
    }
private:
    void invalidBehavior(){
        std::cout<<"invalid behavior"<<std::endl;
    }
};

void GamballMachine::insertQuarter(){
    CurState->insertQuarter();
}
void GamballMachine::ejectsQuarter(){
    CurState->ejectsQuarter();
}
void GamballMachine::turnCrank(){
    CurState->turnCrank();
}
void GamballMachine::dispenseGumball(){
    CurState->dispenseGumball();
}

struct HasQuarterState : public State{
    HasQuarterState(std::shared_ptr<GamballMachine> gamballMachine){
        gamballMachine_ = gamballMachine;
    }
    void ejectsQuarter() override{
        gamballMachine_->CurState = gamballMachine_->noQuarterState;
        std::cout<<"ejectstQuarter"<<std::endl;
    }
    void turnCrank() override{
        gamballMachine_->CurState = gamballMachine_->soldState;
        std::cout<<"turnCrank"<<std::endl;
    }
};

struct NoQuarterState : public State{
    NoQuarterState(std::shared_ptr<GamballMachine> gamballMachine){
        gamballMachine_ = gamballMachine;
    }
    void insertQuarter() override{
        gamballMachine_->CurState = gamballMachine_->hasQuarterState;
        std::cout<<"insertQuarter"<<std::endl;
    }
};

struct SoldState : public State{
    SoldState(std::shared_ptr<GamballMachine> gamballMachine){
        gamballMachine_ = gamballMachine;
    }
    void dispenseGumball() override{
        if(--gamballMachine_->BallCount == 0)
            gamballMachine_->CurState = gamballMachine_->soldOutState;
        else
            gamballMachine_->CurState = gamballMachine_->noQuarterState;
        std::cout<<"dispenseGumball"<<std::endl;
    }
};

struct SoldOutState : public State{
    SoldOutState(std::shared_ptr<GamballMachine> gamballMachine){
        gamballMachine_ = gamballMachine;
    }
};

struct GamballMachineFactory{
    static std::shared_ptr<GamballMachine> createGamballMAchine(int numBalls){
        //cant use make shared here as GamballMachine constructor is private.
        auto sp = std::shared_ptr<GamballMachine>(new GamballMachine());
        sp->hasQuarterState = std::make_shared<HasQuarterState>(sp);
        sp->noQuarterState = std::make_shared<NoQuarterState>(sp);
        sp->soldState = std::make_shared<SoldState>(sp);
        sp->soldOutState = std::make_shared<SoldOutState>(sp);
        sp->CurState = sp->noQuarterState;
        sp->BallCount = numBalls;
        return sp;
    }
};

#endif //DESIGN_PATTERN_STATE_PATTERN_H
