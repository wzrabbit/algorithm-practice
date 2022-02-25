#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> arr[r][c];
        }
    }

    for (int m = 0; m < n; m++)
    {
        for (int s = 0; s < n; s++)
        {
            for (int e = 0; e < n; e++)
            {
                if (arr[s][m] == 1 && arr[m][e] == 1)
                {
                    arr[s][e] = 1;
                }
            }
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << arr[r][c] << ' ';
        }
        cout << '\n';
    }
}