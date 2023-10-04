#include <algorithm>
#include <iostream>
#define MAX 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Area {
    ll s, e;
};

bool operator<(const Area& a, const Area& b) {
    return a.s < b.s;
}

Area area[100001];
int N, M;

bool is_possible(ll interval) {
    int index = 1;
    int success_count = 1;
    ll pos = area[1].s;
    ll distance_left = interval;

    while (success_count < N) {
        if (pos + distance_left <= area[index].e) {
            success_count += 1;
            pos += distance_left;
            distance_left = interval;

            continue;
        }

        index += 1;

        if (index > M) {
            return false;
        }

        ll gap = area[index].s - pos;
        pos = area[index].s;
        distance_left = max(0ll, distance_left - gap);
    }

    return success_count == N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        ll s, e;
        cin >> s >> e;

        area[i] = {s, e};
    }

    sort(area + 1, area + M + 1);

    ll start = 1;
    ll end = MAX;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}