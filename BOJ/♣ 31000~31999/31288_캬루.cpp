#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;

        cin >> N >> S;

        int remainder = 0;

        for (int i = 0; i < N; i++) {
            remainder = (remainder + (S[i] - '0')) % 3;
        }

        for (int i = 0; i < N; i++) {
            int selected_num = S[i] - '0' + 3 - remainder;

            if (selected_num >= 10) {
                selected_num -= 9;
            }

            if (selected_num == 0 || selected_num == 3) {
                selected_num = 6;
            }

            for (int j = 0; j < N; j++) {
                if (j == i) {
                    cout << selected_num;
                } else {
                    cout << S[j];
                }
            }

            cout << ' ' << 3 << '\n';
        }
    }
}
