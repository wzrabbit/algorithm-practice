#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll ice[1000001];

int main() {
    int N, K;
    cin >> N >> K;

    K = min(K * 2 + 1, 1000001);

    while (N--) {
        int amount, pos;
        cin >> amount >> pos;

        ice[pos] = amount;
    }

    ll cur = 0;

    for (int i = 0; i < K; i++) {
        cur += ice[i];
    }

    ll best = cur;

    for (int i = 0; i <= 1000000 - K; i++) {
        cur -= ice[i];
        cur += ice[i + K];
        best = max(best, cur);
    }

    cout << best;
}