//
// Created by Tianyi Zhang on 10/24/20.
//

#include "3.concept_model_idiom.h"

int main(){
    TaskQueue taskQueue;
    taskQueue.push(PrintTask());
    taskQueue.push(GrabTask());
    taskQueue.run();
    PrintTask printTask;
    taskQueue.push(printTask);
    taskQueue.run();
    return 0;
}