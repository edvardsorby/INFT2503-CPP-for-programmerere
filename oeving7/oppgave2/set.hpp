#pragma once
#include <vector>

using namespace std;

class Set {
public:
  vector<int> numbers;

  Set();

  Set(const Set &other);

  Set operator||(const Set &other) const;

  void operator+=(int number);

  Set &operator=(const Set &other);
};
