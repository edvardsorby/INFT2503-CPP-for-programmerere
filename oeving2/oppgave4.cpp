int main() {

  int a = 5;
  int &b = a; // Vi kan ikke ha en referanse uten å referere til noe.
  int *c;
  c = &b;
  a = b + *c; // a og b er ikke en pekere
  b = 2;      // Vi kan ikke sette adressen til b til en int
}
