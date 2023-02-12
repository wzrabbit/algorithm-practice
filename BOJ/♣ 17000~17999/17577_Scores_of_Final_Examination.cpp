#include <algorithm>
#include <iostream>
using namespace std;

int scores[50][1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        int C, R;
        int max_score = 0;

        cin >> C >> R;

        if (R == 0 && C == 0) {
            break;
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> scores[r][c];
            }
        }

        for (int c = 0; c < C; c++) {
            int current_score = 0;

            for (int r = 0; r < R; r++) {
                current_score += scores[r][c];
            }

            max_score = max(max_score, current_score);
        }

        cout << max_score << '\n';
    }
}