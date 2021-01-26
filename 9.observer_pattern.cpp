//
// Created by Tianyi Zhang on 12/19/20.
//

#include "9.observer_pattern.h"
int main(){
    std::shared_ptr<AlertStation> alertStation = std::make_shared<AlertStation>();
    std::shared_ptr<WeatherStation> weatherStation = std::make_shared<WeatherStation>(alertStation);
    alertStation->add(weatherStation);
    std::shared_ptr<IObserver> phoneDisplay = std::make_shared<PhoneDisplay>(weatherStation);
    std::shared_ptr<IObserver> monitorDisplay = std::make_shared<MonitorDisplay>(weatherStation);
    weatherStation->add(phoneDisplay);
    weatherStation->add(monitorDisplay);

    weatherStation->setNewTemp(1, 0);
    weatherStation->remove(phoneDisplay);
    std::cout<<"after removing phone display"<<std::endl;
    alertStation->setAlert(true);
    weatherStation->setNewTemp(110,3);
}