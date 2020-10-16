#include <iostream>
#include "robot.h"

int main() {
    auto robot = Robot();
    NewRobotBuilder newRobotBuilder;
    RobotEngineer robotEngineer(std::make_shared<NewRobotBuilder>(newRobotBuilder));
    robotEngineer.makeRobot();
    robotEngineer.getRobot();
    return 0;
}