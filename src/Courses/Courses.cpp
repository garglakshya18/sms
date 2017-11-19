//
// Created by Shashank Mohabia on 11/18/2017.
//

#include "Courses.h"

Courses::Courses() {

}

Courses::Courses(string name, string code, char s, User &inst) {
    course_name = move(name);
    course_code = code;
    slot = s;
    instructor = inst;
}

void Courses::remove() {
    if (Courses::show()) {
        cout << "Enter the course no to remove" << endl;
        int n;
        cin >> n;
        auto it = course_list.begin();
        advance(it, n - 1);
        course_list.erase(it);
        cout << course_list.size() << endl;
        Courses::show();
    } else {
        cout << "First enter some courses" << endl;
    }
}

void Courses::save() {
    course_list.insert(pair<string, Courses>(this->course_name, *this));
}

map<string, Courses> Courses::all() {
    return course_list;
}

string Courses::get_course_name() {
    return course_name;
}

Courses::~Courses() {

}

void Courses::add() {
    if (!User::all().empty()) {
        cout << "Enter course name, code, slot and instructor" << endl;
        string name;
        string code;
        char slot;
        string i;
        cin >> name >> code >> slot >> i;
        auto it = User::all().find(i);
        if (it != User::all().end()) {
            User instructor = it->second;
            Courses c1(name, code, slot, instructor);
            cout << c1.get_course_name() << endl;
            c1.save();
        } else {
            cout << "Instructor not registered" << endl;
        }
        cout << Courses::all().size() << endl;
    } else {
        cout << "User list is empty" << endl;
    }
}

bool Courses::show() {
    if (!course_list.empty()) {
        int i = 1;
        for (auto elem : course_list) {
            std::cout << i++ << ". " << elem.first << "\n";
        }
        return true;
    } else {
        cout << "course list is empty" << endl;
        return false;
    }

}
