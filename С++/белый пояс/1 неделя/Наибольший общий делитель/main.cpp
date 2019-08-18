#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while ( r != 0);
    cout << a;
    return 0;
}