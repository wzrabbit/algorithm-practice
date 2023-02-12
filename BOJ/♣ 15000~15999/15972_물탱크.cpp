#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c, h;
};

bool operator<(const Loc a, Loc b) {
    return a.h > b.h;
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int hole[1002][1002][4];
int water[1002][1002];
int R, C, H;

void make_holes() {
    for (int r = 0; r < R - 1; r++) {
        for (int c = 1; c < C - 1; c++) {
            int cur;
            cin >> cur;
            hole[r][c][1] = hole[r + 1][c][0] = cur;
        }
    }

    for (int r = 1; r < R - 1; r++) {
        for (int c = 0; c < C - 1; c++) {
            int cur;
            cin >> cur;
            hole[r][c][3] = hole[r][c + 1][2] = cur;
        }
    }
}

void dijkstra() {
    priority_queue<Loc> pq;
    
    fill(&water[0][0], &water[R - 1][C], H);
    
    for (int r = 0; r < R; r++) {
        water[r][0] = 0;
        water[r][C - 1] = 0;
        pq.push({r, 0, 0});
        pq.push({r, C - 1, 0});
    }
    
    for (int c = 1; c < C - 1; c++) {
        water[0][c] = 0;
        water[R - 1][c] = 0;
        pq.push({0, c, 0});
        pq.push({R - 1, c, 0});
    }
    
    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();
        
        if (cur.h > water[cur.r][cur.c]) {
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            
            if (r >= 0 && r < R && c >= 0 && c < C) {
                int new_height = max(hole[cur.r][cur.c][i], cur.h);
                if (new_height < water[r][c] && hole[cur.r][cur.c][i] != -1) {
                    water[r][c] = new_height;
                    pq.push({r, c, new_height});
                }
            }
        }
    }
}

int get_total_height() {
    int total_height = 0;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            total_height += water[r][c];
        }
    }
    
    return total_height;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> H;
    R += 2;
    C += 2;
    
    make_holes();
    dijkstra();
    cout << get_total_height();
}