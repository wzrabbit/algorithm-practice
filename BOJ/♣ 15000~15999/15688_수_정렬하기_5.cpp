#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << '\n';
    }
}
