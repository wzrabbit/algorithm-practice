#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int total = 0;
        int mod_sum[4] = {0, 0, 0, 0};

        for (int i = 0; i < N; i++) {
            int cur;
            cin >> cur;
            mod_sum[i % 4] += cur;
            total += cur;
        }

        cout << "YES\n";

        for (int i = 0; i < 4; i++) {
            if (mod_sum[i] <= total / 4) {
                if (i == 0) cout << "0";
                if (i == 1) cout << "00";
                if (i == 2) cout << "010";
                if (i == 3) cout << "0220";

                int left = N - i - 1;

                while (left > 0) {
                    if (left >= 4) cout << "3330";
                    if (left == 3) cout << "333";
                    if (left == 2) cout << "22";
                    if (left == 1) cout << "1";
                    left -= 4;
                }

                cout << "\n";
                break;
            }
        }
    }
}
