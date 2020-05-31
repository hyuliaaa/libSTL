//
// Created by hulia on 31.5.2020 г..
//

#ifndef LIB_CLIENT_H
#define LIB_CLIENT_H

#include "User.h"


class Client:public User{
public:
    Client();
    Client(std::string nameData, std::string passwordData);
    virtual ~Client();
};


#endif //LIB_CLIENT_H
