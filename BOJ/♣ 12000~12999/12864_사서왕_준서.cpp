#include <algorithm>
#include <iostream>
#define INF 600000000
using namespace std;

double book_no[5001];
int weight[5001];
int dp[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> book_no[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = weight[i];

        for (int j = 1; j < i; j++) {
            if (book_no[j] <= book_no[i]) {
                dp[i] = max(dp[i], dp[j] + weight[i]);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << sum - answer;
}
