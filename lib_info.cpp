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
    ifstream file;
    file.open(argv[1], ifstream::in);
    for (int i = 0; i < 7; i++)
    {
        getline(file, temp, ' ');
        line.push_back(temp);
    }
    
    return 0;
}