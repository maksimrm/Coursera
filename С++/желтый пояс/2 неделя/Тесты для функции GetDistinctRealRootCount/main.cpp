#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctLin(double  b,double c){
    if (b != 0){
        return 1;
    } else {
        if (c != 0){
            return 0;
        } else {
            return numeric_limits<int>::max();
        }
    }
}

int GetDistinctQuad(double a, double b, double c){
    if (0.5*abs(b) > sqrt(abs(a))*sqrt(abs(c)) || (signbit(a)+signbit(c) )% 2 == 1) {
        return 2;
    } else if (abs(b)/2 == sqrt(abs(a))*sqrt(abs(c))) {
        return 1;
    } else {
        return 0;
    }
//    double D = b*b - 4*a*c;

}

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0){
        return GetDistinctLin(b, c);
    } else {
        return GetDistinctQuad(a, b, c);
    }
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestQuadraticCase(){


    AssertEqual(GetDistinctRealRootCount(1, 2, 3), 0, "TestQuadraticCase1");
    AssertEqual(GetDistinctRealRootCount(0.1, 0.2, 0.3), 0, "TestQuadraticCase2");
    AssertEqual(GetDistinctRealRootCount(-1.0, -2.0, -3.0), 0, "TestQuadraticCase3");

    AssertEqual(GetDistinctRealRootCount(1, 0, 3), 0, "TestQuadraticCase4");
    AssertEqual(GetDistinctRealRootCount(-1, 0, -3), 0, "TestQuadraticCase5");
    AssertEqual(GetDistinctRealRootCount(0.1, 0, 0.3), 0, "TestQuadraticCase6");


    AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, "TestQuadraticCase7");
    AssertEqual(GetDistinctRealRootCount(-1, -1, 0), 2, "TestQuadraticCase8");
    AssertEqual(GetDistinctRealRootCount(0.1, 0.1, 0), 2, "TestQuadraticCase9");

    AssertEqual(GetDistinctRealRootCount(1, 4, 0), 2, "TestQuadraticCase10");
    AssertEqual(GetDistinctRealRootCount(-1, -4, 0), 2, "TestQuadraticCase11");
    AssertEqual(GetDistinctRealRootCount(0.1, 0.4, 0), 2, "TestQuadraticCase12");

    AssertEqual(GetDistinctRealRootCount(4, 10, 2), 2, "TestQuadraticCase13");
    AssertEqual(GetDistinctRealRootCount(-4, -10, -2), 2, "TestQuadraticCase14");
    AssertEqual(GetDistinctRealRootCount(0.04, 0.10, 0.02), 2, "TestQuadraticCase15");

    AssertEqual(GetDistinctRealRootCount(1, -2, 0), 2, "TestQuadraticCase16");
    AssertEqual(GetDistinctRealRootCount(-1, 2, 0), 2, "TestQuadraticCase17");
    AssertEqual(GetDistinctRealRootCount(0.1, -0.2, 0), 2, "TestQuadraticCase18");

    AssertEqual(GetDistinctRealRootCount(1, -2, 1), 1, "TestQuadraticCase19");
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "TestQuadraticCase20");
    AssertEqual(GetDistinctRealRootCount(-1, 2, -1), 1, "TestQuadraticCase21");

//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/4, numeric_limits<double>::max(), numeric_limits<double>::max()/4), 2, "TestQuadraticCase22");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::min()/4, numeric_limits<double>::min(), numeric_limits<double>::min()/4), 2, "TestQuadraticCase23");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/4, numeric_limits<double>::min(), numeric_limits<double>::max()/4), 0, "TestQuadraticCase24");
//
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/2, numeric_limits<double>::max(), numeric_limits<double>::max()/2), 1, "TestQuadraticCase25");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::min()/2, numeric_limits<double>::min(), numeric_limits<double>::min()/2), 1, "TestQuadraticCase26");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/2, numeric_limits<double>::min(), numeric_limits<double>::max()/2), 1, "TestQuadraticCase27");
//
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/2, numeric_limits<double>::max(), numeric_limits<double>::max()/1.5), 0, "TestQuadraticCase28");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::min()/2, numeric_limits<double>::min(), numeric_limits<double>::min()/1.5), 0, "TestQuadraticCase29");
//    AssertEqual(GetDistinctRealRootCount(numeric_limits<double>::max()/2, numeric_limits<double>::min(), numeric_limits<double>::max()/1.5), 0, "TestQuadraticCase30");


};

void TestLinearCase(){

    AssertEqual(GetDistinctRealRootCount(0, 2, 3), 1, "TestLinearCase1");
    AssertEqual(GetDistinctRealRootCount(0, 0.2, 0.3), 1, "TestLinearCase2");
    AssertEqual(GetDistinctRealRootCount(0, -2.0, -3.0), 1, "TestLinearCase3");

    AssertEqual(GetDistinctRealRootCount(0, 0, 3), 0, "TestLinearCase4");
    AssertEqual(GetDistinctRealRootCount(0, 0, -3), 0, "TestLinearCase5");
    AssertEqual(GetDistinctRealRootCount(0, 0, 0.3), 0, "TestLinearCase6");


    AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "TestLinearCase7");
    AssertEqual(GetDistinctRealRootCount(0, -1, 0), 1, "TestLinearCase8");
    AssertEqual(GetDistinctRealRootCount(0, 0.1, 0), 1, "TestLinearCase9");

    AssertEqual(GetDistinctRealRootCount(0, 4, 0), 1, "TestLinearCase10");
    AssertEqual(GetDistinctRealRootCount(0, -4, 0), 1, "TestLinearCase11");
    AssertEqual(GetDistinctRealRootCount(0, 0.4, 0), 1, "TestLinearCase12");

    AssertEqual(GetDistinctRealRootCount(0, 10, 2), 1, "TestLinearCase13");
    AssertEqual(GetDistinctRealRootCount(0, -10, -2), 1, "TestLinearCase14");
    AssertEqual(GetDistinctRealRootCount(0, 0.10, 0.2), 1, "TestLinearCase15");

    AssertEqual(GetDistinctRealRootCount(0, -2, 0), 1, "TestLinearCase16");
    AssertEqual(GetDistinctRealRootCount(0, 2, 0), 1, "TestLinearCase17");
    AssertEqual(GetDistinctRealRootCount(0, -0.2, 0), 1, "TestLinearCase18");

    AssertEqual(GetDistinctRealRootCount(0, -2, 1), 1, "TestLinearCase19");
    AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1, "TestLinearCase20");
    AssertEqual(GetDistinctRealRootCount(0, 2, -1), 1, "TestLinearCase21");
};



int main() {
    TestRunner runner;
    runner.RunTest(TestQuadraticCase, "TestQuadraticCase");
    runner.RunTest(TestLinearCase, "TestLinearCase");
    // добавьте сюда свои тесты
    return 0;
}
