#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int grid[101][101];
bool visited[4][101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<int> success_values;
int R, C;

bool simulate(int start_r) {
    int direction = 1;
    int r = start_r;
    int c = 1;

    fill(&visited[0][1][1], &visited[3][R][C + 1], false);
    visited[1][r][c] = true;

    while (true) {
        int multiplier = grid[r][c];
        r += dr[direction] * multiplier;
        c += dc[direction] * multiplier;
        direction = (direction + 1) % 4;

        if (r < 1 || r > R || c < 1 || c > C) {
            return false;
        }

        if (visited[direction][r][c]) {
            return true;
        }

        visited[direction][r][c] = true;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        if (simulate(r)) {
            success_values.push_back(r);
        }
    }

    cout << success_values.size() << '\n';

    for (size_t i = 0; i < success_values.size(); i++) {
        cout << success_values[i] << ' ';
    }
}
