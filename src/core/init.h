//
// Created by Ajat Prabha on 16-11-2017.
//

#ifndef SMS_INIT_H
#define SMS_INIT_H
#define SMS m##a##i##n

#include <iostream>
#include "auth/user.h"
#include "menu.h"
#include "view.h"

extern bool EXIT_CODE;

enum VIEW_CHOICES{SPLASH, LOGIN, REGISTER, DETAIL};

extern VIEW_CHOICES view_choice;

class Init {
public:
    static void init();
};

#endif //SMS_INIT_H
