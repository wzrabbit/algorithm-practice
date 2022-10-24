#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct Node {
    int v, c;
};

struct S_Node {
    int s, e;
};

int V, E;
vector<Node> graph[2000];
S_Node storage[2000];
bool visited[2000];
bool is_banned[2000][2000];

bool can_cross(int s, int e, int required) {
    queue<int> q;
    q.push(s);
    q.push(e);
    fill(visited, visited + V, false);
    visited[s] = true;
    visited[e] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto i = 0; i < graph[cur].size(); i++) {
            Node nxt = graph[cur][i];
            if (!visited[nxt.v] && nxt.c >= required && !is_banned[cur][nxt.v]) {
                visited[nxt.v] = true;
                q.push(nxt.v);
            }
        }
    }

    if (visited[0] && visited[V - 1]) {
        is_banned[s][e] = true;
        is_banned[e][s] = true;
        return true;
    } else
        return false;
}

ll calc_answer(ll power) {
    ll ans = 1;
    for (int i = 1; i <= power; i++) {
        ans = (ans * 3) % MOD;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back({e, i});
        graph[e].push_back({s, i});
        storage[i] = {s, e};
    }

    ll power = 0;
    for (int i = E - 1; i >= 0; i--) {
        if (can_cross(storage[i].s, storage[i].e, i)) {
            power = (power + calc_answer(i)) % MOD;
        }
    }
    cout << power;
}