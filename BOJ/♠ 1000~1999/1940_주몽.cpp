#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int l = 1;
    int r = N;
    int armor_count = 0;

    while (l < r) {
        if (arr[l] + arr[r] > M) {
            r -= 1;
            continue;
        }

        if (arr[l] + arr[r] < M) {
            l += 1;
            continue;
        }

        armor_count += 1;
        l += 1;
        r -= 1;
    }

    cout << armor_count;
}
