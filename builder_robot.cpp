#include <iostream>
#include "builder_robot.h"

int main() {

    NewRobotSpec newRobotBuilder;
    RobotEngineer robotEngineer(std::make_shared<NewRobotSpec>(newRobotBuilder));
    robotEngineer.makeRobot();
    Robot newRobot = robotEngineer.getRobot();
    newRobot.getInfo();

    OldRobotSpec oldRobotBuilder;
    RobotEngineer robotEngineer1(std::make_shared<OldRobotSpec>(oldRobotBuilder));
    robotEngineer1.makeRobot();
    Robot oldRobot =robotEngineer1.getRobot();
    oldRobot.getInfo();
    return 0;
}