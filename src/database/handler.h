//
// Created by Ajat Prabha on 02-11-2017.
//

#ifndef SMS_HANDLER_H
#define SMS_HANDLER_H

#include <iostream>
#include <fstream>

namespace database {
class handler {
protected:
    std::ofstream outputFile;
    std::string filename = "file.csv";
public:
    handler();
    explicit handler(const std::string& /**/);
    virtual bool save();
    template <class T> T* all();
};
}

#endif //SMS_HANDLER_H
