#include <iostream>
using namespace std;

char grid[20][20];
bool canvas[20][20];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void clear_canvas() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            canvas[r][c] = false;
        }
    }
}

bool draw_cross(int mid_r, int mid_c, int size) {
    if (canvas[mid_r][mid_c] || grid[mid_r][mid_c] == '.') {
        return false;
    }

    canvas[mid_r][mid_c] = true;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            int r = mid_r + dr[j] * i;
            int c = mid_c + dc[j] * i;

            if (r < 1 || r > R || c < 1 || c > C || canvas[r][c] || grid[r][c] == '.') {
                return false;
            }

            canvas[r][c] = true;
        }
    }

    return true;
}

bool is_valid(int r1, int c1, int r2, int c2, int size1, int size2) {
    clear_canvas();
    bool cross_draw_result = draw_cross(r1, c1, size1) && draw_cross(r2, c2, size2);

    return cross_draw_result;
}

int get_answer() {
    int best_answer = 0;
    int max_size = min(R / 2 + 1, C / 2 + 1);

    for (int r1 = 1; r1 <= R; r1++) {
        for (int c1 = 1; c1 <= C; c1++) {
            for (int r2 = 1; r2 <= R; r2++) {
                for (int c2 = 1; c2 <= C; c2++) {
                    for (int i = 1; i <= max_size; i++) {
                        for (int j = 1; j <= max_size; j++) {
                            if (is_valid(r1, c1, r2, c2, i, j)) {
                                best_answer = max(best_answer, (i * 4 - 3) * (j * 4 - 3));
                            }
                        }
                    }
                }
            }
        }
    }

    return best_answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    cout << get_answer();
}
