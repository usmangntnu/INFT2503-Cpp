#include <iostream>
using namespace std;

void print_state(int i, int j, int* p, int* q, string step) {
    cout << "--- " << step << " ---" << endl;
    cout << "i: verdi = " << i << ", adresse = " << &i << endl;
    cout << "j: verdi = " << j << ", adresse = " << &j << endl;
    cout << "p: peker til " << p << ", *p = " << *p << ", adresse til p = " << &p << endl;
    cout << "q: peker til " << q << ", *q = " << *q << ", adresse til q = " << &q << endl;
    cout << endl;
}

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    print_state(i, j, p, q, "Start");

    *p = 7;
    print_state(i, j, p, q, "*p = 7");

    *q += 4;
    print_state(i, j, p, q, "*q += 4");

    *q = *p + 1;
    print_state(i, j, p, q, "*q = *p + 1");

    p = q;
    print_state(i, j, p, q, "p = q");

    cout << "Sluttutskrift: " << *p << " " << *q << endl;

    return 0;
}
