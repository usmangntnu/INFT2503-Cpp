#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // oppretter en vektor av double med fem tall
  vector<double> numbers = {1.1, 2.2, 3.3, 4.4, 5.5};

  // prøver ut medlemsfunksjonene front() og back()
  cout << "Første element (front): " << numbers.front() << endl;
  cout << "Andre element (back): " << numbers.back() << endl;

  // bruker emplace()
  numbers.emplace(numbers.begin() + 1, 0.2);

  cout << "Etter emplace(): " << endl;
  for (auto n : numbers)
    cout << n << " ";
  cout << endl;

  // Front() etterpå
  cout << "Front() etter emplace: " << numbers.front() << endl;

  // STL.algoritmen find()
  double target = 3.3;

  auto it = find(numbers.begin(), numbers.end(), target);

  // sjekker om vi fant tallet
  if (it != numbers.end()) {
    cout << "Fant verdien: " << *it << endl;
  } else {
    cout << "Verdien " << target << " finnes ikke i vektoren." << endl;
  }

  return 0;
}
