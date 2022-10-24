#include <algorithm>
#include <iostream>
using namespace std;

int visited[60][60];
int dr[6] = {1, -1, 1, -1, 1, -1};
int dc[6] = {-1, 0, 1, -1, 0, 1};
int N;
int cnt = 0;

void dfs(int cur_r, int cur_c, int moved) {
    if (visited[cur_r][cur_c] != -10 && moved == N) cnt++;
    if (visited[cur_r][cur_c] != -10) return;

    visited[cur_r][cur_c] = moved;

    if (moved < N) {
        for (int i = 0; i < 3; i++) {
            int r = cur_r + dr[i + cur_r % 2 * 3];
            int c = cur_c + dc[i + cur_r % 2 * 3];

            if (visited[r][c] != moved - 1) {
                dfs(r, c, moved + 1);
            }
        }
    }

    visited[cur_r][cur_c] = -10;
}

int main() {
    cin >> N;

    fill(&visited[0][0], &visited[58][59], -10);
    visited[26][26] = -1;
    dfs(25, 26, 0);
    cout << cnt;
}