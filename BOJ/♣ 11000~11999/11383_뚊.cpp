#include <iostream>
using namespace std;

char grid[10][11];
char grid_2x[10][21];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> grid[r];
    }

    for (int r = 0; r < R; r++) {
        cin >> grid_2x[r];
    }

    bool is_same = true;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C * 2; c++) {
            if (grid[r][c / 2] != grid_2x[r][c]) {
                is_same = false;
            }
        }
    }

    if (is_same)
        cout << "Eyfa";
    else
        cout << "Not Eyfa";
}