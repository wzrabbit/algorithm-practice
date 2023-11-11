#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int get_difference(string a, string b, string c) {
    int difference = 0;

    for (size_t i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            difference += 1;
        }

        if (a[i] != c[i]) {
            difference += 1;
        }

        if (b[i] != c[i]) {
            difference += 1;
        }
    }

    return difference;
}

string mbtis[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> mbtis[i];
        }

        if (N >= 33) {
            cout << 0 << '\n';
            continue;
        }

        int minimum_difference = 12;

        for (int i = 1; i <= N - 2; i++) {
            for (int j = i + 1; j <= N - 1; j++) {
                for (int k = j + 1; k <= N; k++) {
                    minimum_difference = min(
                        minimum_difference,
                        get_difference(mbtis[i], mbtis[j], mbtis[k]));
                }
            }
        }

        cout << minimum_difference << '\n';
    }
}