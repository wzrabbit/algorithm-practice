#include <iostream>
using namespace std;

int cnt = 0;
int num;

void make(long long current, int step, int goal) {
	int recent = current % 10;
	
	if (step == goal) {
		cnt++;
		if (cnt == num) {
			cout << current << '\n';
			exit(0);
		}
		return;
	}
	else if (recent < goal - step) return;

	for (int i = 0; i < recent; i++) {
		make(current * 10 + i, step + 1, goal);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;

	if (num == 0) {
		cout << 0;
		exit(0);
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			make(j, 1, i);
		}
	}

	cout << -1;
}