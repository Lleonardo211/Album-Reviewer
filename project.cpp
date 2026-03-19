#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

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
};

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

class User{
    private:
        int static userCnt;
        const int id;
        char* name;
        Album* albumLog;
        Song* songLog;
        Review* reviews;
      
    public:
        User();
        User(char* name);
        User(const User& obj);
        User& operator=(const User& obj);
        ~User();
};

User::User() : id(userCnt++){
    this->name = strcpy(new char[4], "N/A");
    this->albumLog = nullptr;
    this->songLog = nullptr;
    this->reviews = nullptr; 
}

User::User(char* name) : id(userCnt++){
    this->name = strcpy (new char[strlen(name)+1], name);
    this->albumLog = nullptr;
    this->songLog = nullptr;
    this->reviews = nullptr;
}

User::User(const User& obj) : id(userCnt++){
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    this->albumLog = nullptr;
    this->songLog = nullptr;
    this->reviews = nullptr;
}

User& User::operator=(const User& obj){
    if(this == &obj){
        return *this;
    }
    delete[] name;
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    this->albumLog = nullptr;
    this->songLog = nullptr;
    this->reviews = nullptr;
    return *this;
}

User::~User(){
    delete[] albumLog;
    delete[] songLog;
    delete[] reviews;
}

int main(){  
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
cout<<R"(   
                                                                                                
                                                                                               $$$$$$"
      __       __      .______    __    __  .___  ___.                                        3$$$$$"
    /   \     |  |     |   _  \  |  |  |  | |   \/   |                                       z$$$$P
   /  ^  \    |  |     |  |_)  | |  |  |  | |  \  /  |                                      d$$$$"
  /  /_\  \   |  |     |   _  <  |  |  |  | |  |\/|  |                                    .$$$$$"
 /  _____  \  |  `----.|  |_)  | |  `--'  | |  |  |  |                                   z$$$$$"
/__/     \__\ |_______||______/   \______/  |__|  |__|                                  z$$$$P
                                                                                       d$$$$$$$$$$"
.______       ___________    ____  __   ___________    __    ____   _______.          *******$$$"
|   _  \     |   ____\   \  /   / |  | |   ____\   \  /  \  /   /  /       |              .$$$"
|  |_)  |    |  |__   \   \/   /  |  | |  |__   \   \/    \/   /  |   (----`             .$$"
|      /     |   __|   \      /   |  | |   __|   \            /    \   \                4$P"
|  |\  \----.|  |____   \    /    |  | |  |____   \    /\    / .----)   |              z$"
| _| `._____||_______|   \__/     |__| |_______|   \__/  \__/  |_______/              zP
                                                                                     z"
                                                                                    /

)";
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 0;
}