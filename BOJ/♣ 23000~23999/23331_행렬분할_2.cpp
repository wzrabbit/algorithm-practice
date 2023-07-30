#include <algorithm>
#include <iostream>
#include <vector>
#define INF 80'000'000
using namespace std;

int grid[101][9];
vector<int> cols;
int R, C, R_cut, C_cut;
int minimum_score = INF;

bool is_possible(int limit) {
    int cur_cut = 0;
    vector<int> before_scores(C_cut + 1);
    vector<int> cur_scores(C_cut + 1);

    for (int r = 1; r <= R; r++) {
        int pos = 1;
        bool is_exceeded = false;

        for (int i = 0; i <= C_cut; i++) {
            cur_scores[i] = 0;

            for (int c = pos; c < pos + cols[i]; c++) {
                cur_scores[i] += grid[r][c];
            }

            pos += cols[i];
        }

        for (int i = 0; i <= C_cut; i++) {
            if (cur_scores[i] > limit) {
                return false;
            }
        }

        for (int i = 0; i <= C_cut; i++) {
            if (before_scores[i] + cur_scores[i] > limit) {
                is_exceeded = true;
                break;
            }
        }

        if (is_exceeded) {
            cur_cut += 1;

            for (int i = 0; i <= C_cut; i++) {
                before_scores[i] = cur_scores[i];
            }
        } else {
            for (int i = 0; i <= C_cut; i++) {
                before_scores[i] += cur_scores[i];
            }
        }
    }

    return cur_cut <= R_cut;
}

void calculate_minimum() {
    int start = 1;
    int end = INF;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    minimum_score = min(minimum_score, start);
}

void make_cols(int pos, int left) {
    if (left == 0) {
        if (pos == C) {
            calculate_minimum();
        }

        return;
    }

    for (int i = 1; i <= C - left + 1; i++) {
        cols.push_back(i);
        make_cols(pos + i, left - 1);
        cols.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> R_cut >> C_cut;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }
    make_cols(0, C_cut + 1);

    cout << minimum_score;
}