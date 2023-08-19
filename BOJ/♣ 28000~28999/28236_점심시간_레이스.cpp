#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int best_class = -1;
    int best_distance = 999999;

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;

        int cur_distance = r - 1 + M - c;

        if (cur_distance < best_distance) {
            best_class = i;
            best_distance = cur_distance;
        }
    }

    cout << best_class;
}