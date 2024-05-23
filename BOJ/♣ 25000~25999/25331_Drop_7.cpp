#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100
using namespace std;

int grid_archive[9][9];
int grid[9][9];
int ball_no;

void get_inputs() {
    for (int r = 1; r <= 7; r++) {
        for (int c = 1; c <= 7; c++) {
            cin >> grid_archive[r][c];
        }
    }

    cin >> ball_no;
}

void reset_grid() {
    for (int r = 1; r <= 7; r++) {
        for (int c = 1; c <= 7; c++) {
            grid[r][c] = grid_archive[r][c];
        }
    }
}

void drop_ball(int col) {
    for (int r = 2; r <= 7; r++) {
        if (grid[r][col] != 0) {
            grid[r - 1][col] = ball_no;
            return;
        }
    }

    grid[7][col] = ball_no;
}

bool pop_balls() {
    vector<pair<int, int>> pop_locations;

    for (int r = 1; r <= 7; r++) {
        int start = -1;

        for (int c = 1; c <= 8; c++) {
            if (grid[r][c] == 0 && start != -1) {
                int area = c - start;

                for (int i = start; i < c; i++) {
                    if (grid[r][i] == area) {
                        pop_locations.push_back({r, i});
                    }
                }

                start = -1;
            } else if (grid[r][c] != 0 && start == -1) {
                start = c;
            }
        }
    }

    for (int c = 1; c <= 7; c++) {
        int start = -1;

        for (int r = 1; r <= 8; r++) {
            if (grid[r][c] == 0 && start != -1) {
                int area = r - start;

                for (int i = start; i < r; i++) {
                    if (grid[i][c] == area) {
                        pop_locations.push_back({i, c});
                    }
                }

                start = -1;
            } else if (grid[r][c] != 0 && start == -1) {
                start = r;
            }
        }
    }

    for (size_t i = 0; i < pop_locations.size(); i++) {
        int r = pop_locations[i].first;
        int c = pop_locations[i].second;

        grid[r][c] = 0;
    }

    return pop_locations.size() > 0;
}

void perform_gravity() {
    for (int i = 1; i <= 6; i++) {
        for (int r = 6; r >= 1; r--) {
            for (int c = 1; c <= 7; c++) {
                if (grid[r][c] != 0 && grid[r + 1][c] == 0) {
                    grid[r + 1][c] = grid[r][c];
                    grid[r][c] = 0;
                }
            }
        }
    }
}

int get_left_ball_count(int col) {
    reset_grid();
    drop_ball(col);

    bool should_pop = true;

    while (should_pop) {
        should_pop = pop_balls();
        perform_gravity();
    }

    int result = 0;

    for (int r = 1; r <= 7; r++) {
        for (int c = 1; c <= 7; c++) {
            if (grid[r][c] != 0) {
                result += 1;
            }
        }
    }

    return result;
}

int get_minimum_left_ball_count() {
    int answer = INF;

    for (int i = 1; i <= 7; i++) {
        answer = min(answer, get_left_ball_count(i));
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    get_inputs();
    cout << get_minimum_left_ball_count();
}
