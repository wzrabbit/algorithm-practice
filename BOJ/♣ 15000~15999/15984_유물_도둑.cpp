#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct Lock {
    int time, node;
};

struct Node {
    int no, lv;
};

bool operator<(Lock a, Lock b) {
    return a.time < b.time;
}

int visited[2][10001];
int price[10001];
vector<int> graph[10001];
vector<Lock> locks;
vector<int> start_nodes;
queue<Node> q;
int V, E, Q, K;

void traverse() {
    fill(&visited[0][1], &visited[1][V + 1], -1);

    for (size_t i = 0; i < start_nodes.size(); i++) {
        visited[0][start_nodes[i]] = 0;
        q.push({start_nodes[i], 0});
    }

    start_nodes.clear();

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur.no].size(); i++) {
            int next_no = graph[cur.no][i];
            int next_lv = 1 - cur.lv;

            if (visited[next_lv][next_no] == -1) {
                visited[next_lv][next_no] = visited[cur.lv][cur.no] + 1;
                q.push({next_no, next_lv});
            }
        }
    }
}

void find_possible_nodes(int start_time, int end_time, int banned_node) {
    int lv = (end_time - start_time) % 2;
    int limit_time = end_time - start_time;

    for (int i = 1; i <= V; i++) {
        if (visited[lv][i] != -1 && visited[lv][i] <= limit_time && i != banned_node) {
            start_nodes.push_back(i);
        }
    }
}

void print_answer() {
    int best_price = 0;
    int best_node_count = 0;

    for (size_t i = 0; i < start_nodes.size(); i++) {
        int cur = start_nodes[i];

        if (price[cur] > best_price) {
            best_price = price[cur];
            best_node_count = 1;
        } else if (price[cur] == best_price) {
            best_node_count += 1;
        }
    }

    if (best_price > 0) {
        cout << best_price << ' ' << best_node_count;
    } else {
        cout << -1;
    }
}

void solve() {
    int prev_time = 0;
    start_nodes.push_back(1);

    for (int i = 0; i < Q; i++) {
        traverse();
        find_possible_nodes(prev_time, locks[i].time, locks[i].node);
        prev_time = locks[i].time;
    }

    traverse();
    find_possible_nodes(prev_time, K, -1);
    print_answer();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> Q >> K;

    for (int i = 1; i <= V; i++) {
        cin >> price[i];
    }

    for (int i = 1; i <= E; i++) {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= Q; i++) {
        int t, n;
        cin >> t >> n;

        locks.push_back({t, n});
    }

    sort(locks.begin(), locks.end());

    solve();
}