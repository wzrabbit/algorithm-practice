#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Loc {
    int r, c;
};

char bowl[1002][1002];
bool visited[1002][1002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K;

int get_area(int limit_row, Loc start_location) {
    if (visited[start_location.r][start_location.c] || bowl[start_location.r][start_location.c] == '#') {
        return 0;
    }
    
    int area = 0;
    queue<Loc> q;
    q.push({start_location.r, start_location.c});
    visited[start_location.r][start_location.c] = true;
    
    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();
        area += 1;
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (limit_row <= r && r <= R && 1 <= c && c <= C && !visited[r][c] && bowl[r][c] == '.') {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }
    
    return area;
}

bool is_possible(int limit_row) {
    fill(&visited[1][1], &visited[R][C + 1], false);
    int max_area = 0;
    
    for (int r = limit_row; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            max_area = max(max_area, get_area(limit_row, {r, c}));
        }
    }
    
    if (max_area >= K) {
        return true;
    }
    
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> R >> C >> K;
    
    for (int r = 1; r <= R; r++) {
        cin >> (bowl[r] + 1);
    }
    
    int start = 1;
    int end = R;
    int mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    if (end == 0) {
        cout << -1;
    } else {
        cout << end;
    }
}