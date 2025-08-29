#include <iostream>
using namespace std;

int main() {
  const int length = 5;
  int under10 = 0, between10and20 = 0, over20 = 0;

  cout << "Du skal skrive inn " << length << " temperaturer." << endl;

  for (int i = 0; i < length; ++i) {
    double temp;
    cout << "Temperatur nr " << i + 1 << ": ";
    cin >> temp;

    if (temp < 10)
      ++under10;
    else if (temp <= 20)
      ++between10and20;
    else
      ++over20;
  }

  cout << "Antall under 10 er " << under10 << '\n'
       << "Antall mellom 10 og 20 er " << between10and20 << '\n'
       << "Antall over 20 er " << over20 << endl;

  return 0;
}
