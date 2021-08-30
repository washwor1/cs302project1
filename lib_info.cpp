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
    string temp;
    ifstream file;
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
        Artists[line.at(2)].albums[line.at(3)].songs
    }
    

    return 0;
}

void output(map<string,Artist> &Artists) {
    for(map<string,Artist>::iterator i = Artists.begin(); i!=Artists.end(); ++i) {
        cout << i->second.name << ": " << i->second.nsongs << 
    }
}