#include <iostream>
#include "source1.hpp"
#include "source2.hpp"

int main() {
    // increment_1();
    // increment_2();

    id_1 a {1, 2};
    std::cout << "a.id = " << a.id() << std::endl;

    id_2 b {1, 2};
    std::cout << "b.id = " << b.id() << std::endl;

    return 1;
}
