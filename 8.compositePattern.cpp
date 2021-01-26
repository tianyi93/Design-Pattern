//
// Created by Tianyi Zhang on 12/12/20.
//

#include "8.compositePattern.h"
#include <iostream>
int main(){
    std::shared_ptr<ToDoList> todo1 = std::make_shared<ToDo>("todo1");
    std::shared_ptr<ToDoList> todo2 = std::make_shared<ToDo>("todo2");
    std::vector<std::shared_ptr<ToDoList>> subProjectToDos{todo1, todo2};
    auto subProject = std::make_shared<Project>("subProject", subProjectToDos);

    std::shared_ptr<ToDoList> todo3 = std::make_shared<ToDo>("todo3");
    std::vector<std::shared_ptr<ToDoList>> projectToDos{subProject, todo3};
    auto project = std::make_shared<Project>("mainProject",projectToDos);
    std::cout<<project->getContext();

    return 0;
}