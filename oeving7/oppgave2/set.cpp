#include "set.hpp"
#include <algorithm>
#include <vector>

using namespace std;

Set::Set() : numbers() {}

Set::Set(const Set &other) : numbers(other.numbers) {}

Set Set::operator||(const Set &other) const {
  Set set = *this;

  for (auto &number : other.numbers) {
    set += number;
  }

  return set;
}

void Set::operator+=(int number) {
  if (find(numbers.begin(), numbers.end(), number) == numbers.end()) {
    numbers.emplace_back(number);
  }
}

Set &Set::operator=(const Set &other) {
  numbers = other.numbers;
  return *this;
}
