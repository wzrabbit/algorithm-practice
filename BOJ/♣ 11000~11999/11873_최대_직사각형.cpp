#include <iostream>
#include <stack>
using namespace std;

int combo[1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    combo[0] = -1;

    while (true) {
        int R, C;
        cin >> R >> C;

        if (R == 0 && C == 0) {
            return 0;
        }

        for (int c = 1; c <= C + 1; c++) {
            combo[c] = 0;
        }

        int best_area = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                int cur;
                cin >> cur;

                if (cur == 1) {
                    combo[c] += 1;
                } else {
                    combo[c] = 0;
                }
            }

            stack<int> S;
            S.push(0);

            for (int c = 1; c <= C + 1; c++) {
                while (combo[c] <= combo[S.top()]) {
                    int popped = S.top();
                    S.pop();

                    int cur_area = (c - 1 - S.top()) * combo[popped];
                    best_area = max(best_area, cur_area);
                }

                S.push(c);
            }
        }

        cout << best_area << '\n';
    }
}