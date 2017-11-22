//
// Created by Shashank Mohabia on 11/18/2017.
//

#include "Courses.h"

map<string, Course> Course::course_list = {};
char Course::timetable_map[6][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'A', 'B'},
        {'C', 'D', 'E', 'F'},
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'A', 'B'},
        {'C', 'D', 'E', 'F'}
};
Course::Course()
{
    slot = 'A';
}
Course::Course(const string& _name, const char& _slot, const string& inst, int _year)
{
    name = _name;
    slot = _slot;
    instructor_username = inst;
    year = _year;
}
bool Course::remove()
{
    if (course_list.find(this->get_course_name())!=course_list.end()) {
        auto it = course_list.find(this->get_course_name());
        course_list.erase(it);
        return true;
    }
    else
        return false;
}
void Course::save()
{
    course_list.insert(pair<string, Course>(this->name, *this));
}
map<string, Course> Course::all()
{
    return course_list;
}
string Course::get_course_name()
{
    return name;
}
bool Course::show_user_courses(int _year)
{
    cout << "Name:\t\t" << "Slot:\t\t" << "Instructor:\n";
    for (auto& i : course_list) {
        if (i.second.year==_year)
            cout << i.second.get_course_name() << "\t\t" << i.second.slot << "\t\t"
                 << User::all().find(i.second.get_instructor_name())->second.get_fullname() << endl;
    }
}
char Course::get_slot()
{
    return slot;
}
int Course::get_year()
{
    return year;
}
void Course::show_timetable()
{
    string day[7] = {"", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    string period[5] = {"", "1st", "2nd", "3rd", "4th"};
    for (int i = 0; i<7; ++i) {
        for (int j = 0; j<5; ++j) {
            if (i==0) {
                if (j==0) cout << period[j] << "\t";
                else cout << period[j] << "\t\t\t";
                continue;
            }
            if (j==0) {
                cout << day[i] << "\t";
                continue;
            }
            if (current_user->is_superuser()) cout << Course::timetable_map[i-1][j-1] << "\t\t\t";
            else {
                bool found = false;
                for (auto& k:course_list) {
                    if (k.second.year==current_user->get_year() && k.second.slot == Course::timetable_map[i-1][j-1]) {
                        cout << k.second.get_course_name() << "\t\t\t";
                        found = true;
                    }
                }
                if (!found) cout << "-" << "\t\t\t";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
}
void Course::update_timetable()
{
    for (auto& i : timetable_map) {
        for (char& j : i) {
            cin >> j;
        }
    }
}
string Course::get_instructor_name()
{
    return instructor_username;
}
