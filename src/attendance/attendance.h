//
// Created by Ajat Prabha on 22-11-2017.
//

#ifndef SMS_ATTENDANCE_H
#define SMS_ATTENDANCE_H

#include "../core/auth/user.h"
#include "../courses/courses.h"

using namespace std;

class Attendance {
    static map<string, map<string, vector<bool>>> attendance_record;
public:
    static void show_attendance(const string&);
    static void update_attendance(const string&, const string&, bool);
    static map<string, map<string, vector<bool>>> all();
};

#endif //SMS_ATTENDANCE_H
