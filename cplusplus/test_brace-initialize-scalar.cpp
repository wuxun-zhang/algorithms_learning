#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
  Student(vector<int> ids) : id_(ids) {
    std::cout << "Calling 1st c-tor..." << std::endl;
  }
  Student(initializer_list<int> l) : id_(l) {
    std::cout << "Calling initializer-based c-tor..." << std::endl;
  }
  Student(int num_id) : num_id_(num_id) {
    std::cout << "Calling 2nd c-tor..." << std::endl;
  }

private:
  vector<int> id_;
  int num_id_;
};

int main() {
  Student s1({1, 2}); // It will call 1st c-tor.
  Student s2({2});    // Actually, it will call 2nd c-tor.
                      // {2} is considered as a scalar instead of a vector.
  Student s3(3);
  return 0;
}
