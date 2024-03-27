#include <cassert>
#include <iostream>
using namespace std;

char frag[15][15];
char picture[35][35];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int FR, FC, R, C;
        cin >> FR >> FC;

        // L_i, C_i는 모두 1 이상 12 이하의 정수인가?
        assert(FR >= 1 && FR <= 12 && FC >= 1 && FC <= 12);

        for (int r = 1; r <= FR; r++) {
            cin >> (frag[r] + 1);
        }

        cin >> R >> C;

        // L_m, C_m은 모두 1 이상 32 이하의 정수인가?
        assert(R >= 1 && R <= 32 && C >= 1 && C <= 32);

        for (int r = 1; r <= R; r++) {
            cin >> (picture[r] + 1);
        }

        int success_count = 0;

        for (int i = 0; i <= R - FR; i++) {
            for (int j = 0; j <= C - FC; j++) {
                bool success = true;

                for (int r = 1; r <= FR; r++) {
                    for (int c = 1; c <= FC; c++) {
                        if (frag[r][c] != picture[r + i][c + j]) {
                            success = false;
                        }
                    }
                }

                if (success) {
                    success_count += 1;
                }
            }
        }

        cout << success_count << '\n';
    }
}
