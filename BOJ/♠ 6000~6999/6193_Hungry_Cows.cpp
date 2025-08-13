#include <iostream>
using namespace std;

int arr[5001];
int dp[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = 1;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer;
}
