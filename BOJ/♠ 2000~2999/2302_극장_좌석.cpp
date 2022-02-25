#include <iostream>
using namespace std;

int seat[41] = {};

int main()
{
    int all, vip;
    int total = 1;

    cin >> all >> vip;
    for (int i = 0; i < vip; i++)
    {
        int v;
        cin >> v;
        seat[v] = -1;
    }

    seat[0] = -1;
    for (int i = 1; i <= all; i++)
    {
        if (seat[i] == -1)
        {
            if (seat[i - 1] != -1)
                total *= seat[i - 1];
        }
        else if (seat[i - 1] != -1)
        {
            if (seat[i - 2] != -1)
                seat[i] = seat[i - 2] + seat[i - 1];
            else
                seat[i] = 2;
        }
        else
            seat[i] = 1;
    }
    if (seat[all] != -1)
        total *= seat[all];

    cout << total;
}