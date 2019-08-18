#include <iostream>
#include <vector>


using namespace std;

int main() {
    int N;
    int average = 0;
    cin >> N;
    vector<int> ans;
    vector<int> temperature(N);
    for (int i = 0; i < N; i++){
        cin >> temperature[i];
        average += temperature[i];
    }
    average /= N;

    for (int i = 0; i < N; i++){
        if(temperature[i] > average){
            ans.push_back(i);
        }

    }
    cout << ans.size() << "\n";
    for (auto item : ans){
        cout << item << " ";
    }

    return 0;
}