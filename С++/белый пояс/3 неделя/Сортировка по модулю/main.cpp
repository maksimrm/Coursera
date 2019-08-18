#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        cin >> a;
        numbers.push_back(a);
    }
    sort(begin(numbers), end(numbers), [](int a, int b) { return abs(a) < abs(b);});
    for(const auto& item: numbers){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}