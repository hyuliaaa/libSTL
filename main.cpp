#include <iostream>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Client.h"
#include "Administrator.h"

void sampleRun1()
{
    Library lib; //creating a library
    Book b("Thomas Jefferson", "The new Beginning", "horror","a horror story",1875,"horor,story,end",1234);
    Book c("Jared Olsen", "There", "Comedy", "a comedy book about a family",2005,"comedy,love,fun",12353);
    Book d("Carolina Herrera", "Because of You", "romance", "romantic story",3,"love",1111);
    Administrator admin("admin","i<3c++");
    admin.booksAdd(b,lib);
    admin.booksAdd(d,lib);
    admin.booksAdd(c,lib);

    Client e("Elena", "Mavrodieva");
    //e.booksSort("year",lib,"desc");
   // e.booksAll(lib);

    //admin.booksRemove("There",lib);
    //admin.booksAll(lib);
    admin.booksFind("title", "there",lib);

}

void sampleRun2()
{
    //functions connected with files are not fully implemented and not tested
    Library lib;
    Book b("Thomas Jefferson", "The new Beginning", "horror","a horror story",1875,"horor,story,end",1234);
    Book c("Jared Olsen", "There", "Comedy", "a comedy book about a family",2005,"comedy,love,fun",12353);

    Administrator admin("admin","i<3c++");
    admin.booksAdd(b,lib);
    admin.booksAdd(c,lib);
    User elena("Elena","1234",0);
    User maria("Maria", "5678",0);
    std::vector <User> vecUser;
    vecUser.push_back(elena);
    vecUser.push_back(maria);
    vecUser.push_back(admin);
    std::cout<<"Welcome to Library! To see a list of all commands type help:"<<std::endl;
    std::cout<<"> ";
    std::string str;
    std::getline(std::cin,str);
    bool userLoggedIn= false;
    bool isAdmin=false;
    while (str!="exit")
    {
        if(str=="help")
        {
            lib.help();
        }
        else if(str=="login")
        {
            lib.login();
            std::cout<<"Enter your username:"<<std::endl; //assume that the username and password will not contain spaces
            std::cout<<"> ";
            std::string n;
            std::getline(std::cin,n);
            std::cout<<"Enter your password:"<<std::endl;
            std::cout<<"> ";
            std::string p;
            std::getline(std::cin,p);


            for(size_t i=0; i<vecUser.size();i++)
            {

                if(vecUser[i].getUsername()==n && vecUser[i].getPassword()==p)
                {
                    if(n=="admin" && p=="i<3c++")
                    {
                        std::cout<<"Welcome "<<vecUser[i].getUsername()<<" ! You have administrator permissions!"<<std::endl;

                        userLoggedIn= true;
                        break;
                    }
                    else
                        {
                        std::cout << "Welcome " << vecUser[i].getUsername() << " ! " << std::endl;

                        userLoggedIn=true;
                        break;
                    }
                }



            }
            if(userLoggedIn== false)
            {
                std::cout<<"Wrong username or password!"<<std::endl;
            }

        }
        else if(str=="books info <isbn_value>")
        {
            if(userLoggedIn== false )
            {
                std::cout<<"There is no user logged in!"<<std::endl;
                return;

            }
            else
            {
                std::cout<<"Enter an <isbn_value> to view detailed information about a certain book:";
                int isbnVal;
                std::cout<<"> ";
                std::cin>>isbnVal;
                lib.booksInfo(isbnVal);
                std::cin.ignore();
            }
        }
        else if(str=="books all")
        {
            if(userLoggedIn== false)
            {
                std::cout<<"There is no user logged in!"<<std::endl;
            }
            else
                {
                lib.booksAll();
            }
        }
        else if (str=="logout")
        {
          if(userLoggedIn== false)
          {
              std::cout<<"There is no user logged in!"<<std::endl;

          }
          else
          {
              lib.logout();
              userLoggedIn=false;
          }
        }
        else if(str=="books sort <option> [asc|desc]")
        {
            if(userLoggedIn== false)
            {
                std::cout<<"There is no user logged in!"<<std::endl;

            }
            else
            {
                std::cout<<"Enter an option to sort. Available options are title, author,year,rating"<<std::endl;
                std::string option;
                std::getline(std::cin,option);
                std::cout<<"Enter way of sorting. Available are asc for ascending order and desc for descending"<<std::endl;
                std::string sort;
                std::getline(std::cin,sort);
                lib.booksSort(option,sort);


            }
        }
        else if(str=="users add <user> <password>")
        {
            if(userLoggedIn== false )
            {
                std::cout<<"There is no user logged in!"<<std::endl;
                return;

            }
            else if(isAdmin== false && userLoggedIn==true)
            {
                std::cout<<"You do not have administrator permissions"<<std::endl;
            }
            else
            {
                //not tested
                std::cout<<"Enter dada for the new book";
                std::string author, title, genre,description, keywords;
                int year, rating, ID;
                std::getline(std::cin,author);
                std::getline(std::cin,title);
                std::getline(std::cin,genre);
                std::getline(std::cin,description);
                std::getline(std::cin,keywords);
                std::cin>>year;
                std::cin>>rating;
                std::cin>>ID;
                std::cin.ignore();
                Book newBook(author,title,genre,description,year,keywords,ID);
                lib.booksAdd(newBook);
            }



        }
        else if(str=="books find <option> <option_string>")
        {
            if(userLoggedIn== false )
            {
                std::cout<<"There is no user logged in!"<<std::endl;
                return;

            }
            else
            {
                std::cout<<"Enter an option to find a book. Available options are title, author,tag"<<std::endl;
                std::string option;
                std::getline(std::cin,option);
                std::cout<<"Enter an option_string"<<std::endl;
                std::string optStr;
                std::getline(std::cin,optStr);
                lib.booksFind(option,optStr);
            }
        }
        else if(str=="open")
        {
            lib.open();
        }
        else if(str=="save")
        {
            lib.save();
        }
        else if(str=="save as")
        {
            lib.saveas();
        }
        else if(str=="close")
        {
            lib.close();
        }
        else
        {
            std::cout<<"You have entered a wrong command! Try again!"<<std::endl;
        }


        std::cout<<"Choose a new command to execute:"<<std::endl;
        std::cout<<"> ";
        std::getline(std::cin,str);

    }
    lib.exit();


}

int main() {

    //sampleRun1();
    sampleRun2();
    return 0;
}




