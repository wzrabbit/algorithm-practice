#include <iostream>
#include <vector>
using namespace std;

int L[501], R[501];
bool visited[501];
vector<int> graph[501];
int N, K;

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (int adj : graph[cur]) {
        if (!R[adj] || dfs(R[adj])) {
            L[cur] = adj;
            R[adj] = cur;
            return true;
        }
    }

    return false;
}

int get_matched_count() {
    int matched_count = 0;

    for (int i = 1; i <= N; i++) {
        fill(visited + 1, visited + N + 1, false);

        if (dfs(i)) {
            matched_count += 1;
        }
    }

    return matched_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;

        graph[r].push_back(c);
    }

    cout << get_matched_count();
}
