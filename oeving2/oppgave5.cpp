#include <iostream>

using namespace std;

int main() {

  double number;

  double *pointer = &number;

  double &ref = number;

  // Kan tilordne verdi på vanlig måte:
  number = 1;
  cout << "number = " << number << endl;

  // Kan tilordne verdi med pekeren:
  *pointer = 2;
  cout << "number = " << number << endl;

  // Kan tilordne verdi med referansen:
  ref = 3;
  cout << "number = " << number << endl;
}
