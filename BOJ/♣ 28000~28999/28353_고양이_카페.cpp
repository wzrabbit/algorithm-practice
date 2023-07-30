#include <algorithm>
#include <iostream>
using namespace std;

int cats[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> cats[i];
    }

    sort(cats + 1, cats + N + 1);

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (cats[i] == -1) continue;
        int best_index = -1;
        int best_value = 0;

        for (int j = i + 1; j <= N; j++) {
            if (cats[j] == -1) continue;

            int cur = cats[i] + cats[j];

            if (cur <= K && cur >= best_value) {
                best_index = j;
                best_value = cur;
            }
        }

        if (best_index == -1) continue;

        cats[i] = -1;
        cats[best_index] = -1;
        cnt += 1;
    }

    cout << cnt;
}