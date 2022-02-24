#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char graph[31][31][31];
bool visited[31][31][32];
int dh[6] = { -1, 1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, -1, 1, 0, 0 };
int dc[6] = { 0, 0, 0, 0, -1, 1 };

struct qData {
    int he, ro, co, di;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int height, row, col;
        cin >> height >> row >> col;
        if (height == 0) break;
        queue<qData> que;
        bool success = false;
        fill(&visited[0][0][0], &visited[30][30][31], false);

        for (int h = 0; h < height; h++) {
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    cin >> graph[h][r][c];
                    if (graph[h][r][c] == 'S') {
                        visited[h][r][c] = true;
                        que.push({ h, r, c, 0 });
                    }
                }
            }
        }

        while (que.size()) {
            int h_ = que.front().he;
            int r_ = que.front().ro;
            int c_ = que.front().co;
            int d_ = que.front().di;
            que.pop();

            if (graph[h_][r_][c_] == 'E') {
                cout << "Escaped in " << d_ << " minute(s).\n";
                success = true;
                break;
            }

            for (int i = 0; i < 6; i++) {
                int h = h_ + dh[i];
                int r = r_ + dr[i];
                int c = c_ + dc[i];

                if (h >= 0 && h < height && r >= 0 && r < row && c >= 0 && c < col
                    && graph[h][r][c] != '#' && visited[h][r][c] == false) {
                    visited[h][r][c] = true;
                    que.push({ h, r, c, d_ + 1 });
                }
            }
        }

        if (success == false) {
            cout << "Trapped!\n";
        }
    }
}