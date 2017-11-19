//
// Created by Ajat Prabha on 03-10-2017.
//
#ifndef SMS_USER_H
#define SMS_USER_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class UserError {
private:
    string _err;
public:
    explicit UserError(const string&);

    string print_error();
};


class User {
    static map<string, User> object_list;
protected:
    string _username, _first_name, _last_name, _password;
public:
    User();

    User(string&, string&, string&);

    User(const char*, const char*, const char*);

    static map<string, User> all();

    string get_username();

    virtual bool is_anonymous();

    virtual bool is_authenticated();

    string get_fullname() const;

    string get_shortname() const;

    void set_username(const string& /* unused */);

    virtual void set_password(const string&);

    virtual bool check_password(const string&);

    void save();
};

class AnonymousUser: public User {
public:
    AnonymousUser();

    bool is_anonymous() override;

    bool is_authenticated() override;

    void set_password(const string& /*unused*/) override;

    bool check_password(const string& /*unused*/) override;
};

#endif //SMS_USER_H
