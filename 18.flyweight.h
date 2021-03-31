//
// Created by Tianyi Zhang on 3/30/21.
//

#ifndef DESIGN_PATTERN_18_FLYWEIGHT_H
#define DESIGN_PATTERN_18_FLYWEIGHT_H
#include <vector>
#include <iostream>

// reduces the number of object instances at runtime, saving memory
// without this pattern, Tree will multiple instance.
struct Tree{
    //Intrinsic State
    void display(int x, int y, int age){
        std::cout<<"x coord: "<< x <<" ,y coord: "<< y << " ,age: "<< age<<std::endl;
    }
    std::string getTreeKnowledge(){
        return largeTreeKnowledge_;
    }
private:
    std::string largeTreeKnowledge_;
};

struct TreeManager{
    void add(int x, int y, int age){
        treeArray_.push_back(State(x, y, age));
    }
    void displayTrees(){
        for(auto t: treeArray_)
            tree_.display(t.XCoord, t.YCoord, t.Age);
    }
    std::string getTreeKnowledge(){
        return tree_.getTreeKnowledge();
    }
    struct State{
        //extrinsic State
        State(int x, int y, int age): XCoord(x), YCoord(y), Age(age){}
        int XCoord;
        int YCoord;
        int Age;
    };
private:
    std::vector<State> treeArray_;
    Tree tree_;
};

#endif //DESIGN_PATTERN_18_FLYWEIGHT_H
