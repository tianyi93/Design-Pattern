#include <iostream>
#include "factory_ufo.h"

int main() {
    UFOFactory ufoFactory;
    auto fakeUFO = ufoFactory.makeUFO("F");
    fakeUFO->displayUFO();
    auto realUFO = ufoFactory.makeUFO("R");
    realUFO->displayUFO();
    return 0;
}