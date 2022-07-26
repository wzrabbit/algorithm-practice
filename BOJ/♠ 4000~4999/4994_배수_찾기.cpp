#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Dat
{
    int mod;
    string num;
};

string solve(int N)
{
    if (N == 1)
        return "1";

    vector<bool> visited(N, false);
    queue<Dat> q;
    q.push({1, "1"});

    while (q.size())
    {
        Dat cur = q.front();
        q.pop();

        if (cur.mod == 0)
            return cur.num;

        int zero = cur.mod * 10 % N;
        int one = (cur.mod * 10 + 1) % N;

        if (!visited[zero])
        {
            visited[zero] = true;
            q.push({zero, cur.num + "0"});
        }

        if (!visited[one])
        {
            visited[one] = true;
            q.push({one, cur.num + "1"});
        }
    }

    return "-1";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N;

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        cout << solve(N) << '\n';
    }
}