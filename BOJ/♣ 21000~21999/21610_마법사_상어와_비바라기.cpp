#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int water[51][51];
bool is_cloud[51][51];
int dr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int N, Q;

void move_clouds(int direction, int moves) {
    vector<vector<bool>> saved(N + 1, vector<bool>(N + 1));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!is_cloud[r][c]) {
                continue;
            }

            int next_r = (r + N * 50 - 1 + dr[direction] * moves) % N + 1;
            int next_c = (c + N * 50 - 1 + dc[direction] * moves) % N + 1;

            saved[next_r][next_c] = true;
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            is_cloud[r][c] = saved[r][c];
        }
    }
}

void drop_rain() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (is_cloud[r][c]) {
                water[r][c] += 1;
            }
        }
    }
}

void perform_water_copy_bug() {
    vector<vector<int>> saved(N + 1, vector<int>(N + 1));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!is_cloud[r][c]) {
                continue;
            }

            int adjacent_water = 0;

            for (int i = 2; i <= 8; i += 2) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if (next_r < 1 || next_r > N || next_c < 1 || next_c > N || water[next_r][next_c] == 0) {
                    continue;
                }

                adjacent_water += 1;
            }

            saved[r][c] = adjacent_water;
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            water[r][c] += saved[r][c];
        }
    }
}

void create_clouds() {
    vector<vector<bool>> saved(N + 1, vector<bool>(N + 1));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            saved[r][c] = is_cloud[r][c];
            is_cloud[r][c] = false;
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!saved[r][c] && water[r][c] >= 2) {
                water[r][c] -= 2;
                is_cloud[r][c] = true;
            }
        }
    }
}

int get_water_sum() {
    int water_sum = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            water_sum += water[r][c];
        }
    }

    return water_sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> water[r][c];
        }
    }

    is_cloud[N][1] = true;
    is_cloud[N][2] = true;
    is_cloud[N - 1][1] = true;
    is_cloud[N - 1][2] = true;

    while (Q--) {
        int d, m;
        cin >> d >> m;

        move_clouds(d, m);
        drop_rain();
        perform_water_copy_bug();
        create_clouds();
    }

    cout << get_water_sum();
}
