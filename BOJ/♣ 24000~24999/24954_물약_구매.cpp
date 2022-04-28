#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data_
{
    int no, dis;
};

vector<int> potion;
vector<vector<data_>> sale(10);
vector<int> comb;
bool visited[10];

int n;
int result = 1000000000;

void calc(vector<int> &comb)
{
    int state[10];
    int total = 0;

    for (int i = 0; i < n; i++)
        state[i] = potion[i];

    for (int i = 0; i < n; i++)
    {
        int current = comb[i];
        total += state[current];

        for (int j = 0; j < sale[current].size(); j++)
        {
            int no = sale[current][j].no;
            int dis = sale[current][j].dis;

            state[no] = max(state[no] - dis, 1);
        }
    }

    if (total < result)
    {
        result = total;
    }
}

void make_comb(int current)
{
    visited[current] = true;
    comb.push_back(current);

    if (comb.size() == n)
    {
        calc(comb);

        visited[current] = false;
        comb.pop_back();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            make_comb(i);
    }

    visited[current] = false;
    comb.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        potion.push_back(d);
    }

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            sale[i].push_back({a, b});
        }
    }

    for (int i = 0; i < n; i++)
        make_comb(i);

    cout << result;
}