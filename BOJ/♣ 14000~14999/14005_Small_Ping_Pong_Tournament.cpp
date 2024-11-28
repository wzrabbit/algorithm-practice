#include <algorithm>
#include <iostream>
using namespace std;

int arr[1 << 3];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    N = 1 << N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int dudu_score = arr[0];

    sort(arr, arr + N);

    if (arr[0] == dudu_score && arr[1] > dudu_score) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}
