#include <iostream>
#include <map>
#include <vector>
using  namespace std;


// Предварительное объявление шаблонных функций

template <typename left, typename right>
pair<left, right> Sqr(const pair<left, right>& vec);
template <typename type>
type Sqr(type a);

template <typename key, typename value>
map<key, value> Sqr(const map<key, value>& m);
template <typename type>
vector<type> Sqr(const vector<type>& vec);


template <typename left, typename right>
pair<left, right> Sqr(const pair<left, right>& vec){
    return make_pair(Sqr(vec.first), Sqr(vec.second));
};



template <typename type>
type Sqr(type a){
    return a*a;
}

template <typename key, typename value>
map<key, value> Sqr(const map<key, value>& m){
    map<key, value> ans = {};
    for(auto item : m){
        ans[item.first] = Sqr(item.second);
    }
    return ans;
};

template <typename type>
vector<type> Sqr(const vector<type>& vec){
    vector<type> ans = {};
    for(auto item: vec){
        ans.push_back(Sqr(item));
    }
    return ans;
};






int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}