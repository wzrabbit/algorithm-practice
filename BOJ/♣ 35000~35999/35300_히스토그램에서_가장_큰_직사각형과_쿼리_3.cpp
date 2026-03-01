#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
using namespace std;

int arr[51];
int result[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);

    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    for (int i = 1; i <= 10000; i++) {
        shuffle(arr + 1, arr + N + 1, generator);

        cout << "? ";

        for (int i = 1; i <= N; i++) {
            cout << arr[i] << ' ';
        }

        cout << endl;

        int l, r, h;
        cin >> l >> r >> h;

        for (int j = l; j <= r; j++) {
            result[arr[j]] = max(result[arr[j]], h);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == N / 2 + 1) {
            cout << "! " << i << endl;
            return 0;
        }
    }
}
