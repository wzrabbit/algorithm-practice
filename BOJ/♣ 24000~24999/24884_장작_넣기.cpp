#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dt[3] = {-1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, start, time, need;
    cin >> num >> start >> time >> need;
    int answer = 0;

    vector<int> startVec;
    for (int i = 0; i < num; i++)
    {
        startVec.push_back(0);
        cin >> startVec[i];
    }
    startVec.push_back(start);
    startVec.push_back(1);
    queue<vector<int>> que;
    que.push(startVec);

    // 0 ~ num -1 : 남은 화력, num: 현재 위치, num + 1: 시간
    while (que.size())
    {
        vector<int> p = que.front();
        que.pop();
        vector<int> minus;

        for (int i = 0; i < num; i++)
        {
            if (i == p[num] && p[num + 1] != 1)
            {
                minus.push_back(0);
                continue;
            }

            int m = 3;
            if (i != 0 && p[i - 1] >= 1)
                m--;
            if (i != num - 1 && p[i + 1] >= 1)
                m--;
            minus.push_back(m);
        }

        for (int i = 0; i < num; i++)
        {
            p[i] -= minus[i];
            if (p[i] < 0)
                p[i] = 0;
        }

        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (p[i] >= 1)
                count++;
        }

        if (count >= need)
        {
            if (p[num + 1] == time)
            {
                answer++;
                continue;
            }
        }
        else
            continue;

        p[num + 1]++;
        for (int i = 0; i < 3; i++)
        {
            int temp = p[num];
            int next = p[num] + dt[i];

            if (next >= 0 && next < num)
            {
                p[num] = next;
                que.push(p);
            }

            p[num] = temp;
        }
    }

    cout << answer;
}