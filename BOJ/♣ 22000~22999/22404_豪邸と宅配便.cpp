#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, T;
    cin >> N >> M >> T;

    int prev = 0;
    int ans = 0;
    int cur;

    cin >> cur;
    ans = max(0, cur - M);
    prev = cur;

    for (int i = 1; i < N; i++) {
        cin >> cur;
        ans += max(0, cur - prev - M * 2);
        prev = cur;
    }

    ans += max(0, T - prev - M);
    cout << ans;
}