#include <algorithm>
#include <iostream>
using namespace std;

int arr[500000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int l = 0;
    int r = 0;
    int cur_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while (r < N) {
        if (cur_sum < M) {
            cur_sum += arr[r];
            r++;
        } else {
            cur_sum -= arr[l];
            l++;
        }

        if (cur_sum <= M) {
            max_sum = max(max_sum, cur_sum);
        }
    }

    cout << max_sum;
}