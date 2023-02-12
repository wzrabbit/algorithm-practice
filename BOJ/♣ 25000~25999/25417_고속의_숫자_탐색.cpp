#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

int grid[5][5];
int visited[5][5];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int get_dist(int start_r, int start_c) {
    queue<Loc> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (grid[cur.r][cur.c] == 1) {
            return visited[cur.r][cur.c];
        }
        
        // 걷기
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (0 <= r && r < 5 && 0 <= c && c < 5 && grid[r][c] != -1 && visited[r][c] == -1) {
                visited[r][c] = visited[cur.r][cur.c] + 1;
                q.push({r, c});
            }
        }
        
        // 달리기
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            while (
                0 <= r && r < 5 && 0 <= c && c < 5 && 
                (grid[r - dr[i]][c - dc[i]] != 7 || (r - dr[i] == cur.r && c - dc[i] == cur.c)) &&
                grid[r][c] != -1
            ) {
                r += dr[i];
                c += dc[i];
            }

            r -= dr[i];
            c -= dc[i];

            if (visited[r][c] == -1) {
                visited[r][c] = visited[cur.r][cur.c] + 1;
                q.push({r, c});
            }
        }
    }

    return -1;
}

int main() {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cin >> grid[r][c];
        }
    }

    fill(&visited[0][0], &visited[4][5], -1);

    int start_r, start_c;
    cin >> start_r >> start_c;
    cout << get_dist(start_r, start_c);
}