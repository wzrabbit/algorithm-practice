#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Interval {
    int s, e;
};

bool visited[101];
vector<int> graph[101];
Interval intervals[101];
int N = 0;

bool has_path(int start, int end) {
    fill(visited + 1, visited + N + 1, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) {
            return true;
        }

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];

            if (!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
            }
        }
    }

    return false;
}

void add_interval(int start, int end) {
    N += 1;
    intervals[N] = {start, end};

    for (int i = 1; i < N; i++) {
        Interval target = intervals[i];

        if ((target.s < start && start < target.e) || (target.s < end && end < target.e)) {
            graph[N].push_back(i);
        }

        if ((start < target.s && target.s < end) || (start < target.e && target.e < end)) {
            graph[i].push_back(N);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1) {
            add_interval(a, b);
            continue;
        }

        if (has_path(a, b)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
