#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

ll raw[4][4000];
ll arr_A[16000000];
ll arr_B[16000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int c = 0; c < n; c++)
    {
        for (int r = 0; r < 4; r++)
        {
            cin >> raw[r][c];
        }
    }

    int count = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            arr_A[count] = raw[0][x] + raw[1][y];
            arr_B[count] = raw[2][x] + raw[3][y];
            count++;
        }
    }

    sort(arr_A, arr_A + count);
    sort(arr_B, arr_B + count);

    ll answer = 0;
    for (int i = 0; i < count; i++)
    {
        ll ab = arr_A[i];
        answer += upper_bound(arr_B, arr_B + count, -arr_A[i]) - lower_bound(arr_B, arr_B + count, -arr_A[i]);
    }
    cout << answer;
}