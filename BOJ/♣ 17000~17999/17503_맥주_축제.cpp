#include <algorithm>
#include <iostream>
#define INF 2'147'483'647LL
typedef long long ll;
using namespace std;

struct Beer {
    ll pt, lv;
};

bool operator<(const Beer &a, const Beer &b) {
    return a.pt > b.pt;
}

Beer beers[200001];
int N, K;
ll goal;

bool is_possible(ll limit) {
    ll drink_count = 0;
    ll total_pt = 0;

    for (int i = 1; i <= K; i++) {
        if (drink_count == N) {
            break;
        }

        if (beers[i].lv <= limit) {
            drink_count += 1;
            total_pt += beers[i].pt;
        }
    }

    return total_pt >= goal && drink_count == N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> goal >> K;

    for (int i = 1; i <= K; i++) {
        ll pt, lv;
        cin >> pt >> lv;

        beers[i] = {pt, lv};
    }

    sort(beers + 1, beers + K + 1);

    ll start = 1;
    ll end = INF;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (start == INF + 1) {
        cout << -1;
    } else {
        cout << start;
    }
}
