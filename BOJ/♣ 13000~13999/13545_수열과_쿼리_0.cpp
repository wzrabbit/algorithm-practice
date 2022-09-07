#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#define SQRT 800
using namespace std;

struct query {
    int i, s, e;
};

int arr[100001];
int prefix[100001];
int cnt[100000];
int cnt_sqrt[130];
int answer[100000];
query q_arr[100000];
list<int> loc[200001];
int N, Q;

bool mos_compare(query a, query b) {
    if (a.s / SQRT != b.s / SQRT) return a.s < b.s;
    return a.e < b.e;
}

int get_gap(int val) {
    if (loc[val].size() == 0) return 0;
    return loc[val].back() - loc[val].front();
}

void add_value(int idx, bool is_left) {
    int val = prefix[idx] + 100000;
    int old_gap = get_gap(val);
    cnt[old_gap]--;
    cnt_sqrt[old_gap / SQRT]--;

    if (is_left)
        loc[val].push_front(idx);
    else
        loc[val].push_back(idx);

    int new_gap = get_gap(val);
    cnt[new_gap]++;
    cnt_sqrt[new_gap / SQRT]++;
}

void del_value(int idx, bool is_left) {
    int val = prefix[idx] + 100000;
    int old_gap = get_gap(val);
    cnt[old_gap]--;
    cnt_sqrt[old_gap / SQRT]--;

    if (is_left)
        loc[val].pop_front();
    else
        loc[val].pop_back();

    int new_gap = get_gap(val);
    cnt[new_gap]++;
    cnt_sqrt[new_gap / SQRT]++;
}

int get_answer() {
    int cell = 0;
    for (int i = 129; i >= 1; i--) {
        if (cnt_sqrt[i] > 0) {
            cell = i;
            break;
        }
    }

    for (int i = (cell + 1) * SQRT - 1; i >= cell * SQRT; i--) {
        if (cnt[i] > 0) {
            return i;
        }
    }

    return 0;
}

void move_to_next(query before, query after) {
    int bs = before.s;
    int be = before.e;
    int as = after.s;
    int ae = after.e;

    while (bs > as) add_value(--bs, true);
    while (be < ae) add_value(++be, false);
    while (bs < as) del_value(bs++, true);
    while (be > ae) del_value(be--, false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cnt[0] = 200001;
    cnt_sqrt[0] = 200001;

    cin >> Q;
    for (int i = 0, s, e; i < Q; i++) {
        cin >> s >> e;
        q_arr[i] = {i, s - 1, e};
    }

    for (int i = 1; i <= N; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    sort(&q_arr[0], &q_arr[Q], mos_compare);

    query bq = q_arr[0];
    for (int i = bq.s; i <= bq.e; i++)
        add_value(i, false);
    answer[bq.i] = get_answer();

    for (int i = 1; i < Q; i++) {
        move_to_next(bq, q_arr[i]);
        answer[q_arr[i].i] = get_answer();
        bq = q_arr[i];
    }

    for (int i = 0; i < Q; i++)
        cout << answer[i] << '\n';
}