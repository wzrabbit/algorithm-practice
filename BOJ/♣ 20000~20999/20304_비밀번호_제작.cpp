#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int visited[1000001];
vector<int> xor_value;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int limit, num, d;
    queue<int> que;
    int max_ = 0;
    int temp = 1;

    cin >> limit >> num;
    fill(visited, visited + 1000001, -1);
    while (num--)
    {
        cin >> d;
        visited[d] = 0;
        que.push(d);
    }

    for (int i = 1; i <= 20; i++)
    {
        xor_value.push_back(temp);
        temp *= 2;
    }

    while (que.size())
    {
        int current = que.front();
        que.pop();
        max_ = visited[current];

        for (int i = 0; i < 20; i++)
        {
            int next = current ^ xor_value[i];
            if (next <= limit && visited[next] == -1)
            {
                visited[next] = visited[current] + 1;
                que.push(next);
            }
        }
    }

    cout << max_;
}