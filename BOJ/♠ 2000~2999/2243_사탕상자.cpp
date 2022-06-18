#include <iostream>
#include <algorithm>
using namespace std;

int seg_tree[4000004];

int get_sum(int start, int end, int idx, int left, int right)
{
    if (end < left || start > right)
        return 0;
    if (start >= left && end <= right)
        return seg_tree[idx];

    int mid = (start + end) / 2;
    return get_sum(start, mid, idx * 2, left, right) +
           get_sum(mid + 1, end, idx * 2 + 1, left, right);
}

void update_value(int start, int end, int idx, int target, int diff)
{
    if (start > target || end < target)
        return;

    seg_tree[idx] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update_value(start, mid, idx * 2, target, diff);
        update_value(mid + 1, end, idx * 2 + 1, target, diff);
    }
}

int get_candy_taste(int no)
{
    int start = 1, end = 1000000, mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (get_sum(1, 1000000, 1, 1, mid) >= no)
            end = mid;
        else
            start = mid + 1;
    }

    return start;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int q, x, y, z;
    cin >> q;

    while (q--)
    {
        cin >> x;

        if (x == 1)
        {
            cin >> y;
            int taste = get_candy_taste(y);
            update_value(1, 1000000, 1, taste, -1);
            cout << taste << '\n';
        }
        else
        {
            cin >> y >> z;
            update_value(1, 1000000, 1, y, z);
        }
    }
}