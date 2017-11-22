//
// Created by Shashank Mohabia on 11/18/2017.
//

#ifndef SMS_COURSES_H
#define SMS_COURSES_H

#include <iostream>
#include <string>
#include <map>
#include "../core/auth/user.h"

using namespace std;

class Course {
    static map<string, Course> course_list;
    static char timetable_map[6][4];
    string name, instructor_username;
    int year;
    char slot;
public:
    Course();
    Course(const string&, const char&, const string&, int);
    ~Course() = default;
    //void add();
    bool remove();
    static bool show_user_courses(int);
    void save();
    static map<string, Course> all();
    char get_slot();
    int get_year();
    string get_instructor_name();
    string get_course_name();
    static void show_timetable();
    static void update_timetable();
};


#endif //SMS_COURSES_H
