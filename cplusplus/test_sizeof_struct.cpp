#include <iostream>
using namespace std;

struct T1 {
    char a;
    int b;
    int c;
    short d;
    long e;
};

struct T2 {
    int a;
    int b;
    long c;
    short d;
    char e;
};

int main() {
    cout << "size of T1 is " << sizeof(T1) << endl;
    cout << "size of T2 is " << sizeof(T2) << endl;
    return 1;
}
