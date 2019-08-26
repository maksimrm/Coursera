#include <iostream>
#include <sstream>
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

// Реализуйте для класса Rational операторы << и >>

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;

        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
