// #MakeGodGameAgain

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct q_data {
    int r, c, lv, d, t;
};

int visited[240][5][51][51];
int dr[5] = {0, 1, 0, -1, 0};  // →: 0, ↓: 1, ←: 2, ↑: 3, X: 4
int dc[5] = {1, 0, -1, 0, 0};
int dir[4] = {2, 3, 0, 1};
vector<string> board;

void move_ob(int scale, int start_R, int start_C) {
    int state = scale * 4 - 1;
    int i = state / scale;
    int cur_R = start_R;
    int cur_C = start_C;

    for (int t = 0; t < 240; t++) {
        int sec_R = cur_R - dr[i];
        int sec_C = cur_C - dc[i];

        for (int i = 0; i < 5; i++)
            visited[t][i][cur_R][cur_C] = -2;
        visited[t][dir[i]][sec_R][sec_C] = -2;

        state = (state + 1) % (scale * 4);
        i = state / scale;
        cur_R += dr[i];
        cur_C += dc[i];
    }
}

int play_game(int R, int C, int start_R, int start_C) {
    queue<q_data> q;
    for (int i = 0; i < 5; i++) {
        visited[0][i][start_R][start_C] = 0;
        q.push({start_R, start_C, 0, i, 0});
    }

    while (q.size()) {
        q_data cur = q.front();
        q.pop();

        if (board[cur.r][cur.c] == 'E')
            return cur.t;

        for (int d = 0; d < 5; d++) {
            int r = cur.r + dr[d];
            int c = cur.c + dc[d];
            int lv = (cur.lv + 1) % 240;
            int t = visited[cur.lv][cur.d][cur.r][cur.c] + 1;

            if (r >= 0 && r <= R && c >= 0 && c <= C &&
                board[r][c] != '#' && visited[lv][d][r][c] == -1) {
                visited[lv][d][r][c] = t;
                q.push({r, c, lv, d, t});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    board.resize(R + 1);
    for (int i = 0; i <= R; i++)
        cin >> board[i];

    int start_R, start_C;
    for (int r = 0; r <= R; r++) {
        for (int c = 0; c <= C; c++) {
            if (board[r][c] == 'S') {
                start_R = r;
                start_C = c;
            }
        }
    }

    fill(&visited[0][0][0][0], &visited[239][4][50][51], -1);

    int B;
    cin >> B;

    for (int i = 0; i < B; i++) {
        int s, r, c;
        cin >> s >> r >> c;
        move_ob(s, r, c);
    }

    int result = play_game(R, C, start_R, start_C);
    if (result != -1)
        cout << result;
    else
        cout << "INF";
}