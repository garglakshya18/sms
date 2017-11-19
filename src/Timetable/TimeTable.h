//
// Created by Shashank Mohabia on 11/18/2017.
//

#ifndef SMS_TIMETABLE_H
#define SMS_TIMETABLE_H

#include <iomanip>
#include "../core/auth/User.h"

class TimeTable {
private:
    static string **tt;
public:
    TimeTable() {}

    static void create();

    static void show();
};


#endif //SMS_TIMETABLE_H
