#include <iostream>
using namespace std;

int grid[100][100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int x;
            cin >> x;
            cout << grid[r][c] + x << ' ';
        }
        cout << '\n';
    }
}