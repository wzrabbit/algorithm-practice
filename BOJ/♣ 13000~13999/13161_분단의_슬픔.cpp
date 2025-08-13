/**
 * kks227님의 블로그의 디닉 코드를 참고하여 작성했습니다.
 *
 * https://m.blog.naver.com/kks227/220812858041
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 300'000'000
using namespace std;

int team[502];
int capacity[502][502];
int flow[502][502];
int level[502];
int work[502];
bool visited[502];
vector<int> graph[502];
int N;
int source = 0;
int sink;

void make_graph() {
    for (int i = 1; i <= N; i++) {
        if (team[i] == 1) {
            capacity[source][i] = INF;
            graph[source].push_back(i);
            graph[i].push_back(source);
        }

        if (team[i] == 2) {
            capacity[i][sink] = INF;
            graph[sink].push_back(i);
            graph[i].push_back(sink);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i].push_back(j);
        }
    }
}

/**
 * BFS 함수 - 레벨 그래프를 만드는 과정, sink를 지나는 레벨 그래프를 만들 수
 * 있는지의 여부를 bool으로 리턴
 */
bool make_level_graph() {
    fill(level, level + sink + 1, -1);
    level[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (level[nxt] == -1 && flow[cur][nxt] < capacity[cur][nxt]) {
                level[nxt] = level[cur] + 1;
                q.push(nxt);
            }
        }
    }

    return level[sink] != -1;
}

/**
 * DFS 함수 - 차단 유량(blocking flow)를 구하는 함수
 */
int get_path_flow(int cur, int dest, int path_flow) {
    if (cur == dest) return path_flow;

    for (int &i = work[cur]; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];

        if (level[nxt] == level[cur] + 1 &&
            flow[cur][nxt] < capacity[cur][nxt]) {
            int cur_flow = get_path_flow(
                nxt, dest, min(capacity[cur][nxt] - flow[cur][nxt], path_flow));

            if (cur_flow > 0) {
                flow[cur][nxt] += cur_flow;
                flow[nxt][cur] -= cur_flow;
                return cur_flow;
            }
        }
    }

    return 0;
}

int perform_dinic() {
    int max_flow = 0;

    while (make_level_graph()) {
        fill(work, work + sink + 1, 0);

        while (true) {
            int path_flow = get_path_flow(source, sink, INF);
            if (path_flow == 0) break;
            max_flow += path_flow;
        }
    }

    return max_flow;
}

void traverse_graph() {
    visited[source] = true;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (!visited[nxt] && flow[cur][nxt] < capacity[cur][nxt]) {
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    sink = N + 1;

    for (int i = 1; i <= N; i++) {
        cin >> team[i];
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> capacity[r][c];
        }
    }

    make_graph();
    cout << perform_dinic() << '\n';
    traverse_graph();

    for (int i = 1; i <= N; i++) {
        if (visited[i]) cout << i << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) cout << i << ' ';
    }
    cout << '\n';
}
