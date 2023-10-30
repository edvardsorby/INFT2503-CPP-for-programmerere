#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;

  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  auto pos = find_if(v1.begin(), v1.end(), [](int i) {
    return i > 15;
  });
  cout << "Første element større enn 15 er " << *pos << endl;

  auto pos2 = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i, int j) {
    return abs(i - j) <= 2;
  });

  if (pos2)
    cout << "[v1.begin(), v1.begin() + 5> og v2 er like" << endl;
  else
    cout << "[v1.begin(), v1.begin() + 5> og v2 er ikke like" << endl;

  pos2 = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i, int j) {
    return abs(i - j) <= 2;
  });

  if (pos2)
    cout << "[v1.begin(), v1.begin() + 4> og v2 er like" << endl;
  else
    cout << "[v1.begin(), v1.begin() + 4> og v2 er ikke like" << endl;

  replace_copy_if(
      v1.begin(), v1.end(), v1.begin(), [](int i) {
        return (i % 2) == 1;
      },
      100);

  cout << "Alle oddetall i v1 erstattet med 100: " << v1 << endl;
}
