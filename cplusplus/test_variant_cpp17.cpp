#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;

int main() {
    //std::variant
    //std::variant<int, float, double, vector<int>> var1;
    std::variant<double> var1;

    union VAR {
        int a;
        float b;
        double c;
    } var2;

    cout << "size of double is " << sizeof(double) << endl;
    cout << "size of float is " << sizeof(float) << endl;
    cout << "size of int is " << sizeof(int) << endl;
    cout << "size of long is " << sizeof(long) << endl;
    cout << "size of vector<int> is " << sizeof(vector<int>) << endl;
    cout << "size of variant<std::monostate> is "
         << sizeof(variant<std::monostate>) << endl;

    cout << "Before, size of var1 is " << sizeof(var1) << endl;
    //var1 = vector<int>{1, 2, 3};
    cout << "After, size of var1 is " << sizeof(var1) << endl;

    cout << "size of var2 is " << sizeof(var2) << endl;
}
