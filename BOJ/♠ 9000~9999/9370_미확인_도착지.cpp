#include <algorithm>
#include <iostream>
#include <queue>
#define INF 56'789'012
using namespace std;

struct Node {
    int n, d;
};

bool operator<(const Node& a, const Node& b) {
    return a.d > b.d;
}

vector<Node> graph[2001];
int dist[2001];
int V, E, F, S, G, H;

void dijkstra() {
    fill(dist + 1, dist + V + 1, INF);
    dist[S] = 0;
    priority_queue<Node> pq;
    pq.push({S, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d < dist[cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            Node next_node = graph[cur.n][i];
            int next_dist = cur.d + next_node.d;

            if (next_dist < dist[next_node.n]) {
                pq.push({next_node.n, next_dist});
                dist[next_node.n] = next_dist;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E >> F >> S >> G >> H;

        for (int i = 1; i <= V; i++) {
            graph[i].clear();
        }

        for (int i = 1; i <= E; i++) {
            int u, v, d;
            cin >> u >> v >> d;

            bool is_desired_path = (u == G && v == H) || (u == H && v == G);

            graph[u].push_back({v, d * 2 - is_desired_path});
            graph[v].push_back({u, d * 2 - is_desired_path});
        }

        dijkstra();

        vector<int> answer;

        for (int i = 1; i <= F; i++) {
            int cur;
            cin >> cur;

            if (dist[cur] % 2 == 1) {
                answer.push_back(cur);
            }
        }

        sort(answer.begin(), answer.end());

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}