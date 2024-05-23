#include <iostream>
using namespace std;

bool has_balloon[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int start, interval;
        cin >> start >> interval;

        for (int i = start; i <= N; i += interval) {
            has_balloon[i] = true;
        }
    }

    int empty_count = 0;

    for (int i = 1; i <= N; i++) {
        if (!has_balloon[i]) {
            empty_count += 1;
        }
    }

    cout << empty_count;
}
