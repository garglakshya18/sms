//
// Created by Lakshya on 20-Nov-17.
//

#include <bfd.h>
#include "attendance.h"

attendance::attendance(){

}

attendance::~attendance(){

}

void attendance::mark_present(int day) {
    if(day-1<=attend.size()&&day>0){
        if(day-1==attend.size()){
            attend.push_back(TRUE);
        }
        else{
            attend[day-1] = TRUE;
        }
    }
    else{
        if(day<=0){
            cout << "Day must be greater than zero.\n";
        }
        else {
            cout << "Please mark the attendance of previous days first. You have currently marked attendance for only "
                 << attend.size() << ".\n";
        }
    }
}

void attendance::mark_absent(int day) {
    if(day-1<=attend.size()&&day>0){
        if(day-1==attend.size()){
            attend.push_back(FALSE);
        }
        else{
            attend[day-1] = FALSE;
        }
    }
    else{
        if(day<=0){
            cout << "Day must be greater than zero.\n";
        }
        else {
            cout << "Please mark the attendance of previous days first. You have currently marked attendance for only "
                 << attend.size() << ".\n";
        }
    }
}

void attendance::edit_attendance(string course, int day, bool attendance) {
    if(Courses::all().find(course) == Courses::all().end()){
        cout<<"This course doesn't exist.\n";
    }
    else {
    }
}