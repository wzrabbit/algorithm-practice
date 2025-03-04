#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'001
using namespace std;

struct Path {
    int n, d;
};

vector<Path> graph[501];
int dists[2001];
bool visited[501];
int history[501];
vector<int> answer_path;
int V, E, S, T;
int answer_cost = INF;

void make_answer_path() {
    int cur = T;
    answer_path.clear();

    while (cur != -1) {
        answer_path.push_back(cur);
        cur = history[cur];
    }

    reverse(answer_path.begin(), answer_path.end());
}

bool traverse(int minimum, int maximum) {
    fill(visited + 1, visited + V + 1, false);
    fill(history + 1, history + V + 1, -1);
    visited[S] = true;
    queue<int> q;
    q.push(S);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == T) {
            int cur_cost = maximum - minimum;

            if (cur_cost < answer_cost) {
                answer_cost = cur_cost;
                make_answer_path();
            }

            return true;
        }

        for (Path nxt : graph[cur]) {
            if (!visited[nxt.n] && nxt.d >= minimum && nxt.d <= maximum) {
                visited[nxt.n] = true;
                history[nxt.n] = cur;
                q.push(nxt.n);
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> S >> T;

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
        dists[i] = d;
    }

    sort(dists + 1, dists + E + 1);

    for (int i = 1; i <= E; i++) {
        int start = dists[i];
        int end = dists[E];
        int mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (traverse(dists[i], mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    cout << answer_cost << '\n';

    for (size_t i = 0; i < answer_path.size(); i++) {
        cout << answer_path[i] << ' ';
    }
}
