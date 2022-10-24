#include <iostream>
using namespace std;

int wall[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;

        for (int i = x; i < y; i++) {
            wall[i] = 1;
        }
    }

    int room = 1;
    for (int i = 1; i <= N - 1; i++) {
        if (wall[i] == 0) room++;
    }

    cout << room;
}