#include <iostream>
#include <limits>

using namespace std;

int main() {
    uint64_t mass = 0;

    uint64_t cur;
    uint32_t n;
    uint16_t w, h, d, ro;
    cin >> n >> ro;


    for (uint32_t i =0; i < n; i++){
        cin >> w >> h >> d;
        cur = w;
        cur *= h;
        cur *= d;
        cur *= ro;
        mass += cur;
    }

    cout << mass << endl;
    return 0;
}