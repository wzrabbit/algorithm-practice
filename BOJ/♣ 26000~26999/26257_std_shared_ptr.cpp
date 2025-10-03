#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }

    while (Q--) {
        string query;
        cin >> query;

        if (query == "assign") {
            int a, b;
            cin >> a >> b;
            arr[a] = arr[b];
            continue;
        }

        if (query == "swap") {
            int a, b;
            cin >> a >> b;
            swap(arr[a], arr[b]);
            continue;
        }

        int a;
        cin >> a;
        arr[a] = 0;
    }

    sort(arr + 1, arr + M + 1);

    int alive_count = 0;

    for (int i = 1; i <= M; i++) {
        if (arr[i] != 0 && arr[i] != arr[i - 1]) {
            alive_count += 1;
        }
    }

    cout << alive_count << '\n';

    for (int i = 1; i <= M; i++) {
        if (arr[i] != 0 && arr[i] != arr[i - 1]) {
            cout << arr[i] << '\n';
        }
    }
}
