#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int priority[32001];
vector<vector<int>> graph(32001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		priority[b]++;
	}

	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (priority[i] == 0) que.push(i);
	}

	while (que.size()) {
		int current = que.front();
		que.pop();
		cout << current << ' ';

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			priority[next]--;
			if (priority[next] == 0) que.push(next);
		}
	}
}