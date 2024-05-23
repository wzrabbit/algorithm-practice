#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int A, B;
        cin >> A >> B;

        int best = 99999999;

        for (int a = 0; a <= 1000; a++) {
            for (int b = a * 3; b <= a * 4; b++) {
                if (A <= a && B <= b) {
                    best = min(best, a - A + b - B);
                }
            }
        }

        cout << best << '\n';
    }
}
