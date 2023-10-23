#include "set.cpp"
#include "set.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const Set &set) {
  out << "{ ";
  for (auto it = set.numbers.begin(); it != set.numbers.end(); ++it) {
    out << *it;
    if (next(it) != set.numbers.end()) {
      out << ", ";
    }
  }
  out << " }" << endl;
  return out;
}

int main() {

  Set a;
  cout << "a = " << a;

  a += 8;
  a += 4;
  a += 8;
  a += 16;
  cout << "a = " << a;

  Set b;
  b += 4;
  b += 7;
  b += 11;
  b += 6;
  cout << "b = " << b;

  Set c;
  c = a || b;
  cout << "c = " << c;

  a = b;
  cout << "a = " << b;
}
