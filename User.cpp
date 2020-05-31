//
// Created by hulia on 31.5.2020 г..
//

#include "User.h"
User::User() :isAdministrator(false)
{

}

User::User(std::string nameData, std::string passwordData, bool isAdmin):username(nameData),password(passwordData),isAdministrator(isAdmin)
{

}
User::~User()
{

}

void User::booksInfo(int personalNumber, Library &lib)
{
    lib.booksInfo(personalNumber);
}



void User::booksAll(Library &lib)
{
    lib.booksAll();
}

void User::booksSort(std::string option, Library &lib, std::string wayOfSorting)
{
    lib.booksSort(option,wayOfSorting);
}

void User::booksFind(std::string option, std::string value, Library &lib)
{
    lib.booksFind(option,value);
}





