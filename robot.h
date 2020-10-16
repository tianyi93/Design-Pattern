//
// Created by Tianyi Zhang on 9/24/20.
//

#ifndef DESIGN_PATTERN_ROBOTPLAN_H
#define DESIGN_PATTERN_ROBOTPLAN_H

#include <string>
#include <memory>

class RobotPlan{
public:
    virtual void setRobotHead(std::string const& head) = 0;
    virtual void setRobotLeg(std::string const& leg) = 0;
    virtual void getRobotHead() = 0;
    virtual void getRobotLeg() = 0;
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
        
    }
    void getRobotLeg() override{

    }
};

class RobotBuilder{
public:
    virtual void buildRobotHead() =  0;
    virtual void buildRobotLeg() = 0;
    virtual Robot getRobot() = 0;
};

class OldRobotBuilder : public RobotBuilder{
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

class NewRobotBuilder : public RobotBuilder{
public:
    Robot robot;
    void buildRobotHead() override{
        robot.setRobotHead("newHead");
    }
    void buildRobotLeg() override{
        robot.setRobotLeg("newLeg");
    }
    Robot getRobot() override{
        return robot;
    }
};

class RobotEngineer{
public:
    std::shared_ptr<RobotBuilder> robotBuilder;
    RobotEngineer(std::shared_ptr<RobotBuilder> robotBuilder){
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
