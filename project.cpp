#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h>

class Album{
    private:
        int static albumCnt;
        const int id;
        char* title;
        char* bandName;
        char* genre;
        char format; // l - long play, e - extended play, s - single
        int length;
        
    public:
        Album();
        Album(char* title, char* bandName, char* genre, char format, int length);
        Album(const Album& obj);
        Album& operator=(const Album& obj);
        ~Album();   

        friend std::istream& operator>>(std::istream& in, Album& obj);
        friend std::ostream& operator<<(std::ostream& out, const Album& obj);
};

int Album::albumCnt = 1;

Album::Album() : id(albumCnt++){
    this->title = strcpy(new char[4], "N/A");
    this->bandName = strcpy(new char[4], "N/A");
    this->genre = strcpy(new char[4], "N/A");
    this->format = '-';
    this->length = 0;
}

Album::Album(char* title, char* bandName, char* genre, char format, int length) : id(albumCnt++) {
    this->title = strcpy(new char[strlen(title) + 1], title);
    this->bandName = strcpy(new char[strlen(bandName) + 1], bandName);
    this->genre = strcpy(new char[strlen(genre) +1], genre);
    this->format= format;
    this->length= length;    
}

Album::Album(const Album &obj) : id(albumCnt++) {
    this->title = strcpy(new char[strlen(obj.title) + 1], obj.title);
    this->bandName = strcpy(new char[strlen(obj.bandName)+1], obj.bandName);
    this->genre = strcpy(new char[strlen(obj.genre)+1], obj.genre);
    this->format = obj.format;
    this->length = obj.length;
}

Album& Album::operator=(const Album& obj) {
    if (this == &obj) {
        return *this;
    }
    delete[] this->title;
    this->title = strcpy(new char[strlen(obj.title)+1],obj.title);
    delete[] this->bandName;
    this->bandName = strcpy(new char[strlen(obj.bandName)+1],obj.bandName);
    delete[] this->genre;
    this->genre = strcpy(new char[strlen(obj.genre)+1],obj.genre);
    this->format = obj.format;
    this->length = obj.length;
    return *this;
}

Album::~Album(){
    delete[] title;
    delete[] bandName;
    delete[] genre;
}

std::istream& operator>>(std::istream& in, Album& obj){
    char buffer[256];
    char c;

    std::cout<<" Title: ";
    in.getline(buffer, 256);
    delete[] obj.title;
    obj.title=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Band Name: ";
    in.getline(buffer, 256);
    delete[] obj.bandName;
    obj.bandName=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Genre: ";
    in.getline(buffer, 256);
    delete[] obj.genre;
    obj.genre=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Format ( l - long play, e - extended play, s - single): ";
    in>>c;
    in.ignore();
    while(c != 'l' && c != 'e' && c !='s'){
        std::cout<<" Invalid input! Try again: ";
        in>>c;
    }
    obj.format = c;

    std::cout<<" Length: ";
    in>>obj.length;
    in.ignore();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Album& obj){
    out<<" Album #"<<obj.id<<'\n';
    if(obj.title != nullptr)
        out<<" Title: "<<*obj.title<<'\n';
    else    
        out<<"\n No title registered!";
    if(obj.bandName != nullptr)
        out<<" Band Name: "<<*obj.bandName<<'\n';
    else    
        out<<"\n Band name not registered!";
    if(obj.title != nullptr)
        out<<" Genre: "<<*obj.genre<<'\n';
    else    
        out<<"\n Genre notregistered!";
    out<<" Format: "<<obj.format<<'\n';
    out<<" Length: "<<obj.length<<'\n';
    return out;
}

class Song{
    private:
        int static songCnt;
        const int id;
        char* name;
        char* albumName;
        char* bandName;
        char* genre;
        int length;
        
    public:
        Song();
        Song(char* name, char* albumName, char* bandName, char* genre, int length);
        Song(const Song& obj);
        Song& operator=(const Song& obj);
        ~Song();
        
        
        friend std::istream& operator>>(std::istream& in, Song& obj);
        friend std::ostream& operator<<(std::ostream& out, const Song& obj);
};

int Song::songCnt = 1;

Song::Song() : id(songCnt++){
    this->name = strcpy(new char[4], "N/A");
    this->albumName = strcpy(new char[4], "N/A");
    this->bandName = strcpy(new char[4], "N/A");
    this->genre = strcpy(new char[4], "N/A");
    this->length = 0;
}

Song::Song(char* name, char* albumName, char* bandName, char* genre, int length) : id(songCnt++){
    this->name = strcpy(new char[strlen(name) + 1], name);
    this->albumName = strcpy(new char[strlen(albumName) + 1], albumName);
    this->bandName = strcpy(new char[strlen(bandName) + 1], bandName);
    this->genre = strcpy(new char[strlen(genre) + 1], genre);
    this->length = length;
}

Song::Song(const Song& obj) : id(songCnt++){
    this->name = strcpy(new char[strlen(obj.name) + 1], obj.name);
    this->albumName = strcpy(new char[strlen(obj.albumName) + 1], obj.albumName);
    this->bandName = strcpy(new char[strlen(obj.bandName) + 1], obj.bandName);
    this->genre = strcpy(new char[strlen(obj.genre) + 1], obj.genre);
    this->length = obj.length;
}

Song& Song::operator=(const Song& obj){
    if(this == &obj){
        return *this;
    }
    delete[] name;
    this->name = strcpy(new char[strlen(obj.name) + 1], obj.name);
    delete[] albumName;
    this->albumName = strcpy(new char[strlen(obj.albumName) + 1], obj.albumName);
    delete[] bandName;
    this->bandName = strcpy(new char[strlen(obj.bandName) + 1], obj.bandName);
    delete[] genre;
    this->genre = strcpy(new char[strlen(obj.genre) + 1], obj.genre);
    this->length = obj.length;
    return *this;
}

Song::~Song(){
    delete[] name;
    delete[] albumName;
    delete[] bandName;
    delete[] genre;
}

std::istream& operator>>(std::istream& in, Song& obj){
    char buffer[256];

    std::cout<<" Song: ";
    in.getline(buffer, 256);
    delete[] obj.name;
    obj.name=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" From the Album: ";
    in.getline(buffer, 256);
    delete[] obj.albumName;
    obj.albumName=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Band Name: ";
    in.getline(buffer, 256);
    delete[] obj.bandName;
    obj.bandName=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Genre: ";
    in.getline(buffer, 256);
    delete[] obj.genre;
    obj.genre=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Length: ";
    in>>obj.length;
    in.ignore();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Song& obj){
    out<<" Song #"<<obj.id<<'\n';
    if(obj.name != nullptr)
        out<<" Song: "<<*obj.name<<'\n';
    else    
        out<<"\n Song not registered!";
    if(obj.albumName != nullptr)
        out<<" From the Album: "<<*obj.albumName<<'\n';
    else    
        out<<"\n Album not registered!";
    if(obj.bandName != nullptr)
        out<<" Band Name: "<<*obj.bandName<<'\n';
    else    
        out<<"\n Band name not registered!";
    if(obj.genre != nullptr)
        out<<" Genre: "<<*obj.genre<<'\n';
    else    
        out<<"\n Genre not registered!";
    out<<" Length: "<<obj.length<<'\n';
    return out;
}

class Review{
    private:
        int static reviewCnt;
        const int id;
        float rating;
        char* date;
        char* text;
        bool recommend;
    
    public:
        Review();
        Review(float rating, char* date, char* text, bool recommend);
        Review(const Review& obj);
        Review& operator=(const Review& obj);
        ~Review();

        friend std::istream& operator>>(std::istream& in, Review& obj);
        friend std::ostream& operator<<(std::ostream& out, const Review& obj);
};

int Review::reviewCnt = 1;

Review::Review() : id(reviewCnt++){
    this->rating = 0;
    this->date = strcpy(new char[4], "N/A");
    this->text = strcpy(new char[4], "N/A");
    this->recommend = 0; 
}

Review::Review(float rating, char* date, char* text, bool recommend) : id(reviewCnt){
    this->rating = rating;
    this->date = strcpy(new char[11], date);
    this->text = strcpy(new char[strlen(text) + 1], text);
    this->recommend = recommend;
}

Review::Review(const Review& obj) : id(reviewCnt){
    this->rating = obj.rating;
    this->date = strcpy(new char[11], obj.date);
    this->text = strcpy(new char[strlen(obj.text)+1], obj.text);
    this->recommend = obj.recommend;
}

Review& Review::operator=(const Review& obj){
    if(this == &obj){
        return *this;
    }
    this->rating = obj.rating;
    delete[] date;
    this->date = strcpy(new char[11], obj.date);
    delete[] text;
    this->text = strcpy(new char[strlen(obj.text)+1], obj.text);
    return *this;
}

Review::~Review(){
    delete[] date;
    delete[] text;
}

std::istream& operator>>(std::istream& in, Review& obj){
    char buffer[256];
    float rating;
    bool ok;

    std::cout<<" Rating (out of 10): ";
    in>>rating;
    in.ignore();
    while(rating < 0 || rating > 10){
        std::cout<<" Invalid input! Try again: ";
        in>>rating;
        in.ignore();
    }
    obj.rating = rating;

    std::cout<<" Date (dd-mm-yyyy): ";
    in.getline(buffer, 256);
    while(buffer[2] != '-' || buffer[5] != '-' || buffer[0] > 3 || buffer[3]>1 || strlen(buffer) != 10){
        std::cout<<" Invalid input! Try again: ";
        in.getline(buffer, 256);
    }
    delete[] obj.date;
    obj.date=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Leave a review: ";
    in.getline(buffer, 256);
    delete[] obj.date;
    obj.date=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Do you recommend this album? ( Yes / No ): ";
    in.getline(buffer, 256);
    while(ok == 0){
        strupr(buffer);
        if(strcmp(buffer, "YES") == 0){
            obj.recommend = 1;
            ok = 1;
        }
        else if(strcmp(buffer, "NO") ==0){
            obj.recommend = 0;
            ok = 1;
        }
        else{
            std::cout<<" Invalid input! Try again: ";
            in.getline(buffer, 256);
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Review& obj){
    out<<" Review #"<<obj.id<<'\n';
    out<<" Rating: "<<obj.rating<<'\n';
    if(obj.date != nullptr)
        out<<" Date: "<<*obj.date<<'\n';
    else    
        out<<"\n Band name not registered!";
    if(obj.text != nullptr)
        out<<" Review: "<<*obj.text<<'\n';
    else    
        out<<"\n No review paragraph registered!";
    out<<" Recommended: ";
    if(obj.recommend== 1)
        out<< " Yes!\n";
    else 
        out<< " No!\n";

    return out;
}

class User{
    private:
        int static userCnt;
        const int id;
        char* name;
        Album* albums[100];
        Song* songs[100];
        Review* reviews[100];
      
    public:
        User();
        User(char* name);
        User(const User& obj);
        User& operator=(const User& obj);
        ~User();
 
        friend std::istream& operator>>(std::istream& in, User& obj);
        friend std::ostream& operator<<(std::ostream& out, const User& obj);
};

int User::userCnt = 1;

User::User() : id(userCnt++){
    this->name = strcpy(new char[4], "N/A");
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    } 
}

User::User(char* name) : id(userCnt++){
    this->name = strcpy (new char[strlen(name)+1], name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
}

User::User(const User& obj) : id(userCnt++){
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
}

User& User::operator=(const User& obj){
    if(this == &obj){
        return *this;
    }
    delete[] name;
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
    return *this;
}

User::~User(){
    delete[] name;
}

std::istream& operator>>(std::istream& in, User& obj){
    char buffer[256];

    std::cout<<" Username: ";
    in.getline(buffer, 256);
    delete[] obj.name;
    obj.name=strcpy(new char[strlen(buffer)+1], buffer);

    return in;
}

std::ostream& operator<<(std::ostream& out, const User& obj){
    out<<" User #"<<obj.id<<'\n';
    if(obj.name != nullptr)
        out<<" Title: "<<*obj.name<<'\n';
    else    
        out<<"\n No title registered!";
  
    return out;
}

class Menu{
    private:
        std::vector<User*> users;
        
        void printUsers() const;
        int pickUser() const;

    public:
        Menu() = default;
        ~Menu();
        void run();
        void logIn();
        void userMenu();
};

Menu::~Menu(){
    for(size_t i = 0; i < users.size(); i++) delete users[i];
}

void Menu::printUsers() const{
    if(users.empty()){
        std::cout<<" No registered users!\n";
        return;
    }
    for(size_t i = 0; i < users.size(); i++)
        std::cout<<" "<<i<<". "<<users[i]<<'\n';
}

int Menu::pickUser() const{
    if(users.empty()){
        std::cout<<" No registered users!\n";
        return -1;
    }
    printUsers();
    std::cout<<" Pick user index (type -1 to cancel): ";
    int index;
    std::cin>>index;
    std::cin.ignore();
    if(index < 0 || index >= (int)users.size()) return -1;
    return index;
}

void Menu::run(){
    while(true){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<R"(                                                                         
                                                                                                       $$$$$$"
             __       __      .______    __    __  .___  ___.                                        3$$$$$"
           /   \     |  |     |   _  \  |  |  |  | |   \/   |                                       z$$$$P
          /  ^  \    |  |     |  |_)  | |  |  |  | |  \  /  |                                      d$$$$"
         /  /_\  \   |  |     |   _  <  |  |  |  | |  |\/|  |                                    .$$$$$"
        /  _____  \  |  `----.|  |_)  | |  `--'  | |  |  |  |                                   z$$$$$"
       /__/     \__\ |_______||______/   \______/  |__|  |__|                                  z$$$$P
                                                                                             d$$$$$$$$$$"
        .______       ___________    ____  __   ___________    __    ____   _______.        *******$$$"
        |   _  \     |   ____\   \  /   / |  | |   ____\   \  /  \  /   /  /       |             .$$$"
        |  |_)  |    |  |__   \   \/   /  |  | |  |__   \   \/    \/   /  |   (----`            .$$"
        |      /     |   __|   \      /   |  | |   __|   \            /    \   \               4$P"
        |  |\  \----.|  |____   \    /    |  | |  |____   \    /\    / .----)   |             z$"
        | _| `._____||_______|   \__/     |__| |_______|   \__/  \__/  |_______/             zP
                                                                                            z"
                                                                                           /
        )";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        
        std::cout<<" Main Menu\n\n";
        std::cout<<"0 - Exit\n";
        std::cout<<"1 - Log in\n";
        std::cout<<"2 - Register\n";
        std::cout<<"Option: ";

        int option;
        std::cin>>option;
        std::cin.ignore();

        switch(option){
            case 0:
                std::cout<<"See you soon!\n";
                return;
            case 1:
                pickUser();
                break;
            case 2:{
                User* p = new User();
                std::cin>>*p;
                users.push_back(p);
                std::cout<<"New user registered!";
                break;
            }
            default:
                std::cout<<"Invalid option!\n";
        }
    }
}

int main(){  
    Menu menu;
    menu.run();
    return 0;
}