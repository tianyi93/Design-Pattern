//
// Created by Tianyi Zhang on 9/24/20.
//

#ifndef DESIGN_PATTERN_ROBOTPLAN_H
#define DESIGN_PATTERN_ROBOTPLAN_H

#include <iostream>
#include <string>
#include <memory>

class RobotPlan{
public:
    virtual void setRobotHead(std::string const& head) = 0;
    virtual void setRobotLeg(std::string const& leg) = 0;
    virtual void getRobotHead() = 0;
    virtual void getRobotLeg() = 0;
    virtual void getInfo() = 0;
};

class Robot : public RobotPlan {
public:
    std::string head;
    std::string leg;
    void setRobotHead(std::string const& head) override{
        this->head = head;
    }
    void setRobotLeg(std::string const& leg) override{
        this->leg = leg;
    }
    void getRobotHead() override{
        std::cout<<head<<std::endl;
    }
    void getRobotLeg() override{
        std::cout<<leg<<std::endl;
    }
    void getInfo() override{
        getRobotHead();
        getRobotLeg();
    }
};

class RobotSpec{
public:
    virtual void buildRobotHead() =  0;
    virtual void buildRobotLeg() = 0;
    virtual Robot getRobot() = 0;
};

class OldRobotSpec : public RobotSpec{
public:
    Robot robot;
    void buildRobotHead() {
        robot.setRobotHead("oldHead");
    }
    void buildRobotLeg() {
        robot.setRobotLeg("oldLeg");
    }
    Robot getRobot() {
        return robot;
    }
};

class NewRobotSpec : public RobotSpec{
public:
    Robot robot;
    void buildRobotHead() override{
        robot.setRobotHead("newHead");
    }
    void buildRobotLeg() override{
        robot.setRobotLeg("newLeg");
    }
    Robot getRobot() {
        return robot;
    }
};

class RobotEngineer{
public:
    std::shared_ptr<RobotSpec> robotBuilder;
    RobotEngineer(std::shared_ptr<RobotSpec> robotBuilder){
        this->robotBuilder = robotBuilder;
    }
    void makeRobot(){
        this->robotBuilder->buildRobotHead();
        this->robotBuilder->buildRobotLeg();
    }
    Robot getRobot(){
         return robotBuilder->getRobot();
    }
};
#endif //DESIGN_PATTERN_ROBOTPLAN_H
