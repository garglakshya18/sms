#include <iostream>
#include "core/init.h"

using namespace std;

int SMS()
{
    Menu* menu = Menu::getInstance();
    do {
        menu->display();
    }
    while (!EXIT_CODE);
    return 0;
}
