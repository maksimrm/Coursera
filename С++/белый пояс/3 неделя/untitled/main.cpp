#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name)
    {
        surname[year] = last_name;
    }

    string GetValue(const map<int, string> &m, int year)
    {
        string result = "";

        for (auto temp : m)
        {
            if(temp.first <= year)
            {
                result = temp.second;
            }
            else
            {
                break;
            }
        }
        return result;
    }

    string GetFullName(int year)
    {
        string current_name = GetValue(name, year);
        string current_surname = GetValue(surname, year);

        if(current_name.empty() && current_surname.empty())
        {
            string res = "Incognito";
            return res;
        }
        else if(current_name.empty())
        {
            string res = current_surname + " with unknown first name";
            return res;
        }
        else if(current_surname.empty())
        {
            string res = current_name + " with unknown last name";
            return res;
        }
        else
        {
            string full_name = current_name + " " + current_surname;
            return full_name;
        }
    }

    string GetFullNameWithHistory(int year)
    {
        string names = GetHistory(name, year);
        string surnames = GetHistory(surname, year);

        if(names.empty() && surnames.empty())
        {
            string res = "Incognito";
            return res;
        }
        else if(names.empty())
        {
            string res = surnames + " with unknown first name";
            return res;
        }
        else if(surnames.empty())
        {
            string res = names + " with unknown last name";
            return res;
        }
        else
        {
            string full_name = names + " " + surnames;
            return full_name;
        }
    }

private:
    map<int, string> name;
    map<int, string> surname;

    string GetResStr(vector<string> v)
    {
        string result = v[0] + " (";
        for (int i = 1; i < v.size(); ++i)
        {
            result += v[i] + ", ";
        }
        result.erase(end(result) - 2, end(result));
        if(v.size() > 1) result += ")";

        return result;
    }

    string GetHistory(map<int, string> &m, int year)
    {
        vector<string> v;
        string previous_value;

        for (auto temp : m)
        {
            if(temp.first <= year &&
               temp.second != previous_value)
            {
                v.push_back(temp.second);
            }
            else
            {
                break;
            }
            previous_value = temp.second;
        }

        if(v.empty()) return "";

        reverse(begin(v), end(v));
        string result = GetResStr(v);

        return result;
    }
};

int main()
{

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



