#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;



void ADD(map<string, set<string>>& info){
    string word1, word2;
    cin >> word1 >> word2;
    info[word1].insert(word2);
    info[word2].insert(word1);
}

void COUNT(map<string, set<string>>& info) {
    string word;
    cin >> word;
    cout << info[word].size() << endl;
}




void CHECK(map<string, set<string>>& info){
    string word1, word2;
    cin >> word1 >> word2;
    if(info[word1].count(word2) != 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}






int main() {
    int n;
    cin >> n;
    string s;
    map<string, set<string>> info;
    for (int i = 0; i < n; i++){
        cin >> s;
        if ( s == "ADD") {
            ADD(info);
        } else if ( s == "COUNT") {
            COUNT(info);
        } else if (s == "CHECK"){
            CHECK(info);
        }

    }
    return 0;
}