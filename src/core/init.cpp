//
// Created by Ajat Prabha on 16-11-2017.
//

#include "init.h"

bool EXIT_CODE = false;
VIEW_CHOICES view_choice = VIEW_CHOICES(SPLASH);

void Init::init()
{
    /* Dummy data to drive the program */
    User user("student", "Ajat", "Prabha");
    user.set_password("password");
    user.set_year(1);
    user.save();
    User user1("admin", "Shashank", "Mohabia");
    user1.set_password("password");
    user1.make_superuser();
    user1.save();
    Course course("Linear", 'A', "admin", 1), course1("Physics", 'B', "admin", 1), course2("Chemistry", 'D', "admin", 1);
    course.save();
    course1.save();
    course2.save();
    Attendance::update_attendance(user.get_username(), course.get_course_name(), false);
    Attendance::update_attendance(user.get_username(), course.get_course_name(), true);
    Attendance::update_attendance(user.get_username(), course.get_course_name(), false);
}
