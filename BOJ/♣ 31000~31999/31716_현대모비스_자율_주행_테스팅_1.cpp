#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Loc {
    ll r, c, d;
};

char grid[3][300005];
bool visited[3][300005];
int dr[3] = {-1, 1, 0};
int dc[3] = {0, 0, 1};

ll get_dist(int start, int end) {
    fill(&visited[1][1], &visited[2][end + 1], false);
    queue<Loc> q;

    if (grid[1][start] == '.') {
        q.push({1, start});
        visited[1][start] = true;
    }

    if (grid[2][start] == '.') {
        q.push({2, start});
        visited[2][start] = true;
    }

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (cur.c == end) {
            return cur.d;
        }

        for (int i = 0; i < 3; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > 2 || c > end || visited[r][c] || grid[r][c] == '#') {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c, cur.d + 1});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int r = 1; r <= 2; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= 2; r++) {
        for (int c = N + 1; c <= N * 3; c++) {
            grid[r][c] = grid[r][c - N];
        }
    }

    ll single_dist = get_dist(1, N);
    ll double_dist = get_dist(1, N * 2);
    ll triple_dist = get_dist(1, N * 3);
    ll gap = triple_dist - double_dist;

    if (K == 1) {
        cout << single_dist;
        return 0;
    }

    if (double_dist == -1) {
        cout << -1;
        return 0;
    }

    cout << double_dist + gap * (K - 2);
}
