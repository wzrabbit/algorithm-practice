#include <iostream>
using namespace std;

int dp[100001][30];
int query[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q, N, T;
    cin >> Q >> N >> T;
    T--;

    for (int i = 1; i <= Q; i++) {
        cin >> query[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> dp[i][0];
    }

    for (int j = 1; j <= 29; j++) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= Q; i++) {
        int video = query[i];
        for (int j = 0; j <= 29; j++) {
            if ((T & (1 << j)) > 0) video = dp[video][j];
        }
        cout << video << ' ';
    }
}