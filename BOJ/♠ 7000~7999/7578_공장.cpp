#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

ll seg_tree[2000000];
int no[500000];
int pair_[1000001];

void set_visited(int start, int end, int idx, int target)
{
    if (start > target || end < target)
        return;

    seg_tree[idx]++;

    if (start != end)
    {
        int mid = (start + end) / 2;
        set_visited(start, mid, idx * 2 + 1, target);
        set_visited(mid + 1, end, idx * 2 + 2, target);
    }
}

ll find_cross(int start, int end, int idx, int left, int right)
{
    if (end < left || right < start)
        return 0;
    if (left <= start && end <= right)
        return seg_tree[idx];

    int mid = (start + end) / 2;
    return find_cross(start, mid, idx * 2 + 1, left, right) +
           find_cross(mid + 1, end, idx * 2 + 2, left, right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, c;
    ll total = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> no[i];

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        pair_[c] = i;
    }

    for (int i = 0; i < n; i++)
    {
        total += find_cross(0, n - 1, 0, pair_[no[i]], n - 1);
        set_visited(0, n - 1, 0, pair_[no[i]]);
    }

    cout << total;
}