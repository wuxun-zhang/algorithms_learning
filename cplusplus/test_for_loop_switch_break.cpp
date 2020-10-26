#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 20; ++i) {
        switch (i) {
            case 0: cout << "i[0] " << endl; break;
            case 1: cout << "i[1] " << endl; break;
            case 2: cout << "i[2] " << endl; break;
            default: cout << "*** " << endl; break;
        }
    }
    return 1;
}
