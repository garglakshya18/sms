//
// Created by Ajat Prabha on 22-11-2017.
//

#include "menu.h"
#include "init.h"

bool START = true;

Menu* Menu::getInstance()
{
    return new Menu;
}
void Menu::display()
{
    delete global_view;
    if (START) {
        global_view = new SplashView;
        START = false;
        global_view->display();
        return;
    }
    switch (view_choice) {
    case LOGIN: {
        global_view = new LoginView;
        break;
    }
    case REGISTER: {
        global_view = new RegisterView;
        break;
    }
    case DETAIL: {
        if(current_user->is_superuser()) global_view = new AdminDetailView;
        else global_view = new StudentDetailView;
        break;
    }
    default: {
        cout << "Invalid Choice\n";
        EXIT_CODE = true;
        break;
    }
    }
    global_view->display();
}
