#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Person {
public:
    Person(const string first_name, const string last_name, int year){
        first_name_data[year] = first_name;
        last_name_data[year] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        for (auto item: first_name_data){
            if (item.first <= year){
                first_name_data[year] = first_name;
            }
            break;
        }
    }
    void ChangeLastName(int year, const string& last_name) {

        for (auto item: last_name_data){
            if (item.first <= year){
                last_name_data[year] = last_name;
            }
            break;
        }
    }
    string GetFullName(int year) const {
        string result = "";
        string first_name = get_name(first_name_data, year);
        string last_name = get_name(last_name_data, year);
        if (first_name.empty() && last_name.empty()){
            result = "No person";
        } else if(first_name.empty()){
            result = last_name + " with unknown first name";
        } else if(last_name.empty()){
            result = first_name + " with unknown last name";
        } else{
            result = first_name + " " + last_name;
        }
        return result;
    }

    string GetFullNameWithHistory(int year) const {
        string result = "";
        string first_name = appropriate_form(first_name_data, year);
        string last_name = appropriate_form(last_name_data, year);
        if (first_name.empty() && last_name.empty()){
            result = "No person";
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

    string get_name(const map<int, string>& names, int year) const {
        string result = "";
        for (auto item: names){
            if (item.first <= year){
                result = item.second;
            }
        }
        return result;
    }


    string appropriate_form(const map<int, string>& names, int year) const {
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

    vector<string> get_names_by_year(const map<int, string>& names, int year) const {
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

    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}