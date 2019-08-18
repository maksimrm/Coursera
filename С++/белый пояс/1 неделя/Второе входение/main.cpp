#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = -2;
    int position = 0;
    for (auto c : s){
        if ( c == 'f') {
            i++;
        }
        if ( i == 0){
            cout << position;
            break;
        }
        position++;
    }
    if (i != 0){
        cout << i;
    }

    return 0;
}