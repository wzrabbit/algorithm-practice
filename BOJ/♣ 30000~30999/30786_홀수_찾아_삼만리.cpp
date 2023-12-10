#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Pos {
    int r, c;
};

ll dist[1000000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    Pos before, after;
    cin >> before.r >> before.c;

    ll total_dist = 0;

    for (int i = 1; i <= N - 1; i++) {
        cin >> after.r >> after.c;

        ll cur_dist = abs(before.r - after.r) + abs(before.c - after.c);

        dist[i] = cur_dist;
        total_dist += cur_dist;

        before = after;
    }

    if (total_dist % 2 == 1) {
        cout << "YES\n";

        for (int i = 1; i <= N; i++) {
            cout << i << ' ';
        }

        return 0;
    }

    int selected_node = -1;

    for (int i = 1; i <= N; i++) {
        if (dist[i] % 2 == 1) {
            selected_node = i + 1;
            break;
        }
    }

    if (selected_node == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    cout << selected_node << ' ';

    for (int i = 1; i <= N; i++) {
        if (i != selected_node) {
            cout << i << ' ';
        }
    }
}
