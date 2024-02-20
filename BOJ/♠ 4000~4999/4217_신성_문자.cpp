#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pos {
    int r, c;
};

struct DQData {
    int r, c;
    bool p;
};

char input[202][52];
bool grid[202][202];
bool visited[202][202];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string ANSWER_STR = "WAKJSD";
int R, C;

int hex_to_dec(char hex) {
    int dec = 0;

    if (hex >= 'a' && hex <= 'f') {
        dec += hex - 'a' + 10;
    } else {
        dec += hex - '0';
    }

    return dec;
}

void clear_visited_grid() {
    fill(&visited[0][0], &visited[R + 1][C + 2], false);
}

void decode_hex_grid() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int dec = hex_to_dec(input[r][c]);

            for (int i = c * 4 - 3; i <= c * 4; i++) {
                grid[r][i] = dec & (1 << (c * 4 - i));
            }
        }
    }
}

void traverse_outer_space() {
    queue<Pos> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r > R + 1 || c < 0 || c > C + 1 || visited[r][c] || grid[r][c] == 1) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }
}

int get_hole_count(int start_r, int start_c) {
    deque<DQData> dq;
    dq.push_back({start_r, start_c, false});

    int hole_count = 0;

    while (!dq.empty()) {
        DQData cur = dq.front();
        dq.pop_front();

        if (visited[cur.r][cur.c]) {
            continue;
        }

        visited[cur.r][cur.c] = true;

        if (cur.p) {
            hole_count += 1;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            if (grid[r][c] == 0) {
                dq.push_front({r, c, grid[cur.r][cur.c] == 1});
            } else {
                dq.push_back({r, c, false});
            }
        }
    }

    return hole_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int test_no = 1;

    while (true) {
        cin >> R >> C;

        if (R == 0) {
            break;
        }

        for (int r = 1; r <= R; r++) {
            cin >> (input[r] + 1);
        }

        decode_hex_grid();

        C *= 4;

        clear_visited_grid();
        traverse_outer_space();

        string answer = "";

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (visited[r][c]) {
                    continue;
                }

                int cur_hole_count = get_hole_count(r, c);
                answer += ANSWER_STR[cur_hole_count];
            }
        }

        sort(answer.begin(), answer.end());

        cout << "Case " << test_no << ": " << answer << '\n';
        test_no += 1;
    }
}
