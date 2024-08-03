#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> state;
ll N, M;

void solve() {
    ll selected = 0;

    for (ll i = 1; i <= M; i++) {
        if (state[i] > 0) {
            selected = i;
            break;
        }
    }

    cout << selected << ' ';

    for (ll i = 0; i <= M - selected; i++) {
        state[i + selected] -= state[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (ll i = 0; i <= M; i++) {
        ll cur;
        cin >> cur;

        state.push_back(cur);
    }

    for (int i = 0; i < N; i++) {
        solve();
    }
}
