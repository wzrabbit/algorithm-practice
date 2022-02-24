#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[301][301];
int dr[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dc[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
struct qData {
    int row, col, dist;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        int width, startRow, startCol, endRow, endCol;
        cin >> width >> startRow >> startCol >> endRow >> endCol;
        fill(&visited[0][0], &visited[width][width], false);

        queue<qData> que;
        que.push({ startRow, startCol, 0 });
        visited[startRow][startCol] = true;
        int count = 0;
        while (que.size()) {
            qData current = que.front();
            count++;
            que.pop();

            if (current.row == endRow && current.col == endCol) {
                cout << current.dist << '\n';
                break;
            }

            for (int i = 0; i < 8; i++) {
                int r = current.row + dr[i];
                int c = current.col + dc[i];

                if (r >= 0 && r < width && c >= 0 && c < width && visited[r][c] == false) {
                    visited[r][c] = true;
                    que.push({ r, c, current.dist + 1 });
                }
            }
        }
    }
}