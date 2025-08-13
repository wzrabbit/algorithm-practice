#include <algorithm>
#include <iostream>
using namespace std;

int arr[1048577];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int K;
    cin >> K;
    K = N / K;

    for (int i = 2; i <= K; i *= 2) {
        for (int j = 1; j <= N; j += i) {
            sort(arr + j, arr + j + i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}
