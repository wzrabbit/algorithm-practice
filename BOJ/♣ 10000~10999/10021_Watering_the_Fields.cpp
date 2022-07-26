#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

struct Line
{
    int s, e, c;
};

int parent[2000];
int ranks[2000];
vector<Point> point;
vector<Line> line;

int get_parent(int child)
{
    if (parent[child] == -1)
        return child;

    return parent[child] = get_parent(parent[child]);
}

bool merge(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);

    if (a == b)
        return false;
    else
    {
        if (ranks[a] > ranks[b])
        {
            parent[b] = a;
            ranks[a] += ranks[b];
        }
        else
        {
            parent[a] = b;
            ranks[b] += ranks[a];
        }

        return true;
    }
}

bool compare(Line A, Line B)
{
    return A.c < B.c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M, x, y;
    cin >> N >> M;

    fill(&parent[0], &parent[N], -1);
    fill(&ranks[0], &ranks[N], 1);

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        point.push_back({x, y});
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            Point A = point[i];
            Point B = point[j];
            int cost = (int)pow(A.x - B.x, 2) + (int)pow(A.y - B.y, 2);

            if (cost >= M)
                line.push_back({i, j, cost});
        }
    }

    sort(line.begin(), line.end(), compare);

    int cnt = 0;
    int total = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (merge(line[i].s, line[i].e))
        {
            cnt++;
            total += line[i].c;
        }

        if (cnt == N - 1)
            break;
    }

    if (cnt == N - 1)
        cout << total;
    else
        cout << -1;
}