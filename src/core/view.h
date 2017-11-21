//
// Created by Shashank Mohabia on 11/20/2017.
//

#ifndef SMS_VIEW_H
#define SMS_VIEW_H

#include "auth/User.h"
#include <iomanip>
#include <stdlib.h>
#include <conio.h>

class View {
protected:
    static User *current_user;
public:
    static View *getInstance(View *);

    virtual void display();

    void format_output(const string &);

    ~View();
};

class SplashView : public View {
public:
    static SplashView *getInstance(View *);

    void display() override;

    ~SplashView();
};

class LoginView : public View {
public:
    static LoginView *getInstance(View *);

    void display() override;

};


class RegisterView : public View {
public:
    static RegisterView *getInstance(View *);

    void display() override;


};

#endif //SMS_VIEW_H
