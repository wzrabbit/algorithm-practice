#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int state = 0;
    int start = 1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        state |= cur;

        if ((state | K) != K) {
            state = 0;
            start = i + 1;
            continue;
        }

        if (state == K) {
            cout << start << ' ' << i;
            return 0;
        }
    }

    cout << -1;
}