//
// Created by Tianyi Zhang on 2/1/21.
//

#ifndef DESIGN_PATTERN_13_COMMAND_PATTERN_H
#define DESIGN_PATTERN_13_COMMAND_PATTERN_H
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
//controlled items
struct Light{
    Light():on_(false){}
    bool on_;
    void on(){
        on_ = true;
        std::cout<<"light is on"<<std::endl;
    }
    void off(){
        on_ = false;
        std::cout<<"light is off"<<std::endl;
    }
};

struct Fan{
    Fan():on_(false){}
    bool on_;
    void on(){
        on_ = true;
        std::cout<<"fan is on"<<std::endl;
    }
    void off(){
        on_ = false;
        std::cout<<"fan is off"<<std::endl;
    }
};

struct Command{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command(){}
};

struct LightOnCommand : public Command{
    LightOnCommand(std::shared_ptr<Light> light){
        this->light_ = light;
    }
    void execute() override{
        prev_ = light_->on_;
        light_->on();
    }
    void undo() override{
        if(prev_)
            light_->on();
        else if(!prev_)
            light_->off();
    }
private:
    std::shared_ptr<Light> light_;
    bool prev_;
};

struct LightOffCommand : public Command{
    LightOffCommand(std::shared_ptr<Light> light){
        this->light_ = light;
    }
    void execute() override{
        prev_ = light_->on_;
        light_->off();
    }
    void undo() override{
        if(prev_)
            light_->on();
        else if(!prev_)
            light_->off();
    }
private:
    std::shared_ptr<Light> light_;
    bool prev_;
};

struct FanOnCommand : public Command{
    FanOnCommand(std::shared_ptr<Fan> fan){
        this->fan_ = fan;
    }
    void execute() override{
        prev_ = fan_->on_;
        fan_->on();
    }
    void undo() override{
        if(prev_)
            fan_->on();
        else if(!prev_)
            fan_->off();
    }
private:
    std::shared_ptr<Fan> fan_;
    bool prev_;
};

struct FanOffCommand : public Command{
    FanOffCommand(std::shared_ptr<Fan> fan){
        this->fan_ = fan;
    }
    void execute() override{
        fan_->off();
    }
    void undo() override{
        if(prev_)
            fan_->on();
        else if(!prev_)
            fan_->off();
    }
private:
    std::shared_ptr<Fan> fan_;
    bool prev_;
};

struct RemoteControl{
    RemoteControl(int numSlot){
        onCommands_.reserve(numSlot);
        offCommands_.reserve(numSlot);
    }
    void setCommand(int slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand){
        onCommands_[slot] = onCommand;
        offCommands_[slot] = offCommand;
    }
    void onButtonPushed(int slot){
        onCommands_[slot]->execute();
        undoCommand_ = onCommands_[slot];
    }
    void offButtonPushed(int slot){
        offCommands_[slot]->execute();
        undoCommand_ = offCommands_[slot];
    }
    void undoCommandpushed(){
        undoCommand_->undo();
    }
private:
    std::vector<std::shared_ptr<Command>> onCommands_;
    std::vector<std::shared_ptr<Command>> offCommands_;
    std::shared_ptr<Command> undoCommand_;
};

#endif //DESIGN_PATTERN_13_COMMAND_PATTERN_H
