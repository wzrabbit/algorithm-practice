#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[50];
int dp[50];
bool visited[50];

void dfs(int cur) {
    visited[cur] = true;
    dp[cur] = 0;
    vector<int> next_arr;
    int time = 0;

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];

        if (visited[next])
            continue;

        dfs(next);
        next_arr.push_back(dp[next]);
    }

    sort(next_arr.begin(), next_arr.end(), greater<int>());
    for (int i = 0; i < next_arr.size(); i++)
        dp[cur] = max(dp[cur], next_arr[i] + (i + 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;

        if (p != -1) {
            graph[i].push_back(p);
            graph[p].push_back(i);
        }
    }

    dfs(0);
    cout << dp[0];
}