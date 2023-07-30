#include <iostream>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    N = N / 100 * 100;

    for (int i = 0; i <= 99; i++) {
        if ((N + i) % F == 0) {
            if (i <= 9) {
                cout << 0;
            }

            cout << i;
            break;
        }
    }
}