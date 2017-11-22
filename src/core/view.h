//
// Created by Ajat Prabha and Shashank Mohabia on 11/20/2017.
//

#ifndef SMS_VIEW_H
#define SMS_VIEW_H

#include <iomanip>
#include <cstdlib>
#include "init.h"
#include "auth/user.h"
#include "../courses/courses.h"
#include "../attendance/attendance.h"

using namespace std;

class View {
public:
    View() = default;
    virtual void display();
    void format_output(const string&);
    virtual ~View() = default;
};

extern View* global_view;

class SplashView: public View {
public:
    SplashView() = default;
    void display() override;
    ~SplashView() override = default;
};
class LoginView: public View {
public:
    LoginView() = default;
    void display() override;
    ~LoginView() override = default;
};
class RegisterView: public View {
public:
    RegisterView() = default;
    void display() override;
    ~RegisterView() override = default;
};
class StudentDetailView: public View {
public:
    StudentDetailView() = default;
    void display() override;
    ~StudentDetailView() override = default;
};
class AdminDetailView: public View {
public:
    AdminDetailView() = default;
    void display() override;
    ~AdminDetailView() override = default;
};

#endif //SMS_VIEW_H
