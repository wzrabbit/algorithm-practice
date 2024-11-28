#include <algorithm>
#include <iostream>
using namespace std;

bool is_answer[12][12];

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    fill(&is_answer[1][1], &is_answer[N][N + 1], true);

    while (M--) {
        int compass_r, compass_c, direction;
        cin >> compass_r >> compass_c >> direction;

        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (dr[direction] < 0 && r >= compass_r) {
                    is_answer[r][c] = false;
                    continue;
                }

                if (dr[direction] == 0 && r != compass_r) {
                    is_answer[r][c] = false;
                    continue;
                }

                if (dr[direction] > 0 && r <= compass_r) {
                    is_answer[r][c] = false;
                    continue;
                }

                if (dc[direction] < 0 && c >= compass_c) {
                    is_answer[r][c] = false;
                    continue;
                }

                if (dc[direction] == 0 && c != compass_c) {
                    is_answer[r][c] = false;
                    continue;
                }

                if (dc[direction] > 0 && c <= compass_c) {
                    is_answer[r][c] = false;
                    continue;
                }
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (is_answer[r][c]) {
                cout << r << ' ' << c;
                return 0;
            }
        }
    }
}
