#include <iostream>
#include "1.factory_ufo.h"

int main() {
    UFOFactory ufoFactory;
    std::shared_ptr<UFO> fakeUFO = ufoFactory.makeUFO("F");
    fakeUFO->displayUFO();
    auto realUFO = ufoFactory.makeUFO("R");
    realUFO->displayUFO();
    return 0;
}