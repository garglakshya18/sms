//
// Created by Ajat Prabha on 02-11-2017.
//

#include "handler.h"
bool database::handler::save()
{
    return false;
}

database::handler::handler(const std::string& _filename)
{
    filename = _filename + ".csv";
}
database::handler::handler()
{
    filename = "NULL";
}
template<class T>
T* database::handler::all()
{
    return nullptr;
}
