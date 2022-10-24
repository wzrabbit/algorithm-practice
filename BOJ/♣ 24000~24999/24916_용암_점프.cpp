#include <algorithm>
#include <iostream>
#define INF 10000000
using namespace std;

int arr[100001];
int dp[22][22][2];

int top_down(int left, int right, int pos) {
    int& cur = dp[left][right][pos];

    if (cur != -1)
        return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        if (N >= 22) {
            for (int i = 1; i <= N; i++) {
                cout << "NO\n";
            }
            continue;
        }

        for (int i = 1; i <= N; i++) {
            fill(&dp[1][1][0], &dp[N][N][2], -1);
            dp[i][i][0] = 0;

            if (top_down(i, i, 0) == INF)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}