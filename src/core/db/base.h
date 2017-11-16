//
// Created by Ajat Prabha on 15-11-2017.
//

#ifndef SMS_BASE_H
#define SMS_BASE_H
#include <climits>
#include <vector>

namespace db {
class Handler {
    static std::vector<Handler> object_list;
public:
    Handler();
    friend class UserManager;
};
}

#endif //SMS_BASE_H
