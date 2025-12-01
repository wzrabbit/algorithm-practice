#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

int grid[501][501];
bool visited[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K;
int start_R, start_C, end_R, end_C;

int get_required_spaces_count() {
    int result = 0;

    for (int r = start_R; r <= end_R; r++) {
        for (int c = start_C; c <= end_C; c++) {
            if (grid[r][c] != 0) {
                result += 1;
            }
        }
    }

    return result;
}

int get_available_spaces_count(int max_no) {
    queue<Pos> q;
    int spaces_count = 0;
    fill(&visited[1][1], &visited[R][C + 1], false);

    for (int r = start_R; r <= end_R; r++) {
        for (int c = start_C; c <= end_C; c++) {
            visited[r][c] = true;
            q.push({r, c});
        }
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] ||
                grid[r][c] > max_no) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});

            if (grid[r][c] == 0 &&
                !(r >= start_R && r <= end_R && c >= start_C && c <= end_C)) {
                spaces_count += 1;
            }
        }
    }

    return spaces_count;
}

void solve() {
    int required_spaces_count = get_required_spaces_count();

    int start = 0;
    int end = K;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        int spaces_count = get_available_spaces_count(mid);

        if (spaces_count >= required_spaces_count) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    int min_answer = 0;

    for (int r = start_R; r <= end_R; r++) {
        for (int c = start_C; c <= end_C; c++) {
            if (grid[r][c] != 0) {
                min_answer = max(min_answer, grid[r][c]);
            }
        }
    }

    if (start == K + 1) {
        cout << -1;
    } else {
        cout << max(min_answer, start);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = i;
    }

    cin >> start_R >> start_C >> end_R >> end_C;

    solve();
}
