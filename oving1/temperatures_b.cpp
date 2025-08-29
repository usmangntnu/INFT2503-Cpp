#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;
  double temperatures[length];

  read_temperatures(temperatures, length);

  int under10 = 0, between10and20 = 0, over20 = 0;

  for (int i = 0; i < length; ++i) {
    if (temperatures[i] < 10)
      ++under10;
    else if (temperatures[i] <= 20)
      ++between10and20;
    else
      ++over20;
  }

  cout << "Antall under 10 er " << under10 << '\n'
       << "Antall mellom 10 og 20 er " << between10and20 << '\n'
       << "Antall over 20 er " << over20 << endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {
  ifstream file("temperatures.dat");
  if (!file) {
    cout << "Feil ved åpning av innfil." << endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; ++i) {
    if (!(file >> temperatures[i])) {
      cout << "For få eller ugyldige verdier i filen." << endl;
      exit(EXIT_FAILURE);
    }
  }
}
