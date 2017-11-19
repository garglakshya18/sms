#include <iostream>
#include "core/init.h"
#include <random>

using namespace std;

int main()
{
//    string input, input2;
//    cin >> input;
//    User::Handler::writeData();
    Init::init();
//    User user_arr[25];
//    for (auto& i : user_arr) {
//        i.set_username("Yes" + rand());
//        i.save();
//    }
//    string s = "ajatprabha", t = "Ajat", u = "Prabha";
//    User u1(s, t, u);
//    User u2("shashank", "Shashank", "Mohabia");
//    u1.set_password(input);
//    cin >> input2;
//    if (u1.check_password(input2)) cout << "Match\n";
//    else cout << "No match\n";
//
//    AnonymousUser a1;
//    try { a1.set_password(input2); }
//    catch (UserError& e) {
//        cout << e.print_error() << endl;
//    };
//    try { a1.check_password(input2); }
//    catch (UserError& e) {
//        cout << e.print_error() << endl;
//    };
//    cout << u1.get_fullname() << "\t Authenticated: " << u1.is_authenticated() << endl;
//    cout << a1.get_fullname() << "\t Authenticated: " << a1.is_authenticated() << endl;
//    u1.save();
//    u2.save();
    for (auto& i : User::all()) {
        cout << i.second.get_fullname() << " " << i.second.get_username() << endl;
    }
//    User::Handler::writeData();
//    User::Handler::retrieveData();
    //if(User::writeData()) cout << "Written\n";
//    User::writeData();
//    system("pause");
    return 0;
}
