#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct State {
    int ar, ac, br, bc;
};

int visited[50][50][50][50];
State history[50][50][50][50];
char command[50][50][50][51];
char maze[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dm[5] = {'N', 'S', 'W', 'E'};
int R, C;
int ar, ac, br, bc;

void print_path(int cur_ar, int cur_ac, int cur_br, int cur_bc) {
    State nxt = history[cur_ar][cur_ac][cur_br][cur_bc];
    if (nxt.ar != ar || nxt.ac != ac || nxt.br != br || nxt.bc != bc) {
        print_path(nxt.ar, nxt.ac, nxt.br, nxt.bc);
    }

    cout << command[cur_ar][cur_ac][cur_br][cur_bc];
}

void solve() {
    queue<State> q;
    q.push({ar, ac, br, bc});
    visited[ar][ac][br][bc] = 0;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.ar == cur.br && cur.ac == cur.bc) {
            cout << visited[cur.ar][cur.ac][cur.br][cur.bc] << ' ';
            print_path(cur.ar, cur.ac, cur.br, cur.bc);
            cout << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_ar = (cur.ar + R + dr[i]) % R;
            int next_ac = (cur.ac + C + dc[i]) % C;
            int next_br = (cur.br + R + dr[i]) % R;
            int next_bc = (cur.bc + C + dc[i]) % C;

            if (maze[next_ar][next_ac] == 'G' || maze[next_br][next_bc] == 'G') {
                continue;
            }

            if (maze[next_ar][next_ac] == 'X') {
                next_ar = cur.ar;
                next_ac = cur.ac;
            }

            if (maze[next_br][next_bc] == 'X') {
                next_br = cur.br;
                next_bc = cur.bc;
            }

            if (visited[next_ar][next_ac][next_br][next_bc] == -1) {
                visited[next_ar][next_ac][next_br][next_bc] = visited[cur.ar][cur.ac][cur.br][cur.bc] + 1;
                q.push({next_ar, next_ac, next_br, next_bc});
                history[next_ar][next_ac][next_br][next_bc] = cur;
                command[next_ar][next_ac][next_br][next_bc] = dm[i];
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        fill(&visited[0][0][0][0], &visited[49][49][49][50], -1);
        cin >> R >> C;

        for (int r = 0; r < R; r++) {
            cin >> maze[r];
        }

        bool a_found = false;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (maze[r][c] == 'P') {
                    if (a_found) {
                        br = r;
                        bc = c;
                    } else {
                        ar = r;
                        ac = c;
                        a_found = true;
                    }
                }
            }
        }

        solve();
    }
}