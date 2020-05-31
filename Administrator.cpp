//
// Created by hulia on 31.5.2020 г..
//

#include <iostream>
#include "Administrator.h"
Administrator::Administrator() :User()
{

}
Administrator::Administrator(std::string nameData, std::string passwordData):User(nameData,passwordData,true)
{

}
Administrator::~Administrator()
{

}

void Administrator::booksAdd(const Book &source, Library &lib)
{
    lib.booksAdd(source);
}

void Administrator::booksRemove(std::string option, Library &lib)
{
    lib.booksRemove(option);
}

void Administrator::userAdd(std::string nameData, std::string passwordData) {
    std::ofstream out;
    out.open("Users.txt");
    if(!out)
    {
        std::cerr<<"Problem opening file"<<std::endl;
        return ;
    }

    out<<nameData<< "|"<<passwordData<<std::endl;
    out.close();

}