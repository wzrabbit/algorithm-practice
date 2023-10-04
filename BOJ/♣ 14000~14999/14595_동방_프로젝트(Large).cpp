#include <iostream>
using namespace std;

int prefix[1000002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int start, end;
        cin >> start >> end;

        prefix[start] += 1;
        prefix[end] -= 1;
    }

    int state = 0;
    int room_count = 1;

    for (int i = 1; i < N; i++) {
        state += prefix[i];
        if (state == 0) {
            room_count += 1;
        }
    }

    cout << room_count;
}