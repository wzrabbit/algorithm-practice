#include <iostream>
#include <algorithm>
using namespace std;

int row[30001];
int col[30001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N, Q, q, x;
    cin >> N >> Q;

    int r_max = 0, c_max = 0, r_select = N, c_select = N;

    while (Q--)
    {
        cin >> q >> x;

        if (q == 1)
        {
            col[x]++;

            if (col[x] > c_max)
            {
                c_max++;
                c_select = 1;
            }
            else if (col[x] == c_max)
                c_select++;
        }
        else
        {
            row[x]++;

            if (row[x] > r_max)
            {
                r_max++;
                r_select = 1;
            }
            else if (row[x] == r_max)
                r_select++;
        }

        cout << r_select * c_select << '\n';
    }
}