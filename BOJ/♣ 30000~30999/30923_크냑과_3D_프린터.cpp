#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[32769];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll total_area = N * 2;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        total_area += arr[i] * 4;
    }

    for (int i = 1; i <= N - 1; i++) {
        total_area -= min(arr[i], arr[i + 1]) * 2;
    }

    cout << total_area;
}
