#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

struct Pos {
    ll l, n;
};

ll state[2][100001];
ll answer[50001];
ll N, M, T;
queue<Pos> q;

void move(ll no) {
    while (!q.empty() && q.front().l == no % 2) {
        Pos cur = q.front();
        q.pop();

        ll next_amount = state[cur.l][cur.n] / 5;

        if (next_amount == 0) {
            state[cur.l][cur.n] = 0;
            continue;
        }

        for (ll i = -1; i <= 1; i++) {
            ll n = cur.n + i;

            if (n < 1 || n > N) {
                continue;
            }

            if (state[1 - cur.l][n] == 0) {
                q.push({1 - cur.l, n});
            }

            state[1 - cur.l][n] += next_amount;
            answer[no] += next_amount;
        }

        state[cur.l][cur.n] = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> T;

    for (ll t = 1; t <= T; t++) {
        ll target, amount;
        cin >> target >> amount;

        if (state[t % 2][target] == 0) {
            q.push({t % 2, target});
        }

        state[t % 2][target] += amount;

        if (state[t % 2][target] > M) {
            state[t % 2][target] = M;
        }

        move(t);
    }

    for (ll i = 1; i <= T; i++) {
        cout << answer[i] << '\n';
    }
}
