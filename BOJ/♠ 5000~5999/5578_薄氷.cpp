#include <iostream>
#include <algorithm>
using namespace std;

int grid[90][90];
bool visited[90][90];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;
int max_moves = 0;

void move(int cur_r, int cur_c, int moves) {
    if (grid[cur_r][cur_c] == 0) return;
    max_moves = max(max_moves, moves);
    visited[cur_r][cur_c] = true;
    
    for (int i = 0; i < 4; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];
        
        if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c] && grid[r][c] == 1) {
            move(r, c, moves + 1);
        }
    }
    
    visited[cur_r][cur_c] = false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> C >> R;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
        }
    }
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            move(r, c, 1);
        }
    }
    
    cout << max_moves;
}