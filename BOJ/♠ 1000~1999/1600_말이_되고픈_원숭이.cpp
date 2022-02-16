#include <iostream>
#include <queue>
using namespace std;

int board[200][200];
bool visited[31][200][200] = {};
int mr[4] = { -1, 1, 0, 0 };
int mc[4] = { 0, 0, -1, 1 };
int dr[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dc[8] = { -1, 1, 2, -2, 2, -2, 1, -1 };
queue<pair<pair<int, int>, pair<int, int>>> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int move, col, row, data;
	cin >> move >> col >> row;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> data;
			board[r][c] = data;
		}
	}

	que.push(make_pair(make_pair(0, 0), make_pair(0, move)));
	visited[move][0][0] = true;
	while (que.size()) {
		int r_, c_, d, m;
		r_ = que.front().first.first;
		c_ = que.front().first.second;
		d = que.front().second.first;
		m = que.front().second.second;
		que.pop();

		if (r_ == row - 1 && c_ == col - 1) {
			cout << d;
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int r = r_ + mr[i];
			int c = c_ + mc[i];

			if (r >= 0 && r < row && c >= 0 && c < col && board[r][c] == 0 && visited[m][r][c] == false) {
				visited[m][r][c] = true;
				que.push(make_pair(make_pair(r, c), make_pair(d + 1, m)));
			}
		}

		for (int i = 0; i < 8; i++) {
			int r = r_ + dr[i];
			int c = c_ + dc[i];

			if (r >= 0 && r < row && c >= 0 && c < col && m > 0 && board[r][c] == 0 && visited[m - 1][r][c] == false) {
				visited[m - 1][r][c] = true;
				que.push(make_pair(make_pair(r, c), make_pair(d + 1, m - 1)));
			}
		}
	}

	cout << -1;
}