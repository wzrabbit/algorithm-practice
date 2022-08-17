#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct loc {
    int r, c;
};

int board[501][501];
bool visited[501][501];
int dr[4] = {-1, 1, 0, 0};  // Bit: 1↑, 2↓, 4←, 8→
int dc[4] = {0, 0, -1, 1};

void draw_line(int sr, int sc, int er, int ec) {
    if (sr == er) {
        if (sc > ec)
            swap(sc, ec);

        for (int c = sc; c < ec; c++) {
            if (sr > 0)
                board[sr - 1][c] |= 2;
            board[sr][c] |= 1;
        }
    } else {
        if (sr > er)
            swap(sr, er);

        for (int r = sr; r < er; r++) {
            if (sc > 0)
                board[r][sc - 1] |= 8;
            board[r][sc] |= 4;
        }
    }
}

int get_area(int start_r, int start_c) {
    queue<loc> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    int area = 0;

    while (q.size()) {
        loc cur = q.front();
        q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int next_r = cur.r + dr[i];
            int next_c = cur.c + dc[i];
            int b = 1 << i;

            if ((board[cur.r][cur.c] & b) == 0 && !visited[next_r][next_c]) {
                visited[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
        }
    }

    return area;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, D;
    cin >> R >> C >> D;

    for (int i = 0; i < D; i++) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        draw_line(sr, sc, er, ec);
    }
    draw_line(0, 0, R, 0);
    draw_line(0, 0, 0, C);
    draw_line(0, C, R, C);
    draw_line(R, 0, R, C);

    int max_area = 0;
    int min_area = 25001;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!visited[r][c]) {
                int cur = get_area(r, c);

                if (cur > max_area)
                    max_area = cur;

                if (cur < min_area)
                    min_area = cur;
            }
        }
    }

    cout << max_area << '\n'
         << min_area;
}