//
// Created by Tianyi Zhang on 12/19/20.
//

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_H
#define DESIGN_PATTERN_OBSERVER_PATTERN_H
#include <memory>
#include <vector>
#include <iostream>

struct IObserver{
    virtual void update() = 0;
    virtual ~IObserver(){};
};

struct IObserverable{
    virtual void add(std::shared_ptr<IObserver> observer) = 0;
    virtual void remove(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};

struct WeatherStation : public IObserverable{
    void add(std::shared_ptr<IObserver> observer){
        observerList.push_back(observer);
    }

    void remove(std::shared_ptr<IObserver> observer){
        for(int i=0; i<observerList.size(); i++) {
            if(observerList[i] == observer)
                observerList.erase(observerList.begin() + i);
        }
    }

    void setNewTemp(double newTemperature, int timeSerial){
        Temperature = newTemperature;
        TimeSerial = timeSerial;
        notify();
    }

    double Temperature;
    int TimeSerial;

private:
    void notify(){
        for(auto observer : observerList)
            observer->update();
    }
    std::vector<std::shared_ptr<IObserver>> observerList;
};

struct MonitorDisplay : public IObserver{
    MonitorDisplay(std::shared_ptr<WeatherStation> weatherStation){
        this->weatherStation = weatherStation;
    }
    void update(){
        this->displayTemperature = weatherStation->Temperature;
        this->timeSerial = weatherStation->TimeSerial;
        display();
    }

private:
    void display(){
        std::cout<<"Monitor display Temperature : "<< displayTemperature << "; TimeSerial : " << timeSerial << std::endl;
    }
    double displayTemperature;
    double timeSerial;
    std::shared_ptr<WeatherStation> weatherStation;
};

struct PhoneDisplay : public IObserver{
    PhoneDisplay(std::shared_ptr<WeatherStation> weatherStation){
        this->weatherStation = weatherStation;
    }
    void update(){
        this->displayTemperature = weatherStation->Temperature;
        display();
    }

private:
    void display(){
        std::cout<<"Phone display Temperature : "<< displayTemperature << std::endl;
    }
    double displayTemperature;
    std::shared_ptr<WeatherStation> weatherStation;
};
#endif //DESIGN_PATTERN_OBSERVER_PATTERN_H
