#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct NextNode {
    int no;
    bool b;
};

struct Loc {
    int no, used;
};

vector<NextNode> graph[1001];
bool visited[2][1001];
bool is_stopped[1001];

void traverse() {
    queue<Loc> q;
    q.push({1, 0});
    visited[0][1] = true;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        bool stopped = true;

        for (size_t i = 0; i < graph[cur.no].size(); i++) {
            NextNode nxt = graph[cur.no][i];

            if (nxt.b) {
                stopped = false;
            }

            if (nxt.b && !visited[cur.used][nxt.no]) {
                visited[cur.used][nxt.no] = true;
                q.push({nxt.no, cur.used});
            }

            if (!nxt.b) {
                if (cur.used == 0 && !visited[1][nxt.no]) {
                    visited[1][nxt.no] = true;
                    q.push({nxt.no, 1});
                }
            }
        }

        if (stopped) {
            is_stopped[cur.no] = true;
        }
    }
}

void print_stop_count(int V) {
    int stop_count = 0;

    for (int i = 1; i <= V; i++) {
        if (is_stopped[i]) {
            stop_count += 1;
        }
    }

    cout << stop_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int start, end;
        cin >> start >> end;

        bool is_black = start < 0;

        graph[abs(start)].push_back({end, is_black});
    }

    traverse();
    print_stop_count(V);
}