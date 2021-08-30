#include <iostream>
using namespace std;

int main() {
    string time = "12:22";
    unsigned int minutes, seconds;

    sscanf(time.c_str(), "%2d:%2d", &minutes, &seconds);

    cout << minutes<< ' '<<seconds;

}