#ifndef SOURCE_1_HPP_
#define SOURCE_1_HPP_

#include <iostream>
#include "static.hpp"

void increment_1() {
    std::cout << "Calling increment_1 function()...\n";
    //int ret = increment_by_one();
    std::cout << "a = " << ++a << std::endl;
}

class id_1 : public id {
public:
    id_1() {}

    id_1(int x, int y) : a(x), b(y) {}

    int id() { return get_id(); }

private:
    int a;
    int b;
};

#endif
