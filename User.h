//
// Created by hulia on 31.5.2020 г..
//

#ifndef LIB_USER_H
#define LIB_USER_H

#include "Book.h"
#include "Library.h"

class User {
private:
    std::string username;
    std::string password;
    bool isAdministrator;
public:
    User();
    User(std::string nameData, std::string passwordData, bool isAdmin);
    virtual ~User();

    std::string getUsername() const { return username;}
    std::string getPassword()const { return password;}


    virtual void booksInfo(int personalNumber, Library& lib);
    virtual void booksAll(Library& lib);
    void booksSort(std::string option, Library& lib,std::string wayOfSorting="asc"); //this function is not virtual because my IDE was telling me that default arguments on virtual methods are prohibited
    virtual void booksFind(std::string option, std::string value, Library& lib);


};


#endif //LIB_USER_H
