#include <algorithm>
#include <iomanip>
#include <iostream>
#define INF 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Field {
    ll n, p;
};

Field arr[100001];

bool operator<(const Field& a, const Field& b) {
    return a.n < b.n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll base = 0;
    ll left = 0;
    ll right = 0;

    int N;
    cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> arr[i].n >> arr[i].p;
        base += arr[i].p;
    }

    sort(arr + 1, arr + N + 1);

    for (ll i = 2; i <= N; i++) {
        left += (i - 1) * (arr[i].n - arr[i - 1].n);
    }

    for (ll i = N - 1; i >= 1; i--) {
        right += (N - i) * (arr[i + 1].n - arr[i].n);
    }

    ll best = INF;

    // Mid
    for (ll i = 2; i <= N - 1; i++) {
        ll left_cur = base + left;
        ll right_cur = base + right;

        left_cur -= arr[i].p;
        right_cur -= arr[i].p;

        left_cur -= arr[N].n - arr[i].n;
        right_cur -= arr[i].n - arr[1].n;

        best = min({best,
                    left_cur,
                    right_cur});
    }

    // First
    ll cur = 0;

    for (ll i = 3; i <= N; i++) {
        cur += (i - 2) * (arr[i].n - arr[i - 1].n);
    }

    best = min(best, cur + base - arr[1].p);

    cur = 0;

    for (ll i = N - 1; i >= 2; i--) {
        cur += (N - i) * (arr[i + 1].n - arr[i].n);
    }

    best = min(best, cur + base - arr[1].p);

    // Last
    cur = 0;

    for (ll i = 2; i <= N - 1; i++) {
        cur += (i - 1) * (arr[i].n - arr[i - 1].n);
    }

    best = min(best, cur + base - arr[N].p);

    cur = 0;

    for (ll i = N - 2; i >= 1; i--) {
        cur += (N - i - 1) * (arr[i + 1].n - arr[i].n);
    }

    best = min(best, cur + base - arr[N].p);

    cout << best;
}
