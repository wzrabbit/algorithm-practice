#include <algorithm>
#include <iostream>
using namespace std;

int arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int l = 1;
    int r = N;
    int answer = 0;

    while (arr[r] >= K) {
        r -= 1;
        answer += 1;
    }

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (sum >= K) {
            answer += 1;
            l += 1;
            r -= 1;
        } else {
            l += 1;
        }
    }

    if (answer == 0) {
        cout << -1;
    } else {
        cout << answer;
    }
}
