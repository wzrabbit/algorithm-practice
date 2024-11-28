#include <iostream>
using namespace std;

bool grid[10][10000];
int R, C;

int get_maximum_senbei(int bit) {
    int senbei_count = 0;

    for (int c = 0; c < C; c++) {
        int cur_senbei_count = 0;

        for (int r = 0; r < R; r++) {
            cur_senbei_count += (grid[r][c] + ((bit & (1 << r)) != 0)) & 1;
        }

        senbei_count += max(cur_senbei_count, R - cur_senbei_count);
    }

    return senbei_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
        }
    }

    int answer = 0;

    for (int i = 0; i < (1 << R); i++) {
        answer = max(answer, get_maximum_senbei(i));
    }

    cout << answer;
}
