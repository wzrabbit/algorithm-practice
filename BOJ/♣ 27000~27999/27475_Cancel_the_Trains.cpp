#include <algorithm>
#include <iostream>
using namespace std;

int cnt[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        fill(cnt + 1, cnt + 101, 0);

        for (int i = 1; i <= A + B; i++) {
            int cur;
            cin >> cur;

            cnt[cur] += 1;
        }

        int cancel_count = 0;

        for (int i = 1; i <= 100; i++) {
            if (cnt[i] == 2) {
                cancel_count += 1;
            }
        }

        cout << cancel_count << '\n';
    }
}