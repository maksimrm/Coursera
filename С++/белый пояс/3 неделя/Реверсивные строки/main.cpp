#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString{
private:
    string str;


public:
    ReversibleString(){}
    ReversibleString(const string& a){
        str = a;
    }
    void Reverse(){
        reverse(begin(str), end(str));
    }
    string ToString() const {
        return str;
    }
};



int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}