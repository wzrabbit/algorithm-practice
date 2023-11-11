#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, K, m1, m2;
    cin >> T >> K >> m1 >> m2;

    int invalid_count = 0;

    while (T--) {
        int H, N;
        cin >> H >> N;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            int min_height = cur * m2;
            int max_height = cur * m1;

            if (H * K < min_height || H > max_height) {
                invalid_count += 1;
            }
        }
    }

    cout << invalid_count;
}