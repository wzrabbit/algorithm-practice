#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Loc {
    int r, c;
};

ll grid[2][200000];

ll calculate_left_side(Loc start) {
    ll best = 0;
    ll cur = 0;

    cur += grid[1 - start.r][start.c];
    best = max(cur, best);

    for (int c = start.c - 1; c >= 0; c--) {
        cur += max(grid[0][c], grid[1][c]);
        best = max(cur, best);

        cur += min(grid[0][c], grid[1][c]);
        best = max(cur, best);
    }

    best += grid[start.r][start.c];

    return best;
}

ll calculate_mid_side(Loc start, Loc end) {
    ll best = 0;

    for (int c = start.c + 1; c <= end.c - 1; c++) {
        best += max(max(grid[0][c], grid[1][c]), grid[0][c] + grid[1][c]);
    }

    return best;
}

ll calculate_right_side(Loc end, int N) {
    ll best = 0;
    ll cur = 0;

    cur += grid[1 - end.r][end.c];
    best = max(cur, best);

    for (int c = end.c + 1; c <= N - 1; c++) {
        cur += max(grid[0][c], grid[1][c]);
        best = max(cur, best);

        cur += min(grid[0][c], grid[1][c]);
        best = max(cur, best);
    }

    best += grid[end.r][end.c];

    return best;
}

ll calculate_strict_left_side(Loc start) {
    ll best = 0;
    ll cur = 0;

    for (int c = start.c - 1; c >= 0; c--) {
        cur += max(grid[0][c], grid[1][c]);
        best = max(cur, best);

        cur += min(grid[0][c], grid[1][c]);
        best = max(cur, best);
    }

    best += grid[start.r][start.c];

    return best;
}

ll calculate_strict_right_side(Loc start, int N) {
    ll best = 0;
    ll cur = 0;

    for (int c = start.c + 1; c <= N - 1; c++) {
        cur += max(grid[0][c], grid[1][c]);
        best = max(cur, best);

        cur += min(grid[0][c], grid[1][c]);
        best = max(cur, best);
    }

    best += grid[start.r][start.c];

    return best;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < N; c++) {
                cin >> grid[r][c];
            }
        }

        Loc start, end;
        cin >> start.c >> start.r >> end.c >> end.r;
        start.r -= 1;
        start.c -= 1;
        end.r -= 1;
        end.c -= 1;

        if (start.c > end.c) {
            swap(start, end);
        }

        if (start.c == end.c) {
            cout << max(calculate_strict_left_side(start), calculate_strict_right_side(start, N)) +
                        grid[end.r][end.c]
                 << '\n';
        } else {
            cout << calculate_left_side(start) +
                        calculate_mid_side(start, end) +
                        calculate_right_side(end, N)
                 << '\n';
        }
    }
}
