#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int n, d;
};

vector<int> graph[100001];
priority_queue<int, vector<int>, greater<int>> blue_star_depths;
bool visited[100001];

void traverse() {
    queue<Node> q;
    vector<int> leafs;

    visited[1] = true;
    q.push({1, 1});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        bool is_leaf = true;

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i];

            if (!visited[next_node]) {
                visited[next_node] = true;
                is_leaf = false;
                q.push({next_node, cur.d + 1});
            }
        }

        if (is_leaf) {
            leafs.push_back(cur.d);
        }
    }

    int lowest_blue_star = blue_star_depths.top();
    blue_star_depths.pop();

    for (size_t i = 0; i < leafs.size(); i++) {
        blue_star_depths.push(lowest_blue_star + leafs[i]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    blue_star_depths.push(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;

        for (int i = 1; i <= A; i++) {
            graph[i].clear();
            visited[i] = false;
        }

        for (int i = 1; i <= A - 1; i++) {
            int s, e;
            cin >> s >> e;

            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        traverse();
    }

    while (true) {
        if (blue_star_depths.size() == 1) {
            cout << blue_star_depths.top();
            break;
        }

        blue_star_depths.pop();
    }
}
