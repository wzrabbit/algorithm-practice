#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct query {
    int idx, start, end;
};

vector<int> arr;
vector<int> sorted_arr;
vector<int> answer;
vector<int> cnt_arr;
vector<query> q;
int N, Q, S, cnt;

void compress() {
    map<int, int> db;
    copy(arr.begin(), arr.end(), sorted_arr.begin());
    sort(sorted_arr.begin(), sorted_arr.end());
    int prev = 0;
    int id = 0;

    for (int i = 0; i < sorted_arr.size(); i++) {
        if (sorted_arr[i] != prev) {
            prev = sorted_arr[i];
            db[sorted_arr[i]] = id++;
        }
    }

    for (int i = 0; i < N; i++)
        arr[i] = db[arr[i]];
}

bool mos_compare(query a, query b) {
    if (a.start / S != b.start / S) return a.start < b.start;
    return a.end < b.end;
}

void add_value(int val) {
    cnt_arr[val]++;
    if (cnt_arr[val] == 1)
        cnt++;
}

void del_value(int val) {
    cnt_arr[val]--;
    if (cnt_arr[val] == 0)
        cnt--;
}

void move_to_next(query before, query after) {
    int bs = before.start;
    int be = before.end;
    int as = after.start;
    int ae = after.end;

    while (bs < as) del_value(arr[bs++]);
    while (bs > as) add_value(arr[--bs]);
    while (be < ae) add_value(arr[++be]);
    while (be > ae) del_value(arr[be--]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    S = 2000;
    arr.resize(N);
    sorted_arr.resize(N);
    cnt_arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> Q;
    answer.resize(Q);
    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;
        q.push_back({i, s - 1, e - 1});
    }

    compress();

    sort(q.begin(), q.end(), mos_compare);

    query bf_query = q[0];
    for (int i = bf_query.start; i <= bf_query.end; i++)
        add_value(arr[i]);
    answer[q[0].idx] = cnt;

    for (int i = 1; i < Q; i++) {
        move_to_next(bf_query, q[i]);
        answer[q[i].idx] = cnt;
        bf_query = q[i];
    }

    for (size_t i = 0; i < Q; i++)
        cout << answer[i] << '\n';
}