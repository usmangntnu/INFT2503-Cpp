#include <iostream>
using namespace std;

int main() {
    // Variabelen number
    double number = 0.0;

    // Definer en peker som peker til number
    double* ptr = &number;

    // Definer en referanse som refererer til number
    double& ref = number;

    // Tre måter å tilordne verdi til number på

    // a) Direkte tilordning
    number = 3.14;
    cout << "Etter direkte tilordning: number = " << number << endl;

    // b) Tilordning via peker
    *ptr = 6.28;
    cout << "Etter tilordning via peker: number = " << number << endl;

    // c) Tilordning via referanse
    ref = 9.42;
    cout << "Etter tilordning via referanse: number = " << number << endl;

    return 0;
}
