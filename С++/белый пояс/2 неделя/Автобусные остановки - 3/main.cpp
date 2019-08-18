#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<string>> info;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        string s;
        set<string> us;
        for(int j = 0; j < a; j++) {
            cin >> s;
            us.insert(s);
        }
        bool check = false;
        int j;
        for(j = 0; j < info.size(); j++) {
            check = true;
            for (auto item : us){
                if (info[j].count(item) == 0){
                    check = false;
                }
            }
            if (check && info[j].size() == us.size()) {
                break;
            } else {check = false;}
        }
        if(check ){
            cout << "Already exists for " << j+1<< endl;
        } else {
            info.push_back(us);
            cout << "New bus " << info.size() << endl;
        }

    }
    return 0;
}