#include <algorithm>
#include <iostream>
using namespace std;

int grid[1001][1001];
int cnt = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void place_cow(int cur_r, int cur_c) {
    grid[cur_r][cur_c] = 0;

    for (int i = 0; i < 4; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];

        if (r < 0 || r > 1000 || c < 0 || c > 1000)
            continue;

        if (grid[r][c] > -1) {
            grid[cur_r][cur_c]++;
            grid[r][c]++;

            if (grid[cur_r][cur_c] == 3)
                cnt++;

            if (grid[r][c] == 3)
                cnt++;

            if (grid[cur_r][cur_c] == 4)
                cnt--;

            if (grid[r][c] == 4)
                cnt--;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    fill(&grid[0][0], &grid[999][1000], -1);

    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        place_cow(r, c);
        cout << cnt << '\n';
    }
}