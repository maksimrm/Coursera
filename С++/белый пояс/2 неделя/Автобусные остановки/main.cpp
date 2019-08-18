#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void NEW_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
    string bus, s;
    int n;
    cin >> bus >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        buses[bus].push_back(s);
        stops[s].push_back(bus);
    }
}


void BUSES_FOR_STOP(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
    string s;
    cin >> s;
    if (stops.count(s) != 0) {
        for (auto item : stops[s]) {
            cout << item << " ";
        }
        cout << endl;
    } else {
        cout << "No stop" << endl;
    }
}




void STOPS_FOR_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
    string bus;
    cin >> bus;
    if (buses.count(bus) == 0){
        cout << "No bus" << endl;
    } else {
        for (auto item : buses[bus]){
            cout << "Stop " << item << ":";
            if (stops[item].size() == 1){
                cout  << " no interchange" << endl;
            } else {
                for (auto stop: stops[item]) {
                    if (stop != bus){
                        cout << " " << stop;
                    }
                }
                cout << endl;
            }
        }
    }
}


void ALL_BUSES(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
    if (buses.empty()){
        cout << "No buses" << endl;
    } else {
        for (auto item : buses) {
            cout << "Bus " << item.first<< ":";
            for (auto stop : item.second){
                cout << " " << stop;
            }
            cout << endl;
        }
    }


}

int main() {
    int n;
    cin >> n;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if (s == "NEW_BUS"){
            NEW_BUS(buses, stops);
        } else if (s == "BUSES_FOR_STOP"){
            BUSES_FOR_STOP(buses, stops);
        } else if ( s == "STOPS_FOR_BUS"){
            STOPS_FOR_BUS(buses, stops);
        } else if (s == "ALL_BUSES") {
            ALL_BUSES(buses, stops);
        }
    }
    return 0;
}