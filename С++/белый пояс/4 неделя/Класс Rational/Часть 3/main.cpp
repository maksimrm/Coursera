#include <iostream>
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
// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
