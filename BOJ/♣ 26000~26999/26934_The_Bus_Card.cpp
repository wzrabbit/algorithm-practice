#include <algorithm>
#include <initializer_list>
#include <iostream>
#define INF 99999
using namespace std;

int dp[10001];

int main() {
    int N;
    cin >> N;

    if (N % 100 != 0) {
        N = N / 100 * 100 + 100;
    }

    for (int i = 100; i <= N; i++) {
        dp[i] = min({dp[i - 100],
                     i >= 200 ? dp[i - 200] : INF,
                     i >= 500 ? dp[i - 500] : INF}) +
                1;
    }

    cout << dp[N];
}