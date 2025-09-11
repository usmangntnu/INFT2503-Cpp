#pragma once
#include <string>
using namespace std;

const double sales_tax = 0.25; // 25 % moms

class Commodity {
public:
  Commodity(const string &name_, int id_, double price_);

  string get_name() const;
  int get_id() const;

  double get_price() const;                // pris per enhet
  double get_price(double quantity) const; // pris for antall enheter
  double get_price_with_sales_tax(double quantity) const;

  void set_price(double new_price);

private:
  string name;
  int id;
  double price; // pris uten moms
};
