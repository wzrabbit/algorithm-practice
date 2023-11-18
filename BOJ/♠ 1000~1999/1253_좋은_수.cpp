#include <algorithm>
#include <iostream>
using namespace std;

int arr[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int good_count = 0;

    for (int i = 1; i <= N; i++) {
        int l = 1;
        int r = N;

        while (l < r) {
            if (arr[l] + arr[r] == arr[i]) {
                if (l == i) {
                    l += 1;
                    continue;
                }

                if (r == i) {
                    r -= 1;
                    continue;
                }

                good_count += 1;
                break;
            }

            if (arr[l] + arr[r] > arr[i]) {
                r -= 1;
            } else {
                l += 1;
            }
        }
    }

    cout << good_count;
}