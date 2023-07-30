#include <algorithm>
#include <initializer_list>
#include <iostream>
using namespace std;

int power_strip[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> power_strip[i];
    }

    sort(power_strip + 1, power_strip + N + 1);

    if (N == 1) {
        cout << power_strip[1];
        return 0;
    }

    if (N == 2) {
        cout << power_strip[1] + power_strip[2] - 1;
        return 0;
    }

    if (N % 3 == 2) {
        cout << power_strip[N / 3] + power_strip[N - N / 3 - 1] + power_strip[N] - 3;
        return 0;
    }

    cout << power_strip[N / 3] + power_strip[N / 3 * 2] + power_strip[N] - 3;
}