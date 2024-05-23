#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int grid[65][65];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> answer;

        int up_count = 0;
        int down_count = 0;
        int prev_value = -1;

        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                cin >> grid[r][c];
            }

            if (r % 2 == 0) {
                reverse(&grid[r][1], &grid[r][N + 1]);
            }
        }

        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                int cur = grid[r][c];

                answer.push_back(cur);

                if (prev_value == -1) {
                    prev_value = cur;
                    continue;
                }

                if (cur > prev_value) {
                    up_count += 1;
                } else {
                    down_count += 1;
                }

                prev_value = cur;
            }
        }

        if (up_count > down_count) {
            reverse(answer.begin(), answer.end());
        }

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}
