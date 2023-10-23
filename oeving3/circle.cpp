const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_); // Manglet stor forbokstav
  int get_area() const;
  double get_circumference() const;

private: // Manglet kolon
  double radius;
}; // Manglet semikolon

// ==> Implementasjon av klassen Circle

// Fjernet "public:"
Circle::Circle(double radius_) : radius(radius_) {} // Byttet om navnet på variablene for å få riktig referanse

int Circle::get_area() const { // La til const
  return pi * radius * radius;
}

double Circle::get_circumference() const { // La til type (double)
  // Fjernet unødvendig deklarasjon
  return 2.0 * pi * radius;
}
