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

        int best, cur;

        for (int i = 1; i <= N; i++) {
            int num;
            cin >> num;

            if (i == 1) {
                best = num;
                cur = num;
                continue;
            }

            if (cur < 0) {
                cur = num;
            } else {
                cur += num;
            }

            best = max(best, cur);
        }

        cout << best << '\n';
    }
}
