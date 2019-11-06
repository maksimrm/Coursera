#include <iostream>
#include <vector>

#include <limits>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    int64_t av = 0;

    for(int i = 0; i < n; i++){
        cin >> t[i];
        av += t[i];
    }
    av /= n;
    vector<int> ans;
    for (int i = 0; i < t.size(); i++){
        if (t[i] > av){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto i: ans){
        cout << i << " ";
    }
    return 0;

}