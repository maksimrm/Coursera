#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>



using namespace std;



// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name = "";  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        vector<string> names = get_names(first_names, year);
        vector<string> so_names = get_names(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            string ans = get_history(so_names, 1);
            return last_name +ans + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            string ans = get_history(names, 1);
            return first_name+" "+ans + "with unknown last name";

            // если известны и имя, и фамилия
        } else {
            string ans_1 = get_history(names, 1);
            string ans_2 = get_history(so_names, 2);
            return first_name + " " + ans_1+ last_name+ans_2;
        }
    }

private:
    string get_history(vector<string> names, int a){
        string ans = "";
        if (names.size() > 1){
            if ( a != 1){
                ans += " ";
            }
            ans += "(";
            for (int i = names.size()-2; i >0; i--){
                if (names[i] != names[i+1]){
                    ans +=  names[i]+", ";
                }
            }
            if (names[0] != names[1]){
                ans +=  names[0];
            }
            ans += ")";
            if (a == 1){
                ans +=" ";
            }
        }
        if (ans == "()" || ans == "() " || ans == " ()" || ans == " () "){
            ans.clear();
        }
        return ans;
    }
    vector<string> get_names(const map<int, string>& names, int year){
        vector<string> name;  // изначально имя неизвестно

        // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
        for (const auto& item : names) {
            // если очередной год не больше данного, обновляем имя
            if (item.first <= year) {
                name.push_back(item.second);
            } else {
                // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
                break;
            }
        }

        return name;



    }
    map<int, string> first_names;
    map<int, string> last_names;
};





    int main() {
        Person person;

        //person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");
        //person.ChangeFirstName(1965, "Polina1");
        person.ChangeLastName(1964, "Sergeeva1");
        //person.ChangeFirstName(1965, "Polina2");
        person.ChangeLastName(1969, "Sergeeva2");
        //person.ChangeFirstName(1980, "Polina3");
        person.ChangeLastName(1970, "Sergeeva3");
        for (int year : {1900, 1965, 1990}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        //person.ChangeFirstName(1970, "Appolinaria");
        for (int year : {1969, 1970}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeLastName(1968, "Volkova");
        for (int year : {1969, 1970}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        //person.ChangeFirstName(1990, "Polina");
        person.ChangeLastName(1990, "Volkova-Sergeeva");
        cout << person.GetFullNameWithHistory(1990) << endl;

        //person.ChangeFirstName(1966, "Pauline");
        cout << person.GetFullNameWithHistory(1966) << endl;

        person.ChangeLastName(1960, "Sergeeva");
        for (int year : {1960, 1967}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeLastName(1961, "Ivanova");
        cout << person.GetFullNameWithHistory(1967) << endl;

        return 0;
    }

