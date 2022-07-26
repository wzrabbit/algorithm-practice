#include <iostream>
#include <algorithm>
#define INF 1e9 + 1
using namespace std;

struct s_data
{
    int min_, max_;
};

int raw[100000];
s_data seg_tree[400000];

s_data make_segtree(int start, int end, int idx)
{
    if (start == end)
        return seg_tree[idx] = {raw[start], raw[start]};

    int mid = (start + end) / 2;
    s_data left_res = make_segtree(start, mid, idx * 2 + 1);
    s_data right_res = make_segtree(mid + 1, end, idx * 2 + 2);

    return seg_tree[idx] = {
               min(left_res.min_, right_res.min_),
               max(left_res.max_, right_res.max_)};
}

s_data get_minmax(int start, int end, int idx, int left, int right)
{
    if (left > end || right < start)
        return {1000000001, -1000000001};

    if (left <= start && end <= right)
        return seg_tree[idx];

    int mid = (start + end) / 2;
    s_data left_res = get_minmax(start, mid, idx * 2 + 1, left, right);
    s_data right_res = get_minmax(mid + 1, end, idx * 2 + 2, left, right);

    return {min(left_res.min_, right_res.min_),
            max(left_res.max_, right_res.max_)};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, Q, L, R;
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> raw[i];

    make_segtree(0, N - 1, 0);

    for (int i = 0; i < Q; i++)
    {
        cin >> L >> R;
        L--;
        R--;
        s_data answer = get_minmax(0, N - 1, 0, L, R);
        cout << answer.min_ << ' ' << answer.max_ << '\n';
    }
}