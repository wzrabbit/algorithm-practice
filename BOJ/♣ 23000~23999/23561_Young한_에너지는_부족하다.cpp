#include <algorithm>
#include <iostream>
using namespace std;

int arr[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= 3 * N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 3 * N + 1);
    cout << arr[2 * N] - arr[N + 1];
}