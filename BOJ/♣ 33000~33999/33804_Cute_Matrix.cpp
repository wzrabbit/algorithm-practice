#include <iostream>
using namespace std;

int answer[9][257][257];

int get_level(int num) {
    int level = 0;

    while (num > 1) {
        if (num % 2 == 1) {
            return -1;
        }

        num /= 2;
        level += 1;
    }

    return level;
}

void make_answer() {
    answer[0][1][1] = 1;

    for (int i = 1; i <= 8; i++) {
        int full = 1 << i;
        int half = full / 2;

        for (int r = 1; r <= full; r++) {
            for (int c = 1; c <= full; c++) {
                if ((r <= half && c <= half) || (r > half && c > half)) {
                    answer[i][r][c] =
                        answer[i - 1][(r - 1) % half + 1][(c - 1) % half + 1] *
                            2 -
                        1;
                } else {
                    answer[i][r][c] =
                        answer[i - 1][(r - 1) % half + 1][(c - 1) % half + 1] *
                        2;
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int level = get_level(N);

    if (level == -1) {
        cout << 0;
        return 0;
    }

    make_answer();

    cout << 1 << '\n';

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << answer[level][r][c] << ' ';
        }
        cout << '\n';
    }
}
