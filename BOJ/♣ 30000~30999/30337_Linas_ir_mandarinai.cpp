#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int day = 1;
    int left = K;
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] < day) {
            continue;
        }

        answer += 1;
        left -= 1;

        if (left == 0) {
            day += 1;
            left = K;
        }
    }

    cout << answer;
}
