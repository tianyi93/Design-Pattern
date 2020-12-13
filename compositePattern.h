//
// Created by Tianyi Zhang on 12/12/20.
//

#ifndef DESIGN_PATTERN_COMPOSITEPATTERN_H
#define DESIGN_PATTERN_COMPOSITEPATTERN_H
#include <string>
#include <vector>
#include <memory>
struct ToDoList{
    virtual std::string getContext() = 0;
};

struct ToDo : ToDoList{
    ToDo(std::string const& content) : content(content){}

    std::string getContext() override{
        std::string context;
        context += "<beginItem>";
        context += content;
        context +=" <EndItem>\n";
        return context;
    }

private:
    std::string content;
};

struct Project : public ToDoList{
    Project(std::string const& projName, std::vector<std::shared_ptr<ToDoList>> const& todos) :
    name(projName), todos(todos){}
    std::string getContext() override {
        std::string context;
        context += "<beginItem>(" + name +")\n";
        for(auto todo : todos){
            context += todo->getContext();
        }
        context +="<EndItem>(" + name +")\n";
        return context;
    }
private:
    std::string name;
    std::vector<std::shared_ptr<ToDoList>> todos;
};
#endif //DESIGN_PATTERN_COMPOSITEPATTERN_H
