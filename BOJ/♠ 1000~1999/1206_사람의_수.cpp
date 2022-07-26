#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int avg[50];

bool check(int avg, int ans)
{
    for (int i = 0; i <= ans * 10; i++)
    {
        int cur = i * 1000 / ans;

        if (cur == avg)
            return true;
    }

    return false;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string temp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
        avg[i] = stoi(temp);
    }

    for (int i = 1; i <= 1000; i++)
    {
        bool success = true;

        for (int j = 0; j < N; j++)
        {
            if (!check(avg[j], i))
            {
                success = false;
                break;
            }
        }

        if (success)
        {
            cout << i;
            break;
        }
    }
}