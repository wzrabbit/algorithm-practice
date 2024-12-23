#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

bool operator<(const Node &a, const Node &b) {
    if (a.d != b.d) {
        return a.d > b.d;
    }

    return a.n < b.n;
}

vector<Node> graph[10001];
ll mac_dist[10001], star_dist[10001];
bool is_store[10001];
int V, E;

void perform_dijkstra(vector<int> &start_nodes, ll dist[10001]) {
    fill(&dist[1], &dist[V + 1], INF);
    priority_queue<Node> pq;

    for (int start : start_nodes) {
        pq.push({start, 0});
        dist[start] = 0;
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (const Node nxt : graph[cur.n]) {
            if (dist[cur.n] + nxt.d < dist[nxt.n]) {
                dist[nxt.n] = dist[cur.n] + nxt.d;
                pq.push({nxt.n, dist[nxt.n]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    set<Node> input_nodes;  // 입력으로 들어온 간선을 검증을 위해 저장할 부분

    for (int i = 1; i <= E; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

        // 입력으로 들어온 간선을 정렬 후 저장
        if (u > v) {
            swap(u, v);
        }

        input_nodes.insert({u, v});
    }

    // 입력으로 들어온 간선에 중복 간선이 없다면 간선의 개수와 셋의
    // 크기가 같아야 함
    // 크기가 같지 않다면 중복 간선이 주어진다는 것을 의미하고, 이로 인해
    // AssertionFailed가 나올 것
    assert(input_nodes.size() == E);

    vector<int> mac_no_list, star_no_list;

    ll mac_count, mac_limit;
    cin >> mac_count >> mac_limit;

    for (int i = 1; i <= mac_count; i++) {
        int no;
        cin >> no;
        mac_no_list.push_back(no);
        is_store[no] = true;
    }

    ll star_count, star_limit;
    cin >> star_count >> star_limit;

    for (int i = 1; i <= star_count; i++) {
        int no;
        cin >> no;
        star_no_list.push_back(no);
        is_store[no] = true;
    }

    perform_dijkstra(mac_no_list, mac_dist);
    perform_dijkstra(star_no_list, star_dist);

    ll answer = INF;

    for (int i = 1; i <= V; i++) {
        if (is_store[i] || mac_dist[i] > mac_limit ||
            star_dist[i] > star_limit) {
            continue;
        }

        answer = min(answer, mac_dist[i] + star_dist[i]);
    }

    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer;
    }
}
