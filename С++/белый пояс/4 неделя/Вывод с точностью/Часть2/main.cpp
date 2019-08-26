#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    ifstream input("../input.txt");
    ofstream output("../output.txt");
//    ifstream input("input.txt");
//    ofstream output("output.txt");
    double line;
    output << fixed << setprecision(3);
    for (int i = 0; i < 3; i++){
        input >> line;
        output << line << endl;
    }
    return 0;
}