#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

ll prefix[200001];
map<ll, ll> prefix_count;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    prefix_count[0] = 1;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;
        cur -= K;

        prefix[i] = prefix[i - 1];
        prefix[i] += cur;

        if (prefix_count.find(prefix[i]) == prefix_count.end()) {
            prefix_count[prefix[i]] = 1;
        } else {
            prefix_count[prefix[i]] += 1;
        }
    }

    ll answer = 0;

    for (auto it = prefix_count.begin(); it != prefix_count.end(); it++) {
        ll cur = it->second;
        answer += cur * (cur - 1) / 2;
    }

    cout << answer;
}