//Walter Ashworth and Andy Zeng

#include "structs.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
    map<string,Artist> Artists;
    vector<string> line;
    string temp;
    ofstream musicf;
    musicf.open("argv[1]");
    while (!musicf.eof())
    {
        getline(musicf, temp);
    }
    


    return 0;
}