#include <iostream>
#include <algorithm>
using namespace std;

int arr[501];
int wrong[3][3];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T, sub;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        int cnt = 0;

        fill(&wrong[0][0], &wrong[2][3], 0);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        for (int i = 0; i < N; i++)
            wrong[arr[i] % 3][i % 3]++;

        sub = min(wrong[0][1], wrong[1][0]);
        cnt += sub;
        wrong[0][1] -= sub;
        wrong[1][0] -= sub;

        sub = min(wrong[0][2], wrong[2][0]);
        cnt += sub;
        wrong[0][2] -= sub;
        wrong[2][0] -= sub;

        sub = min(wrong[1][2], wrong[2][1]);
        cnt += sub;
        wrong[1][2] -= sub;
        wrong[2][1] -= sub;

        cnt += wrong[0][1] * 2;
        cnt += wrong[1][0] * 2;

        cout << "Case #" << t << ": " << cnt << '\n';
    }
}