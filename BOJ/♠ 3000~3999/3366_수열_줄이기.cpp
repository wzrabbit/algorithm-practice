#include <algorithm>
#include <iostream>
#include <stack>
#define INF 2'000'000'000
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    stack<ll> S;
    ll cost = 0;
    S.push(INF);

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        while (true) {
            if (S.top() > cur) {
                S.push(cur);
                break;
            }

            S.pop();
            ll left_comparer = S.top();
            cost += min(left_comparer, cur);
        }
    }

    S.pop();
    while (S.size() > 1) {
        ll cur = S.top();
        S.pop();
        cost += cur;
    }

    cout << cost;
}