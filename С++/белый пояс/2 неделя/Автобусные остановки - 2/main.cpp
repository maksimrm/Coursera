#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


vector<string> read_path(){
    vector<string> result;
    string s;
    int n;
    cin >> n;
    for (int i = 0;  i < n; i++) {
        cin >> s;
        result.push_back(s);
    }
    return result;
}


bool is_in_paths(const map<vector<string>, int>& paths,const vector<string>& exmpl){
    if (paths.count(exmpl) == 0) {
        return false;
    } else {
        return true;
    }
}


void add_path(map<vector<string>, int>& paths, vector<string>& result) {
    int n = paths.size();
    paths[result] = n + 1;
}

int main() {
    map<vector<string>, int> paths;
    int n;
    cin >> n;
    vector<string> test;
    for (int i = 0; i < n; i++){
        test = read_path();
        if(is_in_paths(paths, test)){
            cout << "Already exists for " << paths[test]<< endl;
        } else {
            add_path(paths, test);
            cout << "New bus " << paths[test] << endl;
        }
    }

    return 0;
}