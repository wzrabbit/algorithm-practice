#include <iostream>
#include <algorithm>
using namespace std;

int scale[3000];
int parent[3000];
int lines[3000][4];

int getParent(int no) {
	if (parent[no] == -1) return no;
	return parent[no] = getParent(parent[no]);
}

void merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		if (scale[a] >= scale[b]) {
			parent[b] = a;
			scale[a] += scale[b];
		}
		else {
			parent[a] = b;
			scale[b] += scale[a];
		}
	}
}

double getCCW(double ax, double ay, double bx, double by, double cx, double cy) {
	return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
}

bool isConnected(int no1, int no2) {
	double ax, ay, bx, by, cx, cy, dx, dy;
	ax = lines[no1][0]; ay = lines[no1][1];
	bx = lines[no1][2]; by = lines[no1][3];
	cx = lines[no2][0]; cy = lines[no2][1];
	dx = lines[no2][2]; dy = lines[no2][3];

	if (getCCW(ax, ay, bx, by, cx, cy) * getCCW(ax, ay, bx, by, dx, dy) == 0 &&
		getCCW(cx, cy, dx, dy, ax, ay) * getCCW(cx, cy, dx, dy, bx, by) == 0) {
		if (min(ax, bx) <= max(cx, dx) && min(cx, dx) <= max(ax, bx) &&
			min(ay, by) <= max(cy, dy) && min(cy, dy) <= max(ay, by)) {
			return true;
		}
		else return false;
	}
	else if (getCCW(ax, ay, bx, by, cx, cy) * getCCW(ax, ay, bx, by, dx, dy) <= 0 &&
		getCCW(cx, cy, dx, dy, ax, ay) * getCCW(cx, cy, dx, dy, bx, by) <= 0) {
		return true;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l;
	cin >> l;
	fill(parent, parent + l, -1);
	fill(scale, scale + l, 1);

	for (int i = 0; i < l; i++) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;

		lines[i][0] = a;
		lines[i][1] = b;
		lines[i][2] = c;
		lines[i][3] = d;
	}

	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (isConnected(i, j)) {
				merge(i, j);
			}
		}
	}

	int count = 0;
	int max_ = 0;
	for (int i = 0; i < l; i++) {
		if (parent[i] == -1) {
			count++;
			if (scale[i] > max_) max_ = scale[i];
		}
	}

	cout << count << '\n' << max_;
	return 0;
}