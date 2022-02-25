#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

set<string> visited;
int d1[4] = {-1, 1, -3, 3};
int d2[4][3] = {{0, 3, 6}, {2, 5, 8}, {0, 1, 2}, {6, 7, 8}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string start = "";
    char temp;
    for (int i = 0; i < 9; i++)
    {
        cin >> temp;
        start += temp;
    }

    queue<pair<string, int>> que;
    que.push(make_pair(start, 0));
    int success = false;

    while (que.size())
    {
        string current = que.front().first;
        int dist = que.front().second;
        que.pop();

        if (current == "123456780")
        {
            cout << dist << '\n';
            success = true;
            break;
        }

        int zero = current.find('0');
        for (int i = 0; i <= 3; i++)
        {
            int z = zero + d1[i];
            bool kill = false;
            for (int j = 0; j <= 2; j++)
            {
                if (zero == d2[i][j])
                    kill = true;
            }
            if (kill)
                continue;

            string next = current;
            swap(next[zero], next[z]);

            if (visited.find(next) == visited.end())
            {
                visited.insert(next);
                que.push(make_pair(next, dist + 1));
            }
        }
    }

    if (success == false)
        cout << "-1\n";
}