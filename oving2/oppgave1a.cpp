#include <iostream>
using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "i: verdi = " << i << ", adresse = " << &i << endl;
    cout << "j: verdi = " << j << ", adresse = " << &j << endl;

    cout << "p: verdi (adressen den peker til) = " << p
         << ", adresse til p-variabelen = " << &p
         << ", innholdet *p = " << *p << endl;

    cout << "q: verdi (adressen den peker til) = " << q
         << ", adresse til q-variabelen = " << &q
         << ", innholdet *q = " << *q << endl;

    return 0;
}
