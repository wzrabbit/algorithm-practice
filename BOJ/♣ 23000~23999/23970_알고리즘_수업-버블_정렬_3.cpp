#include <algorithm>
#include <iostream>
using namespace std;

int before[10001];
int after[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int diff = 0;

    for (int i = 1; i <= N; i++) {
        cin >> before[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> after[i];

        if (before[i] != after[i]) {
            diff += 1;
        }
    }

    if (diff == 0) {
        cout << 1;
        return 0;
    }

    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (before[j] > before[j + 1]) {
                int diff_updates = 0;

                if (before[j] == after[j]) {
                    diff_updates += 1;
                }

                if (before[j + 1] == after[j + 1]) {
                    diff_updates += 1;
                }

                swap(before[j], before[j + 1]);

                if (before[j] == after[j]) {
                    diff_updates -= 1;
                }

                if (before[j + 1] == after[j + 1]) {
                    diff_updates -= 1;
                }

                diff += diff_updates;

                if (diff == 0) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
}