#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1000001];
int dist_count[1000001];

void perform_dfs(int cur, int dist) {
    dist_count[dist] += 1;

    for (int next : graph[cur]) {
        perform_dfs(next, dist + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        int parent;
        cin >> parent;
        graph[parent].push_back(i);
    }

    perform_dfs(1, 0);

    int answer = 0;

    for (int i = 2; i <= N; i++) {
        int cur = 0;

        for (int j = 0; j <= N; j += i) {
            cur += dist_count[j];
        }

        answer = max(answer, cur);
    }

    cout << answer;
}
