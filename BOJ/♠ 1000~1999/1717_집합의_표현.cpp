#include <iostream>
#include <algorithm>

using namespace std;

int parent[1000001] = {};

int findUnion(int n)
{
    if (parent[n] == -1)
        return n;
    return parent[n] = findUnion(parent[n]);
}

void setUnion(int a, int b)
{
    a = findUnion(a);
    b = findUnion(b);
    if (a != b)
    {
        if (a > b)
            parent[a] = b;
        else
            parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(parent, parent + 1000001, -1);
    int num, query;
    cin >> num >> query;

    while (query--)
    {
        int m, a, b;
        cin >> m >> a >> b;

        if (m == 0)
        {
            setUnion(a, b);
        }
        else
        {
            if (findUnion(a) == findUnion(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}