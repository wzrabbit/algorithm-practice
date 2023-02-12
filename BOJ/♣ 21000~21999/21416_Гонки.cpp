#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

char grid[22][22];
int visited[22][22];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;
Loc start_loc, end_loc;

int bfs() {
    queue<Loc> q;
    visited[start_loc.r][start_loc.c] = 0;
    q.push(start_loc);
    
    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();
        
        if (cur.r == end_loc.r && cur.c == end_loc.c) {
            return visited[cur.r][cur.c];
        }
        
        for (int i = 0; i < 4; i++) {
            int move_length = 0;
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            while (0 <= r && r < R && 0 <= c && c < C && grid[r][c] != '#') {
                move_length += 1;
                r += dr[i];
                c += dc[i];
            }
            
            r = cur.r + dr[i] * (move_length - move_length / 2);
            c = cur.c + dc[i] * (move_length - move_length / 2);
            
            if (visited[r][c] == -1) {
                visited[r][c] = visited[cur.r][cur.c] + 1;
                q.push({r, c});
            }
        }
    }
    
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    
    cin >> R >> C;
    
    for (int r = 0; r < R; r++) {
        cin >> grid[r];
    }
    
    fill(&visited[0][0], &visited[R - 1][C], -1);
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'S') {
                start_loc.r = r;
                start_loc.c = c;
            }
            
            if (grid[r][c] == 'T') {
                end_loc.r = r;
                end_loc.c = c;
            }
        }
    }
    
    cout << bfs();
}