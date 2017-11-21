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

LoginView *LoginView::getInstance(View *global_view) {
    delete global_view;
    return new LoginView;
}

void LoginView::display() {
    format_output("Welcome to login screen\n");
    format_output("Enter username");
    string username, password;
    cin >> username;
    format_output("Enter password");
    cin >> password;
    auto user = User::all().find(username);
    if (user != User::all().end() &&
        user->second.check_password(password)) {
        current_user = &(user->second);
        cout << current_user->get_fullname() << " successfully logged in" << endl;
    } else {
        cout << "Either username or password is incorrect\n";
    }
    system("pause");
}

RegisterView *RegisterView::getInstance(View *global_view) {
    delete global_view;
    return new RegisterView;
}

void RegisterView::display() {
    format_output("Welcome to register screen");
    cout << "At present there are " << User::all().size() << " users in the system" << endl;
    string username, f_name, l_name, pass = "   ", c_pass = "     ";
    cout << "Enter username, first_name, last_name" << endl;
    cin >> username >> f_name >> l_name;
    User u(username, f_name, l_name);
    while (pass != c_pass) {
        if (pass != "   ") {
            cout << "Password doesn't match, retry!" << endl;
        }
        cout << "Enter password" << endl;
        cin >> pass;
        cout << "Confirm password" << endl;
        cin >> c_pass;
    }
    u.set_password(pass);
    cout << "Do you want to make this user a superuser?\n1. Yes\n2. No\n";
    int ch;
    cin >> ch;
    switch (ch) {
        case 1:
            u.make_superuser();
            break;
        case 2 :
            break;
        default:
            break;
    }
    current_user = &(u.save());
    cout << u.get_fullname() << " successfully registered" << endl;
    cout << "Now there are " << User::all().size() << " users in the system" << endl;
    system("pause");
}

void DetailView::display() {
    format_output("Welcome to DetailView");
    cout << "\n";
    format_output("1. ");
    format_output("2. Register");
    format_output("0. Exit");
    cout << endl << current_user->get_fullname() << endl;
}

DetailView *DetailView::getInstance(View *global_view) {
    delete global_view;
    return new DetailView;
}
