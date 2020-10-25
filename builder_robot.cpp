#include <iostream>
#include "builder_robot.h"

int main() {
    NewRobotSpec newRobotSpec;
    RobotBuilder robotBuilder(newRobotSpec);
    robotBuilder.makeRobot();
    Robot newRobot = robotBuilder.getRobot();
    newRobot.getInfo();

    OldRobotSpec oldRobotSpec;
    RobotBuilder robotBuilder1(oldRobotSpec);
    robotBuilder1.makeRobot();
    Robot oldRobot =robotBuilder1.getRobot();
    oldRobot.getInfo();
    return 0;
}