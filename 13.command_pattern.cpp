//
// Created by Tianyi Zhang on 2/1/21.
//

#include "13.command_pattern.h"

int main(){
    RemoteControl remoteControl(2);
    auto fan = std::make_shared<Fan>();
    auto light = std::make_shared<Light>();

    remoteControl.setCommand(0, std::make_shared<FanOnCommand>(fan), std::make_shared<FanOffCommand>(fan));
    remoteControl.setCommand(1, std::make_shared<LightOnCommand>(light), std::make_shared<LightOffCommand>(light));

    remoteControl.onButtonPushed(0);
    remoteControl.offButtonPushed(0);
    remoteControl.onButtonPushed(1);
    remoteControl.offButtonPushed(1);

    remoteControl.undoCommandpushed();
}