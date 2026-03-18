#include <iostream>
#include <cstring>
#include <windows.h>
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
        Album();
        Album(char * title, char * bandName, char * genre, int length);
        Album(const Album&);
        Album& operator=(const Album& obj);
        ~Album();   
};

int Album::albumCnt=1;

Album::Album() : id(albumCnt++){
    this->title = strcpy(new char[4], "N/A");
    this->bandName = strcpy(new char[4], "N/A");
    this->genre = strcpy(new char[4], "N/A");
    this->length=0;
}

Album::Album(char * title, char * bandName, char * genre, int length) : id(albumCnt++) {
    this->title = strcpy(new char[strlen(title) + 1], title);
    this->bandName = strcpy(new char[strlen(bandName) + 1], bandName);
    this->genre = strcpy(new char[strlen(genre) +1], genre);
    this->length=length;    
}

Album::~Album(){
    delete[] title;
    delete[] bandName;
    delete[] genre;
}

Album::Album(const Album &obj) : id(albumCnt++) {
    this->title = strcpy(new char[strlen(obj.title) + 1], obj.title);
    this->bandName = strcpy(new char[strlen(obj.bandName)+1], obj.bandName);
    this->genre = strcpy(new char[strlen(obj.genre)+1], obj.genre);
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
    this->length=obj.length;
    return *this;
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