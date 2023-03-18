#include <algorithm>
#include <iostream>
using namespace std;

int blocks[501];
bool dp[501][250001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> blocks[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 250000; j++) {
            if (blocks[i] == 2) {
                if (dp[i - 1][j]) dp[i][j] = true;
            }

            if (dp[i - 1][abs(j - blocks[i])]) dp[i][j] = true;
            if (dp[i - 1][j + blocks[i]]) dp[i][j] = true;
        }
    }

    if (dp[N][0]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}