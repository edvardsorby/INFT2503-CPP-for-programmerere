#include <iostream>

using namespace std;

template <typename Type1, typename Type2>
class Pair {
public:
  Type1 first;
  Type2 second;

  Pair(Type1 first, Type2 second) : first(first), second(second) {}

  Pair operator+(const Pair &other) {
    Pair pair = *this;
    pair.first += other.first;
    pair.second += other.second;
    return pair;
  }

  bool operator>(const Pair &other) { // Forutsetter at en kan legge sammen typene som blir brukt i parene
    Pair pair = *this;
    auto sum1 = pair.first + pair.second;
    auto sum2 = other.first + other.second;

    if (sum1 > sum2) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/
