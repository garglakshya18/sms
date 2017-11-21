//
// Created by Ajat Prabha on 22-11-2017.
//

#ifndef SMS_MENU_H
#define SMS_MENU_H

extern bool START;

class Menu {
public:
    static Menu* getInstance();
    void display();
};

#endif //SMS_MENU_H
