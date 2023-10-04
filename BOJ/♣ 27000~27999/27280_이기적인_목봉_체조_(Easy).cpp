#include <iostream>
#define INF 100000000000000
typedef long long ll;
using namespace std;

struct Trainee {
    ll h, s;
};

Trainee trainees[1001];
ll values[1001][1001];
ll dp[11][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    fill(&dp[0][0], &dp[N][N + 1], -INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        ll h, s;
        cin >> h >> s;

        trainees[i].h = h;
        trainees[i].s = s;
    }

    for (int i = 1; i <= N; i++) {
        ll best_height = 0;
        ll total_strength = 0;

        for (int j = i; j <= N; j++) {
            Trainee cur = trainees[j];

            if (cur.h > best_height) {
                best_height = cur.h;
                total_strength = cur.s;
            } else if (cur.h == best_height) {
                total_strength += cur.s;
            }

            values[i][j] = total_strength;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + values[k + 1][j]);
            }
        }
    }

    cout << dp[M][N];
}