#include <iostream>
#include <utility> // for std::forward and std::move
using namespace std;

void overloaded(int const &a) {
    cout << "by lvalue\n";
}

void overloaded(int &&a) {
    cout << "by rvalue\n";
}

template <typename T>
void forwarding(T &&a) {
    std::cout << "via std::forward: ";
    overloaded(std::forward<T>(a));
    std::cout << "via std::move: ";
    overloaded(std::move(a)); // conceptually this would invalidate arg
    std::cout << "by simple passing: ";
    overloaded(a);
}

int main() {
    std::cout << "initial caller passes rvalue:\n";
    forwarding(5);
    std::cout << "initial caller passes lvalue:\n";
    int x = 5;
    forwarding(x);
    return 1;
}
