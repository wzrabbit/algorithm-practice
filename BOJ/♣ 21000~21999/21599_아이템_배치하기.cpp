#include <algorithm>
#include <iostream>
using namespace std;

int arr[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1, greater<int>());

    int enchanted_count = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            break;
        }

        enchanted_count = max(i + arr[i] - 1, enchanted_count);
    }

    cout << min(enchanted_count, N);
}