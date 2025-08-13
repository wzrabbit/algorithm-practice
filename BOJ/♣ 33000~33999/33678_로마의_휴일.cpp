#include <iostream>
using namespace std;

int arr[200001];
int prefix[200001];
int N, K, X;

bool is_possible(int start, int end) {
    int total_profit = prefix[start - 1] * X + prefix[N] - prefix[end];
    return total_profit >= K;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> X;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int start = i;
        int end = N;
        int mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (is_possible(i, mid)) {
                start = mid + 1;
                answer = max(answer, mid - i + 1);
            } else {
                end = mid - 1;
            }
        }
    }

    if (answer > 0) {
        cout << answer;
    } else {
        cout << -1;
    }
}
