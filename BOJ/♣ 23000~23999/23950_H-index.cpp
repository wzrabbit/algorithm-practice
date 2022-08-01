#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        priority_queue<int, vector<int>, greater<int>> pq;
        cout << "Case #" << t << ": ";

        for (int i = 1; i <= N; i++)
        {
            int d;
            cin >> d;
            pq.push(d);

            while (pq.size() > 0 && pq.top() < pq.size())
                pq.pop();

            cout << pq.size() << ' ';
        }
        cout << '\n';
    }
}