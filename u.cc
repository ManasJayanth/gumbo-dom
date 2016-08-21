#include <iostream>
#include <string>

int main() {
  unordered_map <string, int> m;
  m["foo"] = 42;
  std::cout << m["foo"] << endl;
}
