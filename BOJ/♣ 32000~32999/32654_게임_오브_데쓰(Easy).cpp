#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int n, d;
};

vector<int> graph[1001];
bool visited[1001][101];
bool result[101];

void bfs() {
    queue<Pos> q;
    q.push({1, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.d >= 100) {
            continue;
        }

        for (int next : graph[cur.n]) {
            if (!visited[next][cur.d + 1]) {
                visited[next][cur.d + 1] = true;
                q.push({next, cur.d + 1});
            }
        }
    }
}

void find_k() {
    for (int i = 1; i <= 100; i++) {
        if (!visited[1][i]) {
            continue;
        }

        for (int j = i; j <= 100; j += i) {
            result[j] = true;
        }
    }

    for (int i = 10; i <= 99; i++) {
        if (!result[i]) {
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
    find_k();
}
