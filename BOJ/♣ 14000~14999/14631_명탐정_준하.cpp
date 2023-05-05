#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int bit, r, c;
};

int visited[1048576][4][5];
char board[4][6];
int location_bit[20];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int success_bit = 0;
int start_r, start_c;

int convert_char_to_int(char c) {
    if (c >= 'A' && c <= 'J') {
        return c - 'A' + 10;
    }

    return c - '0';
}

void init() {
    success_bit = 0;
    fill(&visited[0][0][0], &visited[1048575][3][5], -1);
}

void set_bits() {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] != '.' && board[r][c] != '#') {
                location_bit[convert_char_to_int(board[r][c])] = 1 << (r * 5 + c);
            }

            if (board[r][c] != '.') {
                success_bit |= (1 << (r * 5 + c));
            }
        }
    }
}

void set_start_location() {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == '0') {
                start_r = r;
                start_c = c;
                return;
            }
        }
    }
}

void traverse() {
    queue<Loc> q;
    int start_bit = location_bit[0];
    visited[start_bit][start_r][start_c] = 0;
    q.push({start_bit, start_r, start_c});

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (cur.bit == success_bit) {
            cout << visited[cur.bit][cur.r][cur.c] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r > 3 || c < 0 || c > 4 || board[r][c] == '.') {
                continue;
            }

            if (board[r][c] != '0' && board[r][c] != '#') {
                int current_int = convert_char_to_int(board[r][c]);

                if ((location_bit[current_int - 1] & cur.bit) == 0) {
                    continue;
                }
            }

            int new_bit = cur.bit | (1 << (r * 5 + c));

            if (visited[new_bit][r][c] == -1) {
                visited[new_bit][r][c] = visited[cur.bit][cur.r][cur.c] + 1;
                q.push({new_bit, r, c});
            }
        }
    }

    cout << -1 << '\n';
}

void solve() {
    init();
    set_bits();
    set_start_location();
    traverse();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        for (int r = 0; r < 4; r++) {
            cin >> board[r];
        }

        solve();
    }
}