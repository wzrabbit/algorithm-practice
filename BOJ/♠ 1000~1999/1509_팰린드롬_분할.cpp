#include <iostream>
#include <string>

using namespace std;
int dpA[2501][2501] = {};
int dpB[2501] = {};

int main()
{
    ios::sync_with_stdio(false);
    string text;
    cin >> text;

    // 팰린드롬 판별 DP
    for (unsigned int c = 0; c < text.length(); c++)
    {
        for (int r = 0; r <= c; r++)
        {
            if (r == c)
                dpA[r][c] = 1;
            else if (text[r] != text[c])
                dpA[r][c] = 0;
            else if (c - r == 1)
                dpA[r][c] = 1;
            else if (dpA[r + 1][c - 1] == 1)
                dpA[r][c] = 1;
            else
                dpA[r][c] = 0;
        }
    }

    // 분할 개수 DP
    dpB[0] = 1;
    for (unsigned int i = 1; i < text.length(); i++)
    {
        dpB[i] = 9999;
        if (dpA[0][i] == 1)
        {
            dpB[i] = 1;
            continue;
        }
        for (int j = 1; j <= i; j++)
        {
            if (dpA[j][i] == 1 && dpB[j - 1] + 1 < dpB[i])
            {
                dpB[i] = dpB[j - 1] + 1;
            }
        }
    }
    cout << dpB[text.length() - 1];
}