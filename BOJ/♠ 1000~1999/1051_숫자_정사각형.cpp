#include <algorithm>
#include <iostream>
using namespace std;

char grid[101][101];

int check(int start_R, int start_C, int width) {
    if (grid[start_R][start_C] == grid[start_R + width - 1][start_C] &&
        grid[start_R][start_C] == grid[start_R][start_C + width - 1] &&
        grid[start_R][start_C] == grid[start_R + width - 1][start_C + width - 1])
        return width * width;
    else
        return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 0; r < R; r++)
        cin >> grid[r];

    int W = min(R, C);
    int ans = 0;
    for (int w = W; w >= 1; w--) {
        for (int r = 0; r < R - w + 1; r++) {
            for (int c = 0; c < C - w + 1; c++)
                ans = max(ans, check(r, c, w));
        }
    }

    cout << ans;
}