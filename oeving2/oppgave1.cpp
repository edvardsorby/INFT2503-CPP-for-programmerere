#include <iostream>

using namespace std;

int main() {

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "Adresse til i: " << &i << "\n";
  cout << "Adresse til *p: " << &*p << "\n";
  cout << "Adresse til j: " << &j << "\n";
  cout << "Adresse til *q: " << &*q << "\n";

  cout << "Innholdet til i: " << i << "\n";
  cout << "Innholdet til *p: " << *p << "\n";
  cout << "Innholdet til j: " << j << "\n";
  cout << "Innholdet til *q: " << *q << "\n";

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << "*p er nå " << *p << " og *q er " << *q << endl;
}
