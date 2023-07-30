#include <algorithm>
#include <iostream>
using namespace std;

char grid[7][7];

bool is_valid_act_number(int act_number, int repeat_count) {
    int bit_count[2] = {0, 0};

    for (int i = 1; i <= repeat_count; i++) {
        bit_count[act_number & 1] += 1;
        act_number >>= 1;
    }

    return bit_count[0] == bit_count[1];
}

int simulate(int act_number, int repeat_count) {
    int result_number = grid[1][1] - '0';
    char cur_operator;
    int r = 1;
    int c = 1;

    for (int i = 1; i <= repeat_count; i++) {
        int current_act = act_number & 1;
        act_number >>= 1;

        if (current_act == 0) {
            c += 1;
        } else {
            r += 1;
        }

        if (i % 2 == 0) {
            int cur_number = grid[r][c] - '0';

            switch (cur_operator) {
                case '+':
                    result_number += cur_number;
                    break;
                case '-':
                    result_number -= cur_number;
                    break;
                case '*':
                    result_number *= cur_number;
                    break;
            }
        } else {
            cur_operator = grid[r][c];
        }
    }

    return result_number;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    int max_number = -3126;
    int min_number = 3126;
    int repeat_count = (N - 1) * 2;

    for (int i = 0; i < (1 << repeat_count); i++) {
        if (!is_valid_act_number(i, repeat_count)) {
            continue;
        }

        int result = simulate(i, repeat_count);

        max_number = max(max_number, result);
        min_number = min(min_number, result);
    }

    cout << max_number << ' ' << min_number;
}