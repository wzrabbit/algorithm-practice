#include <algorithm>
#include <iostream>
using namespace std;

int attack[100001];
int M, N, L;

bool can_hunt(int x, int y) {
    int start = 1;
    int end = M;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (attack[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    int left = max(1, end);
    int right = min(left + 1, M);

    return abs(attack[left] - x) + y <= L ||
           abs(attack[right] - x) + y <= L;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> L;

    for (int i = 1; i <= M; i++) {
        cin >> attack[i];
    }

    sort(attack + 1, attack + M + 1);

    int hunt_count = 0;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        if (can_hunt(x, y)) {
            hunt_count += 1;
        }
    }

    cout << hunt_count;
}