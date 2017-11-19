//
// Created by Shashank Mohabia on 11/18/2017.
//

#ifndef SMS_COURSES_H
#define SMS_COURSES_H

#include <string>
#include <map>
#include "../core/auth/User.h"

using namespace std;


class Courses {
private:
    static map<string, Courses> course_list;
    string course_name, course_code;
    char slot;
    User instructor;

public:
    Courses();

    Courses(string, string, char, User &);

    ~Courses();

    void add();

    static void remove();

    static bool show();

    void save();

    static map<string, Courses> all();

    string get_course_name();
};


#endif //SMS_COURSES_H
