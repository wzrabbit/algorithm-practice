#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000001], cnt[1000001];

int get_parent(int child)
{
    if (parent[child] == 0)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);

    if (a != b)
    {
        if (cnt[a] > cnt[b])
        {
            parent[b] = a;
            cnt[a] += cnt[b];
        }
        else
        {
            parent[a] = b;
            cnt[b] += cnt[a];
        }
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int t, x, y;
    char q;
    fill(cnt + 1, cnt + 1000001, 1);

    cin >> t;
    while (t--)
    {
        cin >> q;

        if (q == 'I')
        {
            cin >> x >> y;
            merge(x, y);
        }
        else
        {
            cin >> x;
            cout << cnt[get_parent(x)] << '\n';
        }
    }
}