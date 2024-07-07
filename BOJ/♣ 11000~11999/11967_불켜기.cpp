#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

bool has_light[101][101];
vector<Pos> graph[101][101];
bool visited[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, M;

void traverse() {
    queue<Pos> q;
    q.push({1, 1});
    visited[1][1] = true;
    has_light[1][1] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur.r][cur.c].size(); i++) {
            int r = graph[cur.r][cur.c][i].r;
            int c = graph[cur.r][cur.c][i].c;

            has_light[r][c] = true;

            if (visited[r][c]) {
                continue;
            }

            for (size_t i = 0; i < 4; i++) {
                int adj_r = r + dr[i];
                int adj_c = c + dc[i];

                if (adj_r < 1 || adj_r > N || adj_c < 1 || adj_c > N || !visited[adj_r][adj_c]) {
                    continue;
                }

                visited[r][c] = true;
                q.push({r, c});
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N || visited[r][c] || !has_light[r][c]) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }
}

void print_answer() {
    int light_count = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (has_light[r][c]) {
                light_count += 1;
            }
        }
    }

    cout << light_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        graph[r1][c1].push_back({r2, c2});
    }

    traverse();
    print_answer();
}
