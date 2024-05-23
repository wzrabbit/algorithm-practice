#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<int> graph[333334];
vector<tuple<int, int, int>> answer;
bool visited[333334];
vector<int> sub_nodes[333334];
int N;
bool success = true;

void perform_tree_dp(int cur_node) {
    if (!success) {
        return;
    }

    visited[cur_node] = true;
    sub_nodes[cur_node].push_back(cur_node);

    for (size_t i = 0; i < graph[cur_node].size(); i++) {
        int next_node = graph[cur_node][i];

        if (visited[next_node]) {
            continue;
        }

        perform_tree_dp(next_node);

        for (size_t i = 0; i < sub_nodes[next_node].size(); i++) {
            sub_nodes[cur_node].push_back(sub_nodes[next_node][i]);
        }
    }

    if (sub_nodes[cur_node].size() >= 4) {
        success = false;
        return;
    }

    if (sub_nodes[cur_node].size() == 3) {
        answer.push_back({sub_nodes[cur_node][0],
                          sub_nodes[cur_node][1],
                          sub_nodes[cur_node][2]});

        sub_nodes[cur_node].clear();
        return;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    perform_tree_dp(1);

    if (success) {
        cout << "S\n";

        for (size_t i = 0; i < answer.size(); i++) {
            cout
                << get<0>(answer[i]) << ' '
                << get<1>(answer[i]) << ' '
                << get<2>(answer[i]) << '\n';
        }
    } else {
        cout << "U\n";
    }
}
