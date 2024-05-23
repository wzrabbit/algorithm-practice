#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

string directions;
ll capacities[200001];
bool visited[200000];
ll N, M;

ll get_capacity(int start_pos) {
    visited[start_pos] = true;
    visited[(start_pos + 1) % N] = true;
    int left = (start_pos + N - 1) % N;
    int right = (start_pos + 2) % N;
    ll left_capacity = 0;
    ll right_capacity = 0;

    while (directions[left] == 'R' && !visited[left]) {
        visited[left] = true;
        left_capacity += capacities[left];
        left = (left + N - 1) % N;
    }

    while (directions[right] == 'L' && !visited[right]) {
        visited[right] = true;
        right_capacity += capacities[right];
        right = (right + 1) % N;
    }

    return min(left_capacity, M) + min(right_capacity, M);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    cin >> directions;

    ll before_capacity = 0;

    for (int i = 0; i < N; i++) {
        cin >> capacities[i];
        before_capacity += capacities[i];
    }

    ll total_capacity = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }

        if (directions[i] == 'R' && directions[(i + 1) % N] == 'L') {
            total_capacity += get_capacity(i);
        }
    }

    cout << before_capacity - total_capacity;
}
