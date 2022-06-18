#include <iostream>
#include <algorithm>
using namespace std;

int priority[1000002];
int result[1000001];
int no = 1;

void set_priority(int start, int end)
{
    int mid = (start + end) / 2;
    priority[mid] = no;
    no++;

    if (start == end)
        return;

    if (end - start == 1)
    {
        set_priority(end, end);
        return;
    }

    set_priority(start, mid - 1);
    set_priority(mid + 1, end);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    set_priority(1, N);
    priority[N + 1] = 0;

    for (int i = 1; i <= N; i++)
        result[i] = i;

    int l = 1;
    for (int r = 1; r <= N + 1; r++)
    {
        if (priority[r] < K)
        {
            if (l == r)
                l = r + 1;
            else
            {
                reverse(&result[l], &result[r]);
                l = r;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= N; i++)
        cout << result[i] << ' ';
    cout << '\n';
}