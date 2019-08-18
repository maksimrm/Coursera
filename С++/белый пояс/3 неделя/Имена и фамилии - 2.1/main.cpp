#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_name_data[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_name_data[year] = last_name;
    }
    string GetFullName(int year) {
        string result = "";
        string first_name = get_name(first_name_data, year);
        string last_name = get_name(last_name_data, year);
        if (first_name.empty() && last_name.empty()){
            result = "Incognito";
        } else if(first_name.empty()){
            result = last_name + " with unknown first name";
        } else if(last_name.empty()){
            result = first_name + " with unknown last name";
        } else{
            result = first_name + " " + last_name;
        }
        return result;
    }

    string GetFullNameWithHistory(int year) {
        string result = "";
        string first_name = appropriate_form(first_name_data, year);
        string last_name = appropriate_form(last_name_data, year);
        if (first_name.empty() && last_name.empty()){
            result = "Incognito";
        } else if(first_name.empty()){
            result = last_name + " with unknown first name";
        } else if(last_name.empty()){
            result = first_name + " with unknown last name";
        } else{
            result = first_name + " " + last_name;
        }
        return result;
    }
private:

    string get_name(const map<int, string>& names, int year){
        string result = "";
        for (auto item: names){
            if (item.first <= year){
                result = item.second;
            }
        }
        return result;
    }


    string appropriate_form(const map<int, string>& names, int year){
        vector<string> name = get_names_by_year(names, year);
        string result = "";
        string need = "";
        if (!name.empty()){
            result = name[0];
            if (name.size() > 1){
                need += " (";
                for (int i = 1; i < name.size(); i++){
                    if (name[i] != name[i-1]){
                        need += name[i]+", ";
                    }
                }
                need.erase(end(need)-1);
                need.erase(end(need)-1);

                if (need != ""){
                    need += ")";
                }
            }

        }
        return result + need;
    }

    vector<string> get_names_by_year(const map<int, string>& names, int year){
        vector<string> result;
        for (auto item: names){
            if (item.first <= year){
                result.push_back(item.second);
            }
        }
        reverse(begin(result), end(result));
        return result;
    }


    map<int, string> first_name_data, last_name_data;
};




int main() {

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}