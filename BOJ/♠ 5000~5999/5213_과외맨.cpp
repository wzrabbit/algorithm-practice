#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct d_data
{
    int left, right;
};
struct t_data
{
    int node, hist;
};
vector<t_data> tra;

void print_result(t_data best)
{
    if (best.hist != -1)
        print_result(tra[best.hist]);
    cout << best.node << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;
    a = n * n - n / 2;
    vector<d_data> domino(a + 1);
    vector<int> visited(a + 1);
    for (int i = 1; i <= a; i++)
    {
        cin >> domino[i].left >> domino[i].right;
        visited[i] = 0;
    }

    t_data best = {1, -1};
    int index = 0;
    tra.push_back({1, -1});
    visited[1] = 1;
    while (index < tra.size())
    {
        int current = tra[index].node;
        if (current > best.node)
            best = {current, tra[index].hist};

        int state, next[2];
        int calc = current % (n * 2 - 1);
        if (calc == 1)
            state = 1; // 홀수 줄, 첫 칸
        else if (calc == n)
            state = 2; // 홀수 줄, 마지막 칸
        else if (calc == n + 1)
            state = 3; // 짝수 줄, 첫 칸
        else if (calc == 0)
            state = 4; // 짝수 줄, 마지막 칸
        else if (calc < n)
            state = 5; // 홀수 줄, 나머지 칸
        else
            state = 6; // 짝수 줄, 나머지 칸

        // ↖, ↙
        next[0] = current - n;
        next[1] = current + n - 1;
        for (int i = 0; i <= 1; i++)
        {
            if (state != 1 && next[i] >= 1 && next[i] <= a && visited[next[i]] == 0 &&
                domino[next[i]].right == domino[current].left)
            {
                visited[next[i]] = visited[current] + 1;
                tra.push_back({next[i], index});
            }
        }

        // ↗, ↘
        next[0] = current - n + 1;
        next[1] = current + n;
        for (int i = 0; i <= 1; i++)
        {
            if (state != 2 && next[i] >= 1 && next[i] <= a && visited[next[i]] == 0 &&
                domino[next[i]].left == domino[current].right)
            {
                visited[next[i]] = visited[current] + 1;
                tra.push_back({next[i], index});
            }
        }

        // ←
        next[0] = current - 1;
        if (state != 1 && state != 3 && visited[next[0]] == 0 &&
            domino[next[0]].right == domino[current].left)
        {
            visited[next[0]] = visited[current] + 1;
            tra.push_back({next[0], index});
        }

        // →
        next[0] = current + 1;
        if (state != 2 && state != 4 && visited[next[0]] == 0 &&
            domino[next[0]].left == domino[current].right)
        {
            visited[next[0]] = visited[current] + 1;
            tra.push_back({next[0], index});
        }

        index++;
    }

    cout << visited[best.node] << '\n';
    print_result(best);
}