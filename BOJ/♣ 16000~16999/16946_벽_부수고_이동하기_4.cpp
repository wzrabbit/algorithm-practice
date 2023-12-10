#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct Pos {
    int r, c;
};

char grid[1002][1002];
int visited[1002][1002];
int group_size[1000001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void bfs(int start_r, int start_c, int group_no) {
    queue<Pos> q;
    visited[start_r][start_c] = group_no;
    q.push({start_r, start_c});

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        group_size[group_no] += 1;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] != 0 || grid[r][c] == '1') {
                continue;
            }

            visited[r][c] = group_no;
            q.push({r, c});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int group_no = 1;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '0' && visited[r][c] == 0) {
                bfs(r, c, group_no++);
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '0') {
                cout << 0;
                continue;
            }

            set<int> selected_groups;
            int space_count = 1;

            for (int i = 0; i < 4; i++) {
                int adj_r = r + dr[i];
                int adj_c = c + dc[i];

                if (
                    adj_r < 1 ||
                    adj_r > R ||
                    adj_c < 1 ||
                    adj_c > C ||
                    visited[adj_r][adj_c] == 0) {
                    continue;
                }

                int group_no = visited[adj_r][adj_c];

                if (selected_groups.find(group_no) != selected_groups.end()) {
                    continue;
                }

                selected_groups.insert(group_no);
                space_count = (space_count + group_size[group_no]) % 10;
            }

            cout << space_count;
        }

        cout << '\n';
    }
}
