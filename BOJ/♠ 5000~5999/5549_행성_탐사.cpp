#include <iostream>
#include <algorithm>
using namespace std;

char board[1002][1002];
int ps[3][1001][1001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col, query;
	cin >> row >> col >> query;
	for (int r = 1; r <= row; r++) {
		cin >> board[r] + 1;
	}

	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			if (board[r][c] == 'J') ps[0][r][c] = 1;
			else if (board[r][c] == 'O') ps[1][r][c] = 1;
			else ps[2][r][c] = 1;

			for (int i = 0; i < 3; i++) {
				ps[i][r][c] += ps[i][r - 1][c] + ps[i][r][c - 1] - ps[i][r - 1][c - 1];
			}
		}
	}

	int r1, c1, r2, c2;
	while (query--) {
		cin >> r1 >> c1 >> r2 >> c2;
		for (int i = 0; i < 3; i++) {
			cout << ps[i][r2][c2] - ps[i][r1 - 1][c2] - ps[i][r2][c1 - 1] + ps[i][r1 - 1][c1 - 1] << ' ';
		}
		cout << '\n';
	}
}