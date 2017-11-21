//
// Created by Lakshya on 20-Nov-17.
//

#ifndef SMS_ATTENDANCE_H
#define SMS_ATTENDANCE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../core/auth/User.h"
#include "../Courses/Courses.h"

using namespace std;

class attendance{
private:
    static map<User, vector<Courses> > attendance_list;
public:
    attendance();

    ~attendance();

    void mark_present(int day);

    void mark_absent(int day);

    void edit_attendance(string course, int day, bool attendance);
};

#endif //SMS_ATTENDANCE_H
