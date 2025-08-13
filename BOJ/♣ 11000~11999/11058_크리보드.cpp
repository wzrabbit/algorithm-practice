#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll dp[101];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i] + 1);

        for (int j = i + 3; j <= N; j++) {
            dp[j] = max(dp[j], dp[i] + (j - i - 2) * dp[i]);
        }
    }

    cout << dp[N];
}
