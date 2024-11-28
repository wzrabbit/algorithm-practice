#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[10001];
bool visited[10001];
vector<int> answer;
int best_hack_count = 0;
int N, M;

void spread_virus(int start) {
    queue<int> q;
    q.push(start);
    fill(visited + 1, visited + N + 1, false);
    visited[start] = true;

    int cur_hack_count = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];

            if (!visited[next_node]) {
                visited[next_node] = true;
                q.push(next_node);
                cur_hack_count += 1;
            }
        }
    }

    if (cur_hack_count > best_hack_count) {
        answer.clear();
        best_hack_count = cur_hack_count;
    }

    if (cur_hack_count >= best_hack_count) {
        answer.push_back(start);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        spread_virus(i);
    }

    sort(answer.begin(), answer.end());

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}