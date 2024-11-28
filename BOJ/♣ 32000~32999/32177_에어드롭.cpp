#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y, v;
    bool p;
};

Node nodes[3001];
bool visited[3001];
bool graph[3001][3001];
vector<int> answer;
int N, K, T;

void traverse() {
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i <= N; i++) {
            if (graph[cur][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);

                if (nodes[i].p) {
                    answer.push_back(i);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> T;
    K *= K;

    cin >> nodes[0].x >> nodes[0].y >> nodes[0].v;

    for (int i = 1; i <= N; i++) {
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].v >> nodes[i].p;
    }

    for (int i = 0; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            int x = abs(nodes[i].x - nodes[j].x);
            int y = abs(nodes[i].y - nodes[j].y);
            int dist = x * x + y * y;
            int version_gap = abs(nodes[i].v - nodes[j].v);

            if (dist <= K && version_gap <= T) {
                graph[i][j] = graph[j][i] = true;
            }
        }
    }

    traverse();

    sort(answer.begin(), answer.end());

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    if (answer.size() == 0) {
        cout << 0;
    }
}
