#include <cassert>
#include <iostream>
using namespace std;

int digit[40];
bool is_appeared[40];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        fill(digit, digit + 40, -1);
        fill(is_appeared, is_appeared + 40, false);
        digit[39] = N;

        for (int i = 39; i >= 0; i--) {
            if (digit[i] / K == 0) break;
            digit[i - 1] = digit[i] / K;
            digit[i] %= K;
        }

        cout << "Base-" << K << " representation of " << N << " is ";

        for (int i = 0; i < 40; i++) {
            if (digit[i] >= 0) {
                if (digit[i] >= 10)
                    cout << (char)('a' + digit[i] - 10);
                else
                    cout << digit[i];

                is_appeared[digit[i]] = true;
            }
        }

        bool all_appeared = true;
        cout << "; ";

        for (int i = 0; i < K; i++) {
            if (!is_appeared[i]) {
                all_appeared = false;
                break;
            }
        }

        if (all_appeared)
            cout << "contains all digits.\n";
        else
            cout << "does not contain all digits.\n";
    }
}