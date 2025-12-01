#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

int R, C;
char grid[502][502];
bool visited[502][502];
vector<Pos> graph[502][502];

void make_graph() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'U') graph[r - 1][c].push_back({r, c});
            if (grid[r][c] == 'D') graph[r + 1][c].push_back({r, c});
            if (grid[r][c] == 'L') graph[r][c - 1].push_back({r, c});
            if (grid[r][c] == 'R') graph[r][c + 1].push_back({r, c});
        }
    }
}

int get_answer() {
    queue<Pos> q;

    for (int r = 0; r <= R + 1; r++) {
        q.push({r, 0});
        q.push({r, C + 1});
    }

    for (int c = 0; c <= C + 1; c++) {
        q.push({0, c});
        q.push({R + 1, c});
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (Pos next : graph[cur.r][cur.c]) {
            if (!visited[next.r][next.c]) {
                visited[next.r][next.c] = true;
                q.push({next.r, next.c});
            }
        }
    }

    int answer = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (visited[r][c]) {
                answer += 1;
            }
        }
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    make_graph();
    cout << get_answer();
}
