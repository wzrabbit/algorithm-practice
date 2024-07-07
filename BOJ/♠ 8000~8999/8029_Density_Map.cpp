#include <algorithm>
#include <iostream>
using namespace std;

int prefix[251][251];
int N, R;

int get_sum_from_center(int center_r, int center_c) {
    int start_r = max(center_r - R, 1);
    int start_c = max(center_c - R, 1);
    int end_r = min(center_r + R, N);
    int end_c = min(center_c + R, N);

    return prefix[end_r][end_c] -
           prefix[start_r - 1][end_c] -
           prefix[end_r][start_c - 1] +
           prefix[start_r - 1][start_c - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> R;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> prefix[r][c];
            prefix[r][c] += prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << get_sum_from_center(r, c) << ' ';
        }

        cout << '\n';
    }
}
