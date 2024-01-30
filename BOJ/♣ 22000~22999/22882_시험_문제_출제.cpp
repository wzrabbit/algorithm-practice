#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll grid[21][21];
vector<ll> left_segments[21], right_segments[21], k_left_segments[21], k_right_segments[21];
ll N, K;

void add_left_segment(ll bit, ll size) {
    ll max_sum = grid[1][1];
    ll cur_sum = grid[1][1];
    ll r = 1;
    ll c = 1;

    while (size--) {
        if (bit & 1) {
            r += 1;
        } else {
            c += 1;
        }

        if (cur_sum < 0) {
            cur_sum = 0;
        }

        cur_sum += grid[r][c];
        max_sum = max(max_sum, cur_sum);

        bit >>= 1;
    }

    if (max_sum > K) {
        return;
    }

    if (max_sum == K) {
        k_left_segments[r].push_back(cur_sum);
        return;
    }

    left_segments[r].push_back(cur_sum);
}

void add_right_segment(ll bit, ll size) {
    ll max_sum = grid[N][N];
    ll cur_sum = grid[N][N];
    ll r = N;
    ll c = N;

    while (size--) {
        if (bit & 1) {
            r -= 1;
        } else {
            c -= 1;
        }

        if (cur_sum < 0) {
            cur_sum = 0;
        }

        cur_sum += grid[r][c];
        max_sum = max(max_sum, cur_sum);

        bit >>= 1;
    }

    if (max_sum > K) {
        return;
    }

    if (max_sum == K) {
        k_right_segments[r].push_back(cur_sum);
        k_right_segments[r - 1].push_back(cur_sum);
        return;
    }

    right_segments[r].push_back(cur_sum);
    right_segments[r - 1].push_back(cur_sum);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    if (N == 1) {
        cout << (grid[1][1] == K ? 1 : 0);
        return 0;
    }

    for (int i = 0; i < (1 << (N - 1)); i++) {
        add_left_segment(i, N - 1);
    }

    for (int i = 0; i < (1 << (N - 2)); i++) {
        add_right_segment(i, N - 2);
    }

    for (int r = 1; r <= N; r++) {
        sort(left_segments[r].begin(), left_segments[r].end());
        sort(right_segments[r].begin(), right_segments[r].end());
        sort(k_left_segments[r].begin(), k_left_segments[r].end());
        sort(k_right_segments[r].begin(), k_right_segments[r].end());
    }

    ll answer = 0;

    // left <-> right
    for (int r = 1; r <= N; r++) {
        for (size_t i = 0; i < left_segments[r].size(); i++) {
            ll target = K - left_segments[r][i];
            ll lower = lower_bound(right_segments[r].begin(), right_segments[r].end(), target) - right_segments[r].begin();
            ll upper = upper_bound(right_segments[r].begin(), right_segments[r].end(), target) - right_segments[r].begin();

            answer += upper - lower;
        }
    }

    // left <-> k_right
    for (int r = 1; r <= N; r++) {
        for (size_t i = 0; i < left_segments[r].size(); i++) {
            ll target = K - left_segments[r][i];
            ll upper = upper_bound(k_right_segments[r].begin(), k_right_segments[r].end(), target) - k_right_segments[r].begin();

            answer += upper;
        }
    }

    // k_left <-> right
    for (int r = 1; r <= N; r++) {
        for (size_t i = 0; i < k_left_segments[r].size(); i++) {
            ll target = K - k_left_segments[r][i];
            ll upper = upper_bound(right_segments[r].begin(), right_segments[r].end(), target) - right_segments[r].begin();

            answer += upper;
        }
    }

    // k_left <-> k_right
    for (int r = 1; r <= N; r++) {
        for (size_t i = 0; i < k_left_segments[r].size(); i++) {
            ll target = K - k_left_segments[r][i];
            ll upper = upper_bound(k_right_segments[r].begin(), k_right_segments[r].end(), target) - k_right_segments[r].begin();

            answer += upper;
        }
    }

    cout << answer;
}
