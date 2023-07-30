#include <iostream>
typedef long long ll;
using namespace std;

ll booth[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    ll minimum = 1'000'000'000;

    for (int i = 1; i <= N; i++) {
        cin >> booth[i];
        minimum = min(minimum, booth[i]);
    }

    ll start = 1;
    ll end = M * minimum;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        ll complete = 0;

        for (int i = 1; i <= N; i++) {
            complete += mid / booth[i];
        }

        if (complete >= M) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}