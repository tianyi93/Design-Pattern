//
// Created by Tianyi Zhang on 12/19/20.
//

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_H
#define DESIGN_PATTERN_OBSERVER_PATTERN_H
#include <memory>
#include <vector>
#include <iostream>

struct IObserver{
    virtual void getUpdates() = 0;
    virtual ~IObserver(){};
};

struct IObserverable{
    virtual void add(std::shared_ptr<IObserver> observer) = 0;
    virtual void remove(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};

struct AlertStation : public IObserverable{
    void add(std::shared_ptr<IObserver> observer) override{
        observerList.push_back(observer);
    }
    void remove(std::shared_ptr<IObserver> observer) override{
        for(int i=0; i<observerList.size(); i++) {
            if(observerList[i] == observer)
                observerList.erase(observerList.begin() + i);
        }
    }
    void setAlert(bool alertStatus){
        Alert = alertStatus;
        notify();
    }

    bool Alert;
private:
    void notify() override{
        for(auto observer : observerList)
            observer->getUpdates();
    }
    std::vector<std::shared_ptr<IObserver>> observerList;
};

struct WeatherStation : public IObserverable, public IObserver{
    WeatherStation() = default;
    WeatherStation(std::shared_ptr<AlertStation> alertStation){
        this->alertStation = alertStation;
    }
    void add(std::shared_ptr<IObserver> observer) override{
        observerList.push_back(observer);
    }

    void remove(std::shared_ptr<IObserver> observer) override{
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

    void getUpdates() override{
        this->Alert = alertStation->Alert;
        notify();
    }
    bool Alert;
private:
    void notify() override{
        for(auto observer : observerList)
            observer->getUpdates();
    }
    std::vector<std::shared_ptr<IObserver>> observerList;
    std::shared_ptr<AlertStation> alertStation;
};

struct MonitorDisplay : public IObserver{
    MonitorDisplay(std::shared_ptr<WeatherStation> weatherStation){
        this->weatherStation = weatherStation;
    }
    void getUpdates() override{
        this->displayTemperature = weatherStation->Temperature;
        this->timeSerial = weatherStation->TimeSerial;
        this->alert = weatherStation->Alert;
        display();
    }

private:
    void display(){
        std::cout<<"Monitor display Temperature : "<< displayTemperature << "; TimeSerial : " << timeSerial << std::endl;
        std::cout<<"Alert status: "<< alert<<std::endl;
    }
    double displayTemperature;
    double timeSerial;
    bool alert;
    std::shared_ptr<WeatherStation> weatherStation;
};

struct PhoneDisplay : public IObserver{
    PhoneDisplay(std::shared_ptr<WeatherStation> weatherStation){
        this->weatherStation = weatherStation;
    }
    void getUpdates() override{
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
