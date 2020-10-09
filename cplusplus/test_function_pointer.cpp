#include <cstdlib>
#include <iostream>

using namespace std;

typedef void (*fn1_t)(const int &);
typedef void (*fn2_t)(const int &, const int &);
typedef void (*void_fn)(void);

void print_1(const int &x) { printf("x = %d\n", x); }

void print_2(const int &a, const int &b) { printf("a + b = %d\n", a + b); }

// void test(int x, int y, void (*fn1)(int), void (*fn2)(int, int)) {
//     fn1(x);
//     fn2(x, y);
// }

void test(int x, int y, void (*fn1)(void), void (*fn2)(void)) {
  fn1_t fn_1 = (fn1_t)fn1;
  fn2_t fn_2 = (fn2_t)fn2;
  fn_1(x);
  fn_2(x, y);
}

// Main function
int main(void) {
  int x = 2, y = 3;
  test(x, y, (void_fn)print_1, (void_fn)print_2);
  return 1;
}
