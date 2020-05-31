//
// Created by hulia on 31.5.2020 г..
//

#ifndef LIB_BOOK_H
#define LIB_BOOK_H

#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string genre;
    std::string description;
    int yearOfPublishing;
    std::string keywords;
    int rating;
    int ID;

public:
    Book();
    Book(std::string authorData, std::string titleData, std::string genreData, std::string descData, int yearData, std::string keywordsData, int IDData);
    ~Book();


    std::string getAuthor()const{ return author;}
    std::string getTitle()const{return title;}
    std::string getGenre()const { return  genre;}
    std::string getDescription()const { return description;}
    int getYearOfPublishing()const { return yearOfPublishing;}
    std::string getKeyWords()const { return  keywords;}
    int getRating()const { return rating;}
    int getID()const { return ID;}


    void setAuthorName(std::string authorName);
    void setYearOfPublishing(int yearData);
    void setRating(int ratingData);
    void setID(int idData);



};


#endif //LIB_BOOK_H
