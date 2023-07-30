#include <algorithm>
#include <iomanip>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;

ll arr[300001];
ld prefix[300001];
int N, K;

bool is_possible_avg(ld avg) {
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + arr[i] - avg;
    }

    ld worst_prefix = 0;

    for (int i = K; i <= N; i++) {
        if (prefix[i] - worst_prefix >= 0) {
            return true;
        }

        worst_prefix = min(worst_prefix, prefix[i - K + 1]);
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ld start = -3e11;
    ld end = 3e11;
    ld mid;

    for (int i = 1; i <= 55; i++) {
        mid = (start + end) / 2;

        if (is_possible_avg(mid)) {
            start = mid;
        } else {
            end = mid;
        }
    }

    cout << fixed << setprecision(4) << end;
}