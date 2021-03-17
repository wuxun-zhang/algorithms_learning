#ifndef SOURCE_2_HPP_
#define SOURCE_2_HPP_

#include <iostream>
#include "static.hpp"

void increment_2() {
    std::cout << "Calling increment_2 function()...\n";
    //int ret = increment_by_one();
    std::cout << "a = " << ++a << std::endl;
}

class id_2 : public id {
public:
    id_2() {}

    id_2(int x, int y) : a(x), b(y) {}

    int id() { return get_id(); }

private:
    int a;
    int b;
};

#endif
