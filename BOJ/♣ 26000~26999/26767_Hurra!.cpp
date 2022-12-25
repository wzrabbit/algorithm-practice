#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 7 == 0 && i % 11 == 0) {
            cout << "Wiwat!" << '\n';
            continue;
        }

        if (i % 7 == 0) {
            cout << "Hurra!" << '\n';
            continue;
        }

        if (i % 11 == 0) {
            cout << "Super!" << '\n';
            continue;
        }

        cout << i << '\n';
    }
}