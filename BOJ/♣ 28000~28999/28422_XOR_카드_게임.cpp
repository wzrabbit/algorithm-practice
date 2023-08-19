#include <algorithm>
#include <iostream>
#define INF 999999999
using namespace std;

int dp[100001];
int arr[100001];

int get_one_count(int num) {
    int one_count = 0;

    while (num > 0) {
        if (num % 2 == 1) {
            one_count += 1;
        }

        num >>= 1;
    }

    return one_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    dp[1] = -INF;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 2; i <= N; i++) {
        dp[i] = max(
            dp[i - 2] + get_one_count(arr[i - 1] ^ arr[i]),
            (i >= 3) ? dp[i - 3] + get_one_count(arr[i - 2] ^ arr[i - 1] ^ arr[i]) : 0);
    }

    cout << dp[N];
}