#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Step(vector<string>& queue, string s, int command) {
    if (s == "WORRY") {
        queue[command] = "WORRY";
    }
    if (s == "QUIET"){
        queue[command] = "QUIET";
    }
    if (s == "COME") {
        if (command > 0) {
            for (int i = 0; i < command; i++) {
                queue.push_back("QUIET");
            }
        } else {
            queue.resize(queue.size() + command);
        }

    }
    if (s == "WORRY_COUNT") {
        int i = 0;
        for (auto c : queue){
            if (c == "WORRY"){
                i++;
            }
        }
        cout << i << "\n";
    }

}



int main() {
    int n;
    cin >> n;
    vector<string> queue;
    string s;
    int command;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s != "WORRY_COUNT"){
            cin >> command;
        }
        Step(queue, s, command);
    }



    return 0;
}