//
// Created by Ajat Prabha and Shashank Mohabia on 11/20/2017.
//

#include "view.h"

View* global_view = new View;

void View::display()
{
    cout << "Yes\n";
}

void View::format_output(const string& s)
{
    int l = s.length();
    auto pos = (170-l)/2;
    for (int i = 0; i<pos; i++) {
        cout << " ";
    }
    system("color A1");
    cout << s << endl;
}

void SplashView::display()
{
    format_output("Welcome to SMS");
    cout << "\n";
    format_output("1. Login");
    format_output("2. Register");
    format_output("0. Exit");
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        view_choice = VIEW_CHOICES(LOGIN);
        break;
    }
    case 2: {
        view_choice = VIEW_CHOICES(REGISTER);
        break;
    }
    case 0: {
        EXIT_CODE = true;
        break;
    }
    default: {
        view_choice = VIEW_CHOICES(LOGIN);
        break;
    }
    }
}

void LoginView::display()
{
    format_output("Welcome to login screen\n");
    format_output("Enter username");
    string username, password;
    cin >> username;
    format_output("Enter password");
    cin >> password;
    auto user = User::all().find(username);
    if (user!=User::all().end() &&
            user->second.check_password(password)) {
        current_user = &(user->second);
        cout << current_user->get_fullname() << " successfully logged in" << endl;
    }
    else {
        cout << "Either username or password is incorrect\n";
    }
    if (current_user->is_authenticated()) view_choice = VIEW_CHOICES(DETAIL);
    system("pause");
}

void RegisterView::display()
{
    format_output("Welcome to register screen");
    cout << "At present there are " << User::all().size() << " users in the system" << endl;
    string username, f_name, l_name, pass = "   ", c_pass = "     ";
    cout << "Enter username, first_name, last_name" << endl;
    cin >> username >> f_name >> l_name;
    User u(username, f_name, l_name);
    while (pass!=c_pass) {
        if (pass!="   ") {
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
    case 1:u.make_superuser();
        break;
    case 2 :break;
    default:break;
    }
    current_user = &(u.save());
    cout << u.get_fullname() << " successfully registered" << endl;
    cout << "Now there are " << User::all().size() << " users in the system" << endl;
    system("pause");
    view_choice = VIEW_CHOICES(LOGIN);
}

void DetailView::display()
{
    format_output("Welcome to DetailView");
    cout << "\n";
    format_output("YOYOYOYOYO");
}
