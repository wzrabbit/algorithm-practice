#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1001
using namespace std;

struct Query {
    char t;
    int p;
};

struct Edge {
    int s, e;
};

vector<int> graph[1001];
Edge edges[100001];
Query queries[200001];
bool is_banned[1001][1001];
int dist[1001];
vector<int> answers;

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            if (is_banned[cur][nxt] || dist[cur] + 1 >= dist[nxt]) {
                continue;
            }

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        edges[i] = {s, e};
    }

    for (int i = 1; i <= Q; i++) {
        char t;
        int p;
        cin >> t >> p;

        queries[i] = {t, p};

        if (t == 'U') {
            int s = edges[p].s;
            int e = edges[p].e;
            is_banned[s][e] = true;
        }
    }

    fill(dist + 1, dist + N + 1, INF);
    dist[1] = 0;

    bfs(1);

    for (int i = Q; i >= 1; i--) {
        if (queries[i].t == 'U') {
            int s = edges[queries[i].p].s;
            int e = edges[queries[i].p].e;
            is_banned[s][e] = false;

            bfs(s);
        } else {
            int cur_dist = dist[queries[i].p];

            if (cur_dist == INF) {
                answers.push_back(-1);
            } else {
                answers.push_back(cur_dist);
            }
        }
    }

    for (int i = answers.size() - 1; i >= 0; i--) {
        cout << answers[i] << '\n';
    }
}