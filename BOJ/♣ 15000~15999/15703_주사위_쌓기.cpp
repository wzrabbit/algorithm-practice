#include <iostream>
using namespace std;

int num_count[1001];

bool make_tower() {
    int tower_size = 0;

    for (int i = 0; i <= 1000; i++) {
        while (num_count[i] > 0 && tower_size <= i) {
            num_count[i] -= 1;
            tower_size += 1;
        }
    }

    return tower_size > 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        num_count[cur] += 1;
    }

    int tower_count = 0;

    while (make_tower()) {
        tower_count += 1;
    }

    cout << tower_count;
}
