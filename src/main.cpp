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
            global_view = LoginView::getInstance();
            global_view->display();
            break;
        }

        case 2: {
            global_view = LoginView::getInstance();
            global_view->display();
            break;
        }
        case 0: {
            break;
        }
        default: {
            break;
        }
    }

    /*
      int t=1;
    while (t) {
        cout << "1. User\n2. Add Course\n3. Remove course\n4. Create TimeTable\n5. Show TimeTable\n0. exit" << endl;
        int n;
        cin >> n;
        switch (n) {
            case 1: {
                string name, pass, cpass;
                cout << "Enter your name" << endl;
                cin >> name;
                User u1(name, name, name);
                cout << "Enter password" << endl;
                cin >> pass;
                u1.set_password(pass);
                cout << "confirm password" << endl;
                cin >> cpass;
                if (u1.check_password(cpass)) cout << "Match\n";
                else cout << "No match\n";
                cout << u1.get_fullname() << " Authenticated: " << u1.is_authenticated() << endl;
                u1.save();
                break;
            }
            case 2: {
                Courses c;
                c.add();
                break;
            }

            case 3: {
                Courses::remove();
                break;
            }

            case 4: {
                TimeTable::create();
                break;
            }

            case 5: {
                TimeTable::show();
                break;
            }

            case 0: {
                t = 0;
                break;
            }

            default: {
                t = 0;
                cout << "no cases matched" << endl;
                break;
            }
        }
    }*/
    return 0;
}
