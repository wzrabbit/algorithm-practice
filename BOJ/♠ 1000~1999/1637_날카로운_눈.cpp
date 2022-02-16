#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll query[20000][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> query[i][0] >> query[i][1] >> query[i][2];
	}

	ll start = 1;
	ll end = 2147483648;
	ll mid;
	ll final_count = 0;
	while (start < end) {
		mid = (start + end) / 2;
		ll num_count = 0;
		ll count = 0;
		for (int i = 0; i < n; i++) {
			ll a = query[i][0];
			ll b = min(mid, query[i][1]);
			ll c = query[i][2];
			if (b - a >= 0) count += (b - a) / c + 1;
			if (mid >= a && mid <= b && (mid - a) % c == 0) num_count++;
		}

		if (count % 2 == 1) {
			end = mid;
			final_count = num_count;
		}
		else start = mid + 1;
	}
	if (start == 2147483648) cout << "NOTHING";
	else cout << start << ' ' << final_count;
}