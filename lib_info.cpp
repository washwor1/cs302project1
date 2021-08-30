//Walter Ashworth and Andy Zeng

#include "structs.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void output(const map<string,Artist> &Artists);

int main(int argc, char *argv[]) {
    map<string,Artist> Artists;
    vector<string> line(6);
    ifstream file;
    unsigned int minutes, seconds;
    file.open(argv[1], ifstream::in);


    /* Reference for line:
    0 is Song Name
    1 is Song Length
    2 is Artist Name
    3 is Album Name
    4 is Genre
    5 is Song Position in Album*/
    
    while(file>>line.at(0)>>line.at(1)>>line.at(2)>>line.at(3)>>line.at(4)>>line.at(5)) {
        for(int i = 0; i<6;++i) {
            replace(line[i].begin(), line[i].end(), '_', ' ');
        }
        Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].title = line.at(0);
        sscanf(line.at(1).c_str(), "%2d:%2d", &minutes, &seconds);
        Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].time = (minutes*60+seconds);
        
    }
    

    return 0;
}

void output(map<string,Artist> &Artists) {
    for(map<string,Artist>::iterator i = Artists.begin(); i!=Artists.end(); ++i) {
        cout << i->second.name << ": " << i->second.nsongs << ", " << i->second.time / 60 << ":" << i->second.time % 60 << endl;
        for (map<string, Album>::iterator j = i->second.albums.begin(); j != i->second.albums.end(); ++j){
            cout << "        " << j->second.name << ": " << j->second.nsongs << ", " << j->second.time / 60 << ":" << j->second.time % 60 << endl;
            for (map<int, Song>::iterator k = j->second.songs.begin(); k != j->second.songs.end(); ++k){
                cout << "                 " << k->second.track << ". " << k-> second.title << ": " << k->second.time / 60 << ":" << k->second.time % 60;
            }
        }
    }
}