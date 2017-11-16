//
// Created by Ajat Prabha on 03-10-2017.
//
#include "User.h"

using namespace std;

User::User(string username, string first_name, string last_name)
{
    //filename = "Users.csv";
    _username = move(username);
    _first_name = move(first_name);
    _last_name = move(last_name);
}

string User::get_username()
{
    return _username;
}

bool User::is_anonymous()
{
    return false;
}

bool User::is_authenticated()
{
    return true;
}

string User::get_fullname() const
{
    return _first_name+" "+_last_name;
}

void User::set_password(const string& password)
{
    _password = password;
}

bool User::check_password(const string& raw_password)
{
    return _password==raw_password;
}

User::User()
{
    _username = "guest";
    _first_name = "FGuest";
    _last_name = "LGuest";
}

string User::get_shortname() const
{
    return _first_name;
}
void User::save()
{
    object_list.push_back(*this);
}
std::vector<User> User::all()
{
    return object_list;
}
//bool User::save()
//{
//    outputFile.open(filename, ios::app);
//    outputFile << _username << "," << _first_name << "," << _last_name << "," << _password << std::endl;
//    outputFile.close();
//};

AnonymousUser::AnonymousUser()
{
    _username = "anonymous";
    _first_name = "Anonymous";
    _last_name = "User";
}

bool AnonymousUser::is_anonymous()
{
    return true;
}

bool AnonymousUser::is_authenticated()
{
    return false;
}

void AnonymousUser::set_password(const string& string1)
{
    throw UserError("No set_password method is implemented for Anonymous User");
}

bool AnonymousUser::check_password(const string& raw_password)
{
    throw UserError("No check_password method is implemented for Anonymous User");
}
//bool AnonymousUser::save()
//{
//    throw UserError("An anonymous user can't be saved in database");
//}
string UserError::print_error()
{
    return _err;
}
UserError::UserError(const string& err)
{
    _err = err;
}

