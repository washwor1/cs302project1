//Walter Ashworth and Andy Zeng

#include "structs.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


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

    for (int i = 0; i < line.size() - 1; i++)
    {
        cout << line[i] << " ";
    }
    cout << line[line.size()] << endl;

    return 0;
}