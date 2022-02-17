#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int result[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, limit;
	cin >> num >> limit;
	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 1; i <= num - 1; i++) {
		int start = 1;
		int end = min(i, num - (i + 1) + 1);
		int mid;

		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[i] - arr[i - mid] <= limit && arr[i + 1 + mid - 1] - arr[i] <= limit) start = mid + 1;
			else end = mid - 1;
		}
		if (result[i - end+ 1] < end * 2) result[i - end + 1] = end * 2;
	}

	int prev = result[1];
	cout << result[1] << '\n';
	for (int i = 2; i <= num; i++) {
		result[i] = max(result[i], prev - 2);
		cout << result[i] << '\n';
		prev = result[i];
	}
}