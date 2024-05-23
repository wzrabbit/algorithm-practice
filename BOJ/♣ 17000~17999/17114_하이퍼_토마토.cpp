#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int n, d;
};

int dimension_sizes[11];
int tomatoes[1000000];
int visited[1000000];
int d[22];
int N = 1;
int ripe_time;

void make_diff_array() {
    d[0] = 1;

    for (int i = 1; i < 11; i++) {
        d[i] = d[i - 1] * dimension_sizes[i - 1];
    }

    for (int i = 11; i < 22; i++) {
        d[i] = -d[i - 11];
    }
}

void simulate_tomato_riping() {
    queue<Node> q;

    for (int i = 0; i < N; i++) {
        if (tomatoes[i] == 1) {
            q.push({i, 0});
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        ripe_time = cur.d;

        for (int i = 0; i < 22; i++) {
            int n = cur.n + d[i];

            if (n < 0 ||
                n >= N ||
                visited[n] ||
                tomatoes[n] != 0) {
                continue;
            }

            if (i % 11 != 10) {
                int divisor = d[(i + 1) % 11];

                if (d[i] > 0 && cur.n % divisor >= n % divisor) {
                    continue;
                }

                if (d[i] < 0 && cur.n % divisor <= n % divisor) {
                    continue;
                }
            }

            visited[n] = true;
            q.push({n, cur.d + 1});
        }
    }
}

bool check_tomatoes_ripened() {
    for (int i = 0; i < N; i++) {
        if (tomatoes[i] == 0 && !visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 11; i++) {
        cin >> dimension_sizes[i];
        N *= dimension_sizes[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> tomatoes[i];
    }

    make_diff_array();
    simulate_tomato_riping();

    if (check_tomatoes_ripened()) {
        cout << ripe_time;
    } else {
        cout << -1;
    }
}
