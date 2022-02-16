#include <iostream>
using namespace std;

int board[500][500];
int dp[500][500];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int row, col;

int traverse(int ro, int co) {
	if (dp[ro][co] >= 0) return dp[ro][co];
	dp[ro][co] = 0;

	int plus = 0;
	for (int i = 0; i <= 3; i++) {
		int r = ro + dr[i];
		int c = co + dc[i];

		if (r >= 0 && r < row && c >= 0 && c < col && board[ro][co] > board[r][c]) {
			plus += traverse(r, c);
		}
	}

	dp[ro][co] += plus;
	return plus;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> row >> col;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> n;
			board[r][c] = n;
			dp[r][c] = -1;
		}
	}

	dp[row - 1][col - 1] = 1;
	traverse(0, 0);

	cout << dp[0][0] << '\n';
}