#include <iostream>
#include <vector>

template <typename T>
void getAddr(const T **ret) {
    static std::vector<int> arr {1, 2, 3, 4, 5, 6};
    *ret = &arr;
    std::cout << "The address of arr is " << ret << std::endl;
}

int main() {
    const void *addr = nullptr;
    getAddr(&addr);
    auto arr = static_cast<const std::vector<int> *>(addr);
    std::cout << "The address of addr is " << arr << std::endl;
    for (int i = 0; i < (*arr).size(); ++i)
        std::cout << "a[" << i << "] is " << (*arr)[i] << std::endl;
    return 1;
}
