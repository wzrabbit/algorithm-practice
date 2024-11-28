#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int l, n, d;
};

vector<int> graph[1001];
bool visited[2][1001][101];
bool result[101];
int dp[100];
vector<int> l_next;
vector<int> r_next;

void bfs() {
    queue<Pos> q;
    int l = graph[1][0];
    int r = graph[1][1];
    q.push({0, l, 1});
    q.push({1, r, 1});
    visited[0][1][0] = true;
    visited[1][1][0] = true;
    visited[0][l][1] = true;
    visited[1][r][1] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.n == 1) {
            continue;
        }

        if (cur.d >= 100) {
            continue;
        }

        for (int next : graph[cur.n]) {
            if (!visited[cur.l][next][cur.d + 1]) {
                visited[cur.l][next][cur.d + 1] = true;
                q.push({cur.l, next, cur.d + 1});
            }
        }
    }
}

void init_next_values() {
    for (int i = 1; i <= 100; i++) {
        if (visited[0][1][i]) {
            l_next.push_back(i);
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (visited[1][1][i]) {
            r_next.push_back(i);
        }
    }
}

int top_down(int cur) {
    if (cur < 0) {
        return true;
    }

    if (cur == 0) {
        return false;
    }

    if (dp[cur] != 0) {
        return dp[cur] == 1;
    }

    bool l_success = true;

    for (size_t i = 0; i < l_next.size(); i++) {
        if (!top_down(cur - l_next[i])) {
            l_success = false;
            break;
        }
    }

    bool r_success = true;

    for (size_t i = 0; i < r_next.size(); i++) {
        if (!top_down(cur - r_next[i])) {
            r_success = false;
            break;
        }
    }

    bool is_success = l_success || r_success;
    dp[cur] = is_success ? 1 : 2;
    return is_success;
}

void output_k() {
    for (int i = 10; i <= 99; i++) {
        if (top_down(i)) {
            cout << i;
            return;
        }
    }

    cout << -1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;

        graph[i].push_back(l);
        graph[i].push_back(r);
    }

    bfs();
    init_next_values();
    output_k();
}
