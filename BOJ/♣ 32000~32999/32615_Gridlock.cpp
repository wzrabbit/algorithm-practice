#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Pos {
    int r, c;

    bool operator==(const Pos &other) const {
        return r == other.r && c == other.c;
    }

    bool operator!=(const Pos &other) const {
        return r != other.r || c != other.c;
    }
};

int grid[2002][2002];
bool visited[2002][2002];
Pos next_pos[4][2002][2002];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<Pos> answer;
int R, C;

Pos get_next_pos(int index, Pos child) {
    Pos &parent = next_pos[index][child.r][child.c];

    if (parent == Pos{child.r, child.c}) {
        return child;
    }

    return parent = get_next_pos(index, parent);
}

void merge(int index, Pos a, Pos b) {
    a = get_next_pos(index, a);
    b = get_next_pos(index, b);

    if (a != b) {
        next_pos[index][a.r][a.c] = b;
    }
}

void init_next_pos() {
    for (int i = 0; i < 4; i++) {
        for (int r = 0; r <= R + 1; r++) {
            for (int c = 0; c <= C + 1; c++) {
                next_pos[i][r][c] = {r, c};
            }
        }
    }
}

void update_removed_cell(Pos target) {
    int r = target.r;
    int c = target.c;

    for (int i = 0; i < 4; i++) {
        merge(i, next_pos[i][r][c], next_pos[i][r + dr[i]][c + dc[i]]);
    }
}

bool is_out_range(Pos target) {
    return target.r < 1 || target.r > R || target.c < 1 || target.c > C;
}

void traverse() {
    queue<Pos> q;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int next_r = r + dr[grid[r][c]];
            int next_c = c + dc[grid[r][c]];

            if (next_r < 1 || next_r > R || next_c < 1 || next_c > C) {
                q.push({r, c});
                visited[r][c] = true;
            }
        }
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();
        answer.push_back(cur);
        update_removed_cell(cur);

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            Pos next_pos = get_next_pos(i, {r, c});

            if (is_out_range(next_pos)) {
                continue;
            }

            Pos opposite_pos = get_next_pos((i + 2) % 4, cur);

            bool should_visit = abs(grid[next_pos.r][next_pos.c] - i) == 2 &&
                                is_out_range(opposite_pos) &&
                                !visited[next_pos.r][next_pos.c];

            if (should_visit) {
                q.push(next_pos);
                visited[next_pos.r][next_pos.c] = true;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        string cur;
        cin >> cur;

        for (int c = 1; c <= C; c++) {
            switch (cur[c - 1]) {
                case '^':
                    grid[r][c] = 0;
                    break;
                case '>':
                    grid[r][c] = 1;
                    break;
                case 'v':
                    grid[r][c] = 2;
                    break;
                case '<':
                    grid[r][c] = 3;
                    break;
            }
        }
    }

    init_next_pos();
    traverse();

    if (answer.size() != R * C) {
        cout << "impossible";
        return 0;
    }

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].r << ' ' << answer[i].c << '\n';
    }
}
