#include <iostream>
#include <vector>
#include <string>

using namespace std;


void Add(vector<vector<string>>& list_of_deals){
    int i;
    string s;
    cin >> i >> s;
    list_of_deals[i-1].push_back(s);
}


int nextmonth(int current_month){
    int next_month = current_month + 1;
    if (next_month == 12) {
        next_month = 0;
    }
    return next_month;
}



void Next(vector<vector<vector<string>>>& list_of_deals, int& current_month, const vector<int> days){
    int next_month = nextmonth(current_month);
    if( list_of_deals[current_month].size() > list_of_deals[next_month].size()){
        for (int i = 0; i < list_of_deals[next_month].size(); i++) {
            list_of_deals[next_month][i].insert(end(list_of_deals[next_month][i]),
                                                begin(list_of_deals[current_month][i]),
                                                end(list_of_deals[current_month][i]));
        }
        for (int i = 0; i < list_of_deals[current_month].size() - list_of_deals[next_month].size(); i++) {
            list_of_deals[next_month][list_of_deals[next_month].size() - 1].insert(end(list_of_deals[next_month][list_of_deals[next_month].size() - 1]),
                                                begin(list_of_deals[current_month][i+list_of_deals[next_month].size()]),
                                                end(list_of_deals[current_month][i+list_of_deals[next_month].size()]));
        }
    } else {
        for (int i = 0; i < list_of_deals[current_month].size(); i++) {
            list_of_deals[next_month][i].insert(end(list_of_deals[next_month][i]),
                                                begin(list_of_deals[current_month][i]),
                                                end(list_of_deals[current_month][i]));
        }
    }

    vector<vector<string>> month(days[current_month]);
    list_of_deals[current_month] = month;
    current_month = next_month;
}

void Dump(vector<vector<string>>& list_of_deals){
    int i;
    cin >> i;
    cout << list_of_deals[i-1].size() << " ";
    for (auto s : list_of_deals[i-1]){
        cout << s << " ";
    }

    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<vector<vector<string>>>   list_of_deals(12);
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string command;
    int current_month = 0;
    for (int i = 0; i < 12; i++) {
        vector<vector<string>> month(days[i]);
        list_of_deals[i] = month;
    }



    for (int i = 0; i < N; i++){
        cin >> command;

        if (command == "ADD") {
                Add(list_of_deals[current_month]);
        }

        if (command == "NEXT") {
            Next(list_of_deals, current_month, days);
        }
        if (command == "DUMP") {
            Dump(list_of_deals[current_month]);
        }


    }
    return 0;
}