#include <algorithm>
#include <initializer_list>
#include <iostream>
typedef long long ll;
using namespace std;

ll dp[3001][3001];  // dp[x, x+1이 슬롯에 있음][y가 슬롯에 있음]
ll stick[3000];
int N;

ll top_down(int x, int y) {
    ll &cur = dp[x][y];

    if (x == N - 1) return cur = stick[x] * stick[y];
    if (x == N) return cur = 0;
    if (cur != -1) return cur;

    cur = max({top_down(x + 2, y) + stick[x] * stick[x + 1],
               top_down(x + 2, x + 1) + stick[x] * stick[y],
               top_down(x + 2, x) + stick[x + 1] * stick[y]});

    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> stick[i];

    fill(&dp[0][0], &dp[N][N + 1], -1);
    cout << top_down(1, 0);  // 0, 1, 2
}