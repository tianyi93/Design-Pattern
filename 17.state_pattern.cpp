//
// Created by Tianyi Zhang on 3/7/21.
//

#include "17.state_pattern.h"

int main(){
    auto gamballMachine = GamballMachineFactory::createGamballMAchine(5);
    gamballMachine->insertQuarter();
    gamballMachine->ejectsQuarter();
    gamballMachine->insertQuarter();
    gamballMachine->turnCrank();
    gamballMachine->dispenseGumball();

    gamballMachine->dispenseGumball();
    gamballMachine->insertQuarter();
    gamballMachine->ejectsQuarter();
    gamballMachine->turnCrank();

    return 0;
}

/*
insertQuarter
        ejectstQuarter
insertQuarter
        turnCrank
dispenseGumball
invalid behavior
insertQuarter
        ejectstQuarter
invalid behavior
 */