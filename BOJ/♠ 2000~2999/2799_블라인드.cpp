#include <iostream>
using namespace std;

char grid[502][502];
int blind_count[5];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R * 5 + 1; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 2; r <= R * 5 + 1; r += 5) {
        for (int c = 2; c <= C * 5 + 1; c += 5) {
            int blind = 0;

            for (int i = 0; i < 4; i++) {
                if (grid[r + i][c] == '*') {
                    blind += 1;
                }
            }

            blind_count[blind] += 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << blind_count[i] << ' ';
    }
}