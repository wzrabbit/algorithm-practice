#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

vector<ll> parent;
vector<ll> scale;
vector<vector<ll>> element;
vector<ll> sorted;
vector<vector<ll>> group;
vector<ll> group_sum;
vector<ll> occupied;
map<ll, ll> comp;

ll get_parent(int child)
{
    if (parent[child] == -1)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);

    if (a != b)
    {
        if (scale[a] > scale[b])
        {
            parent[b] = a;
            scale[a] += scale[b];
        }
        else
        {
            parent[a] = b;
            scale[b] += scale[a];
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    element.resize(N);
    scale.resize(N);
    parent.resize(N);
    group.resize(N);
    group_sum.resize(N);
    fill(parent.begin(), parent.end(), -1);
    fill(scale.begin(), scale.end(), 1);

    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        element[i].push_back(a);
        element[i].push_back(b);
        sorted.push_back(a);
        sorted.push_back(b);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (size_t i = 0; i < sorted.size(); i++)
        comp[sorted[i]] = i;

    occupied.resize(sorted.size());
    fill(occupied.begin(), occupied.end(), -1);

    for (size_t i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (occupied[comp[element[i][j]]] != -1)
                merge(i, occupied[comp[element[i][j]]]);
            else
                occupied[comp[element[i][j]]] = i;
        }
    }

    for (int i = 0; i < N; i++)
    {
        ll p = get_parent(i);
        group[p].push_back(element[i][0]);
        group[p].push_back(element[i][1]);
        group_sum[i] += element[i][0] + element[i][1];
    }

    for (int i = 0; i < N; i++)
    {
        ll sub = group[i].size() / 2;
        sort(group[i].begin(), group[i].end());
        group[i].erase(unique(group[i].begin(), group[i].end()), group[i].end());

        for (int j = 0; j < sub; j++)
            group_sum[i] -= group[i][j];
    }

    ll answer = 0;
    for (int i = 0; i < N; i++)
        answer += group_sum[i];

    cout << answer;
}