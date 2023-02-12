#include <iostream>
using namespace std;

int grid[5][5];
bool visited[5][5];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool success = false;

void dfs(int cur_r, int cur_c, int apple, int moved) {
    visited[cur_r][cur_c] = true;
    
    if (apple == 2) {
        success = true;
        visited[cur_r][cur_c] = false;
        return;
    }
    
    if (moved == 3) {
        visited[cur_r][cur_c] = false;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];
        if (0 <= r && r < 5 && 0 <= c && c < 5 && !visited[r][c] && grid[r][c] != -1) {
            dfs(r, c, apple + grid[r][c], moved + 1);
        }
    }
    
    visited[cur_r][cur_c] = false;
}

int main() {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cin >> grid[r][c];
        }
    }
    
    int start_r, start_c;
    cin >> start_r >> start_c;
    dfs(start_r, start_c, 0, 0);
    
    if (success) {
        cout << 1;
    } else {
        cout << 0;
    }
}