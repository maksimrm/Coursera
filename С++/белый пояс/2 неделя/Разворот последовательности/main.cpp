#include <iostream>
#include <vector>

using namespace std;


void Reverse(vector<int>& v) {
    int c = 0;
    for (int i = 0; i < v.size()/2; i++){
        c = v[i];
        v[i] = v[v.size() - i -1];
        v[v.size() - i -1] = c;
    }
}


int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto i : numbers){
        cout << i<< " ";
    }
    return 0;
}