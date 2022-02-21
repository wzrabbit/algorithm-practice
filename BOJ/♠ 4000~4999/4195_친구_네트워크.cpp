#include <iostream>
#include <string>
#include <map>
using namespace std;

int scale[200001] = {};
int parent[200001] = {};

int getParent(int no) {
	if (parent[no] == 0) return no;
	return parent[no] = getParent(parent[no]);
}

int getFriendScale(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		if (scale[a] >= scale[b]) {
			parent[b] = a;
			scale[a] += scale[b];
			return scale[a];
		}
		else {
			parent[a] = b;
			scale[b] += scale[a];
			return scale[b];
		}
	}
    else {
        return scale[a];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;

	while (test--) {
		int t;
		cin >> t;
		int id = 1;
		fill(scale + 1, scale + 200001, 1);
		fill(parent + 1, parent + 200001, 0);
		map<string, int> personMap;

		while (t--) {
			string personA, personB;
			cin >> personA >> personB;

			if (personMap.count(personA) == 0) {
				personMap[personA] = id++;
			}
			if (personMap.count(personB) == 0) {
				personMap[personB] = id++;
			}

			cout << getFriendScale(personMap[personA], personMap[personB]) << '\n';
		}
	}

	return 0;
}