#include <algorithm>
#include <initializer_list>
#include <iostream>
#define INF 2000000
using namespace std;

int dp[1000001];

int top_down(int num) {
    int &value = dp[num];
    if (value != INF) return value;

    value = min({top_down(num - 1) + 1,
                 num % 2 == 0 ? top_down(num / 2) + 1 : INF,
                 num % 3 == 0 ? top_down(num / 3) + 1 : INF});

    return value;
}

int main() {
    int N;
    cin >> N;

    fill(dp, dp + N + 1, INF);
    dp[1] = 0;

    cout << top_down(N);
}