#include <algorithm>
#include <iostream>
using namespace std;

int arr[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;

        swap(arr[x], arr[y]);
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}