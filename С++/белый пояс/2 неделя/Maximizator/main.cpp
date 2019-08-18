#include <iostream>

using namespace std;

void  UpdateIfGreater(const int& x, int&y){
    if (x > y){
        y = x;
    }
}


int main() {
    int x, y;
    cin >> x >> y;
    UpdateIfGreater(x, y);
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    return 0;
}