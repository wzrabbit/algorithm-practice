#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll raw[1000001];
ll tree[4000001];
ll mod = 1000000007;

ll makeSegTree(int start, int end, int index)
{
    if (start == end)
    {
        tree[index] = raw[start];
        return tree[index];
    }
    int mid = (start + end) / 2;
    tree[index] = makeSegTree(start, mid, index * 2 + 1) % mod * makeSegTree(mid + 1, end, index * 2 + 2) % mod;
    return tree[index];
}

ll getMul(int start, int end, int index, int left, int right)
{
    if (left > end || right < start)
        return 1;
    if (left <= start && right >= end)
        return tree[index];
    int mid = (start + end) / 2;
    return getMul(start, mid, index * 2 + 1, left, right) * getMul(mid + 1, end, index * 2 + 2, left, right) % mod;
}

ll update(int start, int end, int index, int target, ll newValue)
{
    if (target < start || target > end)
        return tree[index];
    if (start == end)
    {
        tree[index] = newValue;
        return tree[index];
    }
    int mid = (start + end) / 2;
    tree[index] = update(start, mid, index * 2 + 1, target, newValue) * update(mid + 1, end, index * 2 + 2, target, newValue) % mod;
    return tree[index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> raw[i];
    makeSegTree(0, n - 1, 0);

    for (int i = 0; i < m + k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        b--;

        if (a == 1)
        {
            update(0, n - 1, 0, b, c);
            raw[b] = c;
        }

        else
        {
            c--;
            cout << getMul(0, n - 1, 0, b, c) << '\n';
        }
    }
}