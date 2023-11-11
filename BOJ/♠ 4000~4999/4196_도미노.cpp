#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[100001];
int labels[100001];
int teams[100001];
bool finish[100001];
bool is_zero_degree[100001];
int cur_label = 0;
int scc_label = 0;
stack<int> st;
int V, E;

void reset(int V) {
    for (int i = 1; i <= V; i++) {
        graph[i].clear();
    }

    fill(labels + 1, labels + V + 1, 0);
    fill(teams + 1, teams + V + 1, 0);
    fill(finish + 1, finish + V + 1, false);
    fill(is_zero_degree + 1, is_zero_degree + V + 1, true);
    cur_label = 0;
    scc_label = 0;
}

int scc(int cur) {
    int parent = labels[cur] = ++cur_label;
    st.push(cur);

    for (size_t i = 0; i < graph[cur].size(); i++) {
        int next_node = graph[cur][i];

        if (labels[next_node] == 0) {
            parent = min(parent, scc(next_node));
            continue;
        }

        if (!finish[next_node]) {
            parent = min(parent, labels[next_node]);
        }
    }

    if (parent == labels[cur]) {
        int popped = -1;
        scc_label += 1;

        while (popped != cur) {
            popped = st.top();
            st.pop();

            finish[popped] = true;
            teams[popped] = scc_label;
        }
    }

    return parent;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        reset(V);

        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
        }

        for (int i = 1; i <= V; i++) {
            if (!finish[i]) {
                scc(i);
            }
        }

        for (int i = 1; i <= V; i++) {
            for (size_t j = 0; j < graph[i].size(); j++) {
                int next_node = graph[i][j];

                if (teams[i] != teams[next_node]) {
                    is_zero_degree[teams[next_node]] = false;
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= scc_label; i++) {
            if (is_zero_degree[i]) {
                answer += 1;
            }
        }

        cout << answer << '\n';
    }
}