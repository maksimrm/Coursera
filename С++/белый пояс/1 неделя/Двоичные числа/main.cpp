#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> ans = {};
    do {
        ans.push_back(a % 2);
        a /= 2;
    } while ( a != 0);
    for (int i = 1; i <= ans.size(); i++){
        cout << ans[ans.size() - i];
    }
    return 0;
}