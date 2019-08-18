#include <iostream>
#include <vector>

using namespace std;


vector<int> Reversed(const vector<int>& v) {
    vector<int> ans = v;
    for (int i = 0; i < v.size()/2; i++){
        ans[i] = v[v.size() - i -1];
        ans[v.size() - i -1] = v[i];
    }
    return ans;
}


int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    numbers = Reversed(numbers);
    for (auto i : numbers){
        cout << i<< " ";
    }
    return 0;
}