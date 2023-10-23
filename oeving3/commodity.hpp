#pragma once

#include <string>

using namespace std;

class Commodity {
public:
  Commodity(string name_, int id_, double price_);

  string get_name() const { return name; }
  double get_id() const { return id; }
  double get_price() const { return price; }
  double get_price(double quantity) const;
  void set_price(double price_) { price = price_; }
  double get_price_with_sales_tax(double quantity) const;

private:
  string name;
  double id;
  double price;
};
