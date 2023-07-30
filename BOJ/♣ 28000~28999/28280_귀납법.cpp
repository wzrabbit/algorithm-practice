#include <iostream>
#include <queue>
using namespace std;

int visited[8000001];

int bfs(int N) {
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == N) {
            return visited[cur];
        }

        if (cur < N && visited[cur * 2] == -1) {
            visited[cur * 2] = visited[cur] + 1;
            q.push(cur * 2);
        }

        if (cur > 1 && visited[cur - 1] == -1) {
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        fill(visited + 1, visited + N * 2 + 1, -1);

        cout << bfs(N) << '\n';
    }
}