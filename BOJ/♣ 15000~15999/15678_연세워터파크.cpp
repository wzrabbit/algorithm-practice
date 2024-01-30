#include <algorithm>
#include <iostream>
typedef long long ll;
#define INF 2'000'000'000
using namespace std;

ll dp[100001];
ll seg_tree[400001];

ll make_seg_tree(ll start, ll end, ll index) {
    if (start == end) {
        return seg_tree[index] = dp[end];
    }

    ll mid = (start + end) / 2;
    ll left_max = make_seg_tree(start, mid, index * 2);
    ll right_max = make_seg_tree(mid + 1, end, index * 2 + 1);

    return seg_tree[index] = max(left_max, right_max);
}

ll get_max_value(ll start, ll end, ll index, ll left, ll right) {
    if (left > end || right < start) {
        return -INF;
    }

    if (left <= start && end <= right) {
        return seg_tree[index];
    }

    ll mid = (start + end) / 2;
    ll left_max = get_max_value(start, mid, index * 2, left, right);
    ll right_max = get_max_value(mid + 1, end, index * 2 + 1, left, right);

    return max(left_max, right_max);
}

ll update_value(ll start, ll end, ll index, ll target, ll value) {
    if (target < start || target > end) {
        return seg_tree[index];
    }

    if (start == end) {
        return seg_tree[index] = value;
    }

    ll mid = (start + end) / 2;
    ll left_max = update_value(start, mid, index * 2, target, value);
    ll right_max = update_value(mid + 1, end, index * 2 + 1, target, value);

    return seg_tree[index] = max(left_max, right_max);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    for (int i = 1; i <= N; i++) {
        cin >> dp[i];
    }

    make_seg_tree(1, N, 1);

    ll answer = dp[1];

    for (int i = 2; i <= N; i++) {
        dp[i] += max(0ll, get_max_value(1, N, 1, max(1, i - D), i - 1));
        update_value(1, N, 1, i, dp[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer;
}