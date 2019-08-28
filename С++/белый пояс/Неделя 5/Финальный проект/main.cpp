#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    int GetYear() const{
        return year;
    };
    int GetMonth() const{
        return month;
    };
    int GetDay() const{
        return day;
    };
    Date(){
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d){
        if(m >12 || m < 1){
            throw runtime_error("Month value is invalid: "+ to_string(m));
        }

        if (d < 1 || d > 31){
            throw runtime_error("Day value is invalid: " + to_string(d));
        }
        day = d;
        month = m;
        year = y;
    }

private:
    int day;
    int year;
    int month;
};

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
};

void check_stream_for_data(stringstream& stream){
    if (stream.peek() != '-'){
        throw runtime_error("Wrong date format: "+ stream.str());
    }
    stream.ignore(1);
    if (stream.peek() != '-' && stream.peek() != '+' && (stream.peek() > 57 || stream.peek() < 48)){
        throw runtime_error("Wrong date format: "+ stream.str());
    }
}


Date get_data_from(stringstream& stream){
    int year, month, day;

    stream >> year;
    check_stream_for_data(stream);
    stream >> month;
    check_stream_for_data(stream);

    stream >> day;

    if (stream.peek() != -1){
        throw runtime_error("Wrong date format: "+ stream.str());
    }
    return {year, month, day};
}

istream& operator>>(istream& stream, Date& a){
    string s;
    stream >> s;
    stringstream qw(s);
    a = get_data_from(qw);
    return stream;
}

ostream& operator<<(ostream& stream, const Date& a){
        stream << setw(4) <<  setfill('0') << a.GetYear() << "-" <<
        setw(2) << setfill('0') << a.GetMonth()<< "-" <<
       setw(2) << setfill('0') << a.GetDay();
        return stream;
}



void print_set(const set<string>& value){
    for (auto item : value){
        cout << item << endl;
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        map_of_events[date].insert(event);
    };
    bool DeleteEvent(const Date& date, const string& event){
        try{
            set<string> value = map_of_events.at(date);
            if (value.count(event)){
                map_of_events[date].erase(event);
                return true;
            } else {
                return false;
            }
        } catch (exception& ex){
            return false;
        }
    };
    int  DeleteDate(const Date& date){
        int cnt = map_of_events[date].size();
        map_of_events.erase(date);
        return cnt;
    };

    void Find(const Date& date) const{
        try {
            set<string> value = map_of_events.at(date);
            print_set(value);
        } catch (exception& ex){
//            cout << "There is no events" << endl;
        }
    };

    void Print() const {
        for (auto item : map_of_events){
            for (auto event : item.second){
                cout << item.first << " " << event << endl;
            }
        }
    };

private:
    map<Date, set<string>> map_of_events;
};



int main() {
    Database db;

    string command;
    while (getline(cin, command, '\n')) {
        stringstream input(command);
        string first;
        input >> first;
        if (first == ""){
            continue;
        }
        try {
            if (first == "Add") {
                Date date;
                string event;
                input >> date >> event;
                db.AddEvent(date, event);
            } else if (first == "Del") {
                Date date;
                input >> date;
                string event;

                input >> event;
                if (event != "") {
                    bool result;
                    result = db.DeleteEvent(date, event);
                    if (result) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    int cnt = db.DeleteDate(date);
                    cout << "Deleted " << cnt << " events" << endl;
                }
            } else if (first == "Find") {
                Date date;
                input >> date;
                db.Find(date);
            } else if (first == "Print") {
                db.Print();
            } else {
                cout << "Unknown command: " << first << endl;
            }
        } catch (runtime_error& ex){
            cout << ex.what() <<endl;
        }
    }

    return 0;
}