#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll chest_times[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> chest_times[i];
        }

        sort(chest_times + 1, chest_times + N + 1);

        ll golden_key_time = 0;
        for (int i = 1; i <= N - K; i++) {
            golden_key_time += chest_times[i];
        }

        ll silver_key_time = chest_times[N];

        cout << max(golden_key_time, silver_key_time) << '\n';
    }
}