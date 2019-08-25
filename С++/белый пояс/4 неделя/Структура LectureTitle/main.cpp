
#include <iostream>
#include <string>

using namespace std;



struct Specialization{
    string value;

    explicit Specialization(string str){
        value = str;
    }
};

struct Course{
    string value;
    explicit Course(string str){
        value = str;
    }
};

struct Week{
    string value;
    explicit Week(string str){
        value = str;
    }
};
struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization a, Course b,Week c){
        specialization = a.value;
        course = b.value;
        week = c.value;
    }
};



int main(){

    return 0;
}