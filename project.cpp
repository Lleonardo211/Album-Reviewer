#include <iostream>
#include <cstring>
using namespace std;

class Album{
    private:
        int static albumCnt;
        const int id;
        char * title;
        char * bandName;
        char * genre;
        int length;
        
    public:
        Album(char * title, char * bandName, char * genre, int length);
        ~Album();   
};

Album::Album(char * title, char * bandName, char * genre, int length) : id(albumCnt++) {
    this->title = new char[strlen(title) + 1];
    this->bandName = new char[strlen(bandName) + 1];
    this->genre = new char[strlen(genre) +1];

    strcpy(this->title,title);
    strcpy(this->bandName,bandName);
    strcpy(this->genre,genre);

    this->length=length;    
}

int Album::albumCnt=1;

Album::~Album(){
    delete[] title;
    delete[] bandName;
    delete[] genre;
}

int main(){
    
    return 0;
}