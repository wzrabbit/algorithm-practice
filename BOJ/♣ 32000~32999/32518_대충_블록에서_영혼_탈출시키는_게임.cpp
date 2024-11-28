#include <algorithm>
#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

map<ll, ll> dp;

ll top_down(ll cur) {
    if (dp.find(cur) != dp.end()) {
        return dp[cur];
    }

    ll answer = top_down(cur / 3) +
                top_down((cur - 1) / 3) +
                top_down((cur - 2) / 3) + 2;

    if (cur % 3 == 1) {
        answer = max(answer, top_down((cur + 2) / 3) +
                                 top_down((cur - 2) / 3) +
                                 top_down((cur - 2) / 3) + 2);
    }

    return dp[cur] = answer;
}

int main() {
    ll N;
    cin >> N;

    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    cout << top_down(N);
}
