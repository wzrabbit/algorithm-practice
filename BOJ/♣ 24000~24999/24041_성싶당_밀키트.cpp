#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Ingredient {
    ll s, l, o;
};

Ingredient ingredients[200001];
ll N, G, K;

bool is_possible(ll day) {
    vector<ll> bans;
    ll total_virus = 0;

    for (int i = 1; i <= N; i++) {
        ll s = ingredients[i].s;
        ll l = ingredients[i].l;
        ll o = ingredients[i].o;

        ll cur_virus = s * max(1ll, day - l);
        total_virus += cur_virus;

        if (o == 1) {
            bans.push_back(cur_virus);
        }
    }

    sort(bans.begin(), bans.end(), greater<ll>());

    for (int i = 0; i < min((ll)bans.size(), K); i++) {
        total_virus -= bans[i];
    }

    return total_virus <= G;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> G >> K;

    for (int i = 1; i <= N; i++) {
        Ingredient cur;
        cin >> cur.s >> cur.l >> cur.o;

        ingredients[i] = cur;
    }

    ll start = 0;
    ll end = 2'000'000'000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}