#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

int mineral[1000][1000];
bool visited[1000][1000];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K;

bool can_mine(int strength) {
    queue<Loc> que;
    int mineral_count = 0;

    fill(&visited[0][0], &visited[R - 1][C], false);

    for (int c = 0; c < C; c++) {
        que.push({0, c});
        visited[0][c] = true;
    }

    for (int r = 1; r < R; r++) {
        que.push({r, 0});
        que.push({r, C - 1});
        visited[r][0] = true;
        visited[r][C - 1] = true;
    }

    while (!que.empty()) {
        Loc cur = que.front();
        que.pop();

        if (strength < mineral[cur.r][cur.c]) {
            continue;
        }
        mineral_count += 1;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c]) {
                que.push({r, c});
                visited[r][c] = true;
            }
        }
    }

    if (mineral_count >= K) {
        return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> mineral[r][c];
        }
    }

    int left = 1;
    int right = 1000000;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (can_mine(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
}