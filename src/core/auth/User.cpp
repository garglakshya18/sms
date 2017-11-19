//
// Created by Ajat Prabha on 03-10-2017.
//
#include "User.h"

static map<string, User> object_list = {};
User::User(string& username, string& first_name, string& last_name)
{
    _username = username;
    _first_name = first_name;
    _last_name = last_name;
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
    object_list.insert(pair<string, User>(this->get_username(), *this));
}
map<string, User> User::all()
{
    return object_list;
}
void User::set_username(const string& username)
{
    _username = username;
}
User::User(const char* username, const char* first_name, const char* last_name)
{
    _username = username;
    _first_name = first_name;
    _last_name = last_name;
}

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

void AnonymousUser::set_password(const string& /* unused */)
{
    throw UserError("No set_password method is implemented for Anonymous User");
}
bool AnonymousUser::check_password(const string& /* unused */)
{
    throw UserError("No check_password method is implemented for Anonymous User");
}
string UserError::print_error()
{
    return _err;
}
UserError::UserError(const string& err)
{
    _err = err;
}

