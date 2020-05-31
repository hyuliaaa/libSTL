//
// Created by hulia on 31.5.2020 г..
//

#include "Client.h"
Client::Client():User()
{

}

Client::Client(std::string nameData, std::string passwordData):User(nameData,passwordData,false)
{

}
Client::~Client()
{

}