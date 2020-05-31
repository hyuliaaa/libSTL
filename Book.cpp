//
// Created by hulia on 31.5.2020 г..
//

#include "Book.h"
Book::Book()
{

}
Book::Book(std::string authorData, std::string titleData, std::string genreData, std::string descData, int yearData,
           std::string keywordsData, int IDData):author(authorData),title(titleData),genre(genreData),description(descData), yearOfPublishing(yearData),
           keywords(keywordsData),ID(IDData)
{

}

Book::~Book()
{

}

void Book::setAuthorName(std::string authorName)
{
    author=authorName;
}
void Book::setRating(int ratingData)
{
    rating=ratingData;
}
void Book::setYearOfPublishing(int yearData)
{
    yearOfPublishing=yearData;
}

void Book::setID(int idData)
{
    ID=idData;
}

