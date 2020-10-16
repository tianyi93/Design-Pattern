#include <iostream>
#include "builder_robot.h"

int main() {

    NewRobotBuilder newRobotBuilder;
    RobotEngineer robotEngineer(std::make_shared<NewRobotBuilder>(newRobotBuilder));
    robotEngineer.makeRobot();
    Robot newRobot = robotEngineer.getRobot();
    newRobot.getInfo();

    OldRobotBuilder oldRobotBuilder;
    RobotEngineer robotEngineer1(std::make_shared<OldRobotBuilder>(oldRobotBuilder));
    robotEngineer1.makeRobot();
    Robot oldRobot =robotEngineer1.getRobot();
    oldRobot.getInfo();
    return 0;
}