//Walter Ashworth and Andy Zeng
//Reference: We got structs from the write up and the time conversion from stackoverflow
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
    vector<string> line;
    ifstream file;
    file.open(argv[1], ifstream::in);








    //while the file can input into line 6 times it will it will replace the underscore with a space
     while(file>>line.at(0)>>line.at(1)>>line.at(2)>>line.at(3)>>line.at(4)>>line.at(5)) {
        for(int i = 0; i<6;++i) {
            replace(line[i].begin(), line[i].end(), '_', ' ');
        }
        Artists[line.at(2)].albums[line.at(3)].songs
    }
    

    return 0;
}

//comment outpus into the formated on the writeup
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