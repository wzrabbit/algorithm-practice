#include <deque>
#include <iostream>
using namespace std;

struct Pos {
    int n, d;
};

bool visited[200001];

int bfs_01(int N, int K) {
    deque<Pos> dq;
    dq.push_back({N, 0});

    while (!dq.empty()) {
        Pos cur = dq.front();
        dq.pop_front();

        if (visited[cur.n]) {
            continue;
        }

        if (cur.n == K) {
            return cur.d;
        }

        visited[cur.n] = true;

        if (cur.n <= 100'000 && !visited[cur.n * 2]) {
            dq.push_front({cur.n * 2, cur.d});
        }

        if (cur.n >= 1 && !visited[cur.n - 1]) {
            dq.push_back({cur.n - 1, cur.d + 1});
        }

        if (cur.n < 200'000 && !visited[cur.n + 1]) {
            dq.push_back({cur.n + 1, cur.d + 1});
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << bfs_01(N, K);
}