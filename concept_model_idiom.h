//
// Created by Tianyi Zhang on 10/24/20.
//

#ifndef DESIGN_PATTERN_CONCEPT_MODEL_IDIOM_H
#define DESIGN_PATTERN_CONCEPT_MODEL_IDIOM_H
#include <iostream>
#include <memory>
#include <vector>
//refer to https://gracicot.github.io/conceptmodel/2017/09/13/concept-model-part1.html

class PrintTask{
public:
    void process(){
        std::cout<<"Print task"<<std::endl;
    }
};

class GrabTask{
public:
    void process(){
        std::cout<<"Grab task"<<std::endl;
    }
};

//actually just an adapter to convert PrintTask and GrabTask to Task
class Task{
public:
    template<typename T>
    Task(T task){
        self = std::unique_ptr<TaskConcept>(new TaskModel<T>(std::move(task)));
    }
    void process(){
        this->self->process();
    }
private:
    class TaskConcept{
    public:
        virtual void process() = 0;
    };

    template<typename T>
    class TaskModel: public TaskConcept{
    public:
        TaskModel(T&& task){
            this->task = std::move(task);
        }
        void process() override{
            task.process();
        }
        T task;
    };

    std::unique_ptr<TaskConcept> self;


};

class TaskQueue{
public:
    void push(Task task){
        this->taskQueue.push_back(std::move(task));
    }
    void run(){
        for(auto& task:taskQueue)
            task.process();
    }

private:
    std::vector<Task> taskQueue;
};
#endif //DESIGN_PATTERN_CONCEPT_MODEL_IDIOM_H
