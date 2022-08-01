#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> scale;
vector<vector<int>> party;
vector<int> know;
int lie = 0;

int get_parent(int child)
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

    int N, P, K;
    cin >> N >> P >> K;

    parent.resize(N + 1);
    scale.resize(N + 1);
    party.resize(P);
    know.resize(K);

    fill(parent.begin(), parent.end(), -1);
    fill(scale.begin(), scale.end(), 1);

    for (int i = 0; i < K; i++)
        cin >> know[i];

    for (int i = 0; i < P; i++)
    {
        int x;
        cin >> x;

        party[i].resize(x);
        for (int j = 0; j < x; j++)
            cin >> party[i][j];

        for (int j = 0; j < x - 1; j++)
            merge(party[i][j], party[i][j + 1]);
    }

    for (int i = 0; i < P; i++)
    {
        bool success = true;

        for (size_t j = 0; j < party[i].size(); j++)
        {
            for (size_t k = 0; k < know.size(); k++)
            {
                if (get_parent(party[i][j]) == get_parent(know[k]))
                {
                    success = false;
                    break;
                }
            }

            if (!success)
                break;
        }

        if (success)
            lie++;
    }

    cout << lie;
}