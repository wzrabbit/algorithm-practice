#include <iostream>
using namespace std;

char grid[1025][1025];

void solve(int start_row, int start_col, int size) {
    for (int c = start_col; c < start_col + size; c++) {
        grid[start_row][c] = '*';
    }

    for (int r = start_row; r < start_row + size; r++) {
        grid[r][start_col] = '*';
        grid[r][start_col + size - (r - start_row) - 1] = '*';
    }

    if (size == 1) {
        return;
    }

    solve(start_row, start_col, size / 2);
    solve(start_row, start_col + size / 2, size / 2);
    solve(start_row + size / 2, start_col, size / 2);
}

int main() {
    int N;
    cin >> N;
    N = 1 << N;

    fill(&grid[0][0], &grid[N - 1][N], ' ');
    solve(0, 0, N);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N - r; c++) {
            cout << grid[r][c];
        }

        if (r != N - 1) {
            cout << '\n';
        }
    }
}
