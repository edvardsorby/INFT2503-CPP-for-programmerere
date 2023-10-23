#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {

  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}

int main() {

  const int table[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int sum1 = find_sum(&table[0], 10);
  cout << sum1 << endl;
  int sum2 = find_sum(&table[10], 5);
  cout << sum2 << endl;
  int sum3 = find_sum(&table[15], 5);
  cout << sum3 << endl;
}
