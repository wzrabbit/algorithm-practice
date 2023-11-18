#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Range {
    int s, e;
};

bool operator<(const Range& a, const Range& b) {
    if (a.s != b.s) {
        return a.s < b.s;
    }

    return a.e > b.e;
}

vector<Range> raw_ranges;
vector<Range> limit_ranges;
int arr[200001];
int prev_value[200001];
ll dp[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;

        raw_ranges.push_back({s, e});
    }

    sort(raw_ranges.begin(), raw_ranges.end());
    Range cur_range = raw_ranges[0];

    for (int i = 1; i < M; i++) {
        if (raw_ranges[i].e > cur_range.e) {
            limit_ranges.push_back(cur_range);
            cur_range = raw_ranges[i];
        }
    }

    limit_ranges.push_back(cur_range);

    fill(prev_value + 1, prev_value + N + 1, -1);
    int prev_end = 0;

    for (size_t i = 0; i < limit_ranges.size(); i++) {
        for (int j = max(limit_ranges[i].s, prev_end + 1); j <= limit_ranges[i].e; j++) {
            prev_value[j] = limit_ranges[i].s - 1;
        }

        prev_end = limit_ranges[i].e;
    }

    for (int i = 1; i <= N; i++) {
        if (prev_value[i] == -1) {
            prev_value[i] = i - 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[prev_value[i]] + (ll)arr[i]);
    }

    cout << dp[N];
}