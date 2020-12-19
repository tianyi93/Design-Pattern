//
// Created by Tianyi Zhang on 12/19/20.
//

#include "observer_pattern.h"
int main(){
    std::shared_ptr<WeatherStation> weatherStation = std::make_shared<WeatherStation>();
    std::shared_ptr<IObserver> phoneDisplay = std::make_shared<PhoneDisplay>(weatherStation);
    std::shared_ptr<IObserver> monitorDisplay = std::make_shared<MonitorDisplay>(weatherStation);
    weatherStation->add(phoneDisplay);
    weatherStation->add(monitorDisplay);
    for(int i=0; i<=10; i++){
        weatherStation->setNewTemp(i*10, i);
    }
    weatherStation->remove(phoneDisplay);
    std::cout<<"after removing phone display"<<std::endl;
    weatherStation->setNewTemp(110,11);
}