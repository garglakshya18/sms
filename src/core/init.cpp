//
// Created by Ajat Prabha on 16-11-2017.
//

#include "init.h"

std::map<string, User> User::object_list = {};
std::map<string, Courses> Courses::course_list = {};
std::map<User, vector<Courses> > attendance::attendance_list = {};
User *View::current_user = new AnonymousUser();
string **TimeTable::tt = nullptr;

