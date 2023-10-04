#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int total = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        total += cur;

        if (total == K) {
            cout << K;
            return 0;
        } else if (total == K + 1) {
            cout << K - 1;
            return 0;
        }
    }
}