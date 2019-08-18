#include <iostream>
#include <map>
#include <string>

using namespace std;

void CHANGE_CAPITAL(map<string, string>& info) {
    string country, capital;
    cin >> country >> capital;
    if (info.count(country) == 0) {
        cout << "Introduce new country " <<country << " with capital " << capital<< endl;
        info[country] = capital;
    } else if (info[country] == capital){
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << info[country] << " to " << capital << endl;
        info[country] = capital;
    }
}

void RENAME(map<string, string>& info) {
    string old_country, new_country;
    cin >> old_country >> new_country;

    if ( old_country == new_country || info.count(old_country) == 0 || info.count(new_country) != 0){
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << old_country << " with capital " << info[old_country] << " has been renamed to " << new_country << endl;
        info[new_country] = info[old_country];
        info.erase(old_country);
    }
}

void ABOUT(map<string, string>& info) {
    string country;
    cin >> country;
    if (info.count(country) == 0){
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << info[country] << endl;
    }

}

void DUMP(map<string, string>& info) {
    if (info.empty()) {
        cout << "There are no countries in the world"<< endl;
    } else {
        for (auto item : info) {
            cout << item.first << "/"<< item.second << endl;
        }
    }
}




int main() {
    int n;
    cin >> n;
    string s;
    map<string, string> info;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s == "CHANGE_CAPITAL") {
            CHANGE_CAPITAL(info);
        } else if (s == "RENAME") {
            RENAME(info);
        } else if (s == "ABOUT") {
            ABOUT(info);
        } else if( s == "DUMP") {
            DUMP(info);
        } else {
            cout << "Incorrect command" << endl;
        }
    }
    return 0;
}