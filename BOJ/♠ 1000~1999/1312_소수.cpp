#include <iostream>
using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;

    int decimal_count = 0;
    A %= B;

    while (true) {
        A *= 10;
        decimal_count += 1;

        if (decimal_count == N) {
            cout << A / B;
            return 0;
        }

        A %= B;
    }
}