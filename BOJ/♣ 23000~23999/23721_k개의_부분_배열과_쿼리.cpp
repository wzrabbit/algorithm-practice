#include <algorithm>
#include <iostream>
using namespace std;

int arr[200001];
int prefix[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1];

        if (i != 1 && arr[i - 1] > arr[i]) {
            prefix[i] += 1;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int l, r;
        cin >> l >> r;

        int conflict = prefix[r] - prefix[l];

        if (arr[r] > arr[l] && conflict > 0) {
            conflict += 1;
        }

        cout << min(1 + conflict, 3) << '\n';
    }
}