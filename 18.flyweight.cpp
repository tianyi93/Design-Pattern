//
// Created by Tianyi Zhang on 3/30/21.
//

#include "18.flyweight.h"
int main(){
    TreeManager treeManager;
    treeManager.add(0, 0, 1);
    treeManager.add(1,1,2);
    treeManager.add(2,2,4);
    treeManager.displayTrees();
}