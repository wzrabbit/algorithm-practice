#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define SAFE 0
#define FREE 1
#define DANGER 2
#define BLOCKED 3
#define INF 20000000000
typedef long long ll;
using namespace std;

struct Q_Data {
    ll v, d;
};

bool operator<(Q_Data x, Q_Data y) {
    return x.d > y.d;
}

int city_state[100001];
vector<int> graph[100001];
ll budget[100001];
queue<Q_Data> q;
priority_queue<Q_Data> pq;
int V, E, Z, R;
int cost_normal, cost_premium;

int get_cost(int no) {
    if (city_state[no] == SAFE) {
        return cost_normal;
    } else if (city_state[no] == DANGER) {
        return cost_premium;
    } else {
        return 0;
    }
}

void bfs() {
    while (!q.empty()) {
        Q_Data cur = q.front();
        q.pop();

        if (cur.d >= R) continue;

        for (size_t i = 0; i < graph[cur.v].size(); i++) {
            int next = graph[cur.v][i];
            if (city_state[next] == SAFE) {
                city_state[next] = DANGER;
                q.push({next, cur.d + 1});
            }
        }
    }
}

void dijkstra() {
    while (!pq.empty()) {
        Q_Data cur = pq.top();
        pq.pop();

        if (cur.d > budget[cur.v]) continue;

        for (size_t i = 0; i < graph[cur.v].size(); i++) {
            int next = graph[cur.v][i];
            if (city_state[next] == BLOCKED) continue;

            ll next_cost = cur.d + get_cost(next);

            if (next_cost < budget[next]) {
                budget[next] = next_cost;
                pq.push({next, next_cost});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> Z >> R;
    cin >> cost_normal >> cost_premium;

    for (int i = 0; i < Z; i++) {
        int zombie_no;
        cin >> zombie_no;
        city_state[zombie_no] = BLOCKED;
        q.push({zombie_no, 0});
    }

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    fill(budget + 2, budget + V + 1, INF);
    pq.push({1, 0});

    bfs();
    city_state[1] = FREE;
    city_state[V] = FREE;

    dijkstra();

    cout << budget[V];
}