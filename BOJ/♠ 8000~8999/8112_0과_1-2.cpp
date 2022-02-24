#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

bool mod[1000001] = {};
pair<int, char> history[1000001];

void track(int index) {
	int next = history[index].first;
	if (next != -1) track(next);
	cout << history[index].second;
}

void bfs(int num) {
	for (int i = 0; i <= 1000000; i++) {
		mod[i] = false;
	}
	mod[1] = true;
	bool success = false;
	queue<int> que;
	history[1] = make_pair(-1, '1');
	que.push(1);

	while (que.size()) {
		int m = que.front();
		que.pop();
		if (m == 0) {
			success = true;
			break;
		}

		for (int i = 0; i <= 1; i++) {
			if (mod[(m * 10 + i) % num] == false) {
				int calc = (m * 10 + i) % num;
				mod[calc] = true;
				que.push(calc);
				history[calc] = make_pair(m, '0' + i);
			}
		}
	}

	if (success) {
		int index = 0;
		track(0);
		cout << '\n';
	}
	else {
		cout << "BRAK\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int num;
		cin >> num;
		if (num == 1) cout << "1\n";
		else bfs(num);
	}
}