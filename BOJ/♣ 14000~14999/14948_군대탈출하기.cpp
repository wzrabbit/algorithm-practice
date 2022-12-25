#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Loc {
    int l, r, c;
};

int camp[100][100];
bool visited[2][100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

bool can_escape(int level) {
    if (level < camp[0][0]) {
        return false;
    }
    
    queue<Loc> que;
    fill(&visited[0][0][0], &visited[1][R - 1][C], false);
    que.push({0, 0, 0});
    visited[0][0][0] = true;
    
    while (!que.empty()) {
        Loc cur = que.front();
        que.pop();
        
        if (cur.r == R - 1 && cur.c == C - 1) {
            return true;
        }
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (0 <= r && r < R && 0 <= c && c < C && !visited[cur.l][r][c] && level >= camp[r][c]) {
                que.push({cur.l, r, c});
                visited[cur.l][r][c] = true;
            }
            
            r = cur.r + dr[i] * 2;
            c = cur.c + dc[i] * 2;
            if (cur.l == 0 && 0 <= r && r < R && 0 <= c && c < C && !visited[cur.l][r][c] && level >= camp[r][c]) {
                que.push({1, r, c});
                visited[1][r][c] = true;
            }
        }
    }
    
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> R >> C;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> camp[r][c];
        }
    }
    
    int left = 0;
    int right = 1000000000;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (can_escape(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left;
}