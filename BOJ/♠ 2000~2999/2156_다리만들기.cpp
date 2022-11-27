#include <iostream>
#include <algorithm>
#include <queue>
#define NOT_VISITED -1
#define INIT 1
#define INF 100000
using namespace std;

struct Loc {
    int r, c;
};

int N;
int grid[101][101];
int dist[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void paint_unit(int start_row, int start_col, int color) {
    queue<Loc> que;
    grid[start_row][start_col] = color;
    que.push({start_row, start_col});
    
    while (que.size() > 0) {
        Loc cur = que.front();
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (grid[r][c] == INIT) {
                grid[r][c] = color;
                que.push({r, c});
            }
        }
    }
}

void paint_grid() {
    int color_no = 2;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == INIT) {
                paint_unit(r, c, color_no++);
            }
        }
    }
}

int get_shortest_dist() {
    fill(&dist[1][1], &dist[N][N + 1], NOT_VISITED);
    int shortest_dist = INF;
    
    queue<Loc> que;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] > INIT) {
                que.push({r, c});
                dist[r][c] = 0;
            }
        }
    }
    
    while (que.size() > 0) {
        Loc cur = que.front();
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (r < 1 || r > N || c < 1 || c > N) continue;
            
            if (grid[r][c] == 0) {
                grid[r][c] = grid[cur.r][cur.c];
                dist[r][c] = dist[cur.r][cur.c] + 1;
                que.push({r, c});
                continue;
            }
            
            if (grid[r][c] != grid[cur.r][cur.c]) {
                shortest_dist = min(shortest_dist, dist[r][c] + dist[cur.r][cur.c]);    
            }
        }
    }
    
    return shortest_dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }
    
    paint_grid();
    cout << get_shortest_dist();
}