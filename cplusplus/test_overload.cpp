#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void func(float a) { cout << "Calling func_1..." << endl; }

void func(int64_t a) { cout << "Calling func_2..." << endl; }

void func(vector<int64_t> a) { cout << "Calling func_3..." << endl; }

void func(vector<float> a) { cout << "Calling func_4..." << endl; }

int main() {
  func(float(1));
  func(vector<float>{1, 1});
  return 0;
}
