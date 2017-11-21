//
// Created by Shashank Mohabia on 11/20/2017.
//

#include "view.h"

View *View::getInstance(View *global_view) {
    delete global_view;
    return new View;
}

void View::display() {
    cout << "Yes\n";
}

void View::format_output(const string &s) {
    int l = s.length();
    auto pos = (170 - l) / 2;
    for (int i = 0; i < pos; i++) {
        cout << " ";
    }
    system("color A1");
    cout << s << endl;
}

View::~View() {
    cout << "Base view destructor called.\n";
}

void SplashView::display() {
    format_output("Welcome to SMS");
    cout << "\n";
    format_output("1. Login");
    format_output("2. Register");
    format_output("0. Exit");
    cout << endl << current_user->get_fullname() << endl;
}

SplashView *SplashView::getInstance(View *global_view) {
    delete global_view;
    return new SplashView;
}

SplashView::~SplashView() {
    cout << "Splash Destructed\n";
}

LoginView *LoginView::getInstance(View *global_view) {
    delete global_view;
    return new LoginView;
}

void LoginView::display() {
    system("cls");
    format_output("Welcome to login screen");
    format_output("Enter username");
    string username, password;
    cin >> username;
    format_output("Enter password");
    cin >> password;
    auto user = User::all().find(username);
    if (user != User::all().end() &&
        user->second.check_password(password)) {
        current_user = &(user->second);
    } else {
        cout << "Either username or password is incorrect\n";
    }
    cout << current_user->get_fullname() << " successfully logged in" << endl;
    system("pause");
}

RegisterView *RegisterView::getInstance(View *global_view) {
    delete global_view;
    return new RegisterView;
}

void RegisterView::display() {
    system("cls");
    format_output("Welcome to register screen");
    User::create_new_user();
    system("pause");

}
