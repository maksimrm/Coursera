#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student{
    string name;
    string second_name;
    double  day;
    double month;
    double year;
    Student(string n,
    string s,
    double d,
    double m, double y){
        name = n;
        second_name = s;
        day = d;
        month = m;
        year = y;
    }
};

Student get_person(){

    string name;
    string second_name;
    double day;
    double month;
    double year;
    getline(cin, name, ' ');
    getline(cin, second_name, ' ');
    cin >> day >> month >> year;
    cin.ignore(1);
    return {name, second_name, day, month, year};
}

void print_student_name(const vector<Student>& students, double K){
    if ( K <= students.size() && K > 0){
        cout << students[K-1].name << " " << students[K-1].second_name << endl;
    } else {
        cout << "bad request" << endl;
    }

}

void print_birth_day(const vector<Student>& students, double K){
    if (K <= students.size() && K > 0){
        cout << students[K-1].day << "." << students[K-1].month <<"."<< students[K-1].year <<  endl;
    } else {
        cout << "bad request" << endl;
    }



}

int main() {
    double n;
    cin >> n;
    cin.ignore(1);
    vector<Student> students;
    for (double i = 0; i < n; i++){
        Student person = get_person();
        students.push_back(person);
    }
    cin >> n;
    cin.ignore(1);
    cout << fixed << setprecision(0);
    for (double i = 0; i < n; i++) {
        string command;
        double K;

        getline(cin, command, ' ');
        cin >> K;
        cin.ignore(1);
        if (command == "name") {
            print_student_name(students, K);
        } else if (command == "date") {
            print_birth_day(students, K);
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}