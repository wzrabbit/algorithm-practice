#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int mul = 1;
        int A = 0;
        int B = 0;
        int direction = 0;

        for (int i = 1; i <= 10; i++) {
            int digit = N % 10;
            N /= 10;

            if (digit % 2 == 0) {
                A += digit / 2 * mul;
                B += digit / 2 * mul;
            } else {
                A += ((direction == 0) ? digit / 2 : digit / 2 + 1) * mul;
                B += ((direction == 1) ? digit / 2 : digit / 2 + 1) * mul;
                direction = 1 - direction;
            }

            mul *= 10;
        }

        cout << A << ' ' << B << '\n';
    }
}