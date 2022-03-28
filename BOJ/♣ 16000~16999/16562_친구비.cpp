#include <iostream>
using namespace std;

int cost[10001] = {};
int parent[10001] = {};

int getParent(int no)
{
    if (parent[no] == 0)
        return no;
    return parent[no] = getParent(parent[no]);
}

void addFriend(int a, int b)
{
    if (getParent(a) != getParent(b))
    {
        if (cost[a] >= cost[b])
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

    int pupil, friends, limit;
    cin >> pupil >> friends >> limit;

    for (int i = 1; i <= pupil; i++)
    {
        cin >> cost[i];
    }

    for (int i = 0; i < friends; i++)
    {
        int a, b;
        cin >> a >> b;
        addFriend(getParent(a), getParent(b));
    }

    int money = 0;
    bool success = true;
    for (int i = 1; i <= pupil; i++)
    {
        if (parent[i] == 0)
            money += cost[i];
        if (money > limit)
        {
            success = false;
            break;
        }
    }

    if (success)
        cout << money;
    else
        cout << "Oh no";

    return 0;
}