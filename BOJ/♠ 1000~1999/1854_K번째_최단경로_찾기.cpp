#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000
using namespace std;

struct Loc {
    int v, d;
};

bool operator<(Loc a, Loc b) {
    return a.d > b.d;
}

vector<Loc> graph[1001];
priority_queue<int> dist[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
    }

    priority_queue<Loc> pq;
    pq.push({1, 0});
    dist[1].push(0);

    while (pq.size()) {
        Loc cur = pq.top();
        pq.pop();

        for (size_t i = 0; i < graph[cur.v].size(); i++) {
            Loc nxt = graph[cur.v][i];

            if (dist[nxt.v].size() == 0 || cur.d + nxt.d < dist[nxt.v].top()) {
                if (dist[nxt.v].size() == K) dist[nxt.v].pop();
                dist[nxt.v].push(cur.d + nxt.d);
                pq.push({nxt.v, cur.d + nxt.d});
            } else if (cur.d + nxt.d >= dist[nxt.v].top() && dist[nxt.v].size() < K) {
                dist[nxt.v].push(cur.d + nxt.d);
                pq.push({nxt.v, cur.d + nxt.d});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i].size() < K)
            cout << -1 << '\n';
        else
            cout << dist[i].top() << '\n';
    }
}