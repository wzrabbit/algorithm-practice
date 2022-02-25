#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int unions[100];
int ranks[100];
vector<pair<double, double>> stars;
vector<pair<pair<int, int>, double>> lines;

int getParent(int a)
{
    if (unions[a] == -1)
        return a;
    return unions[a] = getParent(unions[a]);
}

bool merge(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a != b)
    {
        if (ranks[a] > ranks[b])
        {
            unions[b] = a;
            ranks[a] += ranks[b];
        }
        else
        {
            unions[a] = b;
            ranks[b] += ranks[a];
        }
        return true;
    }
    return false;
}

bool compare(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(unions, unions + 100, -1);
    fill(ranks, ranks + 100, 1);

    int tc;
    double x, y;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }

    for (int i = 0; i < tc; i++)
    {
        for (int j = i + 1; j < tc; j++)
        {
            double x1 = stars[i].first;
            double y1 = stars[i].second;
            double x2 = stars[j].first;
            double y2 = stars[j].second;

            double calc = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            lines.push_back(make_pair(make_pair(i, j), calc));
        }
    }

    sort(lines.begin(), lines.end(), compare);

    int count = 0;
    double len = 0;
    int index = 0;

    while (count < tc - 1)
    {
        int x = lines[index].first.first;
        int y = lines[index].first.second;
        double v = lines[index].second;

        if (merge(x, y))
        {
            count++;
            len += v;
        }

        index++;
    }

    cout << len;
}