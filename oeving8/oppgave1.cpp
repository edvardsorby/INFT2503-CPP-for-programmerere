#include <iomanip>
#include <iostream>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {

  cout << "Er " << a << " lik " << b << "?" << endl;
  cout << "Bruker funksjonstemplaten:" << endl;

  if (a == b) {
    return true;
  } else {
    return false;
  }
}

bool equal(double a, double b) {

  cout << "Er " << a << " lik " << b << "?" << endl;
  cout << "Bruker spesialutgaven:" << endl;

  double threshold = 0.00001;

  if (abs(a - b) < threshold) {
    return true;
  } else {
    return false;
  }
}

int main() {

  cout << equal(1, 2) << endl
       << endl;
  cout << equal(5, 5) << endl
       << endl;

  cout << equal(true, false) << endl
       << endl;
  cout << equal(false, false) << endl
       << endl;

  cout << equal("Hello", "there") << endl
       << endl;
  cout << equal("Hei", "Hei") << endl
       << endl;

  cout << equal(1.0, 1.00001) << endl
       << endl;
  cout << setprecision(10) << equal(1.0, 1.000001) << endl
       << endl;
}
