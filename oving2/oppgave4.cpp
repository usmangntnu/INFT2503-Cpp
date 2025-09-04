#include <iostream>
using namespace std;

int main() {
    int a = 5;

    // int &b;
    // Feil: en referanse må alltid initialiseres
    int x = 0;
    int &b = x;  // korrekt: b refererer til x

    int *c;
    c = &b;  // ok: c peker på objektet som b refererer til (x)

    // *a = *b + *c;
    // Feil: a og b er ikke pekere, * kan ikke brukes her
    a = b + *c;   // korrekt syntaks

    // &b = 2;
    // Feil: &b er en adresse, man kan ikke tilordne til en adresse
    b = 2;        // korrekt: endrer verdien som referansen b peker til

    cout << "a = " << a << ", b = " << b << ", *c = " << *c << endl;

    return 0;
}
