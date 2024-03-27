#include <iostream>
using namespace std;

char grid[105][105];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N == 2) {
        cout << -1;
        return 0;
    }

    for (int r = 1; r <= 50; r++) {
        for (int c = 1; c <= 50; c++) {
            grid[r][c] = '.';
        }
    }

    for (int r = 50; r >= 50 - (N - 1) / 2; r--) {
        grid[r][1] = 'o';
    }

    for (int c = 2; c <= (N - 1) / 2 + 1; c++) {
        grid[50][c] = 'o';
    }

    if (N % 2 == 0) {
        grid[49][2] = 'o';
    }

    cout << "50\n";

    for (int r = 1; r <= 50; r++) {
        for (int c = 1; c <= 50; c++) {
            cout << grid[r][c];
        }

        cout << '\n';
    }
}