#include <algorithm>
#include <iostream>
using namespace std;

char grid[52][52];
int R, C, K;

int get_same_pattern_count(int row) {
    int same_count = 0;

    for (int r = 1; r <= R; r++) {
        bool is_same = true;

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] != grid[row][c]) {
                is_same = false;
                break;
            }
        }

        if (is_same) {
            same_count += 1;
        }
    }

    return same_count;
}

bool is_possible_pattern(int row) {
    int zero_count = 0;

    for (int c = 1; c <= C; c++) {
        if (grid[row][c] == '0') {
            zero_count += 1;
        }
    }

    return zero_count <= K && zero_count % 2 == K % 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    cin >> K;

    int answer = 0;

    for (int r = 1; r <= R; r++) {
        if (is_possible_pattern(r)) {
            answer = max(answer, get_same_pattern_count(r));
        }
    }

    cout << answer;
}