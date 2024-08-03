#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

ll arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll sum = 0;
    ll cur_sum = 0;
    ll answer = N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll required = (sum + 1) / 2;

    ll l = 0;
    ll r = 0;

    while (r <= N) {
        if (cur_sum >= required) {
            answer = min(answer, r - l);
            l += 1;
            cur_sum -= arr[l];
        } else {
            r += 1;
            cur_sum += arr[r];
        }
    }

    l = 0;
    r = 0;
    cur_sum = 0;

    multiset<ll> scores;
    scores.insert(1'000'000'001);

    while (r <= N) {
        if (cur_sum - *scores.begin() >= required) {
            answer = min(answer, r - l - 1);

            l += 1;
            cur_sum -= arr[l];
            auto it = scores.find(arr[l]);
            scores.erase(it);
        } else {
            r += 1;
            cur_sum += arr[r];
            scores.insert(arr[r]);
        }
    }

    cout << answer;
}
