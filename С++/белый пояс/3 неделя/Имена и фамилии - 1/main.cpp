#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>


using namespace std;






class Person{
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_years.push_back(year);
        sort(begin(first_years), end(first_years));
        changes_first[year] = first_name;
//        for (auto item: first_years){
//            cout << item << " ";
//        }
//        cout << endl;
//        for (auto item: changes_first){
//            cout << item.first<< " : "<< item.second<< endl;
//        }
     };
    void ChangeLastName(int year, const string& last_name) {
        second_years.push_back(year);
        sort(begin(second_years), end(second_years));
        changes_second[year] = last_name;
//        for (auto item: second_years){
//            cout << item << " ";
//        }
//        cout << endl;
//        for (auto item: changes_second){
//            cout << item.first<< " : "<< item.second<< endl;
//        }
    };
    string GetFullName(int year) {
        int flag1, flag2;
        flag1 = is_name(year, first_years);
        flag2 = is_name(year, second_years);
        string ans;
        if (flag1 != 0 && flag2 != 0){
            string s1, s2;
            s1 = get_current_name(year, changes_first, first_years);
            s2 = get_current_name(year, changes_second, second_years);
            ans = s1 +" " +s2 ;
        } else if(flag1 != 0 && flag2 == 0){
            string s1 = get_current_name(year, changes_first, first_years);
            ans = s1 + " with unknown last name" ;
        }
        if(flag1 == 0 && flag2 != 0){
            string s2 = get_current_name(year, changes_second, second_years);
            ans = s2 + " with unknown first name";
        }
        if (flag1 == 0 && flag2 == 0){
            ans = "Incognito";
        }
        return ans;
    };
private:
    int is_name(int year, const vector<int>& v){
        if (v.empty()){
            return 0;
        } else if ( v[0] > year){
            return 0;
        } else {
            return 1;
        }


    };

    string get_current_name(int year,map<int, string>& names, const vector<int>& years){
        int i = 0;
//        for (i = 0;  i < years.size(); i++){
//            if (years[i] > year){
//                i--;
//
//                break;
//            }
//
//        }
        while( i < years.size() && years[i] <= year){
            if (years[i] != year){
                i++;
            } else {
                i++;
                break;
            }}
        i--;
//        cout << "data = " << i << " name" << names[years[i]]<< endl;
        return names[years[i]];
    };


    map<int, string> changes_first, changes_second;
    vector<int> first_years, second_years;
};




int main() {
//    vector<string> s1 ;
//    if (s1.empty()){
//        cout << "YES";
//    }
//    string s2 = "train";
//    cout << s1+" "+ s2+ "\n";
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }


    return 0;
}