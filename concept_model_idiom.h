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
    Task(PrintTask task){
        self = std::unique_ptr<PrintTaskModel>(new PrintTaskModel(std::move(task)));
    }
    Task(GrabTask task){
        self = std::unique_ptr<GrabTaskModel>(new GrabTaskModel(std::move(task)));
    }
    void process(){
        this->self->process();
    }
private:
    class ConceptTask{
    public:
        virtual void process() = 0;
    };

    class PrintTaskModel: public ConceptTask{
    public:
        PrintTaskModel(PrintTask const& task){
            this->task = task;
        }
        void process() override{
            task.process();
        }
        PrintTask task;
    };

    class GrabTaskModel: public ConceptTask{
    public:
        GrabTaskModel(GrabTask const& task){
            this->task = task;
        }
        void process() override{
            task.process();
        }
        GrabTask task;
    };

    std::unique_ptr<ConceptTask> self;


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
