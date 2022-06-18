#include <iostream>
#include <algorithm>
#define INF 1e9 + 1
using namespace std;

int raw[100000];
int seg_tree[4000000];

int make_seg_tree(int start, int end, int idx)
{
    if (start == end)
    {
        seg_tree[idx] = raw[start];
        return seg_tree[idx];
    }

    int mid = (start + end) / 2;
    seg_tree[idx] = min(
        make_seg_tree(start, mid, idx * 2 + 1),
        make_seg_tree(mid + 1, end, idx * 2 + 2));
    return seg_tree[idx];
}

int get_min(int start, int end, int idx, int left, int right)
{
    if (left > end || right < start)
        return INF;
    if (left <= start && right >= end)
        return seg_tree[idx];

    int mid = (start + end) / 2;
    return min(
        get_min(start, mid, idx * 2 + 1, left, right),
        get_min(mid + 1, end, idx * 2 + 2, left, right));
}

int update_value(int start, int end, int idx, int target)
{
    if (target < start || target > end)
        return seg_tree[idx];
    if (target == start && target == end)
    {
        seg_tree[idx] = raw[target];
        return seg_tree[idx];
    }

    int mid = (start + end) / 2;
    seg_tree[idx] = min(
        update_value(start, mid, idx * 2 + 1, target),
        update_value(mid + 1, end, idx * 2 + 2, target));
    return seg_tree[idx];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, q, x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> raw[i];
    make_seg_tree(0, n - 1, 0);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y >> z;
        if (x == 1)
        {
            y--;
            raw[y] = z;
            update_value(0, n - 1, 0, y);
        }
        else
        {
            y--;
            z--;
            cout << get_min(0, n - 1, 0, y, z) << '\n';
        }
    }
}