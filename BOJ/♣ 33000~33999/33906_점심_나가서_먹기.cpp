#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 2'000'000'000
using namespace std;

struct Node {
    int n, d;
};

struct State {
    int n;
    bool r, c;
    int d;
};

bool operator<(const State &a, const State &b) { return a.d > b.d; }

int V, E;
bool visited[100001];
int restaurant[100001];
int cafe[100001];
int dist[100001][2][2];
vector<Node> graph[100001];
int min_restaurant_cost = INF;
int min_cafe_cost = INF;

void preliminary_traverse() {
    fill(visited + 1, visited + V + 1, false);
    visited[1] = true;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        min_restaurant_cost = min(min_restaurant_cost, restaurant[cur]);
        min_cafe_cost = min(min_cafe_cost, cafe[cur]);

        for (Node nxt : graph[cur]) {
            if (!visited[nxt.n]) {
                visited[nxt.n] = true;
                q.push(nxt.n);
            }
        }
    }
}

int get_min_dist() {
    fill(&dist[1][0][0], &dist[100000][1][2], INF);
    dist[1][0][0] = 0;
    priority_queue<State> pq;
    pq.push({1, 0, 0, 0});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n][cur.r][cur.c]) {
            continue;
        }

        for (Node nxt : graph[cur.n]) {
            bool next_r = cur.r | (restaurant[nxt.n] == min_restaurant_cost);
            bool next_c = cur.c | (cafe[nxt.n] == min_cafe_cost);

            int next_d = cur.d + nxt.d;

            if (next_d < dist[nxt.n][next_r][next_c]) {
                dist[nxt.n][next_r][next_c] = next_d;
                pq.push({nxt.n, next_r, next_c, next_d});
            }
        }
    }

    return dist[1][1][1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        cin >> restaurant[i];

        if (restaurant[i] == 0) {
            restaurant[i] = INF;
        }
    }

    for (int i = 1; i <= V; i++) {
        cin >> cafe[i];

        if (cafe[i] == 0) {
            cafe[i] = INF;
        }
    }

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    preliminary_traverse();
    cout << get_min_dist();
}
