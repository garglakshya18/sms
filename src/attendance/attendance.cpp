//
// Created by Ajat Prabha on 22-11-2017.
//

#include "attendance.h"

map<string, map<string, vector<bool>>> Attendance::attendance_record = {};
void Attendance::show_attendance(const string& username)
{
    cout << "\t\tPresent\t\tAbsent\t\tTotal\n";
    for (auto &i : attendance_record[username]) {
        cout << i.first;
        int days_present = 0;
        for (auto&& j : i.second) {
            if(j== true){
                days_present++;
            }
        }
        cout << "\t\t" << days_present << "\t\t" << i.second.size() - days_present << "\t\t" << i.second.size() << "\n";
    }

}
void Attendance::update_attendance(const string& username, const string& course, bool is_present)
{
    if (attendance_record.find(username) == attendance_record.end()) {
        map<string, vector<bool>>m1 = {};
        vector<bool> v1 = {is_present};
        m1.insert(pair<string, vector<bool>>(course, v1));
        attendance_record.insert(pair<string, map<string, vector<bool>>>(username, m1));
    }
    else {
        attendance_record.find(username)->second.find(course)->second.push_back(is_present);
    }
    //cout<<"\n"<<attendance_record.find(username)->second.find(course)->second.size()<<"\n";
    //attendance_record.insert(pair<string, map<string, vector<bool>>>(username,attendance_record.find(username)->second));
}
map<string, map<string, vector<bool>>> Attendance::all()
{
    return attendance_record;
}
