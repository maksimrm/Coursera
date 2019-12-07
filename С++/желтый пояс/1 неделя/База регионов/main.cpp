//#include <iostream>
//#include <map>
//#include <vector>
//
//
//using namespace std;
//
//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

bool operator==(Region a, Region b){
    return (a.std_name == b.std_name) && (a.parent_std_name == b.parent_std_name) && (a.population == b.population) && (a.names == b.names);
}


int FindMaxRepetitionCount(const vector<Region>& regions){
    int ans = 0;
    int cur = 0;
    if (regions.size() == 0){
        return ans;
    }

    vector<int> flag(regions.size(), 0);

    for (int i = 0; i < regions.size(); i++){
        if (flag[i] == 0){
            cur = 0;
            for (int j = 0; j < regions.size(); j++){
                if (flag[j] == 0 && regions[i]==regions[j]){
                    cur++;
                    flag[j] = 1;
                }
            }

        }
        if (cur > ans){
            ans = cur;
        }
    }

    return ans;
}

//int main() {
//    cout << FindMaxRepetitionCount({
//                                           {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Russia",
//                                                   "Eurasia",
//                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                                                   89
//                                           }, {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Russia",
//                                                   "Eurasia",
//                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                                                   89
//                                           },
//                                   }) << endl;
//
//    cout << FindMaxRepetitionCount({
//                                           {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Russia",
//                                                   "Eurasia",
//                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                                                   89
//                                           }, {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Moscow",
//                                                   "Toulouse",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           }, {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   31
//                                           },
//                                   }) << endl;
//
//    return 0;
//}