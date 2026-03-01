#include <algorithm>
#include <iostream>
using namespace std;

int arr[1001];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int answer = 0;

    for (int i = 1; i <= 10000 - K; i++) {
        int cur = 0;

        for (int j = 1; j <= N; j++) {
            if (arr[j] >= i && arr[j] <= i + K) {
                cur += 1;
            }
        }

        answer = max(answer, cur);
    }

    cout << answer;
}
