#include <iostream>
using namespace std;

int arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int unit = min(N / 2, M);
    int left = M;

    for (int i = 1; i <= unit; i++) {
        arr[i] = 1;
        left -= 1;
    }

    for (int i = unit + 2; i <= N; i++) {
        int matched = min(left, unit + 1);
        arr[i] = matched;
        left -= matched;
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}
