#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[10001];
int cur_label = 1;
int labels[10001];
bool finish[10001];
stack<int> st;
vector<vector<int>> answer;
int V, E;

int scc(int cur) {
    int parent = labels[cur] = cur_label++;
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
        vector<int> cur_answer;
        int popped;

        while (popped != cur) {
            popped = st.top();
            st.pop();

            finish[popped] = true;
            cur_answer.push_back(popped);
        }

        answer.push_back(cur_answer);
    }

    return parent;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

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

    for (size_t i = 0; i < answer.size(); i++) {
        sort(answer[i].begin(), answer[i].end());
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        for (size_t j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << ' ';
        }

        cout << "-1\n";
    }
}