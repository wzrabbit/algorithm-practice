#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

char horizontal[1001][1001];
char vertical[1001][1001];
int result[1001][1001];
int priority[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
queue<Pos> q;
int id = 1;
int N;

void perform_topological_sort() {
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (size_t i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N) {
                continue;
            }

            if ((i == 0 && vertical[cur.r - 1][cur.c] == 'v') ||
                (i == 1 && vertical[cur.r][cur.c] == '^') ||
                (i == 2 && horizontal[cur.r][cur.c - 1] == '>') ||
                (i == 3 && horizontal[cur.r][cur.c] == '<')) {
                priority[r][c] -= 1;

                if (priority[r][c] == 0) {
                    q.push({r, c});
                    result[r][c] = id;
                    id += 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N - 1; c++) {
            cin >> horizontal[r][c];
        }
    }

    for (int r = 1; r <= N - 1; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> vertical[r][c];

            if (vertical[r][c] == '>') {
                vertical[r][c] = 'v';
            } else {
                vertical[r][c] = '^';
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (r != 1 && vertical[r - 1][c] == '^') {
                priority[r][c] += 1;
            }

            if (r != N && vertical[r][c] == 'v') {
                priority[r][c] += 1;
            }

            if (c != 1 && horizontal[r][c - 1] == '<') {
                priority[r][c] += 1;
            }

            if (c != N && horizontal[r][c] == '>') {
                priority[r][c] += 1;
            }

            if (priority[r][c] == 0) {
                q.push({r, c});
                result[r][c] = id;
                id += 1;
            }
        }
    }

    perform_topological_sort();

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << result[r][c] << ' ';
        }

        cout << '\n';
    }
}
