#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Result {
    int n;
    bool b;
};

vector<int> graph[200001];
int V, a, b, x;

Result get_traverse_result(int parent, int cur) {
    Result result = {1, false};

    for (int nxt : graph[cur]) {
        if (nxt == parent) {
            continue;
        }

        Result child_result = get_traverse_result(cur, nxt);

        result.n += child_result.n;
        result.b |= child_result.b;
    }

    if (cur == a || cur == b) {
        result.b = true;
    }

    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V;

    for (int i = 1; i <= V - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> a >> b >> x;
    int answer = 0;

    if (a == b && b == x) {
        cout << V;
        return 0;
    }

    if (a == b && b != x) {
        cout << 1;
        return 0;
    }

    if (a == x) {
        for (int adj : graph[a]) {
            Result result = get_traverse_result(a, adj);

            if (!result.b) {
                answer += result.n;
            }
        }

        cout << answer + 1;
        return 0;
    }

    if (b == x) {
        for (int adj : graph[b]) {
            Result result = get_traverse_result(b, adj);

            if (!result.b) {
                answer += result.n;
            }
        }

        cout << answer + 1;
        return 0;
    }

    for (int adj : graph[x]) {
        Result result = get_traverse_result(x, adj);

        if (!result.b) {
            answer += result.n;
        }
    }

    cout << answer + 1;
}
