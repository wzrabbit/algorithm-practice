#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Query1 {
    ll t, v;
};

struct Query2 {
    ll origin, l, r;
};

ll raw[100001];
ll seg[400001];
ll answer[100001];
Query1 query1[100001];
vector<Query2> query2[100001];

ll make_seg(ll start, ll end, ll index) {
    if (start == end) return seg[index] = raw[end];

    ll mid = (start + end) / 2;
    return seg[index] =
               make_seg(start, mid, index * 2) +
               make_seg(mid + 1, end, index * 2 + 1);
}

void update(ll start, ll end, ll index, ll target, ll value) {
    if (target < start || end < target) return;

    seg[index] += value;

    if (start == end) return;

    ll mid = (start + end) / 2;
    update(start, mid, index * 2, target, value);
    update(mid + 1, end, index * 2 + 1, target, value);
}

ll get_sum(ll start, ll end, ll index, ll left, ll right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return seg[index];

    ll mid = (start + end) / 2;
    return get_sum(start, mid, index * 2, left, right) +
           get_sum(mid + 1, end, index * 2 + 1, left, right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
    }

    int Q;
    cin >> Q;

    int query1_id = 0;
    int query2_id = 0;

    for (int i = 1; i <= Q; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            ll t, v;
            cin >> t >> v;
            query1[++query1_id] = {t, v};
        } else {
            ll k, l, r;
            cin >> k >> l >> r;
            query2[k].push_back({++query2_id, l, r});
        }
    }

    make_seg(1, N, 1);
    query1[0] = {1, raw[1]};

    for (int i = 0; i <= query1_id; i++) {
        Query1 query1_cur = query1[i];
        ll gap = query1_cur.v - raw[query1_cur.t];

        raw[query1_cur.t] = query1_cur.v;
        update(1, N, 1, query1_cur.t, gap);

        for (size_t j = 0; j < query2[i].size(); j++) {
            Query2 query2_cur = query2[i][j];
            answer[query2_cur.origin] = get_sum(1, N, 1, query2_cur.l, query2_cur.r);
        }
    }

    for (int i = 1; i <= query2_id; i++) {
        cout << answer[i] << '\n';
    }
}