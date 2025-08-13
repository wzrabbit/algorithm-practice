#include <iostream>
typedef long long ll;
using namespace std;

ll X[2000002];
ll Y[2000002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    ll min_x_cost = 0;
    ll min_y_cost = 0;

    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;

        X[x + 1000001] += 1;
        Y[y + 1000001] += 1;
        min_x_cost += (x + 1000001) * A;
        min_y_cost += (y + 1000001) * C;
    }

    ll right_count = N;
    ll cur_x_cost = min_x_cost;

    for (int i = 1; i <= 2000001; i++) {
        cur_x_cost -= A * right_count;
        cur_x_cost += B * (N - right_count);
        right_count -= X[i];
        min_x_cost = min(min_x_cost, cur_x_cost);
    }

    ll down_count = N;
    ll cur_y_cost = min_y_cost;

    for (int i = 1; i <= 2000001; i++) {
        cur_y_cost -= C * down_count;
        cur_y_cost += D * (N - down_count);
        down_count -= Y[i];
        min_y_cost = min(min_y_cost, cur_y_cost);
    }

    cout << min_x_cost + min_y_cost;
}
