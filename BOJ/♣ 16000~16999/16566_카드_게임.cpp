#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[4000000] = {};
vector<int> minsu;

int findCard(int n, int have)
{
    if (parent[n] == -1)
    {
        if (n != have - 1)
            parent[n] = n + 1;
        return n;
    }
    return parent[n] = findCard(parent[n], have);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(parent, parent + 4000000, -1);
    int all, have, query;
    cin >> all >> have >> query;

    for (int i = 0; i < have; i++)
    {
        int c;
        cin >> c;
        minsu.push_back(c);
    }
    sort(minsu.begin(), minsu.end());

    while (query--)
    {
        int q;
        int start = 0;
        int end = have - 1;
        cin >> q;
        q++;

        while (start < end)
        {
            int mid = (start + end) / 2;
            if (minsu[mid] >= q)
                end = mid;
            else
                start = mid + 1;
        }

        cout << minsu[findCard(end, have)] << '\n';
    }
}