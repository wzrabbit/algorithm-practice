#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

int priority[400000] = {};
int ranks[400000] = {};
vector<vector<int>> graph(400000);
map<string, int> intMap;
map<int, string> stringMap;
queue<int> que;
vector<string> sorter;
vector<string> temp;
vector<string> order;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    signed int id = 0;

    cin >> tc;

    while (tc--)
    {
        string a, b;
        cin >> a >> b;

        if (intMap.count(a) == 0)
        {
            intMap[a] = id;
            stringMap[id++] = a;
        }
        if (intMap.count(b) == 0)
        {
            intMap[b] = id;
            stringMap[id++] = b;
        }

        vector<int> data = graph[intMap[a]];
        if (find(data.begin(), data.end(), intMap[b]) == data.end())
        {
            graph[intMap[a]].push_back(intMap[b]);
            priority[intMap[b]] += 1;
        }
    }

    for (int i = 0; i < id; i++)
    {
        if (priority[i] == 0)
        {
            que.push(i);
            ranks[i] = 0;
        }
    }

    int step = 0;
    while (que.size())
    {
        int c = que.front();
        que.pop();

        if (ranks[c] > step)
        {
            step++;
            sort(sorter.begin(), sorter.end());
            for (size_t i = 0; i < sorter.size(); i++)
            {
                order.push_back(sorter[i]);
            }
            sorter.clear();
        }
        sorter.push_back(stringMap[c]);

        for (size_t i = 0; i < graph[c].size(); i++)
        {
            priority[graph[c][i]]--;
            ranks[graph[c][i]] = max(ranks[graph[c][i]], ranks[c] + 1);
            if (priority[graph[c][i]] == 0)
            {
                que.push(graph[c][i]);
            }
        }
    }

    sort(sorter.begin(), sorter.end());
    for (size_t i = 0; i < sorter.size(); i++)
    {
        order.push_back(sorter[i]);
    }

    if (order.size() == id)
    {
        for (size_t i = 0; i < order.size(); i++)
        {
            cout << order[i] << '\n';
        }
    }
    else
        cout << "-1\n";
}