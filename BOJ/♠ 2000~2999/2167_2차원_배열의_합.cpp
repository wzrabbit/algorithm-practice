#include <iostream>
using namespace std;

int grid[301][301];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;

        int sum = 0;

        for (int r = sr; r <= er; r++) {
            for (int c = sc; c <= ec; c++) {
                sum += grid[r][c];
            }
        }

        cout << sum << '\n';
    }
}