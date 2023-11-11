#include <iostream>
using namespace std;

int apples[1001][1001];
int prefix[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> apples[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            prefix[r][c] = apples[r][c] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    int best_value = apples[1][1];

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            for (int s = 1; s <= min(r, c); s++) {
                int cur_value = prefix[r][c] - prefix[r - s][c] - prefix[r][c - s] + prefix[r - s][c - s];
                best_value = max(best_value, cur_value);
            }
        }
    }

    cout << best_value;
}