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
        int mx = N;
        int cur = N;

        while (cur > 1) {
            if (cur % 2 == 0) {
                cur /= 2;
            } else {
                cur = cur * 3 + 1;
            }
            mx = max(mx, cur);
        }

        cout << mx << '\n';
    }
}