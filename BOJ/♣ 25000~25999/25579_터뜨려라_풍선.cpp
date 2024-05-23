#include <iostream>
typedef long long ll;
using namespace std;

struct Info {
    ll scale, sum;
};

ll parent[100001];
ll scale[100001];
ll sum[100001];
bool is_exist[100002];
ll queries[100001];
ll cur_score = 0;
ll best_score = 0;

ll get_parent(ll x) {
    if (parent[x] == 0) {
        return x;
    }

    return parent[x] = get_parent(parent[x]);
}

void merge(ll a, ll b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) {
        return;
    }

    cur_score -= sum[a] * scale[a];
    cur_score -= sum[b] * scale[b];

    parent[b] = a;
    scale[a] += scale[b];
    sum[a] += sum[b];
    scale[b] = 0;
    sum[b] = 0;

    cur_score += sum[a] * scale[a];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        scale[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> queries[i];
    }

    for (int i = N; i >= 1; i--) {
        best_score = max(cur_score, best_score);

        int cur = queries[i];
        is_exist[cur] = true;
        cur_score += sum[cur];

        if (is_exist[cur - 1]) {
            merge(cur - 1, cur);
        }

        if (is_exist[cur + 1]) {
            merge(cur + 1, cur);
        }
    }

    cout << best_score;
}
