#include <iostream>
typedef long long ll;
using namespace std;

int grid[31][31];

ll get_square_sum(int start_r, int start_c, int scale) {
    ll sum = 0;

    for (int r = start_r; r < start_r + scale; r++) {
        for (int c = start_c; c < start_c + scale; c++) {
            sum += grid[r][c];
        }
    }

    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, L;
    cin >> R >> C >> L;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int answer = 0;

    for (int s = 1; s <= min(R, C); s++) {
        for (int r = 1; r <= R - s + 1; r++) {
            for (int c = 1; c <= C - s + 1; c++) {
                if (get_square_sum(r, c, s) < L) {
                    answer += 1;
                }
            }
        }
    }

    cout << answer;
}