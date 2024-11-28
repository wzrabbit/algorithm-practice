#include <deque>
#include <iostream>
using namespace std;

struct Pos {
    int n, d;
};

int next_pos[200001];
bool has_time_machine[200001];
bool visited[200001];
int N, K;

void write_next_pos() {
    int cur_next_pos = -1;

    for (int i = N; i >= 1; i--) {
        next_pos[i] = cur_next_pos;

        if (has_time_machine[i]) {
            cur_next_pos = i;
        }
    }
}

bool is_possible(int t) {
    deque<Pos> dq;
    fill(visited + 1, visited + N + 1, false);
    dq.push_back({N, 0});

    while (!dq.empty()) {
        Pos cur = dq.front();
        dq.pop_front();

        if (visited[cur.n]) {
            continue;
        }

        visited[cur.n] = true;

        if (cur.n == 1) {
            return cur.d <= K;
        }

        if (has_time_machine[cur.n]) {
            int next_n = max(1, cur.n - t);

            if (!visited[next_n]) {
                dq.push_back({next_n, cur.d + 1});
            }
        }

        int next_n = next_pos[cur.n];

        if (next_n != -1 && !visited[next_n]) {
            dq.push_front({next_n, cur.d});
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> has_time_machine[i];
    }

    write_next_pos();

    int start = 1;
    int end = N - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}
