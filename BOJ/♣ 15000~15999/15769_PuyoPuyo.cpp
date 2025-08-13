#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int board[21][21];
int is_odd_height[21];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, K;
    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> board[r][c];

            if (board[r][c] != 0) {
                is_odd_height[c] = !is_odd_height[c];
            }
        }
    }

    vector<tuple<int, int, int, int>> answer;

    for (int c = 1; c <= C; c++) {
        if (!is_odd_height[c]) {
            continue;
        }

        int other_color = (board[R][c] == 1) ? 2 : 1;
        answer.push_back(make_tuple(1, c, other_color, board[R][c]));
        answer.push_back(make_tuple(1, c, other_color, other_color));
        answer.push_back(make_tuple(1, c, other_color, other_color));
    }

    for (int c = 1; c <= C; c++) {
        for (int r = R - 1 - is_odd_height[c]; r >= 1; r -= 2) {
            if (board[r][c] == 0) {
                break;
            }

            answer.push_back(make_tuple(1, c, board[r][c], board[r + 1][c]));
        }
    }

    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << get<0>(answer[i]) << ' ' << get<1>(answer[i]) << ' '
             << get<2>(answer[i]) << ' ' << get<3>(answer[i]) << '\n';
    }
}
