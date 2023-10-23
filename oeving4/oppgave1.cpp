#include <algorithm> // header-fil for algoritmer
#include <iostream>
#include <vector> // header-fil for vector

using namespace std;

int main() {

  vector<double> numbers;

  numbers.emplace_back(3);
  numbers.emplace_back(12);
  numbers.emplace_back(6);
  numbers.emplace_back(55);
  numbers.emplace_back(9);

  cout << numbers.front() << endl;
  cout << numbers.back() << endl;

  numbers.emplace(numbers.begin(), 7);

  cout << numbers.front() << endl;

  auto result = find(numbers.begin(), numbers.end(), 55);
  if (result != numbers.end()) {
    cout << "Fant tallet " << *result << endl;
  } else {
    cout << "Fant ikke tallet" << endl;
  }
}
