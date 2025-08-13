#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 251
typedef long long ll;
using namespace std;

struct Point {
    ll x, y;
};

int flow[302][302];
int capacity[302][302];
int prv[302];
vector<int> graph[302];
int N, K, H, M;

Point corners[1002], holes[51], mice[251];

ll get_ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int get_ccw_sign(Point a, Point b, Point c) {
    ll ccw = get_ccw(a, b, c);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool is_intersect(Point a1, Point a2, Point b1, Point b2) {
    int ccw1 = get_ccw_sign(a1, a2, b1) * get_ccw_sign(a1, a2, b2);
    int ccw2 = get_ccw_sign(b1, b2, a1) * get_ccw_sign(b1, b2, a2);

    if (ccw1 == 0 && ccw2 == 0) {
        return (min(a1.x, a2.x) <= max(b1.x, b2.x) &&
                min(b1.x, b2.x) <= max(a1.x, a2.x) &&
                min(a1.y, a2.y) <= max(b1.y, b2.y) &&
                min(b1.y, b2.y) <= max(a1.y, a2.y));
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

void make_graph() {
    for (int i = 1; i <= M; i++) {
        capacity[0][i] = 1;
        graph[0].push_back(i);
        graph[i].push_back(0);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= H; j++) {
            int intersect_count = 0;
            for (int k = 1; k <= N; k++) {
                if (holes[j].x == corners[k].x && holes[j].y == corners[k].y) {
                    continue;
                }

                if (is_intersect(corners[k], corners[k + 1], mice[i],
                                 holes[j])) {
                    intersect_count += 1;
                }
            }

            if (intersect_count == 1) {
                capacity[i][M + j] = 1;
                graph[i].push_back(M + j);
                graph[M + j].push_back(i);
            }
        }
    }

    for (int i = M + 1; i <= M + H; i++) {
        capacity[i][M + H + 1] = K;
        graph[i].push_back(M + H + 1);
        graph[M + H + 1].push_back(i);
    }
}

int get_max_flow() {
    int max_flow = 0;

    while (true) {
        fill(prv, prv + M + H + 2, -1);
        queue<int> q;
        q.push(0);

        while (!q.empty() && prv[M + H + 1] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    prv[nxt] = cur;
                    q.push(nxt);
                }
            }
        }

        if (prv[M + H + 1] == -1) {
            break;
        }

        int path_flow = INF;

        for (int i = M + H + 1; i != 0; i = prv[i]) {
            path_flow = min(path_flow, capacity[prv[i]][i] - flow[prv[i]][i]);
        }

        for (int i = M + H + 1; i != 0; i = prv[i]) {
            flow[prv[i]][i] += path_flow;
            flow[i][prv[i]] -= path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> H >> M;

    for (int i = 1; i <= N; i++) {
        cin >> corners[i].x >> corners[i].y;
    }
    corners[N + 1] = corners[1];

    for (int i = 1; i <= H; i++) {
        cin >> holes[i].x >> holes[i].y;
    }

    for (int i = 1; i <= M; i++) {
        cin >> mice[i].x >> mice[i].y;
    }

    make_graph();

    if (get_max_flow() == M) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }
}
