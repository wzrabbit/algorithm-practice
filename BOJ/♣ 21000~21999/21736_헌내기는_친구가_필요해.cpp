#include <algorithm>
#include <iostream>
#include <queue>
#define INF 9'876'543
using namespace std;

struct Loc {
    int r, c;
};

char grid[601][601];
bool visited[601][601];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;
int start_r, start_c;

void init() {
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'I') {
                start_r = r;
                start_c = c;
            }
        }
    }
}

int get_possible_people_count() {
    queue<Loc> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    int possible_people_count = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (grid[cur.r][cur.c] == 'P') {
            possible_people_count += 1;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || grid[r][c] == 'X') {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }

    return possible_people_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();
    int possible_people_count = get_possible_people_count();

    if (possible_people_count > 0) {
        cout << possible_people_count;
    } else {
        cout << "TT";
    }
}
