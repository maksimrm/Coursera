#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
//    ifstream input("../input.txt");

    ifstream input("input.txt");
    double line;
    cout << fixed << setprecision(3);
    while(input >> line){

        cout << line << endl;
    }
    return 0;
}