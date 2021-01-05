//
// Created by Tianyi Zhang on 1/4/21.
//

#include "observer_pattern_Csharp.h"
int main(){
    auto temperatureMonitor = std::make_shared<TemperatureMonitor>();
    auto temperatureReporter =  std::make_shared<TemperatureReporter>();

    auto temperatureReporterUnScrib  = temperatureMonitor->subscribe(temperatureReporter);

    temperatureMonitor->setTimeSerial(0);
    temperatureMonitor->setIndoorTemp(10);
    temperatureMonitor->setOutdoorTemp(20);

    temperatureReporterUnScrib->unSubscribe();
    temperatureMonitor->setTimeSerial(1);
}