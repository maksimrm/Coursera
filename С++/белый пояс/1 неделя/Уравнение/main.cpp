#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float a, b, c;

    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0){
            if (c == 0) {

            } else {

            }
        } else {
            cout << (-c/b);
        }


    } else {
        if (b*b > 4*a*c){
            float D;
            D = sqrt(b*b - 4*a*c);
            cout << ((-b+D)/2/a) << ' ' << ((-b-D)/2/a);
        } else if (b*b == 4*a*c){
            cout << (-b/2/a);
        }
    }

    return 0;
}