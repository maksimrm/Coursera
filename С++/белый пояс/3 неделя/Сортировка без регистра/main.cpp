#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    vector<string> numbers;
    for(int i = 0; i < n; i++){
        cin >> s;
        numbers.push_back(s);
    }
    sort(begin(numbers), end(numbers), [](string a, string b) {
        for(int i = 0; i < a.size(); i++){
            a[i] = tolower(a[i]);
        }
        for(int i = 0; i < b.size(); i++){
            b[i] = tolower(b[i]);
        }
        return a < b;

    });
    for(const auto& item: numbers){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}