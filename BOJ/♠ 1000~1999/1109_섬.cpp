#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

struct QLoc {
    int r, c;
};

struct DLoc {
    int r, c, p;
};

char grid[53][53];
int id[52][52];
int visited[52][52];
int parent[1251];
int island_depth_count[51];
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> graph[1251];
queue<QLoc> que;
deque<DLoc> deq;
int max_depth = -1;
int R, C;

void set_borders() {
    for (int c = 0; c < C; c++) {
        grid[0][c] = '.';
        grid[R - 1][c] = '.';
    }

    for (int r = 1; r < R - 1; r++) {
        grid[r][0] = '.';
        grid[r][C - 1] = '.';
    }
}

void traverse(int start_r, int start_c, int current_id) {
    id[start_r][start_c] = current_id;
    visited[start_r][start_c] = 1;
    que.push({start_r, start_c});

    while (!que.empty()) {
        QLoc cur = que.front();
        que.pop();

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c] && grid[r][c] == 'x') {
                id[r][c] = current_id;
                visited[r][c] = 1;
                que.push({r, c});
            }
        }
    }
}

void paint_islands() {
    int current_id = 1;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'x' && !visited[r][c]) {
                traverse(r, c, current_id++);
            }
        }
    }
}

void set_parents() {
    fill(&visited[0][0], &visited[R - 1][C], -1);
    fill(parent, parent + 1251, -1);

    for (int c = 0; c < C; c++) {
        deq.push_back({0, c, 0});
        deq.push_back({R - 1, c, 0});
    }

    for (int r = 1; r < R - 1; r++) {
        deq.push_back({r, 0, 0});
        deq.push_back({r, C - 1, 0});
    }

    while (!deq.empty()) {
        DLoc cur = deq.front();
        deq.pop_front();

        if (visited[cur.r][cur.c] != -1) {
            continue;
        }

        if (grid[cur.r][cur.c] == '.') {
            visited[cur.r][cur.c] = cur.p;
        } else {
            visited[cur.r][cur.c] = id[cur.r][cur.c];
        }

        if (grid[cur.r][cur.c] == 'x' && id[cur.r][cur.c] != cur.p) {
            parent[id[cur.r][cur.c]] = cur.p;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && visited[r][c] == -1) {
                if (grid[cur.r][cur.c] == '.' && grid[r][c] == 'x') {
                    deq.push_back({r, c, visited[cur.r][cur.c]});
                } else {
                    deq.push_front({r, c, visited[cur.r][cur.c]});
                }
            }
        }

        for (int i = 4; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && visited[r][c] == -1 && grid[cur.r][cur.c] == 'x' && grid[r][c] == 'x') {
                deq.push_front({r, c, visited[cur.r][cur.c]});
            }
        }
    }
}

void make_relations() {
    for (int i = 1; i <= 1250; i++) {
        if (parent[i] != -1) {
            graph[parent[i]].push_back(i);
        }
    }
}

int set_island_depths(int node) {
    int depth = 0;
    for (size_t i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        depth = max(depth, set_island_depths(nxt) + 1);
    }

    if (node != 0) {
        island_depth_count[depth] += 1;
        max_depth = max(max_depth, depth);
    }
    return depth;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    R += 2;
    C += 2;

    for (int r = 1; r < R - 1; r++) {
        cin >> (grid[r] + 1);
    }

    set_borders();
    paint_islands();
    set_parents();
    make_relations();
    set_island_depths(0);

    if (max_depth == -1) {
        cout << -1;
    } else {
        for (int i = 0; i <= max_depth; i++) {
            cout << island_depth_count[i] << ' ';
        }
    }
}