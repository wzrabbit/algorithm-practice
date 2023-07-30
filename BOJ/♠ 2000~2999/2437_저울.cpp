#include <algorithm>
#include <iostream>
using namespace std;

int weights[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> weights[i];
    }

    sort(weights + 1, weights + N + 1);

    int sum = 0;

    for (int i = 1; i <= N; i++) {
        if (weights[i] > sum + 1) {
            cout << sum + 1;
            return 0;
        }

        sum += weights[i];
    }

    cout << sum + 1;
}