#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;

    }

    Rational(int num, int den) {
        int cnt = 1;
        if ((num < 0 && den > 0) ||(num > 0 && den < 0)){
            cnt = -1;
        }

        int a = NOD(abs(num), abs(den));
        numerator = abs(num)*cnt/a;
        denominator = abs(den)/a;

    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }


    Rational& operator=(const Rational& right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        numerator = right.Numerator();
        denominator = right.Denominator();
        return *this;
    }

private:
    int NOD(int a, int b){
        int r;
        do {
            r = a % b;
            a = b;
            b = r;
        } while ( r != 0);
        return a;
    }

    int numerator;
    int denominator;
};


bool operator==(const Rational& lhs,const Rational rhs){
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

//Rational& operator=(Rational& lhs,  Rational& rhs){
//        lhs = {rhs.Numerator(), rhs.Denominator()};
//        return lhs;
//}

Rational operator+(const Rational& lhs, const Rational rhs){
    int new_numerator = lhs.Numerator()*rhs.Denominator()+rhs.Numerator()*lhs.Denominator();
    int new_denumerator = lhs.Denominator()*rhs.Denominator();
    return {new_numerator, new_denumerator};
}

Rational operator-(const Rational& lhs, const Rational rhs){
    int new_numerator = lhs.Numerator()*rhs.Denominator()-rhs.Numerator()*lhs.Denominator();
    int new_denumerator = lhs.Denominator()*rhs.Denominator();
    return {new_numerator, new_denumerator};
}

Rational operator*(const Rational& lhs, const Rational rhs){
    int new_numerator = lhs.Numerator()*rhs.Numerator();
    int new_denumerator = lhs.Denominator()*rhs.Denominator();
    return {new_numerator, new_denumerator};
}

Rational operator/(const Rational& lhs, const Rational rhs){
    int new_numerator = lhs.Numerator()*rhs.Denominator();
    int new_denumerator = lhs.Denominator()*rhs.Numerator();
    return {new_numerator, new_denumerator};
}

istream& operator>>(istream& stream, Rational& a){
    int numerator = 0, denominator = 0;
    char c;
    if (stream >> numerator>> c >> denominator) {
        a = {numerator, denominator};
    };

    return stream;
}

ostream& operator<<(ostream& stream, const Rational& a){

    stream << a.Numerator() <<"/"<< a.Denominator();
    return stream;
}


bool operator>(const Rational& lhs, const Rational rhs){
    int cmp = lhs.Numerator()*rhs.Denominator() - lhs.Denominator()*rhs.Numerator();
    return cmp > 0;
}
bool operator<(const Rational& lhs, const Rational rhs){
    int cmp = lhs.Numerator()*rhs.Denominator() - lhs.Denominator()*rhs.Numerator();
    return cmp < 0;
}


//void operator[]( const Rational& key, map& mymap);

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}