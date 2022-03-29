#include <iostream>
#include <algorithm>
using namespace std;

int command[100003];
int dp[100003][5][5];
int limit = 0;

int power(int before, int after)
{
    if (before > after)
        swap(before, after);

    if (before == after)
        return 1;
    if (before == 0)
        return 2;
    if ((before == 1 && after == 3) || (before == 2 && after == 4))
        return 4;
    return 3;
}

int top_down(int level, int left, int right)
{
    int &current = dp[level][left][right];
    int temp;

    if (level == limit)
        return 0;
    if (current != -1)
        return current;

    if (command[level + 1] != right)
    {
        current = top_down(level + 1, command[level + 1], right) + power(left, command[level + 1]);
    }

    if (command[level + 1] != left)
    {
        temp = top_down(level + 1, left, command[level + 1]) + power(right, command[level + 1]);
        if (current == -1 || current > temp)
            current = temp;
    }

    return current;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 100001; i++)
    {
        cin >> command[i];
        if (command[i] == 0)
            break;
        limit++;
    }

    fill(&dp[0][0][0], &dp[100002][0][0], -1);
    cout << top_down(0, 0, 0);
}