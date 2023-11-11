#include <iostream>
using namespace std;

int occured[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        occured[cur] += 1;
    }

    int best_number = 0;
    int best_occured = 0;

    for (int i = 1; i <= 10000; i++) {
        if (occured[i] > best_occured) {
            best_number = i;
            best_occured = occured[i];
        }
    }

    cout << best_number;
}