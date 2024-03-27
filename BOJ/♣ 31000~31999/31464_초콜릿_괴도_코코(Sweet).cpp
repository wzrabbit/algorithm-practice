#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

char grid[45][45];
bool visited[45][45];
vector<Loc> answers;
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int dr2[4] = {0, 0, 1, 1};
int dc2[4] = {0, 1, 0, 1};
int N;

bool is_one_piece() {
    int start_R = -1;
    int start_C = -1;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '#') {
                start_R = r;
                start_C = c;
            }
        }
    }

    if (start_R == -1) {
        return false;
    }

    fill(&visited[1][1], &visited[N][N + 1], false);
    visited[start_R][start_C] = true;
    queue<Loc> q;
    q.push({start_R, start_C});

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N) {
                continue;
            }

            if (!visited[r][c] && grid[r][c] == '#') {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '#' && !visited[r][c]) {
                return false;
            }
        }
    }

    return true;
}

bool has_square() {
    for (int r = 1; r <= N - 1; r++) {
        for (int c = 1; c <= N - 1; c++) {
            bool success = false;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr2[i];
                int nc = c + dc2[i];

                if (grid[nr][nc] == '.') {
                    success = true;
                    break;
                }
            }

            if (!success) {
                return true;
            }
        }
    }

    return false;
}

bool has_isolated() {
    fill(&visited[0][0], &visited[N + 1][N + 2], false);
    visited[0][0] = true;
    queue<Loc> q;
    q.push({0, 0});

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r > N + 1 || c < 0 || c > N + 1) {
                continue;
            }

            if (!visited[r][c] && grid[r][c] == '.') {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '.' && !visited[r][c]) {
                return true;
            }
        }
    }

    return false;
}

bool is_possible() {
    return is_one_piece() && !has_square() && !has_isolated();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 0; r <= N + 1; r++) {
        grid[r][0] = '.';
        grid[r][N + 1] = '.';
    }

    for (int c = 0; c <= N + 1; c++) {
        grid[0][c] = '.';
        grid[N + 1][c] = '.';
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '.') {
                continue;
            }

            grid[r][c] = '.';

            if (is_possible()) {
                answers.push_back({r, c});
            }

            grid[r][c] = '#';
        }
    }

    cout << answers.size() << '\n';

    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i].r << ' ' << answers[i].c << '\n';
    }
}
