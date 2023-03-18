#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

int walls[51][51];
int area_id[51][51];
int area_size[2501];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int R, C;

int room_count = 0;
int max_area_size = 0;
int max_twin_area_size = 0;

void bfs(int start_row, int start_col, int id) {
    queue<Loc> q;
    q.push({start_row, start_col});
    area_id[start_row][start_col] = id;

    int current_area_size = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        current_area_size += 1;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 1 && r <= R && c >= 1 && c <= C && area_id[r][c] == 0 && (walls[cur.r][cur.c] & (1 << i)) == 0) {
                area_id[r][c] = id;
                q.push({r, c});
            }
        }
    }

    room_count += 1;
    max_area_size = max(max_area_size, current_area_size);
    area_size[id] = current_area_size;
}

void update_max_twin_area_size() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            for (int i = 0; i < 4; i++) {
                int twin_r = r + dr[i];
                int twin_c = c + dc[i];

                if (twin_r >= 1 && twin_r <= R && twin_c >= 1 && twin_c <= C &&
                    area_id[r][c] != area_id[twin_r][twin_c]) {
                    max_twin_area_size = max(max_twin_area_size,
                                             area_size[area_id[r][c]] + area_size[area_id[twin_r][twin_c]]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C >> R;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> walls[r][c];
        }
    }

    int id = 1;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (area_id[r][c] == 0) {
                bfs(r, c, id++);
            }
        }
    }

    update_max_twin_area_size();

    cout << room_count << '\n'
         << max_area_size << '\n'
         << max_twin_area_size << '\n';
}