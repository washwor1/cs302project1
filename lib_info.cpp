//Walter Ashworth and Andy Zeng
//Reference: We got structs from the write up and the time conversion from stackoverflow
//https://stackoverflow.com/questions/39885508/parsing-a-string-with-a-colon-and-setting-both-sides-to-different-variables-c
#include "structs.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void output( map<string,Artist> &Artists);

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
    //while the file can input into line 6 times it will it will replace the underscore with a space
     while(file>>line.at(0)>>line.at(1)>>line.at(2)>>line.at(3)>>line.at(4)>>line.at(5)) {
        for(int i = 0; i<6;++i) {
            replace(line[i].begin(), line[i].end(), '_', ' ');
        }
        Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].title = line.at(0);
        sscanf(line.at(1).c_str(), "%2d:%2d", &minutes, &seconds);
        Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].time = (minutes*60+seconds);
        Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].track = (stoi(line.at(5)));
        Artists[line.at(2)].albums[line.at(3)].nsongs=Artists[line.at(2)].albums[line.at(3)].songs.size();
        Artists[line.at(2)].albums[line.at(3)].time+=Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].time;
        Artists[line.at(2)].albums[line.at(3)].name = line.at(3);
        Artists[line.at(2)].name=line.at(2);
        Artists[line.at(2)].time+=Artists[line.at(2)].albums[line.at(3)].songs[stoi(line.at(5))].time;
        Artists[line.at(2)].nsongs++;
    }

    output(Artists);
    return 0;
}

//comment output into the formated on the writeup
void output(map<string,Artist> &Artists) {
    for(map<string,Artist>::iterator i = Artists.begin(); i!=Artists.end(); ++i) {
        cout << left << setw(0) << i->second.name << ": " << i->second.nsongs << ", " << i->second.time / 60 << ":" << right << setw(2) << setfill('0') << i->second.time % 60 << endl;
        for (map<string, Album>::iterator j = i->second.albums.begin(); j != i->second.albums.end(); ++j){
            cout << left << setw(0) << "        " << j->second.name << ": " << j->second.nsongs << ", " << j->second.time / 60 << ":" << right << setw(2) << setfill('0') << j->second.time % 60 << endl;
            for (map<int, Song>::iterator k = j->second.songs.begin(); k != j->second.songs.end(); ++k){
                cout << left << setw(0) << "                 " << k->second.track << ". " << k-> second.title << ": " << k->second.time / 60 << ":" << right << setw(2) << setfill('0') << k->second.time % 60 << '\n';
            }
        }
    }
}