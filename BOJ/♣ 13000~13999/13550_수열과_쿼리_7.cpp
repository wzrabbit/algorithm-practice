#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#define SQRT 800
using namespace std;

struct Query {
    int i, s, e;
};

int arr[100001];
int mod_prefix[100001];
int cnt[100001];
int cnt_sqrt[130];
int answers[100001];
list<int> loc[1000000];
Query queries[100001];
int N, mod, Q;

bool mos_compare(Query a, Query b) {
    if (a.s / SQRT != b.s / SQRT) return a.s < b.s;
    return a.e < b.e;
}

int get_gap(int cur) {
    if (loc[cur].size() == 0) return 0;
    return loc[cur].back() - loc[cur].front();
}

void add_value(int index, bool is_left) {
    int cur = mod_prefix[index];
    int old_gap = get_gap(cur);
    cnt[old_gap] -= 1;
    cnt_sqrt[old_gap / SQRT] -= 1;

    if (is_left)
        loc[cur].push_front(index);
    else
        loc[cur].push_back(index);

    int new_gap = get_gap(cur);
    cnt[new_gap] += 1;
    cnt_sqrt[new_gap / SQRT] += 1;
}

void delete_value(int index, bool is_left) {
    int cur = mod_prefix[index];
    int old_gap = get_gap(cur);
    cnt[old_gap] -= 1;
    cnt_sqrt[old_gap / SQRT] -= 1;

    if (is_left)
        loc[cur].pop_front();
    else
        loc[cur].pop_back();

    int new_gap = get_gap(cur);
    cnt[new_gap] += 1;
    cnt_sqrt[new_gap / SQRT] += 1;
}

int get_answer() {
    int bucket = 0;

    for (int i = 129; i >= 1; i--) {
        if (cnt_sqrt[i] > 0) {
            bucket = i;
            break;
        }
    }

    int start = bucket * SQRT;
    int end = (bucket + 1) * SQRT - 1;

    for (int i = end; i >= start; i--) {
        if (cnt[i] > 0) {
            return i;
        }
    }

    return 0;
}

void move_to_next(Query before, Query after) {
    int bs = before.s;
    int be = before.e;
    int as = after.s;
    int ae = after.e;

    while (bs > as) add_value(--bs, true);
    while (be < ae) add_value(++be, false);
    while (bs < as) delete_value(bs++, true);
    while (be > ae) delete_value(be--, false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> mod;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mod_prefix[i] = (mod_prefix[i - 1] + arr[i]) % mod;
    }

    cnt[0] = 987654;
    cnt_sqrt[0] = 987654;

    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int s, e;
        cin >> s >> e;

        queries[i] = {i, s - 1, e};
    }

    sort(queries + 1, queries + Q + 1, mos_compare);

    Query before = queries[1];

    for (int i = before.s; i <= before.e; i++) {
        add_value(i, false);
    }
    answers[before.i] = get_answer();

    for (int i = 2; i <= Q; i++) {
        Query after = queries[i];
        move_to_next(before, after);

        answers[after.i] = get_answer();
        before = after;
    }

    for (int i = 1; i <= Q; i++) {
        cout << answers[i] << '\n';
    }
}