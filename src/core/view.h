//
// Created by Shashank Mohabia on 11/20/2017.
//

#ifndef SMS_VIEW_H
#define SMS_VIEW_H

#include "auth/User.h"
#include <iomanip>
#include <cstdlib>

class View {
public:
    static User *current_user;
    static View *getInstance(View *);

    virtual void display();

    void format_output(const string &);

    virtual ~View() = default;
};

class SplashView : public View {
public:
    static SplashView *getInstance(View *);

    void display() override;

    ~SplashView() override = default;
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

class DetailView : public View {
public:
    static DetailView *getInstance(View *);

    void display() override;


};

#endif //SMS_VIEW_H
