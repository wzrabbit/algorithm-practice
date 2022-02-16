#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int time[1000];
int maxTime[1000];
int priority[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;

	while (tc--) {
		int tower, rule, a, b;
		cin >> tower >> rule;
		vector<vector<int>> graph(tower);
		queue<int> que;
		fill(maxTime, maxTime + tower, 0);
		fill(priority, priority + tower, 0);

		for (int i = 0; i < tower; i++) {
			cin >> a;
			time[i] = a;
		}

		for (int i = 0; i < rule; i++) {
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			priority[b]++;
		}

		for (int i = 0; i < tower; i++) {
			if (priority[i] == 0) {
				que.push(i);
				maxTime[i] = time[i];
			}
		}

		int target;
		cin >> target;
		target--;
		while (que.size()) {
			int c = que.front();
			que.pop();

			for (size_t i = 0; i < graph[c].size(); i++) {
				int n = graph[c][i];
				priority[n]--;
				maxTime[n] = max(maxTime[c] + time[n], maxTime[n]);
				if (priority[n] == 0) que.push(n);
			}
		}

		cout << maxTime[target] << '\n';
	}
}