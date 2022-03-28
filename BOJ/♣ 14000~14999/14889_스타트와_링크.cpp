#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int min_gap = 2000000000;
vector<int> selected;
int point[21][21];

void calculate_gap()
{
    vector<int> unselected;
    int value_A = 0, value_B = 0, gap;
    for (int i = 1; i <= n; i++)
    {
        if (find(selected.begin(), selected.end(), i) == selected.end())
            unselected.push_back(i);
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            value_A += point[selected[i]][selected[j]];
            value_B += point[unselected[i]][unselected[j]];
        }
    }

    gap = abs(value_A - value_B);
    if (gap < min_gap)
        min_gap = gap;
}

void make_team(int current, int count)
{
    selected.push_back(current);

    if (count == n / 2)
    {
        calculate_gap();
        selected.pop_back();
        return;
    }

    for (int i = current + 1; i <= n / 2 + count + 1; i++)
    {
        make_team(i, count + 1);
    }
    selected.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cin >> point[r][c];
        }
    }

    for (int i = 1; i <= n / 2 + 1; i++)
        make_team(i, 1);

    cout << min_gap;
}