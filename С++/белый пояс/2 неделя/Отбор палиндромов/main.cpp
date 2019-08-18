#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s){
    for (int i = 0; i < s.size()/2; i++){
        if (s[i] != s[s.size() - i -1]){
            return false;
        }
    }
    return true;
}



vector<string> PalindromFilter(vector<string> words,  int minLength){
    vector<string> ans = {};
    for (auto s : words) {
        if (s.size() >= minLength) {
            if (IsPalindrom(s)){
                ans.push_back(s);
            }
        }
    }
    return ans;
}

int main() {
    vector<string> words = {};
    int minLength;
    words = {"weew", "bro", "code"};
    minLength = 4;
    for (auto s : PalindromFilter(words, minLength)) {
        cout << s<< ", ";
    }
    return 0;
}