#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        int prev = 1;
        bool success = true;

        cin >> N;

        for (int i = 0; i < N; i++) {
            int num_x;
            cin >> num_x;
            int num_y = N - num_x + 1;

            if (max(num_x, num_y) < prev) {
                success = false;
            } else {
                if (num_x >= prev && num_y >= prev) {
                    prev = min(num_x, num_y);
                } else {
                    prev = max(num_x, num_y);
                }
            }
        }

        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}