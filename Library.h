//
// Created by hulia on 31.5.2020 г..
//

#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <cstdlib>
#include <vector>
#include "Book.h"

class Library {
private:
    std::vector <Book> books;

    void makeLowerCase(std::string str);
public:
    Library();
    Library(std::vector <Book> booksData, size_t sz );
    ~Library();

    void booksAll();
    void booksAdd(const Book& other);
    void booksRemove(std::string option);
    void booksInfo(int personalNumber);
    void booksSort(std::string key, std::string wayOfSorting="asc");
    void booksFind(std::string option, std::string value);

    void login();
    void logout();
    void open();
    void close();
    void save();
    void saveas();
    void help() const;
    void exit();


};


#endif //LIB_LIBRARY_H
