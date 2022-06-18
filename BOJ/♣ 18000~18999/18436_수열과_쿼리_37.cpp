#include <iostream>
#include <algorithm>
#define INF 1e9 + 1
using namespace std;

int raw[100000];
int seg_tree[400000];

int make_seg_tree(int start, int end, int idx)
{
    if (start == end)
        return seg_tree[idx] = raw[start];

    int mid = (start + end) / 2;

    return seg_tree[idx] = make_seg_tree(start, mid, idx * 2 + 1) +
                           make_seg_tree(mid + 1, end, idx * 2 + 2);
}

int get_odd(int start, int end, int idx, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return seg_tree[idx];

    int mid = (start + end) / 2;
    return get_odd(start, mid, idx * 2 + 1, left, right) +
           get_odd(mid + 1, end, idx * 2 + 2, left, right);
}

void update_value(int start, int end, int idx, int target, int diff)
{
    if (target < start || target > end)
        return;

    seg_tree[idx] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update_value(start, mid, idx * 2 + 1, target, diff);
        update_value(mid + 1, end, idx * 2 + 2, target, diff);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, q, x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> raw[i];
        raw[i] %= 2;
    }
    make_seg_tree(0, n - 1, 0);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y >> z;

        if (x == 1)
        {
            y--;
            int before = raw[y];
            raw[y] = z % 2;
            int diff = raw[y] - before;
            update_value(0, n - 1, 0, y, diff);
        }
        else if (x == 2)
        {
            y--;
            z--;
            cout << (z - y + 1) - get_odd(0, n - 1, 0, y, z) << '\n';
        }
        else
        {
            y--;
            z--;
            cout << get_odd(0, n - 1, 0, y, z) << '\n';
        }
    }
}