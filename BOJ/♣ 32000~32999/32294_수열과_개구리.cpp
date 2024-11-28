#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#define INF 1'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Pos {
    ll n, t;
};

bool operator<(const Pos &a, const Pos &b) { return a.t > b.t; }

ll A[600001];
ll B[600001];
ll escape_time[600001];
vector<Pos> graph[600001];
priority_queue<Pos> pq;
int N;

void make_graph() {
    fill(escape_time + 1, escape_time + 600001, INF);

    for (int i = 200001; i <= 200000 + N; i++) {
        ll next_left = i - A[i];
        ll next_right = i + A[i];

        graph[next_left].push_back({i, B[i]});
        graph[next_right].push_back({i, B[i]});

        if (next_left <= 200000 || next_left > 200000 + N) {
            pq.push({next_left, 0});
            escape_time[next_left] = 0;
        }

        if (next_right <= 200000 || next_right > 200000 + N) {
            pq.push({next_right, 0});
            escape_time[next_right] = 0;
        }
    }
}

void calculate_escape_time() {
    while (!pq.empty()) {
        Pos cur = pq.top();
        pq.pop();

        if (cur.t > escape_time[cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            ll next_node = graph[cur.n][i].n;
            ll next_time = graph[cur.n][i].t;

            if (escape_time[next_node] > cur.t + next_time) {
                escape_time[next_node] = cur.t + next_time;
                pq.push({next_node, escape_time[next_node]});
            }
        }
    }
}

void print_answer() {
    for (int i = 200001; i <= 200000 + N; i++) {
        cout << escape_time[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 200001; i <= 200000 + N; i++) {
        cin >> A[i];
    }

    for (int i = 200001; i <= 200000 + N; i++) {
        cin >> B[i];
    }

    make_graph();
    calculate_escape_time();
    print_answer();
}
