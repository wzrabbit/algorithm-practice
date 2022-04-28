#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

bool visited[51][2501][2501];
int score[51];
int n;

void traverse(int no, int r, int c)
{
    visited[no][r][c] = true;
    if (no == n)
        return;
    if (visited[no + 1][r + score[no]][c] == false)
        traverse(no + 1, r + score[no], c); // 1
    if (visited[no + 1][r][c + score[no]] == false)
        traverse(no + 1, r, c + score[no]); // 2
    if (visited[no + 1][r][c] == false)
        traverse(no + 1, r, c); // 3
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    int max_ = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
        sum += score[i];
    }

    traverse(0, 0, 0);

    for (int r = 0; r <= sum; r++)
    {
        for (int c = 0; c <= sum; c++)
        {
            int current = sum - r - c;
            if (visited[n][r][c] == true)
                max_ = max(max_, min({current, r, c}));
        }
    }

    cout << max_;
}