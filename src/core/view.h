//
// Created by Ajat Prabha and Shashank Mohabia on 11/20/2017.
//

#ifndef SMS_VIEW_H
#define SMS_VIEW_H

#include <iomanip>
#include <cstdlib>
#include "init.h"
#include "auth/user.h"

using namespace std;

class View {
public:
    virtual void display();
    void format_output(const string&);
    virtual ~View() = default;
};

extern View* global_view;

class SplashView: public View {
public:
    void display() override;
    ~SplashView() override = default;
};

class LoginView: public View {
public:
    void display() override;
};

class RegisterView: public View {
public:
    void display() override;
};

class DetailView: public View {
public:
    void display() override;
};

#endif //SMS_VIEW_H
