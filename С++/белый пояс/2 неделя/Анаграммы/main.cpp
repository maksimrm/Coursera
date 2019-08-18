#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int>  BuildCharCounters(const string& s){
    map<char, int> result;
    for (auto c : s){
        result[c] += 1;
    }
    return result;
}


int main() {
    int n;
    cin >> n;
    string a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if( BuildCharCounters(a) == BuildCharCounters(b)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}