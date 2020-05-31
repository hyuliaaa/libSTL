//
// Created by hulia on 31.5.2020 г..
//

#include <iostream>
#include "Library.h"
#include <algorithm>
#include <cstring>
#include <fstream>

void Library::makeLowerCase(std::string str)
{

    for(int i=0; str[i];i++)
    {
        tolower(str[i]);
    }
}
Library::Library()
{

}
Library::Library(std::vector<Book> booksData, size_t sz)
{
    for(int i=0; i<sz;i++)
    {
        books[i]=booksData[i];
    }
}
Library::~Library()
{

}

void Library::booksAll()
{
    for(size_t i=0; i<books.size();i++)
    {
        std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
        std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
        std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
        std::cout<<"ID: "<<books[i].getID()<<std::endl;
        std::cout<<std::endl;

    }
}

void Library::booksAdd(const Book& other)
{
    books.push_back(other);
}

void Library::booksRemove(std::string bookTitle) //deletes an book by title
{

    for(int i=0; i<books.size();i++)
    {
        if(books[i].getTitle()==bookTitle)
        {
            books.erase(books.begin()+i); //removes an element at a certain position in a vector
        }
    }
}

void Library::booksInfo(int personalNumber)
{
    bool isBookfound= false;
    for(size_t i=0; i<books.size();i++)
    {
        if(books[i].getID()==personalNumber)
        {
            std::cout<<"Detailed information about book with ID: "<<books[i].getID() <<std::endl;
            std::cout<<"Author:"<<books[i].getAuthor()<<std::endl;
            std::cout<<"Title:"<<books[i].getTitle()<<std::endl;
            std::cout<<"Genre:"<<books[i].getGenre()<<std::endl;
            std::cout<<"Short description:"<<books[i].getDescription()<<std::endl;
            std::cout<<"Year of publishing:"<<books[i].getYearOfPublishing()<<std::endl;
            std::cout<<"Rating:"<< books[i].getRating()<<std::endl;
            isBookfound=true;
            return;
        }
    }
    if(isBookfound== false)
    {
        std::cout<<"Book with that <isbn_value> does not exist!"<<std::endl;
    }
}

void Library::booksSort(std::string option, std::string wayOfSorting)
{
    if(option=="title")//TODO:find a way to sort the title in alphabetical order , write an algorithm different than bubble or insertion sort
    {
        if(wayOfSorting=="desc")
        {

                int k=0;
                bool hasKIncreasedInWhile=false;
                for(size_t i=0; i<books.size()-1;i++)
                {

                    for(size_t j=0; j<books.size()-i-1;j++)
                    {

                        while(books[j].getTitle()[k]<books[j+1].getTitle()[k])
                        {
                            Book temp;
                            temp=books[j];
                            books[j]=books[j+1];
                            books[j+1]=temp;
                        }
                        k++;
                    }


                }




        }
        else
        {

        }
    }
    else if(option=="author")
    {
        if(wayOfSorting=="desc")
        {

        }
        else
        {

        }
    }
    else if(option=="year")
    {
        if(wayOfSorting=="desc")
        {
            for(size_t i=0; i<books.size()-1;i++)
            {

                for(size_t j=0; j<books.size()-i-1;j++)
                {
                    if(books[j].getYearOfPublishing()<books[j+1].getYearOfPublishing())
                    {
                        Book temp;
                        temp=books[j];
                        books[j]=books[j+1];
                        books[j+1]=temp;
                    }
                }


            }

        }
        else
        {

            for(size_t i=0; i<books.size()-1;i++)
            {

                for(size_t j=0; j<books.size()-i-1;j++)
                {
                    if(books[j].getYearOfPublishing()>books[j+1].getYearOfPublishing())
                    {
                        Book temp;
                        temp=books[j];
                        books[j]=books[j+1];
                        books[j+1]=temp;
                    }
                }


            }
        }

    }
    else if(option=="rating")
    {
        if(wayOfSorting=="desc")
        {
            for(size_t i=0; i<books.size()-1;i++)
            {

                for(size_t j=0; j<books.size()-i-1;j++)
                {
                    if(books[j].getRating()<books[j+1].getRating())
                    {
                        Book temp;
                        temp=books[j];
                        books[j]=books[j+1];
                        books[j+1]=temp;
                    }
                }

            }

        }
        else
        {

            for(size_t i=0; i<books.size()-1;i++)
            {

                for(size_t j=0; j<books.size()-i-1;j++)
                {
                    if(books[j].getRating()>books[j+1].getRating())
                    {
                        Book temp;
                        temp=books[j];
                        books[j]=books[j+1];
                        books[j+1]=temp;
                    }
                }

            }
        }
    }


}


void Library::booksFind(std::string option, std::string value)
{

    if(option=="title")
    {
        for(int i=0; i<books.size();i++)
        {

            if(value==books[i].getTitle())
            {
                std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
                std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
                std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
                std::cout<<"ID: "<<books[i].getID()<<std::endl;
                std::cout<<std::endl;
                return;
            }
        }
    }
    else if(option=="author")
    {
        for(size_t i=0; i<books.size();i++)
        {

            if(value==books[i].getAuthor())
            {
                std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
                std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
                std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
                std::cout<<"ID: "<<books[i].getID()<<std::endl;
                std::cout<<std::endl;
                return;
            }
        }
    }
    else if(option=="tag") //TODO:t
    {
        for(size_t i=0; i<books.size();i++)
        {

            //looks for tag amongst the titles
            for(size_t j=0; j<books[i].getTitle().size(); j++)
            {
                char *valueArray=new char[value.size()+1];
                int k=0;
                int l=j;
                int len=value.size();
                while(len)
                {
                    valueArray[k]=books[i].getTitle()[j];
                    k++;
                    j++;
                    len--;
                }
                valueArray[k]='\0';
                j=l;
                if(value==valueArray)
                {
                    std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
                    std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
                    std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
                    std::cout<<"ID: "<<books[i].getID()<<std::endl;
                    std::cout<<std::endl;
                    return;
                }
            }
            //looks for tag amongst genres
            for(size_t j=0; j<books[i].getGenre().size(); j++)
            {
                char *valueArray=new char[value.size()+1];
                int k=0;
                int l=j;
                int len=value.size();
                while(len)
                {
                    valueArray[k]=books[i].getGenre()[j];
                    k++;
                    j++;
                    len--;
                }
                valueArray[k]='\0';
                j=l;
                if(value==valueArray)
                {
                    std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
                    std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
                    std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
                    std::cout<<"ID: "<<books[i].getID()<<std::endl;
                    std::cout<<std::endl;
                    return;
                }
            }
            //amongst keywords
            for(size_t j=0; j<books[i].getKeyWords().size(); j++)
            {

                char *valueArray=new char[value.size()+1];
                int k=0;
                int l=j;
                int len=value.size();
                while(len)
                {
                    valueArray[k]=books[i].getKeyWords()[j];
                    k++;
                    j++;
                    len--;
                }
                valueArray[k]='\0';
                j=l;
                if(value==valueArray)
                {
                    std::cout<<"Title: "<< books[i].getTitle()<<std::endl;
                    std::cout<<"Author: "<<books[i].getAuthor()<<std::endl;
                    std::cout<<"Genre: "<<books[i].getGenre()<<std::endl;
                    std::cout<<"ID: "<<books[i].getID()<<std::endl;
                    std::cout<<std::endl;
                    return;
                }
            }
        }
    }

    std::cout<<"The book you are looking for cannot be found"<<std::endl;

}

void Library::login()
{

}

void Library::logout()
{
    std::cout<<"You have logged out of the system successfully!"<<std::endl;
}


void Library::open()
{
    std::ifstream inFile; //creating an object of type ifstream, to be able to read from that file
    inFile.open("Books.txt"); //trying to open the file;
    if(!inFile) //if the file could not be opened it means that it doesn't exist or it has a problem opening it, so I decided to create a new file
    {
        std::ofstream outFile; //creating a new empty file of type ofstream to be able to write to that file
        outFile.open("Books.txt");
        if(!outFile)
        {
            std::cerr<<"Problem opening the file"<<std::endl;
        }
        std::cout<<"Successfully opened Books.txt"<<std::endl;
        outFile.close();

    }
    std::cout<<"Successfully opened Books.txt"<<std::endl;
    inFile.close();

}
void Library::save() //TODO:complete
{
    std::ofstream outFile;
    outFile.open("Books.txt");
    if(!outFile)
    {
        std::cerr<<"Problem opening the file";
    }
    std::cout<<"Successfully opened Books.txt"<<std::endl;





}

void Library::saveas() //TODO:complete
{
    std::ofstream outFile;
    outFile.open("Books.txt");
    if(!outFile)
    {
        std::cerr<<"Problem opening the file"<<std::endl;
    }


    //TODO::make some changes

    std::string newFileName;
    std::cout<<">saveas ";
    std::cin>>newFileName;



}


void Library::close()
{
    //TODO:must clear the newly loaded information
    std::cout<<"Successfully closed Books.txt"<<std::endl;
}

void Library::help() const
{
    std::cout<<"The following commands are supported:"<<std::endl;
    std::cout<<"open <file>	                                             opens <file>"<<std::endl;
    std::cout<<"close			                                         closes currently opened file"<<std::endl;
    std::cout<<"save			                                         saves the currently open file"<<std::endl;
    std::cout<<"saveas <file>	                                         saves the currently open file in <file>"<<std::endl;
    std::cout<<"help			                                         prints this information"<<std::endl;
    std::cout<<"exit                                                     exits the program"<<std::endl;
    std::cout<<"login                                                    log in to the system"<<std::endl;
    std::cout<<"logout                                                   user logs out the system"<<std::endl;
    std::cout<<"books all                                                gives sequential information about book's:title, author,genre, personal number"<<std::endl;
    std::cout<<"books info <isbn_value>                                  gives detailed information about a book with <isbn_value>"<<std::endl;
    std::cout<<"books find <option> <option_string>                      finds a book by given criteria"<<std::endl;
    std::cout<<"books sort <option> [asc | desc]                         sorts the books"<<std::endl;
    std::cout<<"users add <user> <password>                              add a user with username and password"<<std::endl;
    std::cout<<"users remove                                             deletes user with name <user>"<<std::endl;
}


void Library::exit()
{
    std::cout<<"Exiting the program..."<<std::endl;
    ::exit(0); // the exit function is defined in stdlib library and indicates exit success when having 0 as a parameter

}




