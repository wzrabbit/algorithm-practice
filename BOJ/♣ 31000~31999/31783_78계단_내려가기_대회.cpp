#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

ll dp[300001];
ll height[300001];
ll score[300001];
ll durability[300001];

ll find_closest_prev_index(ll cur) {
    ll start = 1;
    ll end = cur - 1;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (height[mid] >= height[cur] + durability[cur]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    dp[0] = -INF;

    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    for (int i = 2; i <= N; i++) {
        cin >> score[i];
    }

    for (int i = 2; i <= N; i++) {
        cin >> durability[i];
    }

    for (int i = 2; i <= N; i++) {
        ll prev_index = find_closest_prev_index(i);
        dp[i] = max(dp[i - 1], dp[prev_index] + score[i]);
    }

    cout << dp[N];
}
