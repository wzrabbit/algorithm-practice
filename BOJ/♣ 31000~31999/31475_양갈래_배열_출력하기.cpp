#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int grid[2001][2001];
int canvas[2001][2001];
bool visited[2001][2001];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int R, C;

void make_pony_tail(int start_R, int start_C, int start_num, int start_direction, int rotation) {
    int r = start_R;
    int c = start_C;
    int num = start_num;
    int direction = start_direction;
    int fail_count = 0;

    while (true) {
        if (fail_count == 0) {
            visited[r][c] = true;
            canvas[r][c] = num++;
        }

        int next_R = r + dr[direction];
        int next_C = c + dc[direction];

        if (next_R < 1 || next_R > R || next_C < 1 || next_C > C || visited[next_R][next_C]) {
            fail_count += 1;

            if (fail_count == 2) {
                break;
            }

            direction = (direction + 4 + rotation) % 4;
            continue;
        }

        fail_count = 0;
        r = next_R;
        c = next_C;
    }
}

void make_twin_tail(char direction) {
    switch (direction) {
        case 'U':
            for (int r = 1; r <= R; r++) {
                canvas[r][C / 2 + 1] = r;
                visited[r][C / 2 + 1] = true;
            }

            make_pony_tail(R, C / 2, R + 1, 3, 1);
            make_pony_tail(R, C / 2 + 2, R + 1, 1, -1);
            break;
        case 'D':
            for (int r = R; r >= 1; r--) {
                canvas[r][C / 2 + 1] = R - r + 1;
                visited[r][C / 2 + 1] = true;
            }

            make_pony_tail(1, C / 2, R + 1, 3, -1);
            make_pony_tail(1, C / 2 + 2, R + 1, 1, 1);
            break;
        case 'L':
            for (int c = 1; c <= C; c++) {
                canvas[R / 2 + 1][c] = c;
                visited[R / 2 + 1][c] = true;
            }

            make_pony_tail(R / 2, C, C + 1, 0, -1);
            make_pony_tail(R / 2 + 2, C, C + 1, 2, 1);
            break;

        case 'R':
            for (int c = C; c >= 1; c--) {
                canvas[R / 2 + 1][c] = C - c + 1;
                visited[R / 2 + 1][c] = true;
            }

            make_pony_tail(R / 2, 1, C + 1, 0, 1);
            make_pony_tail(R / 2 + 2, 1, C + 1, 2, -1);
            break;
    }
}

void print_answer() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << canvas[r][c] << ' ';
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    char direction;
    cin >> direction;

    make_twin_tail(direction);
    print_answer();
}
