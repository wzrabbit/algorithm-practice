#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct query {
    int idx, start, end;
};

vector<int> arr;
vector<list<int>> loc;
vector<int> len;
vector<int> len_sqrt;
vector<query> query_arr;
vector<int> answer;
int N, K, Q, N_sqrt;

bool mos_compare(query a, query b) {
    if (a.start / N_sqrt != b.start / N_sqrt) return a.start < b.start;
    return a.end < b.end;
}

int get_gap(int val) {
    if (loc[val].size() == 0)
        return 0;

    return loc[val].back() - loc[val].front();
}

void add_value(int idx, int is_left) {
    int val = arr[idx];
    int old_gap = get_gap(val);
    len[old_gap]--;
    len_sqrt[old_gap / N_sqrt]--;

    if (is_left)
        loc[val].push_front(idx);
    else
        loc[val].push_back(idx);

    int new_gap = get_gap(val);
    len[new_gap]++;
    len_sqrt[new_gap / N_sqrt]++;
}

void del_value(int idx, int is_left) {
    int val = arr[idx];
    int old_gap = get_gap(val);
    len[old_gap]--;
    len_sqrt[old_gap / N_sqrt]--;

    if (is_left)
        loc[val].pop_front();
    else
        loc[val].pop_back();

    int new_gap = get_gap(val);
    len[new_gap]++;
    len_sqrt[new_gap / N_sqrt]++;
}

int get_answer() {
    int cell = 0;
    for (int i = len_sqrt.size() - 1; i >= 0; i--) {
        if (len_sqrt[i] > 0) {
            cell = i;
            break;
        }
    }

    for (int i = min((int)len.size(), (cell + 1) * N_sqrt) - 1; i >= cell * N_sqrt; i--) {
        if (len[i] > 0)
            return i;
    }

    return 0;
}

void move_to_next(query before, query after) {
    int bs = before.start;
    int be = before.end;
    int as = after.start;
    int ae = after.end;

    while (bs > as) add_value(--bs, true);
    while (be < ae) add_value(++be, false);
    while (bs < as) del_value(bs++, true);
    while (be > ae) del_value(be--, false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    N_sqrt = (int)sqrt(N * 3);
    arr.resize(N);
    loc.resize(K + 1);
    len.resize(N);
    len_sqrt.resize(N / N_sqrt + 1);
    len[0] = K;
    len_sqrt[0] = K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> Q;
    query_arr.resize(Q);
    answer.resize(Q);

    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;
        query_arr[i] = {i, s - 1, e - 1};
    }

    sort(query_arr.begin(), query_arr.end(), mos_compare);

    query bf_query = query_arr[0];
    for (int i = bf_query.start; i <= bf_query.end; i++)
        add_value(i, false);

    answer[query_arr[0].idx] = get_answer();

    for (int i = 1; i < Q; i++) {
        move_to_next(bf_query, query_arr[i]);
        answer[query_arr[i].idx] = get_answer();
        bf_query = query_arr[i];
    }

    for (size_t i = 0; i < Q; i++)
        cout << answer[i] << '\n';
}