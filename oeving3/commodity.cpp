#include "commodity.hpp"
#include <string>

const double tax = 25.0;

using namespace std;

Commodity::Commodity(string name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

double Commodity::get_price(double quantity) const {
  return quantity * price;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
  return quantity * price * (1 + tax / 100);
}
