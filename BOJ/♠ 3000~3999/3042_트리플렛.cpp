#include <iostream>
using namespace std;

struct Point {
    int r, c;
};

char grid[102][102];
Point points[27];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int id = 0;
    int triplet_count = 0;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] != '.') {
                points[++id] = {r, c};
            }
        }
    }

    for (int i = 1; i <= id - 2; i++) {
        for (int j = i + 1; j <= id - 1; j++) {
            for (int k = j + 1; k <= id; k++) {
                int diff_a_r = points[i].r - points[j].r;
                int diff_a_c = points[i].c - points[j].c;
                int diff_b_r = points[j].r - points[k].r;
                int diff_b_c = points[j].c - points[k].c;

                if (diff_a_r * diff_b_c == diff_a_c * diff_b_r) {
                    triplet_count += 1;
                }
            }
        }
    }

    cout << triplet_count;
}