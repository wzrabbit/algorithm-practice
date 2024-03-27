#include <iostream>
using namespace std;

string grid[11][11];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int r = 1; r <= 10; r++) {
        for (int c = 1; c <= 10; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= 10; r++) {
        bool success = true;

        for (int c = 2; c <= 10; c++) {
            if (grid[r][c] != grid[r][c - 1]) {
                success = false;
                break;
            }
        }

        if (success) {
            cout << 1;
            return 0;
        }
    }

    for (int c = 1; c <= 10; c++) {
        bool success = true;

        for (int r = 2; r <= 10; r++) {
            if (grid[r][c] != grid[r - 1][c]) {
                success = false;
                break;
            }
        }

        if (success) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}
