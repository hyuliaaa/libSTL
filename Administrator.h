//
// Created by hulia on 31.5.2020 г..
//

#ifndef LIB_ADMINISTRATOR_H
#define LIB_ADMINISTRATOR_H

#include "User.h"
#include "Book.h"
#include "Library.h"
#include <fstream>
class Administrator: public User {
public:
    Administrator();
    Administrator(std::string nameData, std::string passwordData);
    ~Administrator();

    void booksAdd(const Book& source, Library& lib);
    void userAdd(std::string nameData, std::string passwordData);
    void booksRemove(std::string option, Library& lib);
    void usersRemove(std::string usernameData); //not implemented function
};


#endif //LIB_ADMINISTRATOR_H
