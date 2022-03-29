#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

char town[52][52];
int fatique[52][52];
bool visited[52][52];
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, 1, -1};
struct loc
{
    int row, col;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    loc start_location;
    int goal = 0;
    cin >> n;
    for (int r = 0; r < n; r++)
    {
        cin >> town[r];
        for (int c = 0; c < n; c++)
        {
            if (town[r][c] == 'P')
                start_location = {r, c};
            else if (town[r][c] == 'K')
                goal++;
        }
    }

    set<int> fatique_set;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> fatique[r][c];
            fatique_set.insert(fatique[r][c]);
        }
    }

    vector<int> fatique_list(fatique_set.begin(), fatique_set.end());
    sort(fatique_list.begin(), fatique_list.end());

    int l = 0;
    int r = 0;
    int start_value = fatique[start_location.row][start_location.col];
    int min_ = 1000010;

    while (r < fatique_list.size())
    {
        int limit_low = fatique_list[l];
        int limit_high = fatique_list[r];
        int left = goal;
        bool success = false;

        fill(&visited[0][0], &visited[n + 1][n + 1], false);
        queue<loc> que;
        if (start_value <= limit_high &&
            start_value >= limit_low)
            que.push({start_location.row, start_location.col});

        while (que.size())
        {
            loc current = que.front();
            que.pop();

            if (town[current.row][current.col] == 'K')
            {
                left--;
                if (left == 0)
                {
                    success = true;
                    break;
                }
            }

            for (int i = 0; i < 8; i++)
            {
                int r = current.row + dr[i];
                int c = current.col + dc[i];

                if (r < n && r >= 0 && c < n && c >= 0 && visited[r][c] == false &&
                    fatique[r][c] <= limit_high && fatique[r][c] >= limit_low)
                {
                    visited[r][c] = true;
                    que.push({r, c});
                }
            }
        }

        if (success)
        {
            min_ = min(min_, fatique_list[r] - fatique_list[l]);
            if (l == r)
                r++;
            else
                l++;
        }
        else
            r++;
    }

    cout << min_;
}