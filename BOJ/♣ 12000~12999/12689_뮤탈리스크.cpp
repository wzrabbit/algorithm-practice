#include <iostream>
#include <algorithm>
#define INF 999999
using namespace std;

int dp[61][61][62];
int input[3];

int top_down(int a, int b, int c)
{
    if (a < 0)
        a = 0;
    if (b < 0)
        b = 0;
    if (c < 0)
        c = 0;

    int &current = dp[a][b][c];
    if (current != INF)
        return current;

    current = min(current, top_down(a - 9, b - 3, c - 1) + 1);
    current = min(current, top_down(a - 9, b - 1, c - 3) + 1);
    current = min(current, top_down(a - 3, b - 9, c - 1) + 1);
    current = min(current, top_down(a - 3, b - 1, c - 9) + 1);
    current = min(current, top_down(a - 1, b - 3, c - 9) + 1);
    current = min(current, top_down(a - 1, b - 9, c - 3) + 1);

    return current;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    fill(&dp[0][0][0], &dp[60][60][61], INF);
    dp[0][0][0] = 0;

    cout << top_down(input[0], input[1], input[2]);
}