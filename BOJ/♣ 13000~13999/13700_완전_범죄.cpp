#include < iostream >
#include < queue >
using namespace std;

int visited[100001] = {};

int main()
{
    ios::sync_with_stdio(false);
    int range, start, end, right, left, police;
    cin >> range >> start >> end >> right >> left >> police;

    for (int i = 0; i < police; i++)
    {
        int p;
        cin >> p;
        visited[p] = -1;
    }

    queue<int> queue;
    queue.push(start);
    int result = -1;

    while (!queue.empty())
    {
        int c = queue.front();
        queue.pop();
        if (c == end)
        {
            result = visited[c];
            break;
        }

        int l = c - left;
        int r = c + right;
        if (r <= range && visited[r] == 0)
        {
            visited[r] = visited[c] + 1;
            queue.push(r);
        }
        if (l >= 1 && visited[l] == 0)
        {
            visited[l] = visited[c] + 1;
            queue.push(l);
        }
    }

    if (result == -1)
        cout << "BUG FOUND";
    else
        cout << result;
}