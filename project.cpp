#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h>

class Album{
    private:
        static int albumCnt;
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
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<" Invalid input! Please enter a valid format: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        in>>c;
    }
    obj.format = c;

    std::cout<<" Length(minutes): ";
    while(!(in>>obj.length) || obj.length < 0){
        in.clear();
        in.ignore(1000, '\n');
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<" Invalid input! Please enter a valid length: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    in.ignore();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Album& obj){
    out<<" Album #"<<obj.id<<'\n';
    if(obj.title != nullptr)
        out<<" Title: "<<obj.title<<'\n';
    else    
        out<<"\n No title registered!";
    if(obj.bandName != nullptr)
        out<<" Band Name: "<<obj.bandName<<'\n';
    else    
        out<<"\n Band name not registered!";
    if(obj.genre != nullptr)
        out<<" Genre: "<<obj.genre<<'\n';
    else    
        out<<"\n Genre notregistered!";
    out<<" Format: "<<obj.format<<'\n';
    out<<" Length: "<<obj.length<<'\n';
    return out;
}

class Song{
    private:
        static int songCnt;
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

    std::cout<<" Length(minutes): ";
    while(!(in>>obj.length) || obj.length < 0){
        in.clear();
        in.ignore(1000, '\n');
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<" Invalid input! Please enter a valid length: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    in.ignore();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Song& obj){
    out<<" Song #"<<obj.id<<'\n';
    if(obj.name != nullptr)
        out<<" Song: "<<obj.name<<'\n';
    else    
        out<<"\n Song not registered!";
    if(obj.albumName != nullptr)
        out<<" From the Album: "<<obj.albumName<<'\n';
    else    
        out<<"\n Album not registered!";
    if(obj.bandName != nullptr)
        out<<" Band Name: "<<obj.bandName<<'\n';
    else    
        out<<"\n Band name not registered!";
    if(obj.genre != nullptr)
        out<<" Genre: "<<obj.genre<<'\n';
    else    
        out<<"\n Genre not registered!";
    out<<" Length: "<<obj.length<<'\n';
    return out;
}

class Review{
    private:
        static int reviewCnt;
        const int id;
        char* albumName;
        float rating;
        char* date;
        char* text;
        bool recommend;
    
    public:
        Review();
        Review(char* albumName, float rating, char* date, char* text, bool recommend);
        Review(const Review& obj);
        Review& operator=(const Review& obj);
        ~Review();

        friend std::istream& operator>>(std::istream& in, Review& obj);
        friend std::ostream& operator<<(std::ostream& out, const Review& obj);
};

int Review::reviewCnt = 1;

Review::Review() : id(reviewCnt++){
    this->albumName = strcpy(new char[4], "N/A");
    this->rating = 0;
    this->date = strcpy(new char[4], "N/A");
    this->text = strcpy(new char[4], "N/A");
    this->recommend = 0; 
}

Review::Review(char* albumName, float rating, char* date, char* text, bool recommend) : id(reviewCnt++){
    this->albumName = strcpy(new char[strlen(albumName) + 1], albumName);
    this->rating = rating;
    this->date = strcpy(new char[11], date);
    this->text = strcpy(new char[strlen(text) + 1], text);
    this->recommend = recommend;
}

Review::Review(const Review& obj) : id(reviewCnt++){
    this->albumName = strcpy(new char[strlen(obj.albumName) + 1], obj.albumName);
    this->rating = obj.rating;
    this->date = strcpy(new char[11], obj.date);
    this->text = strcpy(new char[strlen(obj.text)+1], obj.text);
    this->recommend = obj.recommend;
}

Review& Review::operator=(const Review& obj){
    if(this == &obj){
        return *this;
    }
    delete[] albumName;
    this->albumName = strcpy(new char[strlen(obj.albumName) + 1], obj.albumName);
    this->rating = obj.rating;
    delete[] date;
    this->date = strcpy(new char[11], obj.date);
    delete[] text;
    this->text = strcpy(new char[strlen(obj.text)+1], obj.text);
    this->recommend = obj.recommend;
    return *this;
}

Review::~Review(){
    delete[] albumName;
    delete[] date;
    delete[] text;
}

std::istream& operator>>(std::istream& in, Review& obj){
    char buffer[256];
    float rating;
    bool ok = false;

    std::cout<<" Album Name: ";
    in.getline(buffer, 256);
    delete[] obj.albumName;
    obj.albumName=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Rating (out of 10): ";
    while(!(in>>rating) || rating < 0 || rating > 10){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<" Invalid input! Please enter a valid rating: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        in.clear();
        in.ignore(1000, '\n');
    }
    in.ignore();
    obj.rating = rating;

    std::cout<<" Date (dd-mm-yyyy): ";
    in.getline(buffer, 256);
    while(buffer[2] != '-' || buffer[5] != '-' || strlen(buffer) != 10){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<" Invalid input! Please enter a valid date: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        in.getline(buffer, 256);
    }
    delete[] obj.date;
    obj.date=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Leave a review: ";
    in.getline(buffer, 256);
    delete[] obj.text;
    obj.text=strcpy(new char[strlen(buffer)+1], buffer);

    std::cout<<" Do you recommend this album? ( Yes / No ): ";
    in.getline(buffer, 256);
    while(!ok){
        strupr(buffer);
        if(strcmp(buffer, "YES") == 0){
            obj.recommend = 1;
            ok = true;
        }
        else if(strcmp(buffer, "NO") ==0){
            obj.recommend = 0;
            ok = true;
        }
        else{
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout<<" Invalid input! Please enter Yes/No: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            in.getline(buffer, 256);
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Review& obj){
    out<<" Review #"<<obj.id<<'\n';
    if(obj.albumName != nullptr)
        out<<" Album Name: "<<obj.albumName<<'\n';
    else    
        out<<"\n Band name not registered!";
    out<<" Rating: "<<obj.rating<<'\n';
    if(obj.date != nullptr)
        out<<" Date: "<<obj.date<<'\n';
    else    
        out<<"\n Date not registered!";
    if(obj.text != nullptr)
        out<<" Review: "<<obj.text<<'\n';
    else    
        out<<"\n No review paragraph registered!";
    out<<" Recommended: ";
    if(obj.recommend== 1)
        out<<"Yes!\n";
    else 
        out<<"No!\n";

    return out;
}

class User{
    private:
        static int userCnt;
        const int id;
        char* name;
        int albumCnt;
        Album* albums[100];
        int songCnt;
        Song* songs[100];
        int reviewCnt;
        Review* reviews[100];
      
    public:
        User();
        User(char* name, int albumCnt, int songCnt, int reviewCnt);
        User(const User& obj);
        User& operator=(const User& obj);
        ~User();

        void addAlbum(Album* p);
        void addSong(Song* p);
        void addReview(Review* p);

        void displayAlbums();
        void displaySongs();
        void displayReviews();
        
        const int getAlbumCnt() const {return albumCnt;}
        const int getSongCnt() const {return songCnt;}
        const int getReviewCnt() const {return reviewCnt;}
        void setAlbumCnt(int cnt) {albumCnt = cnt;}
        void setSongCnt(int cnt) {songCnt = cnt;}
        void setReviewCnt(int cnt) {reviewCnt = cnt;}

        static int getUserCnt();
        const char* getName() const;
        void setName(char* name);
 
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
    this->albumCnt = 0;
    this->songCnt = 0;
    this->reviewCnt = 0;
}

User::User(char* name, int albumCnt, int songCnt, int reviewCnt) : id(userCnt++){
    this->name = strcpy (new char[strlen(name)+1], name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
    this->albumCnt = 0;
    this->songCnt = 0;
    this->reviewCnt = 0;
}

User::User(const User& obj) : id(userCnt++){
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
    this->albumCnt = obj.albumCnt;
    this->songCnt = obj.songCnt;
    this->reviewCnt = obj.reviewCnt;
}

User& User::operator=(const User& obj){
    if(this == &obj){
        return *this;
    }
    delete[] name;
    for(int i=0; i < 100; i++){
        delete albums[i];
        delete songs[i];
        delete reviews[i];
    }
    this->name = strcpy(new char[strlen(obj.name)+1], obj.name);
    for(int i=0; i < 100; i++){ 
        this->albums[i] = nullptr;
        this->songs[i] = nullptr;
        this->reviews[i] = nullptr;
    }
    this->albumCnt = obj.albumCnt;
    this->songCnt = obj.songCnt;
    this->reviewCnt = obj.reviewCnt;

    return *this;
}

User::~User(){
    delete[] name;
    for(int i=0;i<100;i++){
        delete albums[i];
        delete songs[i];
        delete reviews[i];
    }
}

void User::addAlbum(Album* p){
    int cnt = getAlbumCnt();
    if(cnt<100){
        this->albums[cnt] = p;
        setAlbumCnt(++cnt);
    }
    else{
        std::cout<<"Album limit reached!";
        std::cin.get();
        delete p;
    }
}

void User::addSong(Song* p){
    int cnt = getSongCnt();
    if(cnt<100){
        this->songs[cnt] = p;
        setSongCnt(++cnt);
    }
    else{
        std::cout<<"Song limit reached!";
        std::cin.get();
        delete p;
    }
}

void User::addReview(Review* p){
    int cnt = getReviewCnt();
    if(cnt<100){
        this->reviews[cnt] = p;
        setReviewCnt(++cnt);
    }
    else{
        std::cout<<"Review limit reached!";
        std::cin.get();
        delete p;
    }
}

void User::displayAlbums(){
    int cnt = getAlbumCnt();
    if(cnt == 0){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<"This playlist is currently empty!";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cin.get();
        return;
    }
    for(int i = 0; i < cnt; i++)
        std::cout<<*this->albums[i]<<'\n';
    std::cin.get();
}

void User::displaySongs(){
    int cnt = getSongCnt();
    if(cnt == 0){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<"This playlist is currently empty!";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cin.get();
        return;
    }
    for(int i = 0; i < cnt; i++)
        std::cout<<*this->songs[i]<<'\n';
    std::cin.get();
}

void User::displayReviews(){
    int cnt = getReviewCnt();
    if(cnt == 0){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<"No reviews submited yet!";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cin.get();
        return;
    }
    for(int i = 0; i < cnt; i++)
        std::cout<<*this->reviews[i]<<'\n';
    std::cin.get();
}


int User::getUserCnt(){
    return userCnt;
}

const char* User::getName() const{
    return name;
}

void User::setName(char* newName){
    delete[] this->name;
    this->name=strcpy(new char[strlen(newName)+1], newName);
}

std::istream& operator>>(std::istream& in, User& obj){
    char buffer[256];

    std::cout<<"Enter username: ";
    in.getline(buffer, 256);
    delete[] obj.name;
    obj.name=strcpy(new char[strlen(buffer)+1], buffer);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::cout<<"\nNew user registered!";
    std::cin.get();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return in;
}

std::ostream& operator<<(std::ostream& out, const User& obj){
    out<<" User #"<<obj.id<<'\n';
    if(obj.name != nullptr)
        out<<" Name: "<<obj.name<<'\n';
    else{  
        out<<"\n No user registered!";
        std::cin.get();
    }
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
        void userMenu(int index);
        void reviewMenu(int index);
};

Menu::~Menu(){
    for(size_t i = 0; i < users.size(); i++) delete users[i];
}

void Menu::printUsers() const{
    if(users.empty()){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<"No registered users!";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cin.get();
        return;
    }
    for(size_t i = 0; i < users.size(); i++)
        std::cout<<*users[i]<<'\n';
}

int Menu::pickUser() const{
    if(users.empty()){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout<<"No registered users!";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cin.get();
        return -1;
    }
    printUsers();
    std::cout<<"Pick user index (type 0 to cancel): ";
    int index;
    std::cin>>index;
    std::cin.ignore();
    if(index < 1 || index >= (int)users.size()) return -1;
    return index;
}

void Menu::run(){
    while(true){
        std::cout<<"\n---Main Menu---\n\n";
        std::cout<<"0 - Exit\n";
        std::cout<<"1 - Log in\n";
        std::cout<<"2 - Register\n";
        std::cout<<"\nOption: ";

        int option;
        std::cin>>option;
        std::cin.ignore();
        std::cout<<'\n';

        switch(option){
            case 0:{
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                std::cout<<"See you soon!\n\n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
                return;
            case 1:{
                int index = pickUser() + 1; 
                if(index != -1) userMenu(index);
                break;
            }
            case 2:{
                User* p = new User();
                std::cin>>*p;
                users.push_back(p);
                break;
            }
            default:{
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout<<"Invalid option!\n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cin.get();
            }
        }
    }
}

void Menu::userMenu(int index){
    while(true){
        std::cout<<"\n"<<*users[index]<<"\n";
        std::cout<<"0 - Exit\n";
        std::cout<<"1 - Edit username\n";
        std::cout<<"2 - Favorite Songs playlist\n";
        std::cout<<"3 - Favorite Albums playlist\n";
        std::cout<<"4 - Add song to favorites\n";
        std::cout<<"5 - Add album to favorites\n";
        std::cout<<"6 - Reviews\n";
        std::cout<<"\nOption: ";

        int option;
        std::cin>>option;
        std::cin.ignore();
        std::cout<<'\n';

        switch(option){
            case 0:
                return;
            case 1:{
                std::cout<<"New username: ";
                char aux[256];
                std::cin.getline(aux, 256);
                (*users[index]).setName(aux);
                break;
            }
            case 2:{
                std::cout<<"Favorite Songs:\n\n";
                (*users[index]).displaySongs();
                break;
            }
            case 3:{
                std::cout<<"Favorite Albums:\n\n";
                (*users[index]).displayAlbums();
                break;
            }
            case 4:{
                Song* s = new Song();
                std::cin>>*s;
                (*users[index]).addSong(s);
                break;
            }
            case 5:{
                Album* a = new Album();
                std::cin>>*a;
                (*users[index]).addAlbum(a);
                break;
            }
            case 6:{
                reviewMenu(index);
                break;
            }
            default:{
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout<<"Invalid option!\n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cin.get();
            }

        }
    }
}

void Menu::reviewMenu(int index){
    while(true){
        std::cout<<"\n"<<*users[index]<<"\n";
        std::cout<<"0 - Exit\n";
        std::cout<<"1 - Review an album\n";
        std::cout<<"2 - Review log\n";
        std::cout<<"\nOption: ";

        int option;
        std::cin>>option;
        std::cin.ignore();
        std::cout<<'\n';

        switch(option){
            case 0:
                return;
            case 1:{
                std::cout<<"Review:\n\n";
                Review* r = new Review();
                std::cin>>*r;
                (*users[index]).addReview(r);
                break;
            }
            case 2:{
               (*users[index]).displayReviews();
                break;
            }
            default:{
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout<<"Invalid option!\n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }

        }
    }
}

int main(){  

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

    Menu menu;
    menu.run();

    return 0;
}