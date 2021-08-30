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
    vector<string> line;
    string temp;
    ifstream file;
    file.open(argv[1], ifstream::in);
    for (int i = 0; i < 7; i++)
    {
        file >> temp;
        line.push_back(temp);
        replace(line[i].begin(), line[i].end(), '_', ' ');
    }
    Artists[line[3]] = 

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