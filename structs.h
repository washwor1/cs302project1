//pulled these structs from the lab writeup and added a couple constructors to make life easier 

#include <iostream>
#include <map>

using namespace std;

struct Song { 
    string title;
    int time;  // could also be a string
    int track;
};

struct Album {
    map <int, Song > songs;
    string name;
    int time;
    int nsongs;  // optional variable but makes it easier
    Album() {
        time =0;
    }
};

struct Artist {
    map <string, Album > albums;
    string name;
    int time;
    int nsongs;
    Artist() {
        time = 0;
        nsongs=0;
    }
};