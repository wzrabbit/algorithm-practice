#include <algorithm>
#include <iostream>
using namespace std;

int arr[300001];
int prefix[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
}