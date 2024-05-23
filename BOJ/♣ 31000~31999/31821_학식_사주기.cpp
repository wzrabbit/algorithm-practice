#include <algorithm>
#include <iostream>
using namespace std;

int prices[11];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> prices[i];
    }

    int Q;
    cin >> Q;

    int total = 0;

    for (int i = 1; i <= Q; i++) {
        int cur;
        cin >> cur;

        total += prices[cur];
    }

    cout << total;
}
