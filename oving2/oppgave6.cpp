#include <iostream>
using namespace std;

// Funksjon som finner summen av elementer i en tabell
int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += table[i];
    }
    return sum;
}

int main() {
    const int SIZE = 20;
    int numbers[SIZE];

    // Fyll tabellen med 1, 2, 3, ..., 20
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = i + 1;
    }

    // Finn summen av de 10 første tallene
    int sum_first10 = find_sum(numbers, 10);

    // Finn summen av de neste 5 tallene (indeks 10–14)
    int sum_next5 = find_sum(numbers + 10, 5);

    // Finn summen av de siste 5 tallene (indeks 15–19)
    int sum_last5 = find_sum(numbers + 15, 5);

    cout << "Sum av de 10 første tallene: " << sum_first10 << endl;
    cout << "Sum av de neste 5 tallene: " << sum_next5 << endl;
    cout << "Sum av de siste 5 tallene: " << sum_last5 << endl;

    return 0;
}
