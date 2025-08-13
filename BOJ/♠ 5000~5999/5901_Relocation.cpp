#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define INF 1'000'000'000
using namespace std;

struct Node {
    int n, d;
};

bool operator<(const Node &a, const Node &b) { return a.d > b.d; }

vector<Node> graph[10001];
int markets[6];
int market_dist[6][10001];
map<int, int> market_indexes;
int N, M, K;

void perform_dijkstra(int start_node, int dist[10001]) {
    fill(dist + 1, dist + N + 1, INF);
    dist[start_node] = 0;
    priority_queue<Node> pq;
    pq.push({start_node, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (Node nxt : graph[cur.n]) {
            int next_dist = cur.d + nxt.d;

            if (next_dist < dist[nxt.n]) {
                dist[nxt.n] = next_dist;
                pq.push({nxt.n, next_dist});
            }
        }
    }
}

int get_min_tour_dist(int farm_node) {
    for (int i = 1; i <= K; i++) {
        if (farm_node == markets[i]) {
            return INF;
        }
    }

    vector<int> permutation;
    int min_tour_dist = INF;

    for (int i = 1; i <= K; i++) {
        permutation.push_back(markets[i]);
    }

    do {
        int tour_dist = 0;

        tour_dist += market_dist[market_indexes[permutation[0]]][farm_node];

        for (int i = 0; i < K - 1; i++) {
            tour_dist +=
                market_dist[market_indexes[permutation[i]]][permutation[i + 1]];
        }

        tour_dist += market_dist[market_indexes[permutation[K - 1]]][farm_node];
        min_tour_dist = min(min_tour_dist, tour_dist);

    } while (next_permutation(permutation.begin(), permutation.end()));

    return min_tour_dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= K; i++) {
        cin >> markets[i];
    }

    sort(markets + 1, markets + K + 1);

    for (int i = 1; i <= K; i++) {
        market_indexes[markets[i]] = i;
    }

    for (int i = 1; i <= M; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for (int i = 1; i <= K; i++) {
        perform_dijkstra(markets[i], market_dist[i]);
    }

    int answer = INF;

    for (int i = 1; i <= N; i++) {
        answer = min(answer, get_min_tour_dist(i));
    }

    cout << answer;
}
