#include <iostream>
#include "core/init.h"

using namespace std;

int main()
{
    string input, input2;
    cin >> input;
    User u1("ajatprabha", "Ajat", "Prabha");
    u1.set_password(input);
    cin >> input2;
    if (u1.check_password(input2)) cout << "Match\n";
    else cout << "No match\n";

    AnonymousUser a1;
    try { a1.set_password(input2); }
    catch (UserError& e) {
        cout << e.print_error() << endl;
    };
    try { a1.check_password(input2); }
    catch (UserError& e) {
        cout << e.print_error() << endl;
    };
    cout << u1.get_fullname() << "\t Authenticated: " << u1.is_authenticated() << endl;
    cout << a1.get_fullname() << "\t Authenticated: " << a1.is_authenticated() << endl;
    u1.save();
    for (int i = 0; i<User::all().size(); ++i) {
        cout << User::all()[i].is_authenticated();
    }
    return 0;
}
