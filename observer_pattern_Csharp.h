//
// Created by Tianyi Zhang on 1/4/21.
//

#ifndef DESIGN_PATTERN_OBSERVER_PATTERN_CSHARP_H
#define DESIGN_PATTERN_OBSERVER_PATTERN_CSHARP_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <exception>
#include <map>

template<typename T>
struct IObserver{
    virtual void onCompleted() = 0;
    virtual void onError(std::exception exp) = 0;
    virtual void onNext(T value) = 0;
    virtual ~IObserver(){};
};

struct UnSubscriber{
    virtual void unSubscribe() = 0;
    virtual ~UnSubscriber(){};
};

template<typename T>
struct IObservable{
    virtual std::shared_ptr<UnSubscriber> subscribe(std::shared_ptr<IObserver<T>> observer) = 0;
};

struct Temperature{
public:
    void setIndoorTemp(double indoorTemp){
        this->indoorTemp = indoorTemp;
        changedField["indoorTemp"] = true;
    }
    void setOutdoorTemp(double outdoorTemp){
        this->outdoorTemp = outdoorTemp;
        changedField["outdoorTemp"] = true;
    }
    void setTimeSerial(int timeSerial){
        this->timeSerial = timeSerial;
        changedField["timeSerial"] = true;
    }
    double getIndoorTemp(){
        return indoorTemp;
    }
    double getOutdoorTemp(){
        return outdoorTemp;
    }
    int getTimeSerial(){
        return timeSerial;
    }
    bool isDirty(std::string const& field){
        return changedField[field] == true;
    }
    void clean(std::string const& field){
        changedField[field] = false;
    }
private:
    double indoorTemp;
    double outdoorTemp;
    int timeSerial;
    std::map<std::string, bool> changedField;
};

struct TemperatureMonitor : public IObservable<Temperature>
{
    std::shared_ptr<UnSubscriber> subscribe(std::shared_ptr<IObserver<Temperature>> observer) override{
        if(std::find(observers.begin(), observers.end(), observer) == observers.end()){
            observers.push_back(observer);
        }
        return std::make_shared<UnsubscriberImpl>(observers, observer);
    }
    void setIndoorTemp(double indoorTemp){
        temperature.setIndoorTemp(indoorTemp);
        for(auto observer : observers)
            observer->onNext(temperature);
        temperature.clean("indoorTemp");
    }
    void setOutdoorTemp(double outdoorTemp){
        temperature.setOutdoorTemp(outdoorTemp);
        for(auto observer : observers)
            observer->onNext(temperature);
        temperature.clean("outdoorTemp");
    }
    void setTimeSerial(int timeSerial){
        temperature.setTimeSerial(timeSerial);
        for(auto observer : observers)
            observer->onNext(temperature);
        temperature.clean("timeSerial");
    }
    void stopMonitor(){
        for(auto observer : observers) {
            observer->onCompleted();
            observers.erase(observers.begin(), observers.end());
        }
    }

private:
    std::vector<std::shared_ptr<IObserver<Temperature>>> observers;
    Temperature temperature;
    struct UnsubscriberImpl : UnSubscriber{
        UnsubscriberImpl(std::vector<std::shared_ptr<IObserver<Temperature>>>& observers,
                         std::shared_ptr<IObserver<Temperature>> observer){
            this->observers = &observers;
            this->observer = observer;
        }
        void unSubscribe(){
            if(std::find(observers->begin(), observers->end(), observer) != observers->end()) {
                observers->erase(std::find(observers->begin(), observers->end(), observer));
            }
        }
    private:
        //possible memory leak here..
        std::vector<std::shared_ptr<IObserver<Temperature>>>* observers;
        std::shared_ptr<IObserver<Temperature>> observer;
    };
};

struct TemperatureReporter : public IObserver<Temperature>{
    void onNext(Temperature temperature) override{
        if(temperature.isDirty("indoorTemp")){
            std::cout<<"indoorTemp : "<<temperature.getIndoorTemp()<<std::endl;
        }
        if(temperature.isDirty("outdoorTemp")){
            std::cout<<"outdoorTemp : "<<temperature.getOutdoorTemp()<<std::endl;
        }
        if(temperature.isDirty("timeSerial")){
            std::cout<<"timeSerial : "<<temperature.getTimeSerial()<<std::endl;
        }
    }
    void onCompleted() override{};
    void onError(std::exception exp) override{};
};


#endif //DESIGN_PATTERN_OBSERVER_PATTERN_CSHARP_H
