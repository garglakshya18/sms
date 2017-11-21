//
// Created by Lakshya on 20-Nov-17.
//

#ifndef SMS_ATTENDANCE_H
#define SMS_ATTENDANCE_H

#include <iostream>
#include <string>
#include "../Courses/Courses.h"

using namespace std;

class attendance{
private:
    vector<bool> attend;
public:
    attendance();

    ~attendance();

    void mark_present(int day);

    void mark_absent(int day);

    void edit_attendance(string course, int day, bool attendance);
};

#endif //SMS_ATTENDANCE_H
