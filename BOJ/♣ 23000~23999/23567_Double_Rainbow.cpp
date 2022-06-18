#include <iostream>
#include <algorithm>
#define INF 10001
using namespace std;

int arr[10001];
int in[10001];
int out[10001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, c;
    int in_color = 0;
    int out_color = 0;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        out[arr[i]]++;

        if (out[arr[i]] == 1)
            out_color++;
    }

    int l = 0;
    int r = 0;
    int min_ = INF;

    while (r <= n)
    {
        if (in_color < c)
        {
            in[arr[r]]++;
            out[arr[r]]--;

            if (in[arr[r]] == 1)
                in_color++;
            if (out[arr[r]] == 0)
                out_color--;

            r++;
        }
        else
        {
            if (out_color == c)
                min_ = min(min_, r - l);

            in[arr[l]]--;
            out[arr[l]]++;

            if (in[arr[l]] == 0)
                in_color--;
            if (out[arr[l]] == 1)
                out_color++;

            l++;
        }
    }

    if (min_ == INF)
        cout << 0;
    else
        cout << min_;
}