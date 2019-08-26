#include <iostream>
#include <fstream>
#include <iomanip>

#include <string>
using namespace std;


int main() {
//    ifstream input("../input.txt");
    ifstream input("input.txt");
    int a;
    int n, m;
    input >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            input >> a;
            cout<< setw(10)<< a;
            if (j != m-1){
                cout << " ";
                input.ignore(1);
            }
        }
        if(i != n-1){
            cout << endl;
        }
    }
    return 0;
}