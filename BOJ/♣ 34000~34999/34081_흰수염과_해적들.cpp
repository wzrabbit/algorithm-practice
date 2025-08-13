#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct Pirate {
    ll d, c;
};

bool operator<(const Pirate &a, const Pirate &b) { return a.d > b.d; }

ll sqrt(ll num) {
    ll start = 1;
    ll end = 1'000'000'000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (mid * mid <= num) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, L;
    cin >> N >> L;

    vector<Pirate> pirates;
    priority_queue<ll> pq;

    for (int i = 0; i < N; i++) {
        ll x, y, c;
        cin >> x >> y >> c;

        ll result_sqrt = sqrt(x * x + y * y);
        if (result_sqrt * result_sqrt == x * x + y * y) {
            pirates.push_back({L - result_sqrt + 1, c});
        } else {
            pirates.push_back({L - result_sqrt, c});
        }
    }

    sort(pirates.begin(), pirates.end());
    ll p = 0;
    ll bounty = 0;

    for (int i = N; i >= 1; i--) {
        while (p < N && pirates[p].d >= i) {
            pq.push(pirates[p].c);
            p += 1;
        }

        if (!pq.empty()) {
            bounty += pq.top();
            pq.pop();
        }
    }

    cout << bounty;
}
