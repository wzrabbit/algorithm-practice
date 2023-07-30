#include <iostream>
using namespace std;

int N, d;

void perform_nine() {
    if (N % 9 != 0) {
        if (N % 9 == d) {
            if (d == 1) {
                cout << 28;
                N -= 9;
            } else {
                cout << 1 << d - 1;
            }
        } else {
            cout << N % 9;
        }
    }

    for (int i = 1; i <= N / 9; i++) {
        cout << 9;
    }
}

void perform_eight() {
    if (N % 8 != 0) {
        cout << N % 8;
    }

    for (int i = 1; i <= N / 8; i++) {
        cout << 8;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> d;

    if (N == 2) {
        if (d == 2) {
            cout << 11;
        } else {
            cout << 2;
        }

        return 0;
    }

    int nine_digit = N / 9;
    int eight_digit = N / 8;

    if (N % 9 != 0) {
        nine_digit += 1;
        if (N % 9 == d) nine_digit += 1;
    }

    if (N % 8 != 0) {
        eight_digit += 1;
        if (N % 8 == d) eight_digit += 1;
    }

    if (d == 9) {
        perform_eight();
        return 0;
    }

    if (d == 8) {
        perform_nine();
        return 0;
    }

    if (nine_digit <= eight_digit) {
        perform_nine();
    } else {
        perform_eight();
    }
}