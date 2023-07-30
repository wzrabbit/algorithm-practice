#include <algorithm>
#include <initializer_list>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100001];
int N;

ll calculate(ll gap) {
    ll total_dist = 0;

    for (int i = 2; i <= N; i++) {
        total_dist += abs(arr[i] - (i - 1) * gap);
    }

    return total_dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll start = 0;
    ll end = 1'000'000'000;

    while (end - start >= 3) {
        ll p = start + (end - start) / 3;
        ll q = start + (end - start) * 2 / 3;

        ll p_result = calculate(p);
        ll q_result = calculate(q);

        if (p_result >= q_result) {
            start = p;
        } else {
            end = q;
        }
    }

    ll best = min({calculate(start),
                   calculate(start + 1),
                   calculate(start + 2)});

    cout << best;
}