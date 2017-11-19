//
// Created by Shashank Mohabia on 11/18/2017.
//

#include "TimeTable.h"


void TimeTable::create() {
    tt = new string *[7];
    for (int i = 0; i < 7; ++i) { tt[i] = new string[5]; }
    tt[0][0] = "0";
    string p[4] = {"1st", "2nd", "3rd", "4th"};
    string d[6] = {"Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};
    for (int i = 1; i < 5; i++) {
        tt[0][i] = p[i - 1];
    }
    for (int i = 1; i < 7; i++) {
        tt[i][0] = d[i - 1];
    }
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 5; j++) {
            cin >> tt[i][j];
        }
    }
}

void TimeTable::show() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(10) << tt[i][j] << "  ";
        }
        cout << endl;
    }
}
