#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll total = 0;
    ll height = 0;

    for (int i = N; i >= 1; i--) {
        height = min(arr[i], height + 1);
        total += height;
    }

    cout << total;
}
