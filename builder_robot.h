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

class OldRobotSpec{
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

class NewRobotSpec{
public:
    Robot robot;
    void buildRobotHead(){
        robot.setRobotHead("newHead");
    }
    void buildRobotLeg(){
        robot.setRobotLeg("newLeg");
    }
    Robot getRobot() {
        return robot;
    }
};

class RobotSpec{
public:
    template<typename T>
    RobotSpec(T robotSpec){
        self = std::make_shared<RobotSpecModel<T>>(robotSpec);
    }
    void buildRobotHead(){
        self->buildRobotHead();
    }
    void buildRobotLeg(){
        self->buildRobotLeg();
    }
    Robot getRobot(){
        return self->getRobot();
    }
private:
    class RobotSpecConcept {
    public:
        virtual void buildRobotHead() = 0;

        virtual void buildRobotLeg() = 0;

        virtual Robot getRobot() = 0;
    };
    template<typename T>
    class RobotSpecModel: public RobotSpecConcept{
    public:
        RobotSpecModel(T const& robotSpec){
            this->robotSpec = robotSpec;
        }
        void buildRobotHead(){
            robotSpec.buildRobotHead();
        }
        void buildRobotLeg(){
            robotSpec.buildRobotLeg();
        }
        Robot getRobot(){
            return robotSpec.getRobot();
        }
        T robotSpec;
    };
    std::shared_ptr<RobotSpecConcept> self;
};

class RobotBuilder{
public:
    RobotBuilder(RobotSpec const& robotSpec):robotSpec(robotSpec){}

    void makeRobot(){
        robotSpec.buildRobotHead();
        robotSpec.buildRobotLeg();
    }
    Robot getRobot(){
         return robotSpec.getRobot();
    }
    RobotSpec robotSpec;
};
#endif //DESIGN_PATTERN_ROBOTPLAN_H
