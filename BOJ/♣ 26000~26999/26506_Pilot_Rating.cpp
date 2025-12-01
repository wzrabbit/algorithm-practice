#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int answer = 2000000;

    for (int i = 1; i <= N / 2; i++) {
        answer = min(answer, arr[i] + arr[N - i + 1]);
    }

    cout << answer;
}
