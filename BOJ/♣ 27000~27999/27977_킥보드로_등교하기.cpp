#include <iostream>
using namespace std;

int position[100002];
int cost[100002];
int L, N, K;

bool is_possible(int capacity) {
    int charge_count = 0;
    int current_fuel = capacity;

    for (int i = 1; i <= N + 1; i++) {
        if (capacity < cost[i]) {
            return false;
        }

        if (current_fuel - cost[i] < 0) {
            charge_count += 1;
            current_fuel = capacity - cost[i];
            continue;
        }

        current_fuel -= cost[i];
    }

    return charge_count <= K;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> L >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> position[i];

        cost[i] = position[i] - position[i - 1];
    }

    position[N + 1] = L;
    cost[N + 1] = position[N + 1] - position[N];

    int start = 1;
    int end = 200000;
    int mid;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}