#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001];
struct qData {
	int loc, dist;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, start, finish, up, down;
	cin >> num >> start >> finish >> up >> down;

	queue<qData> que;
	bool success = false;
	que.push({ start, 0 });
	while (que.size()) {
		qData current = que.front();
		que.pop();

		if (current.loc == finish) {
			success = true;
			cout << current.dist;
			break;
		}

		int u = current.loc + up;
		if (u <= num && visited[u] == false) {
			visited[u] = true;
			que.push({ u, current.dist + 1 });
		}

		int d = current.loc - down;
		if (d >= 1 && visited[d] == false) {
			visited[d] = true;
			que.push({ d, current.dist + 1 });
		}
	}

	if (!success) cout << "use the stairs";
}