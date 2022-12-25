#include <algorithm>
#include <iostream>
#define INF 999999999999999999
typedef long long ll;
using namespace std;

ll x_pos[101];
ll cost[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, scale, cur_x;
    cin >> N;

    fill(x_pos + 1, x_pos + 101, -1);
    cin >> scale;
    x_pos[scale] = scale;
    cur_x = scale * 2;

    for (int i = 2; i <= N; i++) {
        cin >> scale;
        ll best_cost = INF;
        cur_x += scale;

        for (int j = 1; j <= 100; j++) {
            if (x_pos[j] == -1) continue;

            ll x_gap = cur_x - x_pos[j];
            ll y_gap = abs(j - scale);

            best_cost = min(best_cost, cost[j] + x_gap * x_gap + y_gap * y_gap);
        }

        x_pos[scale] = cur_x;
        cost[scale] = best_cost;
        cur_x += scale;

        if (i == N) {
            cout << cost[scale];
        }
    }
}