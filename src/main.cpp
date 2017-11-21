#include <iostream>
#include "core/init.h"

using namespace std;


int main() {
    User user("ajatprabha", "Ajat", "Prabha");
    user.set_password("golmaal");
    user.save();
    View *global_view = nullptr;
    global_view = View::getInstance(global_view);
    global_view = SplashView::getInstance(global_view);
    global_view->display();

    int s;
    cin >> s;
    switch (s) {
        case 1: {
            global_view = LoginView::getInstance(global_view);
            global_view->display();
            break;
        }

        case 2: {
            global_view = RegisterView::getInstance(global_view);
            global_view->display();
            if (View::current_user->is_authenticated()) {
                global_view = LoginView::getInstance(global_view);
                global_view->display();
            } else {
                cout << "Registration Unsuccessful\n";
                global_view->display();
            }
            break;
        }
        case 0: {
            break;
        }
        default: {
            break;
        }
    }
    return 0;
}
