#include <algorithm>
#include <iostream>
using namespace std;

int arr[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    int before = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            before += arr[i];
            arr[i] *= -1;
        }
    }

    int best = -1000000001;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        cur += arr[i];
        best = max(best, cur);
        if (cur < 0) cur = 0;
    }

    cout << before + best;
}