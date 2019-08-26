#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <exception>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;

    }

    Rational(int num, int den) {
        if (den == 0){
            throw invalid_argument("den");
        }
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
    if( rhs.Numerator() == 0){
        throw domain_error("rhs");
    }
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
    Rational a, b;
    char operation;
    try {
        cin >> a >> operation >> b;
    } catch (invalid_argument& ){
        cout << "Invalid argument" << endl;
        return 0;
    }

    try {
        Rational result;
        if (operation == '*'){
            result = a*b;
        } else if (operation == '+'){
            result = a+b;
        } else if (operation == '-'){
            result = a - b;
        } else {
            result = a/b;
        }
        cout << result<< endl;
    } catch (domain_error&){
        cout << "Division by zero"<< endl;
    }

    return 0;
}