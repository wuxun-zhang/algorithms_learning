#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

template <typename... Tvalues>
void test_func(const vector<tuple<Tvalues...>> &students) {

  auto stu1 = students[0];

  cout << "No." << static_cast<int>(std::get<0>(stu1)) << endl;
  cout << "Name: " << static_cast<string>(std::get<1>(stu1)) << endl;
  vector<int> got_scores = static_cast<vector<int>>(std::get<2>(stu1));
  cout << "Scores : " << got_scores[0] << ", " << got_scores[1] << endl;
}

int main() {
  int id = 0;
  string name = "Jack";
  vector<int> scores{80, 90};

  string address = "China";

  auto stu1 = std::make_tuple(id, name, scores);
  auto stu2 = std::make_tuple(id, name, address);
  auto students = std::vector{stu1}; // C++11

  test_func(students);
  return 1;
}
