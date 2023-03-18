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

        if (N % 2 == 0) {
            cout << "nO\n";
            continue;
        }

        cout << "yEs\n";

        int left = 2;
        int goal = 3 + (N - 1) / 2 * 3;

        for (int i = 1; i <= N / 2; i++) {
            cout << left << ' ' << goal - left << '\n';
            left += 2;
            goal += 1;
        }

        cout << 1 << ' ' << N * 2 << '\n';

        left = 3;
        goal += 1;

        for (int i = 1; i <= N / 2; i++) {
            cout << left << ' ' << goal - left << '\n';
            left += 2;
            goal += 1;
        }
    }
}