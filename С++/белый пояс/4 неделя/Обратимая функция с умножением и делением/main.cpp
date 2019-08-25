#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class function_part{
public:
    function_part(char com, double val){
        command = com;
        value = val;
    }
    double apply(const double& init) const {
        double result = init;
        if (command == '+'){
            result += value;
        } else if (command == '-') {
            result -= value;
        } else if (command == '*'){
            result *= value;
        } else  {
            result /= value;
        }
        return result;
    }
    void invert(){
        if (command == '+'){
            command = '-';
        } else if (command == '-'){
            command = '+';
        } else if (command == '*'){
            command = '/';
        } else {
            command = '*';
        }
    }
private:
    char command;
    double value;
};

class Function{
public:
    void AddPart(char command, double val){
        commands.push_back({command, val});
    }
    double Apply(const double& init) const {
        double result = init;
        for (const function_part& item: commands){
            result = item.apply(result);
        }
        return result;
    }
    void Invert(){
        for (function_part& item: commands){
            item.invert();
        }
        reverse(begin(commands), end(commands));
    }
private:
    vector<function_part> commands;
};

//struct Image {
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

//int main() {
//    Image image = {10, 2, 6};
//    Params params = {4, 2, 6};
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 52) << endl;
//    return 0;
//}
